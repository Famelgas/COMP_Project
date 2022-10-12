%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
      
    int line = 1, column = 1;
    bool flag = true;
    int column_aux = 1;
    int line_aux = 0;
    char * buffer;
    bool buffer_flag = true; 

%}


%X JUC STRLIT SINGLECOMM MULTPLECOMM

ID                                  ([a-z]|[A-Z]|"_"|"$")+([a-z]|[A-Z]|"_"|"$"|[0-9])*
INTLIT		                        0|[1-9]+("_"*[0-9]|[0-9]*)*
O                                   [0-7]
H                                   [0-9A-Fa-f]
D                                   [0-9]
CHAR                                [^\r\n\"\\]
REALLIT                             (((("_"*)?[0-9]+)+"."?(("_"*)?[0-9]+)*)|((("_"*)?[0-9]+)*"."?(("_"*)?[0-9]+)+))[eE][+-]?(("_"*)?[0-9]+)+|(("_"*)?[0-9]+)*"."(("_"*)?[0-9]+)+|(("_"*)?[0-9]+)+"."(("_"*)?[0-9]+)*

RESERVED                            "length"|"main"|"new"|"System"|"this"|"Integer"|"null"|"--"|"++"|"for"
ESCAPE                              \\t|\\n|\\f|\\r|\\\"|\\\\
ESPACE                              \t|" "
NEWLINE                             \r\n|\n|\r

%%


\"                                  {buffer=yytext; line_aux =  line; column_aux = column; column += yyleng; buffer_flag = true;  BEGIN STRLIT;}
<STRLIT>{NEWLINE}                   {column=1; printf("Line %d, column %d: unterminated string literal\n",  line, column_aux); line++; column = 1;  BEGIN 0;}
<STRLIT>({CHAR}|{ESCAPE})*          {column += yyleng;}
<STRLIT>\\{NEWLINE}                 {printf("Line %d, column %d: invalid escape sequence (\\)\nLine %d, column %d: unterminated string literal\n", line, column, line, column_aux); column = 1; line++; buffer_flag = false; BEGIN 0;}
<STRLIT>\\                          {printf("Line %d, column %d: invalid escape sequence (\\)\n", line, column); column += yyleng; buffer_flag = false; }

<STRLIT>\\.                         {printf("Line %d, column %d: invalid escape sequence (%s)\n",  line, column, yytext); column += yyleng; buffer_flag = false; }
<STRLIT>\"                          {column += yyleng; if (buffer_flag && flag) {printf("STRLIT(%s)\n", buffer); buffer_flag = true; } BEGIN 0;}
<STRLIT><<EOF>>                     {printf("Line %d, column %d: unterminated string literal\n",  line, column_aux); exit(0);}





" "*"//"                            {BEGIN SINGLECOMM;}
<SINGLECOMM>{NEWLINE}               {line++; column = 1; BEGIN 0;}
<SINGLECOMM>.                       {column += yyleng;}

" "*"/*"                            {line_aux =  line; column_aux = column; column += yyleng; BEGIN MULTPLECOMM;}  
<MULTPLECOMM><<EOF>>                {printf("Line %d, column %d: unterminated comment\n", line_aux, column_aux); exit(0);}
<MULTPLECOMM>"*/"                   {column += yyleng; line_aux = 1; column_aux = 1; BEGIN 0;}
<MULTPLECOMM>{NEWLINE}              {line++; column = 1;}
<MULTPLECOMM>.                      {column += yyleng;}



"false"                             {if (flag) printf("BOOLLIT(false)\n"); column += yyleng; }
"true"                              {if (flag) printf("BOOLLIT(true)\n"); column += yyleng; }
"&&"       	                        {if (flag) printf("AND\n"); column += yyleng; }
"="         	                    {if (flag) printf("ASSIGN\n"); column += yyleng; }
"*"         	                    {if (flag) printf("STAR\n"); column += yyleng; }
","         	                    {if (flag) printf("COMMA\n"); column += yyleng; }
"/"         	                    {if (flag) printf("DIV\n"); column += yyleng; }
"=="        	                    {if (flag) printf("EQ\n"); column += yyleng; }
">="      	                        {if (flag) printf("GE\n"); column += yyleng; }
">"         	                    {if (flag) printf("GT\n"); column += yyleng; }
"{"         	                    {if (flag) printf("LBRACE\n"); column += yyleng; }
"<="        	                    {if (flag) printf("LE\n"); column += yyleng; }
"("        	                        {if (flag) printf("LPAR\n"); column += yyleng; }
"["         	                    {if (flag) printf("LSQ\n"); column += yyleng; }
"<"         	                    {if (flag) printf("LT\n"); column += yyleng; }
"-"         	                    {if (flag) printf("MINUS\n"); column += yyleng; }
"%"         	                    {if (flag) printf("MOD\n"); column += yyleng; }
"!="        	                    {if (flag) printf("NE\n"); column += yyleng; }
"!"         	                    {if (flag) printf("NOT\n"); column += yyleng; }
"||"       	                        {if (flag) printf("OR\n"); column += yyleng; }
"+"         	                    {if (flag) printf("PLUS\n"); column += yyleng; }
"}"         	                    {if (flag) printf("RBRACE\n"); column += yyleng; }
")"         	                    {if (flag) printf("RPAR\n"); column += yyleng; }
"]"         	                    {if (flag) printf("RSQ\n"); column += yyleng; }
";"         	                    {if (flag) printf("SEMIcolumnON\n"); column += yyleng; }
"->"                                {if (flag) printf("ARROW\n"); column += yyleng; }
"<<"                                {if (flag) printf("LSHIFT\n"); column += yyleng; }
">>"                                {if (flag) printf("RSHIFT\n"); column += yyleng; }
"^"                                 {if (flag) printf("XOR\n"); column += yyleng; }
"boolean"                           {if (flag) printf("BOOL\n"); column += yyleng; }
"class"                             {if (flag) printf("CLASS\n"); column += yyleng; }
".length"                           {if (flag) printf("DOTLENGTH\n"); column += yyleng; }
"double"                            {if (flag) printf("DOUBLE\n"); column += yyleng; }
"else"                              {if (flag) printf("ELSE\n"); column += yyleng; }
"if"                                {if (flag) printf("IF\n"); column += yyleng; }
"int"                               {if (flag) printf("INT\n"); column += yyleng; }
"System.out.print"                  {if (flag) printf("PRINT\n"); column += yyleng; }
"Integer.parseInt"                  {if (flag) printf("PARSEINT\n"); column += yyleng; }
"public"                            {if (flag) printf("PUBLIC\n"); column += yyleng; }
"return"                            {if (flag) printf("RETURN\n"); column += yyleng; }
"static"                            {if (flag) printf("STATIC\n"); column += yyleng; }
"String"                            {if (flag) printf("STRING\n"); column += yyleng; }
"void"                              {if (flag) printf("VOID\n"); column += yyleng; }
"while"                             {if (flag) printf("WHILE\n"); column += yyleng; }


{INTLIT}                            {if (flag) printf("INTLIT(%s)\n", yytext); column += yyleng; }
{REALLIT}                           {if (flag) printf("REALLIT(%s)\n", yytext); column += yyleng;}
{RESERVED}                          {if (flag) printf("RESERVED(%s)\n", yytext); column += yyleng;}
{ESPACE}                            {column += yyleng;}
{ID}                                {if (flag) printf("ID(%s)\n", yytext); column += yyleng; }
"\f"                                {column += yyleng;}
.                                   {printf("Line %d, column %d: illegal character (%s)\n", line, column, yytext); column += yyleng; }
<<EOF>>                             {column = 1; exit(0);}





%%

int main(int argc, char **argv) {
    
    for(int i = 1; i < argc; i++){
        if (strcmp(argv[i], "-l") == 0){
            flag = true;
        }
        if (strcmp(argv[i], "-e1") == 0){
            flag = false;
        }
    }
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
