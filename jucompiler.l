ID                                  [a-zA-Z_][a-zA-Z_0-9]*
INTLIT                              [1-9](("_")?{D})*|0(("_")?{O})*|0[xX](("_")?{H})+
REALLIT                             {{D}(("_")?{D})*}"."{{D}(("_")?{D})*}?{[eE][+-]?{{D}(("_")?{D})*} }?|{{D}(("_")?{D})*}{[eE][+-]?{{D}(("_")?{D})*}}|"."{{D}(("_")?{D})*}{[eE][+-]?{{D}(("_")?{D})*}}? 
BOOLLIT                             (true|false)
STRLIT                              ("([^"\\]|\\.)*")
RESERVED                            (length|main|new|System|this|Integer|null|--|++|for)
O                                   [0-7]
H                                   [0-9A-Fa-f]
D                                   [0-9]


%{
    #include <stdio.h>
    #include <stdlib.h>
%}

%X JUC
%%

" "*"//"                            {BEGIN SINGLECOMM;}
" "*"/*"                            {BEGIN DOUBLECOMM;}   

"if"                                {printf("IF\n");}
"else"                              {printf("ELSE\n");}
"var"                               {printf("VAR\n");}
"int"                               {printf("INT\n");}
"boolean"                           {printf("BOOL\n");}
";"                                 {printf("SEMICOLON\n");}
","                                 {printf("COMMA\n");}
"{"                                 {printf("LBRACE\n");}
"("                                 {printf("LPAR\n");}
"["                                 {printf("LSQ\n");}
"}"                                 {printf("RBRACE\n");}
")"                                 {printf("RPAR\n");}
"]"                                 {printf("RSQ\n");}
"="                                 {printf("ASSIGN\n");}
"*"                                 {printf("STAR\n");}
"/"                                 {printf("DIV\n");}
"-"                                 {printf("MINUS\n");}
"+"                                 {printf("PLUS\n");}
"=="                                {printf("EQ\n");}
">="                                {printf("GE\n");}
">"                                 {printf("GT\n");}
"<="                                {printf("LE\n");}
"<"                                 {printf("LT\n");}
"%"                                 {printf("MOD\n");}
"!="                                {printf("NE\n");}
"!"                                 {printf("NOT\n");}
"&&"                                {printf("AND\n");}
"||"                                {printf("OR\n");}
"String"                            {printf("STRING\n");}
"System.out.print"                  {printf("PRINT\n");}
"Integer.parseInt"                  {printf("PARSEINT\n");}
"return"                            {printf("RETURN\n");}
"public"                            {printf("PUBLIC\n");}
"static"                            {printf("STATIC\n");}
"void"                              {printf("VOID\n");}
"while"                             {printf("WHILE\n");}
".length"                           {printf("DOTLENGTH\n");}
"."                                 {printf("DOT\n");}
"class"                             {printf("CLASS\n");}
":"                                 {printf("COLON\n");}
"^"                                 {printf("XOR\n");}
"<<"                                {printf("LSHIFT\n");}
">>"                                {printf("RSHIFT\n");}
"double"                            {printf("DOUBLE\n");}
"void"                              {printf("VOID\n");}

/* ;
*/ ; 
// ;


{BOOLLIT}                           {printf("BOOLLIT(%s)\n", yytext);}
{STRLIT}                            {printf("STRLIT(%s)\n", yytext);}
{INTLIT}                            {printf("INTLIT(%s)\n", yytext);}
{REALLIT}                           {printf("REALLIT(%s)\n", yytext);}
{RESERVED}                          {printf("RESERVED(%s)\n"), yytext;}
{ID}                                {printf("ID(%s)\n", yytext);}

%%

int main()
{
    yylex(); 
    return 0;
}
int yywrap() {
    return 1;
}
