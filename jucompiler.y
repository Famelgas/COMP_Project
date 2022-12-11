%{
    /*
    Miguel Filipe de Andrade Sergio 2020225643
    Filipe David Amado Mendes 2020218797
    */

    #include "functions.h"

    int yylex(void);
    void yyerror (const char *s);

    Node *root, *aux; //Just a aux Node other used aux nodes are declared in the moment
    int flag_error = 0; //Flag to check if there was an error in the code used as extern in lex
%}

%union {
	struct token *token; //Token struct defined in functions.h
	struct Node *no; //Node struct defined in functions.h
}

%token <token> LPAR BOOL DOUBLE INT VOID CLASS LBRACE ARROW ASSIGN RESERVED RBRACE PARSEINT PUBLIC STATIC ELSE WHILE SEMICOLON RPAR STRING COMMA LSQ RSQ IF RETURN PRINT PLUS MINUS STAR DIV MOD AND OR XOR LSHIFT RSHIFT EQ GE GT LE LT NE NOT DOTLENGTH ID INTLIT REALLIT STRLIT BOOLLIT

%type <no> Program Program2 MethodDecl FieldDecl FieldDecl2 Type MethodHeader MethodHeader2 FormalParams FormalParams2 MethodBody MethodBody2 VarDecl VarDecl2 Statement Statement2 Statement3 Statement4 MethodInvocation MethodInvocation2 MethodInvocation3 Assignment ParseArgs Expr Expr2 Expr3 Expr4 Expr5

%right ASSIGN
%left OR
%left AND
%left XOR
%left EQ NE
%left GE GT LE LT
%left LSHIFT RSHIFT
%left PLUS MINUS
%left STAR DIV MOD
%right UNARY
%left LPAR RPAR LSQ RSQ
%right ELSE

/*IMPORTANT I dont hunderstend very much how token like $1, $2 etc work i supose thats have to do whith the order in declaration of grammar*/

/*create_node(type in struct enum in the end dosent use, value to recive or "" if no value, Node name, line, col)*/
/*add_child(parent, child) add a child to  the parent*/
/*add_next(child, brother) add a brother to the child or to the node in general*/
/*free_token(token) free the token, always free tokens thats wase used in create_node*/
/*in case of error flag_error = 1*/
/*in case of grammae acept empety $$->root = NULL*/

%%

Program:	CLASS ID LBRACE Program2 RBRACE					                {root = create_node(node_root, "", "Program",0, 0); aux = create_node(node_id, $2->value, "Id", $2->line, $2->col); add_child(root, aux); add_next(aux, $4); $$ = root;free_token($2);}
            | CLASS ID LBRACE Program2 RBRACE error				            {$$ = NULL; flag_error = 1;}

		;

Program2:  MethodDecl Program2							                    {$$ = $1; add_next($$, $2);}
			|	FieldDecl Program2								            {$$ = $1; add_next($$, $2);}
			|	SEMICOLON Program2								            {$$ = $2;}
            |	/* empty */											        {$$ = NULL;}
			;

MethodDecl:	PUBLIC STATIC MethodHeader MethodBody					        {$$ = create_node(node_methods, "", "MethodDecl",0,0); add_child($$, $3); add_next($3, $4);}
		;

FieldDecl:	PUBLIC STATIC Type ID FieldDecl2 SEMICOLON				        {$$ = create_node(node_var, "", "FieldDecl",0,0); add_child($$, $3); add_next($3, create_node(node_id, $4->value, "Id", $4->line, $4->col));
																	            if ($5 != NULL){
																		            aux = $5;
																	    	        while (aux != NULL) {
																		    	        Node* aux1 = create_node(node_var, "", "FieldDecl",0,0);
																			            Node* aux2 = create_node($3->type, $3->value, $3->symbol, $3->line, $3->col);
																			            add_child(aux1, aux2);
																			            add_next(aux2, create_node(node_id, aux->value, "Id", aux->line, aux->col));
																		                add_next($$, aux1);
																		                aux = aux->brother;
																    	            }
                                                                                    free(aux);
																	            }
                                                                                free_token($4);
                                                                            }
		|	error SEMICOLON											        {$$ = NULL; flag_error = 1;}
		;

FieldDecl2:	COMMA ID FieldDecl2										        {$$ = create_node(node_id, $2->value, "Id",$2->line,$2->col); add_next($$, $3);free_token($2);}
        |   /* empty */												        {$$ = NULL;}
		;

Type:	BOOL														        {$$ = create_node(node_terminals, "", "Bool",0,0);}
	|	INT															        {$$ = create_node(node_terminals, "", "Int",0,0);}
	|	DOUBLE														        {$$ = create_node(node_terminals, "", "Double",0,0);}
	;
    
