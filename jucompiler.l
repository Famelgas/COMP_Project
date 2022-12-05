%{
/*
Miguel Filipe de Andrade Sergio 2020225643
Filipe David Amado Mendes 2020218797
*/
%}

%{
    #include "functions.h"
	#include "y.tab.h"

	int flag = 0;
    int line = 1, col = 1;
    int column_aux = 1, line_aux = 1;
    char *buffer;
    int buffer_flag = 0; 
	extern int flag_error;
	extern Node* root;

	int errors;
	sym_table *table, *table2;
%}


ID                                  	([a-z]|[A-Z]|"_"|"$")+([a-z]|[A-Z]|"_"|"$"|[0-9])*
INTLIT		                        	 0|[1-9]+("_"*[0-9]|[0-9]*)*
REALLIT                             	[0-9]+("_"*[0-9]|[0-9])*[eE][+-]*[0-9]+("_"*[0-9]|[0-9])*|([0-9]+("_"*[0-9]|[0-9])*"."([0-9]*("_"*[0-9]|[0-9])*)*)|([0-9]*("_"*[0-9]|[0-9])*"."([0-9]+("_"*[0-9]|[0-9])*)*)[eE][+-]*[0-9]+("_"*[0-9]|[0-9])*|([0-9]+("_"*[0-9]|[0-9])*"."[0-9]*("_"*[0-9]|[0-9])*)|([0-9]*("_"*[0-9]|[0-9])*"."[0-9]+("_"*[0-9]|[0-9])*)
CHAR                                	[^\r\n\"\\]
ESCAPE                              	\\t|\\n|\\f|\\r|\\\"|\\\\
RESERVED                            	"--"|"++"|"Integer"|"System"|"null"|"abstract"|"assert"|"break"|"byte"|"case"|"catch"|"char"|"const"|"continue"|"default"|"do"|"enum"|"extends"|"final"|"finally"|"float"|"for"|"goto"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"package"|"private"|"protected"|"short"|"strictfp"|"super"|"switch"|"synchronized"|"this"|"throw"|"throws"|"transient"|"try"|"volatile"|"various"

%X              						STLIT SINGLECOMM MULTPLECOMM               

%%

"//"                                	{BEGIN SINGLECOMM; col+=yyleng;}
<SINGLECOMM>(\r\n)|\n|\r              	{line++; col = 1; BEGIN 0;}
<SINGLECOMM>.                       	{col += yyleng;}

"/*"                                	{BEGIN MULTPLECOMM; line_aux =  line; column_aux = col; col += yyleng;}  
<MULTPLECOMM>"*/"                   	{BEGIN 0; col += yyleng;}
<MULTPLECOMM>(\r\n)|\n|\r             	{line++; col = 1;}
<MULTPLECOMM>.                      	{col += yyleng;}
<MULTPLECOMM><<EOF>>                	{BEGIN 0; printf("Line %d, col %d: unterminated comment\n", line_aux, column_aux);}

\"                                  	{BEGIN STLIT; buffer=yytext; line_aux =  line; column_aux = col; col += yyleng; buffer_flag = 0;}
<STLIT>({CHAR}|{ESCAPE})*          		{col += yyleng;}
<STLIT>\\(.?)                       	{printf("Line %d, col %d: invalid escape sequence (%s)\n", line, col, yytext); col += yyleng; buffer_flag = 1;}
<STLIT>(\r\n)|\n|\r                   	{BEGIN 0; printf("Line %d, col %d: unterminated string literal\n",  line_aux, column_aux); line++; col = 1;}
<STLIT>\"                           	{if (buffer_flag == 0 && flag == 0) printf("STRLIT(%s)\n", buffer); col += yyleng; BEGIN 0; 										
											if(flag == 1 && buffer_flag == 0) {
												yylval.token = create_token(buffer, line, col);
												return STRLIT;
											}
										}
<STLIT><<EOF>>                     		{BEGIN 0; buffer = yytext; printf("Line %d, col %d: unterminated string literal\n",  line_aux, column_aux); line++; col = 1;}




"true"              					{if(flag == 0)printf("BOOLLIT(true)\n"); col+=yyleng;
                                        	if(flag == 1) {
												col+=yyleng;
												yylval.token = create_token(yytext, line, col-strlen(yytext));
												return BOOLLIT;
											}
										}
"false"             					{if(flag == 0)printf("BOOLLIT(false)\n"); col+=yyleng;
                                        	if(flag == 1) {
												col+=yyleng;
												yylval.token = create_token(yytext, line, col-strlen(yytext));
												return BOOLLIT;
											}
										}
