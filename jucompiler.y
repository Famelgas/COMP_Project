%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symtab.h"
#include "stuctures.h"
#include "functions.h"

#define NSYMS 100

symtab tab[NSYMS];

node_t *myprogram; // root node
node_t *temp; // temp node to use as an aux
int error = 0; // error status flag
symtab_t *global; // global table
extern char *yytext;
extern int flagT;

symtab *symlook(char *varname);
int yylex (void);
void yyerror(char* s);
%}


%union {
    node_t *node;
    token_t *value;
}


%token <value> ID LPAR BOOL DOUBLE INT VOID STRLIT CLASS LBRACE ASSIGN RBRACE PARSEINT PUBLIC STATIC ELSE WHILE SEMICOLON RPAR STRING COMMA LSQ RSQ IF RETURN PRINT PLUS MINUS STAR DIV MOD AND OR XOR LSHIFT RSHIFT EQ GE GT LE LT NE NOT DOTLENGTH INTLIT REALLIT BOOLLIT 
%type <node> Program Program2 MethodDecl FieldDecl FieldDecl2 Type MethodHeader FormalParams FormalParams2 MethodBody MethodBody2 VarDecl VarDecl2 Statement MethodInvocation MethodInvocation2 Assignment ParseArgs Expr


%%
Program: CLASS ID LBRACE Program2 RBRACE                           {Program(>=1) (Id { FieldDecl | MethodDecl } );}
    ;

Program2: MethodDecl Program2
        | FieldDecl Program2
        | SEMICOLON Program2
        |
    ;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody
    ;

FieldDecl: PUBLIC STATIC Type ID FieldDecl2 SEMICOLON
        | error SEMICOLON                                       {$$ = NULL; error = 1;}
    ;

FieldDecl2: COMMA ID FieldDecl2
        |
    ;

Type: BOOL | INT | DOUBLE
    ;
    
MethodHeader: VOID ID LPAR FormalParams RPAR
        | Type ID LPAR FormalParams RPAR
        | VOID ID LPAR RPAR
        | Type ID LPAR RPAR
    ;

FormalParams: Type ID FormalParams2
            | STRING LSQ RSQ ID
    ;
FormalParams2: COMMA Type ID FormalParams2
        |
    ;

MethodBody: LBRACE MethodBody2 RBRACE
    ;

MethodBody2: Statement MethodBody2
        | VarDecl MethodBody2
        |
    ;

VarDecl: Type ID VarDecl2 SEMICOLON
    ;

VarDecl2: COMMA ID VarDecl2
        |
    ;

Statement: LBRACE Statement2 RBRACE
        | IF LPAR Expr RPAR Statement ELSE Statement
        | IF LPAR Expr RPAR Statement
        | WHILE LPAR Expr RPAR Statement
        | RETURN Expr SEMICOLON
        | RETURN SEMICOLON
        | MethodInvocation SEMICOLON 
        | Assignment SEMICOLON 
        | ParseArgs SEMICOLON 
        | SEMICOLON 
        | PRINT LPAR Expr RPAR SEMICOLON 
        | PRINT LPAR STRLIT RPAR SEMICOLON 
        | error SEMICOLON                                       {$$ = NULL; error = 1;}
    ;

Statement2: Statement Statement2
        |
    ;

MethodInvocation: ID LPAR RPAR
                | ID LPAR Expr MethodInvocation2 RPAR
                | ID LPAR error RPAR                           {$$ = NULL; error = 1;}
    ;

MethodInvocation2:COMMA Expr MethodInvocation2
                |
            ;

Assignment: ID ASSIGN Expr
        ;

ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR
        | PARSEINT LPAR error RPAR                             {$$ = NULL; error = 1;}
        ;

Expr: Expr PLUS Expr
        | Expr MINUS Expr
        | Expr STAR Expr
        | Expr DIV Expr
        | Expr MOD Expr
        | Expr AND Expr
        | Expr OR Expr
        | Expr XOR Expr
        | Expr LSHIFT Expr
        | Expr RSHIFT Expr
        | Expr EQ Expr
        | Expr GE Expr
        | Expr GT Expr
        | Expr LE Expr
        | Expr LT Expr
        | Expr NE Expr
        | MINUS Expr
        | NOT Expr
        | PLUS Expr
        | LPAR Expr RPAR
        | MethodInvocation 
        | Assignment 
        | ParseArgs
        | ID DOTLENGTH
        | ID
        | INTLIT 
        | REALLIT 
        | BOOLLIT
        | LPAR error RPAR                                     {$$ = NULL; error = 1;}
    ;

void yyerror ( char * s ) {
    printf ( " Line ␣ %d , ␣ col ␣ %d : ␣ % s : ␣% s \n " , < num linha >, < num coluna > , s , yytext );
}