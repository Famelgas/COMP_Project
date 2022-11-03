%{
    #include "functions.h"
    extern int flag;
    int flag_error = 0;
%}

%union {
	char * id;
	struct node * node;
}



%token LPAR BOOL DOUBLE INT VOID CLASS LBRACE ARROW ASSIGN RBRACE PARSEINT PUBLIC STATIC ELSE WHILE SEMICOLON RPAR STRING COMMA LSQ RSQ IF RETURN PRINT PLUS MINUS STAR DIV MOD AND OR XOR LSHIFT RSHIFT EQ GE GT LE LT NE NOT DOTLENGTH 

%token <id> ID
%token <id> INTLIT
%token <id> REALLIT
%token <id> BOOLLIT
%token <id> STRLIT

%type <node> Program Program2 MethodDecl FieldDecl FieldDecl2 Type MethodHeader MethodHeader2 FormalParams FormalParams2 MethodBody MethodBody2 VarDecl VarDecl2 Statement Statement2 Statement3 Statement4 MethodInvocation MethodInvocation2 MethodInvocation3 Assignment ParseArgs Expr Expr2 Expr3 Expr4

%left OR
%left AND
%left XOR
%left EQ NE
%left GE GT LE LT
%left LSHIFT RSHIFT
%left PLUS MINUS
%left STAR DIV MOD
%left LPAR RPAR LSQ RSQ
%right ASSIGN
%right UNARY
%right ELSE

%%
Program: CLASS ID LBRACE Program2 RBRACE                                    {$$ = root = create_node(node_root, "", "Program");aux = create_node(node_id, $2, "Id"); add_child(root, aux); add_next(aux, $4);
                                                                                if (flag && !flag_error) {
                                                                                    print_tree($$, 0);
                                                                                }
                                                                            }
    ;       

Program2: FieldDecl Program2                                                {$$ = $1; add_next($$, $2);}
        | MethodDecl Program2   							                {$$ = $1; add_next($$, $2);}
        | SEMICOLON Program2                                                {$$ = $2;}
        | /* empty */                                                       {$$ = NULL;}
    ;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody                           {$$ = create_node(node_methods, "", "MethodDecl"); add_child($$, $3); add_next($3, $4);}     
    ;

FieldDecl: PUBLIC STATIC Type ID FieldDecl2 SEMICOLON                       {$$ = create_node(node_var, "", "FieldDecl"); add_child($$, $3); add_next($3, create_node(node_id, $4, "Id"));
                                                                                if ($5 != NULL){
                                                                                    aux = $5;
                                                                                    while (aux != NULL) {
                                                                                        node_t aux1 = create_node(node_var, "", "FieldDecl");
                                                                                        node_t aux2 = create_node($3->type, $3->value, $3->symbol);
                                                                                        add_child(aux1, aux2);
                                                                                        add_next(aux2, create_node(node_id, aux->value, "Id"));
                                                                                        add_next($$, aux1);
                                                                                        aux = aux->brother;
                                                                                    }
                                                                                    free(aux);
                                                                                }
                                                                            }
        | error SEMICOLON                                                   {$$ = NULL; flag_error = 1;}
    ;

FieldDecl2: COMMA ID FieldDecl2                                             {$$ = create_node(node_id, $2, "Id"); add_next($$, $3);}
        | /* empty */                                                       {$$ = NULL;}
    ;

Type:	BOOL														        {$$ = create_node(node_terminals, "", "Bool");}                                                
    | DOUBLE                                                                {$$ = create_node(node_terminals, "", "Double");}               
    | INT                                                                   {$$ = create_node(node_terminals, "", "Int");}  
    ;
    
MethodHeader: Type ID LPAR MethodHeader2 RPAR						        {$$ = create_node(node_methods, "", "MethodHeader"); add_child($$,$1); add_next($1, create_node(node_id, $2, "Id"));aux = create_node(node_methods, "", "MethodParams"); add_next($1, aux); add_child(aux, $4);}                                            
            | VOID ID LPAR MethodHeader2 RPAR						        {$$ = create_node(node_methods, "", "MethodHeader"); node_t aux2 = create_node(node_methods, "", "MethodParams"); add_next(aux, aux2); add_child(aux2, $4);}
    ;

MethodHeader2:FormalParams										            {$$ = $1;}
            |/* empty */											        {$$ = NULL;}
			;

FormalParams: Type ID FormalParams2                                         {$$ = create_node(node_methods, "", "ParamDecl"); add_child($$, $1); aux = create_node(node_id, $2, "Id"); add_next($1, aux); add_next($$, $3);}                
            | STRING LSQ RSQ ID                                             {$$ = create_node(node_methods, "", "ParamDecl"); aux = create_node(node_methods, "", "StringArray"); add_child($$, aux); add_next(aux, create_node(node_id, $4, "Id"));}
    ;

