%{
/*
Miguel Filipe de Andrade Sergio 2020225643
Filipe David Amado Mendes 2020218797
*/
%}

ID                                  ([a-z]|[A-Z]|"_"|"$")+([a-z]|[A-Z]|"_"|"$"|[0-9])*
INTLIT		                        0|[1-9]+("_"*[0-9]|[0-9]*)*
REALLIT                             (((("_"*)?[0-9]+)+"."?(("_"*)?[0-9]+)*)|((("_"*)?[0-9]+)*"."?(("_"*)?[0-9]+)+))[eE][+-]?(("_"*)?[0-9]+)+|(("_"*)?[0-9]+)*"."(("_"*)?[0-9]+)+|(("_"*)?[0-9]+)+"."(("_"*)?[0-9]+)*
CHAR                                [^\r\n\"\\]
ESCAPE                              \\t|\\n|\\f|\\r|\\\"|\\\\
SPACE                               \t|" "
NEWLINE                             \n|\r|(\r\n)	
RESERVED                            "--"|"++"|"Integer"|"System"|"null"|"abstract"|"assert"|"break"|"byte"|"case"|"catch"|"char"|"const"|"continue"|"default"|"do"|"enum"|"extends"|"final"|"finally"|"float"|"for"|"goto"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"package"|"private"|"protected"|"short"|"strictfp"|"super"|"switch"|"synchronized"|"this"|"throw"|"throws"|"transient"|"try"|"volatile"


%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
	#include <string.h>
	#include <stdarg.h>
    #include "functions.h"
	#include "y.tab.h"

    int line = 1, column = 1;
    int column_aux = 1;
    int line_aux = 1;
    char * buffer;
    bool buffer_flag = true; 
	int flag = 0;
	extern int flag_error;
%}


%X SINGLECOMM MULTPLECOMM SLIT
%%

"//"                                {BEGIN SINGLECOMM;}
<SINGLECOMM>{NEWLINE}               {line++; column = 1; BEGIN 0;}
<SINGLECOMM>.                       {column += yyleng;}

"/*"                                {line_aux =  line; column_aux = column; column += yyleng; BEGIN MULTPLECOMM;}  
<MULTPLECOMM><<EOF>>                {printf("Line %d, col %d: unterminated comment\n", line_aux, column_aux); exit(0);}
<MULTPLECOMM>"*/"                   {column += yyleng; line_aux = 1; column_aux = 1; BEGIN 0;}
<MULTPLECOMM>{NEWLINE}              {line++; column = 1;}
<MULTPLECOMM>.                      {column += yyleng;}

\"                                {buffer=yytext; line_aux =  line; column_aux = column; column += yyleng; buffer_flag = true;  BEGIN STRLIT;}
<SLIT>{NEWLINE}                   {column=1; printf("Line %d, col %d: unterminated string literal\n",  line, column_aux); line++; column = 1;  BEGIN 0;}
<SLIT>({CHAR}|{ESCAPE})*          {column += yyleng;}
<SLIT>\\{NEWLINE}                 {printf("Line %d, col %d: invalid escape sequence (\\)\nLine %d, col %d: unterminated string literal\n", line, column, line, column_aux); column = 1; line++; buffer_flag = false; BEGIN 0;}
<SLIT>\\                          {printf("Line %d, col %d: invalid escape sequence (\\)\n", line, column); column += yyleng; buffer_flag = false; }
<SLIT>\\.                         {printf("Line %d, col %d: invalid escape sequence (%s)\n",  line, column, yytext); column += yyleng; buffer_flag = false; }
<SLIT>\"                          {column += yyleng; if (buffer_flag && flag) {printf("STRLIT(%s)\n", buffer); buffer_flag = true; } BEGIN 0;
										if(flag != 1 && flag_error == 0) {
											yylval.id = strdup(buffer);
											yytext = buffer;
											return STRLIT;
										}
									}
<SLIT><<EOF>>                     {printf("Line %d, col %d: unterminated string literal\n",  line, column_aux); exit(0);}

"false"                             {if (flag) printf("BOOLLIT(false)\n"); column += yyleng; 
										if(flag != 1){
											yylval.id = strdup(yytext);
											return BOOLLIT;
										} 
									}
"true"                              {if (flag) printf("BOOLLIT(true)\n"); column += yyleng;
										if(flag != 1){
											yylval.id = strdup(yytext);
											return BOOLLIT;
										} 
									} 
