%X JUC

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






%{
    #include <stdio.h>
    #include <stdlib.h>
%}

%%
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
%%
int main()
{
yylex(); return 0;
}
int yywrap() {
return 1;
}
