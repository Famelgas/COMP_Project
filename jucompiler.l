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
VOID                            void
WHILE                           while
STRING                          String
STATIC                          static
RETURN                          return
PUBLIC                          public
INT                             int
IF                              if
ELSE                            else
CLASS                           class
RESERVED                        length|main|new|System|this|Integer|null|--|++|for

%{
    #include <stdio.h>
    #include <stdlib.h>
%}

%%

%X SINGLECOMM

<id> <id> { printf("ID(%s)", yytext); }
<BOOLIT> { printf("BOOLLIT(%s)", yytext); }
<STRLIT> { printf("STRLIT(%s)", yytext); }
<ASSIGN> { printf("ASSIGN"); }
<PLUS> { printf("PLUS"); }


/* ;
*/ ; 
// ;


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