FormalParams2: COMMA Type ID FormalParams2                                  {$$ = create_node(node_methods, "", "ParamDecl"); aux = create_node(node_id, $3, "Id"); add_child($$, $2); add_next($2, aux); add_next($$, $4);}
            | /* empty */                                                   {$$ = NULL;}  
    ;

MethodBody: LBRACE MethodBody2 RBRACE                                       {$$ = create_node(node_methods, "", "MethodBody"); add_child($$, $2);}                
    ;

MethodBody2: Statement MethodBody2                                          {if ($1 != NULL){
																		        $$ = $1;
																		        add_child($$, $2);
																		    }
																	        else {
																		        $$ = $2;
																	        }}
            | VarDecl MethodBody2                                           {$$ = $1; add_next($$, $2);}
            | /* empty */                                                   {$$ = NULL;}
    ;

VarDecl: Type ID VarDecl2 SEMICOLON                                         {$$ = create_node(node_methods, "", "VarDecl"); add_child($$, $1); add_next($1, create_node(node_id, $2, "Id"));
																	            if ($3 != NULL){
																		            aux = $3;
																		            while (aux != NULL) {
																			            node_t aux1 = create_node(node_methods, "", "VarDecl");
																			            node_t aux2 = create_node($1->type, $1->value, $1->symbol);
																			            add_child(aux1, aux2);
																			            add_next(aux2, create_node(node_id, aux->value, "Id"));
																			            add_next($$, aux1);
																			            aux = aux->brother;
																		            }
																		            free(aux);
																	            }
                                                                            }         
    ;

VarDecl2: COMMA ID VarDecl2                                                 {$$ = create_node(node_id, $2, "Id"); add_next($$, $3);}
        | /* empty */                                                       {$$ = NULL;}
    ;
    