"&&"                					{if(flag == 0)printf("AND\n"); col+=yyleng;if(flag == 1){col+=yyleng; yylval.token = create_token(NULL, line, col-strlen(yytext));return AND;}}
"="                 					{if(flag == 0)printf("ASSIGN\n"); col+=yyleng; if(flag == 1){col+=yyleng; yylval.token = create_token(yytext, line, col-strlen(yytext));return ASSIGN;}}
"*"                 					{if(flag == 0)printf("STAR\n"); col+=yyleng; if(flag == 1){col+=yyleng; yylval.token = create_token(NULL, line, col-strlen(yytext));return STAR;}}
","                 					{if(flag == 0)printf("COMMA\n"); col+=yyleng; if(flag == 1){col+=yyleng; yylval.token = create_token(NULL, line, col-strlen(yytext));return COMMA;}}
"/"                 					{if(flag == 0)printf("DIV\n"); col+=yyleng; if(flag == 1){col+=yyleng; yylval.token = create_token(NULL, line, col-strlen(yytext));return DIV;}}
"=="                					{if(flag == 0)printf("EQ\n"); col+=yyleng; if(flag == 1){col+=yyleng; yylval.token = create_token(NULL, line, col-strlen(yytext));return EQ;}}
">="                					{if(flag == 0)printf("GE\n"); col+=yyleng; if(flag == 1){col+=yyleng; yylval.token = create_token(NULL, line, col-strlen(yytext));return GE;}}
">"                						{if(flag == 0)printf("GT\n"); col+=yyleng; if(flag == 1){col+=yyleng; yylval.token = create_token(NULL, line, col-strlen(yytext));return GT;}}
"{"                						{if(flag == 0)printf("LBRACE\n"); col+=yyleng; if(flag == 1){col+=yyleng; return LBRACE;}}
"<="                					{if(flag == 0)printf("LE\n"); col+=yyleng; if(flag == 1){col+=yyleng; yylval.token = create_token(NULL, line, col-strlen(yytext));return LE;}}
"("                						{if(flag == 0)printf("LPAR\n");col+=yyleng; if(flag == 1){col+=yyleng; return LPAR;}}
"["                						{if(flag == 0)printf("LSQ\n");col+=yyleng; if(flag == 1){col+=yyleng; return LSQ;}}
"<"                						{if(flag == 0)printf("LT\n");col+=yyleng; if(flag == 1){col+=yyleng; yylval.token = create_token(NULL, line, col-strlen(yytext));return LT;}}
"-"                						{if(flag == 0)printf("MINUS\n");col+=yyleng; if(flag == 1){col+=yyleng; yylval.token = create_token(yytext, line, col-strlen(yytext));return MINUS;}}
"%"                						{if(flag == 0)printf("MOD\n"); col+=yyleng; if(flag == 1){col+=yyleng; yylval.token = create_token(NULL, line, col-strlen(yytext));return MOD;}}
"!="                					{if(flag == 0)printf("NE\n"); col+=yyleng; if(flag == 1){col+=yyleng; yylval.token = create_token(NULL, line, col-strlen(yytext));return NE;}}
"!"                						{if(flag == 0)printf("NOT\n");col+=yyleng; if(flag == 1){col+=yyleng; yylval.token = create_token(NULL, line, col-strlen(yytext));return NOT;}}
"||"                					{if(flag == 0)printf("OR\n"); col+=yyleng; if(flag == 1){col+=yyleng; yylval.token = create_token(NULL, line, col-strlen(yytext));return OR;}}
"+"                						{if(flag == 0)printf("PLUS\n");col+=yyleng; if(flag == 1){col+=yyleng; yylval.token = create_token(yytext, line, col-strlen(yytext));return PLUS;}}
"}"                						{if(flag == 0)printf("RBRACE\n");col+=yyleng; if(flag == 1){col+=yyleng; return RBRACE;}}
")"                						{if(flag == 0)printf("RPAR\n"); col+=yyleng; if(flag == 1){col+=yyleng; return RPAR;}}
"]"                						{if(flag == 0)printf("RSQ\n"); col+=yyleng; if(flag == 1){col+=yyleng; return RSQ;}}
";"                						{if(flag == 0)printf("SEMICOLON\n"); col+=yyleng; if(flag == 1){col+=yyleng; return SEMICOLON;}}
"->"                					{if(flag == 0)printf("ARROW\n"); col+=yyleng; if(flag == 1){col+=yyleng; yylval.token = create_token(NULL, line, col-strlen(yytext)); return ARROW;}}
"<<"                					{if(flag == 0)printf("LSHIFT\n"); col+=yyleng; if(flag == 1){col+=yyleng; yylval.token = create_token(NULL, line, col-strlen(yytext)); return LSHIFT;}}
">>"                					{if(flag == 0)printf("RSHIFT\n"); col+=yyleng; if(flag == 1){col+=yyleng; yylval.token = create_token(NULL, line, col-strlen(yytext)); return RSHIFT;}}
"^"                						{if(flag == 0)printf("XOR\n"); col+=yyleng; if(flag == 1){col+=yyleng; yylval.token = create_token(NULL, line, col-strlen(yytext)); return XOR;}}
"boolean"           					{if(flag == 0)printf("BOOL\n"); col+=yyleng;if(flag == 1){col+=yyleng; return BOOL;}}
"class"             					{if(flag == 0)printf("CLASS\n"); col+=yyleng;if(flag == 1){col+=yyleng; return CLASS;}}
".length"           					{if(flag == 0)printf("DOTLENGTH\n"); col+=yyleng;if(flag == 1){col+=yyleng; yylval.token = create_token(NULL, line, col-strlen(yytext)); return DOTLENGTH;}}
"double"            					{if(flag == 0)printf("DOUBLE\n"); col+=yyleng;if(flag == 1){col+=yyleng; return DOUBLE;}}
"else"              					{if(flag == 0)printf("ELSE\n"); col+=yyleng; if(flag == 1){col+=yyleng; return ELSE;}}
"if"                					{if(flag == 0)printf("IF\n"); col+=yyleng;if(flag == 1){col+=yyleng; yylval.token = create_token(NULL, line, col-strlen(yytext)); return IF;}}
"int"               					{if(flag == 0)printf("INT\n"); col+=yyleng;if(flag == 1){col+=yyleng; return INT;}}
"System.out.print"  					{if(flag == 0)printf("PRINT\n"); col+=yyleng;if(flag == 1){col+=yyleng; yylval.token = create_token(NULL, line, col-strlen(yytext)); return PRINT;}}
"Integer.parseInt"  					{if(flag == 0)printf("PARSEINT\n"); col+=yyleng;if(flag == 1){col+=yyleng; yylval.token = create_token(yytext, line, col-strlen(yytext)); return PARSEINT;}}
"return"            					{if(flag == 0)printf("RETURN\n"); col+=yyleng;if(flag == 1){col+=yyleng; yylval.token = create_token(NULL, line, col-strlen(yytext)); return RETURN;}}
"static"            					{if(flag == 0)printf("STATIC\n"); col+=yyleng;if(flag == 1){col+=yyleng; return STATIC;}}
"String"            					{if(flag == 0)printf("STRING\n"); col+=yyleng;if(flag == 1){col+=yyleng; return STRING;}}
"void"              					{if(flag == 0)printf("VOID\n"); col+=yyleng;if(flag == 1){col+=yyleng;  yylval.token = create_token(yytext, line, col-strlen(yytext)); return VOID;}}
"public"            					{if(flag == 0)printf("PUBLIC\n"); col+=yyleng;if(flag == 1){col+=yyleng; return PUBLIC;}}
"while"             					{if(flag == 0)printf("WHILE\n"); col+=yyleng;if(flag == 1){col+=yyleng; yylval.token = create_token(yytext, line, col-strlen(yytext)); return WHILE;}}

