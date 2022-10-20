%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symtab.h"
#define NSYMS 100

symtab tab[NSYMS];

symtab *symlook(char *varname);
int yylex (void);
void yyerror(char* s);
%}


%union {
    node_t *node;
    token_t *value;
}


%token <value> ID LPAR BOOL DOUBLE INT VOID CLASS LBRACE RBRACE PUBLIC STATIC SEMICOLON RPAR STRING LSQ RSQ IF RETURN PRINT PLUS MINUS STAR DIV MOD AND OR XOR LSHIFT RSHIFT EQ GE GT LE LT NE NOT DOTLENGHT INTLIT REALLIT BOOLLIT 
%type <node> Program MethodDecl FieldDecl Type MethodHeader FormalParams MethodBody VarDecl Statement MethodInvocation Assignment ParseArfs Expr


%%





Program: CLASS ID LBRACE RBRACE
        |CLASS ID LBRACE Program2 RBRACE
    ;

Program2: MethodDecl
        | FieldDecl
        | SEMICOLON
    ;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody
    ;

FieldDecl: PUBLIC STATIC Type ID { COMMA ID } SEMICOLON
    ;

Type: BOOL | INT | DOUBLE
    ;
    
MethodHeader: ( Type | VOID ) ID LPAR [ FormalParams ] RPAR
    ;

FormalParams: Type ID { COMMA Type ID }
            | STRING LSQ RSQ ID
    ;

MethodBody: LBRACE { Statement | VarDecl } RBRACE
    ;

VarDecl: Type ID { COMMA ID } SEMICOLON
    ;