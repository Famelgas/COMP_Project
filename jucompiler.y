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

Program2: MethodDecl Program2                                   {Program2(>=1) (MethodDecl); } 
        | FieldDecl Program2                                   {Program2(>=1) (FieldDecl); }
        | SEMICOLON Program2                                  {Program2(>=1) (SEMICOLON); }
        | /* empty */                                         {Program2(0) (); }
    ;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody            {MethodDecl(2) (PUBLIC, STATIC, MethodHeader, MethodBody); }
    ;

FieldDecl: PUBLIC STATIC Type ID FieldDecl2 SEMICOLON     {FieldDecl(>=1) (PUBLIC, STATIC, Type, Id, FieldDecl2, SEMICOLON); }
        | error SEMICOLON                                       {$$ = NULL; error = 1;}
    ;

FieldDecl2: COMMA ID FieldDecl2                              {FieldDecl2(>=1) (COMMA, Id, FieldDecl2); }
        | /* empty */                                         {FieldDecl2(0) (); }
    ;

Type: BOOL | INT | DOUBLE
    ;
    
MethodHeader: VOID ID LPAR FormalParams RPAR             {MethodHeader(3) (VOID, Id, LPAR, FormalParams, RPAR); }
        | Type ID LPAR FormalParams RPAR                 {MethodHeader(3) (Type, Id, LPAR, FormalParams, RPAR); }
        | VOID ID LPAR RPAR                              {MethodHeader(3) (VOID, Id, LPAR, RPAR); }
        | Type ID LPAR RPAR                             {MethodHeader(3) (Type, Id, LPAR, RPAR); }
    ;

FormalParams: Type ID FormalParams2                     {FormalParams(>=1) (Type, Id, FormalParams2); }
            | STRING LSQ RSQ ID                      
    ;
FormalParams2: COMMA Type ID FormalParams2 
            | /* empty */                            
    ;

MethodBody: LBRACE MethodBody2 RBRACE     
    ;

MethodBody2: Statement MethodBody2              {MethodBody2(>=1) (Statement, MethodBody2); }
            | VarDecl MethodBody2                 {MethodBody2(>=1) (VarDecl, MethodBody2); }
            | /* empty */                        
    ;

VarDecl: Type ID VarDecl2 SEMICOLON            {VarDecl(>=1) (Type, Id, VarDecl2, SEMICOLON); }
    ;

VarDecl2: COMMA ID VarDecl2                  {VarDecl2(>=1) (COMMA, Id, VarDecl2); }
        | /* empty */                         {VarDecl2(0) (); }
    ;

Statement: LBRACE Statement2 RBRACE         {Statement(3) (LBRACE, Statement2, RBRACE); }
        | IF LPAR Expr RPAR Statement ELSE Statement    {Statement(5) (IF, LPAR, Expr, RPAR, Statement, ELSE, Statement); }
        | IF LPAR Expr RPAR Statement             {Statement(4) (IF, LPAR, Expr, RPAR, Statement); }
        | WHILE LPAR Expr RPAR Statement     {Statement(4) (WHILE, LPAR, Expr, RPAR, Statement); }
        | RETURN Expr SEMICOLON            {Statement(3) (RETURN, Expr, SEMICOLON); }
        | RETURN SEMICOLON               {Statement(2) (RETURN, SEMICOLON); }
        | MethodInvocation SEMICOLON    {Statement(2) (MethodInvocation, SEMICOLON); }
        | Assignment SEMICOLON      {Statement(2) (Assignment, SEMICOLON); }
        | ParseArgs SEMICOLON   {Statement(2) (ParseArgs, SEMICOLON); }
        | SEMICOLON             {Statement(1) (SEMICOLON); }
        | PRINT LPAR Expr RPAR SEMICOLON    {Statement(5) (PRINT, LPAR, Expr, RPAR, SEMICOLON); }                    
        | PRINT LPAR STRLIT RPAR SEMICOLON  {Statement(5) (PRINT, LPAR, STRLIT, RPAR, SEMICOLON); } 
        | error SEMICOLON                                       {$$ = NULL; error = 1;}
    ;

Statement2: Statement Statement2        {Statement2(>=1) (Statement, Statement2); }
        |   /* empty */                 {Statement2(0) (); }
    ;

MethodInvocation: ID LPAR RPAR         {MethodInvocation(2) (Id, LPAR, RPAR); }
                | ID LPAR Expr MethodInvocation2 RPAR   {MethodInvocation(4) (Id, LPAR, Expr, MethodInvocation2, RPAR); }
                | ID LPAR error RPAR                           {$$ = NULL; error = 1;}
    ;

MethodInvocation2:COMMA Expr MethodInvocation2  {MethodInvocation2(>=1) (COMMA, Expr, MethodInvocation2); }
                |   /* empty */                 {MethodInvocation2(0) (); }
            ;

Assignment: ID ASSIGN Expr          {Assignment(3) (Id, ASSIGN, Expr); }
        ;

ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR   {ParseArgs(6) (PARSEINT, LPAR, Id, LSQ, Expr, RSQ, RPAR); }
        | PARSEINT LPAR error RPAR                             {$$ = NULL; error = 1;}
        ;

Expr: Expr PLUS Expr        {Expr(3) (Expr, PLUS, Expr); }
        | Expr MINUS Expr   {Expr(3) (Expr, MINUS, Expr); }
        | Expr STAR Expr    {Expr(3) (Expr, STAR, Expr); }
        | Expr DIV Expr    {Expr(3) (Expr, DIV, Expr); }
        | Expr MOD Expr   {Expr(3) (Expr, MOD, Expr); }
        | Expr AND Expr   {Expr(3) (Expr, AND, Expr); }
        | Expr OR Expr  {Expr(3) (Expr, OR, Expr); }
        | Expr XOR Expr {Expr(3) (Expr, XOR, Expr); }
        | Expr LSHIFT Expr  {Expr(3) (Expr, LSHIFT, Expr); }
        | Expr RSHIFT Expr  {Expr(3) (Expr, RSHIFT, Expr); }
        | Expr EQ Expr  {Expr(3) (Expr, EQ, Expr); }
        | Expr GE Expr      {Expr(3) (Expr, GE, Expr); }
        | Expr GT Expr    {Expr(3) (Expr, GT, Expr); }
        | Expr LE Expr  {Expr(3) (Expr, LE, Expr); }
        | Expr LT Expr  {Expr(3) (Expr, LT, Expr); }
        | Expr NE Expr  {Expr(3) (Expr, NE, Expr); }
        | MINUS Expr    {Expr(2) (MINUS, Expr); }
        | NOT Expr      {Expr(2) (NOT, Expr); }
        | PLUS Expr   {Expr(2) (PLUS, Expr); }
        | LPAR Expr RPAR    {Expr(3) (LPAR, Expr, RPAR); }
        | MethodInvocation  {Expr(1) (MethodInvocation); }
        | Assignment    {Expr(1) (Assignment); }
        | ParseArgs    {Expr(1) (ParseArgs); }
        | ID DOTLENGTH  {Expr(2) (Id, DOTLENGTH); }
        | ID       {Expr(1) (Id); }
        | INTLIT    {Expr(1) (INTLIT); }
        | REALLIT   {Expr(1) (REALLIT); }
        | BOOLLIT   {Expr(1) (BOOLLIT); }
        | LPAR error RPAR                                     {$$ = NULL; error = 1;}
    ;
/*
void yyerror ( char * s ) {
    printf ( " Line ␣ %d , ␣ col ␣ %d : ␣ % s : ␣% s \n " , < num linha >, < num coluna > , s , yytext );
}
*/