MethodHeader: Type ID LPAR MethodHeader2 RPAR						        {$$ = create_node(node_methods, "", "MethodHeader",0,0); add_child($$,$1); add_next($1, create_node(node_id, $2->value, "Id", $2->line, $2->col));aux = create_node(node_methods, "" , "MethodParams", 0,0); add_next($1, aux); add_child(aux, $4);free_token($2);}                                            
            | VOID ID LPAR MethodHeader2 RPAR						        {$$ = create_node(node_methods, "", "MethodHeader",0,0); aux = create_node(node_terminals, "", "Void",$1->line,$1->col); add_child($$, aux); add_next(aux, create_node(node_id, $2->value, "Id", $2->line, $2->col)); Node* aux2 = create_node(node_methods, "", "MethodParams", 0, 0); add_next(aux, aux2); add_child(aux2, $4);free_token($1);free_token($2);}
    ;

MethodHeader2:FormalParams										            {$$ = $1;}
            |/* empty */											        {$$ = NULL;}
			;

FormalParams: Type ID FormalParams2                                         {$$ = create_node(node_methods, "", "ParamDecl",0,0); add_child($$, $1); aux = create_node(node_id, $2->value, "Id", $2->line, $2->col); add_next($1, aux); add_next($$, $3);free_token($2);}                
            | STRING LSQ RSQ ID                                             {$$ = create_node(node_methods, "", "ParamDecl",0,0); aux = create_node(node_methods, "", "StringArray", $1->line,$1->col); add_child($$, aux); add_next(aux, create_node(node_id, $4->value, "Id", $4->line, $4->col));free_token($1);free_token($4);}
    ;

FormalParams2: COMMA Type ID FormalParams2                                  {$$ = create_node(node_methods, "", "ParamDecl",0,0); aux = create_node(node_id, $3->value, "Id", $3->line, $3->col); add_child($$, $2); add_next($2, aux); add_next($$, $4);free_token($3);}
            | /* empty */                                                   {$$ = NULL;}  
    ;

MethodBody: LBRACE MethodBody2 RBRACE                                       {$$ = create_node(node_methods, "", "MethodBody",0,0); add_child($$, $2);}                
    ;

MethodBody2: Statement MethodBody2                                          {if ($1 != NULL){
																		        $$ = $1;
																		        add_next($$, $2);
																		    }
																	        else {
																		        $$ = $2;
																	        }}
            | VarDecl MethodBody2                                           {$$ = $1; add_next($$, $2);}
            | /* empty */                                                   {$$ = NULL;}
    ;

VarDecl: Type ID VarDecl2 SEMICOLON                                         {$$ = create_node(node_methods, "", "VarDecl",0,0); add_child($$, $1); add_next($1, create_node(node_id, $2->value, "Id", $2->line, $2->col));
																	            if ($3 != NULL){
																		            aux = $3;
																		            while (aux != NULL) {
																			            Node* aux1 = create_node(node_methods, "", "VarDecl",0,0);
																			            Node* aux2 = create_node($1->type, $1->value, $1->symbol, $1->line, $1->col);
																			            add_child(aux1, aux2);
																			            add_next(aux2, create_node(node_id, aux->value, "Id", aux->line, aux->col));
																			            add_next($$, aux1);
																			            aux = aux->brother;
																		            }
                                                                                    free(aux);
																	            }
                                                                                free_token($2);
                                                                            }         
    ;

VarDecl2: COMMA ID VarDecl2                                                 {$$ = create_node(node_id, $2->value, "Id",$2->line,$2->col); add_next($$, $3);free_token($2);}
        | /* empty */                                                       {$$ = NULL;}
    ;
    
