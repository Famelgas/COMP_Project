%{
/*
Miguel Filipe de Andrade Sergio 2020225643
Filipe David Amado Mendes 2020218797
*/
%}

ID                                  ([a-z]|[A-Z]|"_"|"$")+([a-z]|[A-Z]|"_"|"$"|[0-9])*
INTLIT		                        0|[1-9]+("_"*[0-9]|[0-9]*)*
NEWLINE                             \n|\r|(\r\n)	
RESERVED                            "--"|"++"|"Integer"|"System"|"null"|"abstract"|"assert"|"break"|"byte"|"case"|"catch"|"char"|"const"|"continue"|"default"|"do"|"enum"|"extends"|"final"|"finally"|"float"|"for"|"goto"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"package"|"private"|"protected"|"short"|"strictfp"|"super"|"switch"|"synchronized"|"this"|"throw"|"throws"|"transient"|"try"|"volatile"|"various"
STRLIT				                ([^\n\r\\"]|\\n|\\f|\\r|\\\\|\\\"|\\t)*
REALLIT                             [0-9]+("_"*[0-9]|[0-9])*[eE][+-]*[0-9]+("_"*[0-9]|[0-9])*|([0-9]+("_"*[0-9]|[0-9])*"."([0-9]*("_"*[0-9]|[0-9])*)*)|([0-9]*("_"*[0-9]|[0-9])*"."([0-9]+("_"*[0-9]|[0-9])*)*)[eE][+-]*[0-9]+("_"*[0-9]|[0-9])*|([0-9]+("_"*[0-9]|[0-9])*"."[0-9]*("_"*[0-9]|[0-9])*)|([0-9]*("_"*[0-9]|[0-9])*"."[0-9]+("_"*[0-9]|[0-9])*)
CHAR                                [^\r\n\"\\]
ESCAPE                              \\t|\\n|\\f|\\r|\\\"|\\\\
BOOLS				                "true"|"false"

%{
    #include "functions.h"
	#include "y.tab.h"

    int line = 1, column = 1;
    int column_aux = 1, line_aux = 1;
    char buffer[256];
    int buffer_flag = 0; 
	int flag = 0;
	extern int flag_error;
%}


%X SINGLECOMM MULTPLECOMM SLIT
%%

"//"                                {BEGIN SINGLECOMM; column+=yyleng;}
<SINGLECOMM>{NEWLINE}               {line++; column = 1; BEGIN 0;}
<SINGLECOMM>.                       {column += yyleng;}

"/*"                                {line_aux =  line; column_aux = column; column += yyleng; BEGIN MULTPLECOMM;}  
<MULTPLECOMM>"*/"                   {column += yyleng; BEGIN 0;}
<MULTPLECOMM>{NEWLINE}              {line++; column = 1;}
<MULTPLECOMM>.                      {column += yyleng;}
<MULTPLECOMM><<EOF>>                {printf("Line %d, col %d: unterminated comment\n", line_aux, column_aux);}


\"									{BEGIN SLIT; buffer[0]=0; strcat(buffer, yytext); line_aux = line; column_aux = column; column+=yyleng; buffer_flag = 0;}
<SLIT>{STRLIT}						{column+=yyleng; strcat(buffer, yytext);}
<SLIT>\\(.?)						{strcat(buffer, yytext);printf("Line %d, col %d: invalid escape sequence (%s)\n",line,column,yytext); column += yyleng; buffer_flag = 1;}
<SLIT>\n|\r|(\r\n)					{BEGIN 0; buffer[0] = 0; printf("Line %d, col %d: unterminated string literal\n",line_aux,column_aux); line++; column = 1;}
<SLIT>\"							{BEGIN 0; strcat(buffer, yytext); if(flag == 1 && buffer_flag==0)printf("STRLIT(%s)\n",buffer);column+=yyleng;
										if(flag != 1 && buffer_flag == 0) {
											yylval.id = strdup(buffer);
											yytext = buffer;
											return STRLIT;
										}
									}
<SLIT><<EOF>>						{BEGIN 0; buffer[0] = 0; printf("Line %d, col %d: unterminated string literal\n",line_aux,column_aux); line++; column = 1;}

"&&"       	                        {if (flag == 1) printf("AND\n"); column += yyleng; if(flag != 1) return AND; }
"="         	                    {if (flag == 1) printf("ASSIGN\n"); column += yyleng; if(flag != 1) return ASSIGN;}
"*"         	                    {if (flag == 1) printf("STAR\n"); column += yyleng; if(flag != 1) return STAR; }
","         	                    {if (flag == 1) printf("COMMA\n"); column += yyleng; if(flag != 1) return COMMA; }
"/"         	                    {if (flag == 1) printf("DIV\n"); column += yyleng; if(flag != 1) return DIV; }
"=="        	                    {if (flag == 1) printf("EQ\n"); column += yyleng; if(flag != 1) return EQ; }
">="      	                        {if (flag == 1) printf("GE\n"); column += yyleng; if(flag != 1) return GE; }
">"         	                    {if (flag == 1) printf("GT\n"); column += yyleng; if(flag != 1) return GT; }
"{"         	                    {if (flag == 1) printf("LBRACE\n"); column += yyleng; if(flag != 1) return LBRACE; }
"<="        	                    {if (flag == 1) printf("LE\n"); column += yyleng; if(flag != 1) return LE; }
"("        	                        {if (flag == 1) printf("LPAR\n"); column += yyleng; if(flag != 1) return LPAR; }
"["         	                    {if (flag == 1) printf("LSQ\n"); column += yyleng; if(flag != 1) return LSQ; }
"<"         	                    {if (flag == 1) printf("LT\n"); column += yyleng; if(flag != 1) return LT; }
"-"         	                    {if (flag == 1) printf("MINUS\n"); column += yyleng; if(flag != 1) return MINUS; }
"%"         	                    {if (flag == 1) printf("MOD\n"); column += yyleng; if(flag != 1) return MOD; }
"!="        	                    {if (flag == 1) printf("NE\n"); column += yyleng; if(flag != 1) return NE; }
"!"         	                    {if (flag == 1) printf("NOT\n"); column += yyleng; if(flag != 1) return NOT; }
"||"       	                        {if (flag == 1) printf("OR\n"); column += yyleng; if(flag != 1) return OR; }
"+"         	                    {if (flag == 1) printf("PLUS\n"); column += yyleng; if(flag != 1) return PLUS; }
"}"         	                    {if (flag == 1) printf("RBRACE\n"); column += yyleng; if(flag != 1) return RBRACE; }
")"         	                    {if (flag == 1) printf("RPAR\n"); column += yyleng; if(flag != 1) return RPAR; }
"]"         	                    {if (flag == 1) printf("RSQ\n"); column += yyleng; if(flag != 1) return RSQ; }
";"         	                    {if (flag == 1) printf("SEMICOLON\n"); column += yyleng; if(flag != 1) return SEMICOLON; }
"->"                                {if (flag == 1) printf("ARROW\n"); column += yyleng; if(flag != 1) return ARROW; }
"<<"                                {if (flag == 1) printf("LSHIFT\n"); column += yyleng; if(flag != 1) return LSHIFT; }
">>"                                {if (flag == 1) printf("RSHIFT\n"); column += yyleng; if(flag != 1) return RSHIFT; }
"^"                                 {if (flag == 1) printf("XOR\n"); column += yyleng; if(flag != 1) return XOR; }
"boolean"                           {if (flag == 1) printf("BOOL\n"); column += yyleng; if(flag != 1) return BOOL; }
"class"                             {if (flag == 1) printf("CLASS\n"); column += yyleng; if(flag != 1) return CLASS; }
".length"                           {if (flag == 1) printf("DOTLENGTH\n"); column += yyleng; if(flag != 1) return DOTLENGTH; }
"double"                            {if (flag == 1) printf("DOUBLE\n"); column += yyleng; if(flag != 1) return DOUBLE; }
"else"                              {if (flag == 1) printf("ELSE\n"); column += yyleng; if(flag != 1) return ELSE; }
"if"                                {if (flag == 1) printf("IF\n"); column += yyleng; if(flag != 1) return IF; }
"int"                               {if (flag == 1) printf("INT\n"); column += yyleng; if(flag != 1) return INT; }
"System.out.print"                  {if (flag == 1) printf("PRINT\n"); column += yyleng; if(flag != 1) return PRINT; }
"Integer.parseInt"                  {if (flag == 1) printf("PARSEINT\n"); column += yyleng; if(flag != 1) return PARSEINT; }
"public"                            {if (flag == 1) printf("PUBLIC\n"); column += yyleng; if(flag != 1) return PUBLIC; }
"return"                            {if (flag == 1) printf("RETURN\n"); column += yyleng; if(flag != 1) return RETURN; }
"static"                            {if (flag == 1) printf("STATIC\n"); column += yyleng; if(flag != 1) return STATIC; }
"String"                            {if (flag == 1) printf("STRING\n"); column += yyleng; if(flag != 1) return STRING; }
"void"                              {if (flag == 1) printf("VOID\n"); column += yyleng; if(flag != 1) return VOID; }
"while"                             {if (flag == 1) printf("WHILE\n"); column += yyleng; if(flag != 1) return WHILE; }


{BOOLS}								{if(flag == 1)printf("BOOLLIT(%s)\n",yytext);column+=yyleng;
										if(flag != 1) {
											yylval.id = strdup(yytext);
											return BOOLLIT;
									    }
                                    }
{RESERVED}                          {if(flag == 1)printf("RESERVED(%s)\n",yytext);column+=yyleng; if(flag != 1)return RESERVED;}

"\t" 								{column+=yyleng;}
" "									{column+=yyleng;}
"\f"                                {column += yyleng; }
{NEWLINE}                           {line++; column = 1;}

{ID}                                {if(flag == 1)printf("ID(%s)\n",yytext);column+=yyleng;
										if(flag != 1) {
											yylval.id = strdup(yytext);
											return ID;
										}
          							}
{INTLIT}                            {if (flag == 1) printf("INTLIT(%s)\n", yytext); column += yyleng;
										if(flag != 1) {
											yylval.id = strdup(yytext);
											return INTLIT;
										} 
									}
{REALLIT}                           {if (flag == 1) printf("REALLIT(%s)\n", yytext); column += yyleng;
										if(flag != 1) {
											yylval.id = strdup(yytext);
											return REALLIT;
										}
									}
.                                   {printf("Line %d, col %d: illegal character (%s)\n", line, column, yytext); column += yyleng; }

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
			yyparse();
		}
		else if (strcmp(argv[1],"-t") == 0) {
			// análise lexical, análise sintatica e PRINT TREE
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