"&&"       	                        {if (flag) printf("AND\n"); column += yyleng; if(flag != 1) return AND; }
"="         	                    {if (flag) printf("ASSIGN\n"); column += yyleng; if(flag != 1) return ASSIGN;}
"*"         	                    {if (flag) printf("STAR\n"); column += yyleng; if(flag != 1) return STAR; }
","         	                    {if (flag) printf("COMMA\n"); column += yyleng; if(flag != 1) return COMMA; }
"/"         	                    {if (flag) printf("DIV\n"); column += yyleng; if(flag != 1) return DIV; }
"=="        	                    {if (flag) printf("EQ\n"); column += yyleng; if(flag != 1) return EQ; }
">="      	                        {if (flag) printf("GE\n"); column += yyleng; if(flag != 1) return GE; }
">"         	                    {if (flag) printf("GT\n"); column += yyleng; if(flag != 1) return GT; }
"{"         	                    {if (flag) printf("LBRACE\n"); column += yyleng; if(flag != 1) return LBRACE; }
"<="        	                    {if (flag) printf("LE\n"); column += yyleng; if(flag != 1) return LE; }
"("        	                        {if (flag) printf("LPAR\n"); column += yyleng; if(flag != 1) return LPAR; }
"["         	                    {if (flag) printf("LSQ\n"); column += yyleng; if(flag != 1) return LSQ; }
"<"         	                    {if (flag) printf("LT\n"); column += yyleng; if(flag != 1) return LT; }
"-"         	                    {if (flag) printf("MINUS\n"); column += yyleng; if(flag != 1) return MINUS; }
"%"         	                    {if (flag) printf("MOD\n"); column += yyleng; if(flag != 1) return MOD; }
"!="        	                    {if (flag) printf("NE\n"); column += yyleng; if(flag != 1) return NE; }
"!"         	                    {if (flag) printf("NOT\n"); column += yyleng; if(flag != 1) return NOT; }
"||"       	                        {if (flag) printf("OR\n"); column += yyleng; if(flag != 1) return OR; }
"+"         	                    {if (flag) printf("PLUS\n"); column += yyleng; if(flag != 1) return PLUS; }
"}"         	                    {if (flag) printf("RBRACE\n"); column += yyleng; if(flag != 1) return RBRACE; }
")"         	                    {if (flag) printf("RPAR\n"); column += yyleng; if(flag != 1) return RPAR; }
"]"         	                    {if (flag) printf("RSQ\n"); column += yyleng; if(flag != 1) return RSQ; }
";"         	                    {if (flag) printf("SEMICOLON\n"); column += yyleng; if(flag != 1) return SEMICOLON; }
"->"                                {if (flag) printf("ARROW\n"); column += yyleng; if(flag != 1) return ARROW; }
"<<"                                {if (flag) printf("LSHIFT\n"); column += yyleng; if(flag != 1) return LSHIFT; }
">>"                                {if (flag) printf("RSHIFT\n"); column += yyleng; if(flag != 1) return RSHIFT; }
"^"                                 {if (flag) printf("XOR\n"); column += yyleng; if(flag != 1) return XOR; }
"boolean"                           {if (flag) printf("BOOL\n"); column += yyleng; if(flag != 1) return BOOL; }
"class"                             {if (flag) printf("CLASS\n"); column += yyleng; if(flag != 1) return CLASS; }
".length"                           {if (flag) printf("DOTLENGTH\n"); column += yyleng; if(flag != 1) return DOTLENGTH; }
"double"                            {if (flag) printf("DOUBLE\n"); column += yyleng; if(flag != 1) return DOUBLE; }
"else"                              {if (flag) printf("ELSE\n"); column += yyleng; if(flag != 1) return ELSE; }
"if"                                {if (flag) printf("IF\n"); column += yyleng; if(flag != 1) return IF; }
"int"                               {if (flag) printf("INT\n"); column += yyleng; if(flag != 1) return INT; }
"System.out.print"                  {if (flag) printf("PRINT\n"); column += yyleng; if(flag != 1) return PRINT; }
"Integer.parseInt"                  {if (flag) printf("PARSEINT\n"); column += yyleng; if(flag != 1) return PARSEINT; }
"public"                            {if (flag) printf("PUBLIC\n"); column += yyleng; if(flag != 1) return PUBLIC; }
"return"                            {if (flag) printf("RETURN\n"); column += yyleng; if(flag != 1) return RETURN; }
"static"                            {if (flag) printf("STATIC\n"); column += yyleng; if(flag != 1) return STATIC; }
"String"                            {if (flag) printf("STRING\n"); column += yyleng; if(flag != 1) return STRING; }
"void"                              {if (flag) printf("VOID\n"); column += yyleng; if(flag != 1) return VOID; }
"while"                             {if (flag) printf("WHILE\n"); column += yyleng; if(flag != 1) return WHILE; }

{RESERVED}                          {if (flag) printf("RESERVED(%s)\n", yytext); column += yyleng;}

{SPACE}                             {column += yyleng;}
"\f"                                {column += yyleng;}
{NEWLINE}                           {line++; column = 1;}

{ID}                                {if (flag) printf("ID(%s)\n", yytext); column += yyleng; }
{INTLIT}                            {if (flag) printf("INTLIT(%s)\n", yytext); column += yyleng;
										if(flag != 1) {
											yylval.id = strdup(yytext);
											return INTLIT;
										} 
									}
{REALLIT}                           {if (flag) printf("REALLIT(%s)\n", yytext); column += yyleng;
										if(flag != 1) {
											yylval.id = strdup(yytext);
											return REALLIT;
										}
									}
.                                   {printf("Line %d, col %d: illegal character (%s)\n", line, column, yytext); column += yyleng; }
<<EOF>>                             {column = 1; exit(0);}

%%


int yywrap() {
	return 1;
}

void yyerror(const char *s) { 
     printf ("Line %d, col %d: %s: %s\n", line, (int)(column-strlen(yytext)), s, yytext);
}


int main(int argc, char *argv[]) {
	if (argc > 1) {
		if (strcmp(argv[1],"-l") == 0) {
			flag = 1;
		}
		else if (strcmp(argv[1],"-t") == 0) {
			flag = 2;
			yyparse();
		}
		else if (strcmp(argv[1], "-e1") == 0) {
			flag = 0;
			while (yylex() != 0) {
				;
			}
		}
		else if (strcmp(argv[1], "-e2") == 0) {
			flag = 0;
			flag_error = 1;
			yyparse();
			yylex();
		}
	}
}