Statement:	LBRACE Statement2 RBRACE								        {if (count_child($2) > 1) {
                                                                                aux = create_node(node_statements, "", "Block",0,0);
                                                                                $$ = aux;
                                                                                add_child(aux, $2);
                                                                            }
                                                                            else {
                                                                                $$ = $2;
                                                                            }}
        |	IF LPAR Expr RPAR Statement                   					{$$ = create_node(node_statements, "", "If", $1->line, $1->col);
                                                                                add_child($$,$3);
                                                                                aux = create_node(node_statements, "", "Block",0,0);
                                                                                if (count_child($5) == 1 && $5 != NULL) {
                                                                                    add_next($3, $5);
                                                                                    add_next($5, aux);
                                                                                }
                                                                                else {
                                                                                    add_next($3, aux);
                                                                                    add_child(aux, $5);
                                                                                    add_next(aux, create_node(node_statements, "", "Block",0,0));
                                                                            }
                                                                            free_token($1);
                                                                            }
        |	IF LPAR Expr RPAR Statement ELSE Statement				        {$$ = create_node(node_statements, "" , "If", $1->line, $1->col);
                                                                            add_child($$,$3);
                                                                            aux = create_node(node_statements, "", "Block",0,0);
                                                                            if (count_child($5) == 1 && $5 != NULL) {
                                                                                add_next($3, $5);
                                                                                if (count_child($7) == 1 && $7 != NULL) {
                                                                                    add_next($5, $7);
                                                                                }
                                                                                else {
                                                                                    add_next($5, aux);
                                                                                    add_child(aux, $7);
                                                                                }
                                                                            }
                                                                            else {
                                                                                add_next($3, aux);
                                                                                add_child(aux, $5);
                                                                                if (count_child($7) == 1 && $7 != NULL) {
                                                                                    add_next(aux, $7);
                                                                                }
                                                                                else {
                                                                                    Node* aux2 = create_node(node_statements, "", "Block",0,0);
                                                                                    add_next(aux, aux2);
                                                                                    add_child(aux2, $7);
                                                                                }
                                                                            }
                                                                            free_token($1);
                                                                            }
		|	WHILE LPAR Expr RPAR Statement							        {$$ = create_node(node_statements, "" , "While", $1->line , $1->col);
                                                                                add_child($$, $3);
                                                                                if (count_child($5) == 1 && $5 != NULL) {
                                                                                    add_next($3, $5);
                                                                                }
                                                                                else {
                                                                                    aux = create_node(node_statements, "", "Block", 0, 0);
                                                                                    add_next($3, aux);
                                                                                    add_child(aux, $5);
                                                                                }
                                                                                free_token($1);
                                                                            }
		|	RETURN Expr5 SEMICOLON								            {$$ = create_node(node_statements, "" , "Return", $1->line , $1->col); add_child($$, $2);free_token($1);}
		|	Statement3 SEMICOLON									        {$$ = $1;}
		|	PRINT LPAR Statement4 RPAR SEMICOLON                            {$$ = create_node(node_statements, "" , "Print", $1->line, $1->col); add_child($$, $3);free_token($1);}
		|	error SEMICOLON											        {$$ = NULL; flag_error = 1;}
		;

Expr5:	Expr												    	        {$$ = $1;}
		|    /* empty */												    {$$ = NULL;}
        ;

Statement2: Statement Statement2                                            {if ($1 != NULL) {
																		        $$ = $1;
																		        add_next($$, $2);
                                                                            }
                                                                            else {
                                                                                $$ = $2;
                                                                            }
                                                                            }
        |   /* empty */                                                     {$$ = NULL;}
    ;

Statement3: MethodInvocation										        {$$ = $1;}
		|	Assignment												        {$$ = $1;}
		|	ParseArgs												        {$$ = $1;}
        |   /* empty */                                                     {$$ = NULL;}
		;

Statement4: Expr												            {$$ = $1;}
        |	STRLIT												            {$$ = create_node(node_terminals, $1->value, "StrLit", $1->line, $1->col);free_token($1);}
        ;


MethodInvocation:	ID LPAR MethodInvocation2 RPAR					        {$$ = create_node(node_operators, "" , "Call", $1->line, $1->col); aux = create_node(node_id, $1->value, "Id", $1->line, $1->col); add_child($$, aux); add_next(aux, $3);free_token($1);}
				|	ID LPAR error RPAR								        {$$ = NULL; flag_error = 1;}
				;

MethodInvocation2:	Expr MethodInvocation3						            {$$ = $1; add_next($$, $2);}
				|	/* empty */										        {$$ = NULL;}
				;

MethodInvocation3:	COMMA Expr MethodInvocation3						    {if($2!=NULL) {
                                                                                $$=$2; 
                                                                                add_next($$, $3);
                                                                            }
                                                                            else {
                                                                                $$=$2;
                                                                            }}
				|	/* empty */										        {$$ = NULL;}
				;


Assignment: ID ASSIGN Expr                                                  {$$ = create_node(node_operators, "", "Assign", $2->line, $2->col); aux = create_node(node_id, $1->value, "Id", $1->line, $1->col); add_child($$, aux); add_next(aux, $3);free_token($1);free_token($2);}
        ;

ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR                               {$$ = create_node(node_operators, "", "ParseArgs", $1->line, $1->col); aux = create_node(node_id, $3->value, "Id", $3->line, $3->col); add_child($$, aux); add_next(aux, $5);free_token($1);free_token($3);}
        | PARSEINT LPAR error RPAR                                          {$$ = NULL; flag_error = 1;}
        ;

Expr: Assignment                                                            {$$ = $1;}
    | Expr2                                                                 {$$ = $1;}
    ;