\t|" "|"\f"              				{col+=yyleng;}

(\r\n)|\n|\r          					{line+=1; col=1;}

{RESERVED}          					{if(flag == 0)printf("RESERVED(%s)\n",yytext); col+=yyleng;if(flag == 1){col+=yyleng; yylval.token = create_token(yytext, line, col-strlen(yytext)); return RESERVED;}}

{ID}                					{if(flag == 0)printf("ID(%s)\n",yytext); col+=yyleng;
                                        	if(flag == 1) {
												col+=yyleng;
												yylval.token = create_token(yytext, line, col-strlen(yytext));
												return ID;
											}
										}

{INTLIT}            					{if(flag == 0)printf("INTLIT(%s)\n",yytext); col+=yyleng;
                                    		if(flag == 1) {
												col+=yyleng;
												yylval.token = create_token(yytext, line, col-strlen(yytext));
											 	return INTLIT;
											}
										}

{REALLIT}           					{if(flag == 0)printf("REALLIT(%s)\n",yytext); col+=yyleng;
                                            if(flag == 1) {
												col+=yyleng;
												yylval.token = create_token(yytext, line, col-strlen(yytext));
												return REALLIT;
											}
										}

<<EOF>>									{col+=1; return 0;}

.                   					{printf("Line %d, col %d: illegal character (%s)\n", line,col,yytext); col+=yyleng;}

%%


int yywrap() {
	return 1;
}

void yyerror(const char *s) { 
     printf ("Line %d, col %d: %s: %s\n", line, (int)(col-strlen(yytext)), s, yytext);
}

int main(int argc, char *argv[]) {
	if (argc > 1) {
		if (strcmp(argv[1],"-l") == 0) {
			flag = 0;
			yylex();
		}
		else if (strcmp(argv[1],"-t") == 0) {
			flag = 1;
			yyparse();
			if (flag_error == 0) {
				print_tree(root, 0);
			}
        }
		else if (strcmp(argv[1], "-s") == 0) {
			table = NULL;
			table2 = NULL;
			flag = 1;
			yyparse();
			if (flag_error == 0) {	
				create_table_end(root);
				print_table(table, table2);
				print_tree_anotated(root, 0);
				clear_table(table, table2);
			}
		}
	}
}