Statement:	LBRACE Statement2 RBRACE								        {if (count_children($2) > 1) {
                                                                                aux = create_node(node_statements, "", "Block");
                                                                                $$ = aux;
                                                                                add_child(aux, $2);
                                                                            }
                                                                            else {
                                                                                $$ = $2;
                                                                            }}
        |	IF LPAR Expr RPAR Statement %prec ELSE        					{$$ = create_node(node_statements, "", "If");
                                                                                add_child($$,$3);
                                                                                aux = create_node(node_statements, "", "Block");
                                                                                if (count_children($5) == 1 && $5 != NULL) {
                                                                                    add_next($3, $5);
                                                                                    add_next($5, aux);
                                                                                }
                                                                                else {
                                                                                    add_next($3, aux);
                                                                                    add_child(aux, $5);
                                                                                    add_next(aux, create_node(node_statements, "", "Block"));
                                                                            }}
        |	IF LPAR Expr RPAR Statement ELSE Statement				        {$$ = create_node(node_statements, "", "If");
                                                                            add_child($$,$3);
                                                                            aux = create_node(node_statements, "", "Block");
                                                                            if (count_children($5) == 1 && $5 != NULL) {
                                                                                add_next($3, $5);
                                                                                if (count_children($7) == 1 && $7 != NULL) {
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
                                                                                if (count_children($7) == 1 && $7 != NULL) {
                                                                                    add_next(aux, $7);
                                                                                }
                                                                                else {
                                                                                    node_t aux2 = create_node(node_statements, "", "Block");
                                                                                    add_next(aux, aux2);
                                                                                    add_child(aux2, $7);
                                                                                }
                                                                            }}
		|	WHILE LPAR Expr RPAR Statement							        {$$ = create_node(node_statements, "", "While");
                                                                                add_child($$, $3);
                                                                                if (count_children($5) == 1 && $5 != NULL) {
                                                                                    add_next($3, $5);
                                                                                }
                                                                                else {
                                                                                    aux = create_node(node_statements, "", "Block");
                                                                                    add_next($3, aux);
                                                                                    add_child(aux, $5);
                                                                                }
                                                                            }
		|	RETURN Expr SEMICOLON								            {$$ = create_node(node_statements, "", "Return"); add_child($$, $2);}
		|	Statement3 SEMICOLON									        {$$ = $1;}
		|	PRINT LPAR Statement4 RPAR SEMICOLON                            {$$ = create_node(node_statements, "", "Print"); add_child($$, $3);}
		|	error SEMICOLON											        {$$ = NULL; flag_error = 1;}
		;

Statement2: Statement Statement2                                            {if ($1 != NULL) {
																		        $$ = $1;
																		        add_next($$, $2);
                                                                            }
                                                                            else {
                                                                                $$ = $2;
                                                                            }}
        |   /* empty */                                                     {$$ = NULL;}
    ;

Statement3: MethodInvocation										        {$$ = $1;}
		|	Assignment												        {$$ = $1;}
		|	ParseArgs												        {$$ = $1;}
        |   /* empty */                                                     {$$ = NULL;}
		;

Statement4: Expr												            {$$ = $1;}
        |	STRLIT												            {$$ = create_node(node_terminals, $1, "StrLit");}
        ;


MethodInvocation:	ID LPAR MethodInvocation2 RPAR					        {$$ = create_node(node_operators, "", "Call"); aux = create_node(node_id, $1, "Id"); add_child($$, aux); add_next(aux, $3);}
				|	ID LPAR error RPAR								        {$$ = NULL; flag_error = 1;}
				;

MethodInvocation2:	Expr MethodInvocation3						            {$$ = $1; add_next($$, $2);}
				|	/* empty */										        {$$ = NULL;}
				;

MethodInvocation3:	Expr MethodInvocation3						            {$$ = $1; add_next($$, $2);}
				|	/* empty */										        {$$ = NULL;}
				;


Assignment: ID ASSIGN Expr                                                  {$$ = create_node(node_operators, "", "Assign"); aux = create_node(node_id, $1, "Id"); add_child($$, aux); add_next(aux, $3);}
        ;

ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR                               {$$ = create_node(node_operators, "", "ParseArgs"); aux = create_node(node_id, $3, "Id"); add_child($$, aux); add_next(aux, $5);}
        | PARSEINT LPAR error RPAR                                          {$$ = NULL; flag_error = 1;}
        ;

Expr5: Expr2                                                                {$$ = $1;}
    |	/* empty */										                    {$$ = NULL;}
    ;

Expr: Assignment                                                            {$$ = $1;}
    | Expr2                                                                 {$$ = $1;}
    ;

Expr2: Expr2 PLUS Expr2                                                        {$$ = create_node(node_operators, "", "Add"); add_child($$, $1); add_next($1, $3);}
        | Expr2 MINUS Expr                                                   {$$ = create_node(node_operators, "", "Sub"); add_child($$, $1); add_next($1, $3);}
        | Expr2 STAR Expr                                                    {$$ = create_node(node_operators, "", "Mul"); add_child($$, $1); add_next($1, $3);}
        | Expr2 DIV Expr                                                     {$$ = create_node(node_operators, "", "Div"); add_child($$, $1); add_next($1, $3);}
        | Expr2 MOD Expr                                                     {$$ = create_node(node_operators, "", "Mod"); add_child($$, $1); add_next($1, $3);}
        | Expr2 AND Expr                                                     {$$ = create_node(node_operators, "", "And"); add_child($$, $1); add_next($1, $3);}
        | Expr2 OR Expr                                                      {$$ = create_node(node_operators, "", "Or"); add_child($$, $1); add_next($1, $3);}
        | Expr2 XOR Expr                                                     {$$ = create_node(node_operators, "", "Xor"); add_child($$, $1); add_next($1, $3);}
        | Expr2 LSHIFT Expr                                                  {$$ = create_node(node_operators, "", "Lshift"); add_child($$, $1); add_next($1, $3);}
        | Expr2 RSHIFT Expr                                                  {$$ = create_node(node_operators, "", "Rshift"); add_child($$, $1); add_next($1, $3);}
        | Expr2 EQ Expr                                                      {$$ = create_node(node_operators, "", "Eq"); add_child($$, $1); add_next($1, $3);}
        | Expr2 GE Expr                                                      {$$ = create_node(node_operators, "", "Ge"); add_child($$, $1); add_next($1, $3);}
        | Expr2 GT Expr                                                      {$$ = create_node(node_operators, "", "Gt"); add_child($$, $1); add_next($1, $3);}
        | Expr2 LE Expr                                                      {$$ = create_node(node_operators, "", "Le"); add_child($$, $1); add_next($1, $3);}
        | Expr2 LT Expr                                                      {$$ = create_node(node_operators, "", "Lt"); add_child($$, $1); add_next($1, $3);}
        | Expr2 NE Expr                                                      {$$ = create_node(node_operators, "", "Ne"); add_child($$, $1); add_next($1, $3);}
        | MINUS Expr2 %prec UNARY                                            {$$ = create_node(node_operators, "", "Minus"); add_child($$, $2);}  
        | PLUS Expr2 %prec UNARY                                             {$$ = create_node(node_operators, "", "Plus"); add_child($$, $2);}
        | NOT Expr2 %prec UNARY                                              {$$ = create_node(node_operators, "", "Not"); add_child($$, $2);}
        | LPAR Expr RPAR                                                    {$$ = $2;}
        | LPAR error RPAR                                                   {$$ = NULL; flag_error = 1;}
        | Expr3												                {$$ = $1;}
        | ID                                                                {$$ = create_node(node_id, $1, "Id");}
        | ID DOTLENGTH                                                      {$$ = create_node(node_operators, "", "Length"); add_child($$, create_node(node_id, $1, "Id"));}
        | Expr4												                {$$ = $1;}
    ;

Expr3: MethodInvocation                                                     {$$ = $1;}
    | ParseArgs                                                             {$$ = $1;}
    ;

Expr4: INTLIT                                                               {$$ = create_node(node_terminals, $1, "DecLit");}
    | REALLIT                                                               {$$ = create_node(node_terminals, $1, "RealLit");}
    | BOOLLIT                                                               {$$ = create_node(node_terminals, $1, "BoolLit");}
    ;

%%