Expr2: Expr2 PLUS Expr2                                                     {$$ = create_node(node_operators, "", "Add", $2->line, $2->col); add_child($$, $1); add_next($1, $3);free_token($2);}
        | Expr2 MINUS Expr2                                                 {$$ = create_node(node_operators, "", "Sub",$2->line, $2->col); add_child($$, $1); add_next($1, $3);free_token($2);}
        | Expr2 STAR Expr2                                                  {$$ = create_node(node_operators, "", "Mul", $2->line, $2->col); add_child($$, $1); add_next($1, $3);free_token($2);}
        | Expr2 DIV Expr2                                                   {$$ = create_node(node_operators, "", "Div", $2->line, $2->col); add_child($$, $1); add_next($1, $3);free_token($2);}
        | Expr2 MOD Expr2                                                   {$$ = create_node(node_operators, "", "Mod", $2->line, $2->col); add_child($$, $1); add_next($1, $3);free_token($2);}
        | Expr2 AND Expr2                                                   {$$ = create_node(node_operators, "", "And", $2->line, $2->col); add_child($$, $1); add_next($1, $3);free_token($2);}
        | Expr2 OR Expr2                                                    {$$ = create_node(node_operators, "", "Or", $2->line, $2->col); add_child($$, $1); add_next($1, $3);free_token($2);}
        | Expr2 XOR Expr2                                                   {$$ = create_node(node_operators, "", "Xor", $2->line, $2->col); add_child($$, $1); add_next($1, $3);free_token($2);}
        | Expr2 LSHIFT Expr2                                                {$$ = create_node(node_operators, "", "Lshift", $2->line, $2->col); add_child($$, $1); add_next($1, $3);free_token($2);}
        | Expr2 RSHIFT Expr2                                                {$$ = create_node(node_operators, "", "Rshift", $2->line, $2->col); add_child($$, $1); add_next($1, $3);free_token($2);}
        | Expr2 EQ Expr2                                                    {$$ = create_node(node_operators, "", "Eq", $2->line, $2->col); add_child($$, $1); add_next($1, $3);free_token($2);}
        | Expr2 GE Expr2                                                    {$$ = create_node(node_operators, "", "Ge", $2->line, $2->col); add_child($$, $1); add_next($1, $3);free_token($2);}
        | Expr2 GT Expr2                                                    {$$ = create_node(node_operators, "", "Gt", $2->line, $2->col); add_child($$, $1); add_next($1, $3);free_token($2);}
        | Expr2 LE Expr2                                                    {$$ = create_node(node_operators, "", "Le", $2->line, $2->col); add_child($$, $1); add_next($1, $3);free_token($2);}
        | Expr2 LT Expr2                                                    {$$ = create_node(node_operators, "", "Lt", $2->line, $2->col); add_child($$, $1); add_next($1, $3);free_token($2);}
        | Expr2 NE Expr2                                                    {$$ = create_node(node_operators, "", "Ne", $2->line, $2->col); add_child($$, $1); add_next($1, $3);free_token($2);}
        | MINUS Expr2 %prec UNARY                                             {$$ = create_node(node_operators, "", "Minus", $1->line, $1->col); add_child($$, $2);free_token($1);}  
        | PLUS Expr2 %prec UNARY                                              {$$ = create_node(node_operators, "", "Plus", $1->line, $1->col); add_child($$, $2);free_token($1);}
        | NOT Expr2 %prec UNARY                                               {$$ = create_node(node_operators, "", "Not", $1->line, $1->col); add_child($$, $2);free_token($1);}
        | LPAR Expr RPAR                                                    {$$ = $2;}
        | LPAR error RPAR                                                   {$$ = NULL; flag_error = 1;}
        | Expr3												                {$$ = $1;}
        | ID                                                                {$$ = create_node(node_id, $1->value, "Id", $1->line, $1->col);free_token($1);}
        | ID DOTLENGTH                                                      {$$ = create_node(node_operators, "", "Length", $2->line,$2->col); add_child($$, create_node(node_id, $1->value, "Id", $1->line, $1->col));free_token($2);free_token($1);}
        | Expr4												                {$$ = $1;}
    ;

Expr3: MethodInvocation                                                     {$$ = $1;}
    | ParseArgs                                                             {$$ = $1;}
    ;

Expr4: INTLIT                                                               {$$ = create_node(node_terminals, $1->value, "DecLit", $1->line, $1->col);free_token($1);}
    | REALLIT                                                               {$$ = create_node(node_terminals, $1->value, "RealLit", $1->line, $1->col);free_token($1);}
    | BOOLLIT                                                               {$$ = create_node(node_terminals, $1->value, "BoolLit", $1->line, $1->col);free_token($1);}
    ;

%%