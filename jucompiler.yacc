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

%token <value> ID LPAR BOOL DOUBLE CLASS LBRACE