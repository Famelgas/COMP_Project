%X JUC

<<<<<<< HEAD
id                              [a-zA-Z_][a-zA-Z_0-9]*
BOOLLIT                         true|false
STRLIT                          "([^"\\]|\\.)*"
ASSIGN                          =
PLUS                            +
MINUS                           -
COMMA                           ,
SEMICOLON                       ;
LPAR                            (
RPAR                            )
LBRACE                          {
RBRACE                          }
LSQ                             [
RSQ                             ]
DOT                             .
COLON                           :
STAR                            *
DIV                             /
MOD                             %
AND                             &&
OR                              ||
NOT                             !
LT                              <
LE                              <=
GT                              >
GE                              >=
EQ                              ==
NE                              !=
ARROW                           ->
LSHIFT                          <<
RSHIFT                          >>
XOR                             ^
MOD                             %
BOOL                            boolean
CLASS                           class
DOTLENGTH                       .length
DOUBLE                          double
PRINT                           System.out.print
PARSEINT                        Integer.parseInt
IF                              if
ELSE                            else
WHILE                           while
BREAK                           break
CONTINUE                        continue
RETURN                          return
INT                             int
STRING                          string
VOID                            void
CLASS                           class
NULL                            null
NEW                             new
THIS                            this
EXTENDS                         extends
IMPLEMENTS                      implements
PUBLIC                          public
PRIVATE                         private
PROTECTED                       protected
STATIC                          static
FINAL                           final
ABSTRACT                        abstract
NATIVE                          native
THROWS                          throws
TRY                             try
CATCH                           catch
FINALLY                         finally
FOR                             for
SWITCH                          switch
CASE                            case
DEFAULT                         default
THROW                           throw
IMPORT                          import





=======
ID                                  [a-zA-Z_][a-zA-Z_0-9]*
INTLIT                              [1-9](("_")?{D})*|0(("_")?{O})*|0[xX](("_")?{H})+
REALLIT                             {{D}(("_")?{D})*}"."{{D}(("_")?{D})*}?{[eE][+-]?{{D}(("_")?{D})*} }?|{{D}(("_")?{D})*}{[eE][+-]?{{D}(("_")?{D})*}}|"."{{D}(("_")?{D})*}{[eE][+-]?{{D}(("_")?{D})*}}? 
BOOLLIT                             (true|false)
STRLIT                              ("([^"\\]|\\.)*")
RESERVED                            (length|main|new|System|this|Integer|null|--|++|for)
>>>>>>> ae616fc7e125a29086a3b237781e57f1cdb64bbb

%{
    #include <stdio.h>
    #include <stdlib.h>
%}

%%
<<<<<<< HEAD
=======

%X JAVADOC

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


{ID}                                {printf("ID(%s)\n", yytext);}
{STRLIT}                            {printf("STRLIT(%s)\n", yytext); }
{RESERVED}                          {printf("RESERVED(%s)\n"), yytext;}
{INTLIT}                            {printf("INTLIT(%s)\n", yytext);}
{BOOLIT}                            {printf("BOOLIT(%s)\n", yytext);}
{REALLIT}                           {printf("REALLIT(%s)\n", yytext);}

/* ;
*/ ; 
// ;

>>>>>>> ae616fc7e125a29086a3b237781e57f1cdb64bbb
"/**" {BEGIN JAVADOC;}
<JAVADOC>"@param".* {printf("\nParametro: %s", &yytext[6]);}
<JAVADOC>"@return".* {printf("\nDevolve: %s", &yytext[7]);}
<JAVADOC>"@see".* ; //ignorar
<JAVADOC>"* "* ;
<JAVADOC><p> {printf("\n");}
<JAVADOC>"*/" {BEGIN 0; printf("\n");} //regressar ao normal
<JAVADOC>\n ;
<JAVADOC>. ECHO;
. ; //caso seja codigo Java
\n ; //nao faz nada
<<<<<<< HEAD
%%
=======

%%

>>>>>>> ae616fc7e125a29086a3b237781e57f1cdb64bbb
int main()
{
yylex(); return 0;
}
int yywrap() {
return 1;
}
