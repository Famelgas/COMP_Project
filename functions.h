#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <float.h>

typedef struct token
{
    char *value;
    int line, col;
} token;

typedef enum{
    node_id,
    node_root,
    node_var,
    node_methods,
    node_statements,
    node_operators,
    node_terminals
} node_type;

typedef struct Node{
    char *value;
    char *symbol;
    struct Node *parent;
    struct Node *child;
    struct Node *brother;
    node_type type;
    char *type_anoted;
    int line, col;
    int nparams;
    int anote;
    struct param *params;
} Node;

typedef struct var{
    int line, col;
    char *name;
    char *type;
    int flag;
    int function;
    int params;
    struct param *param_types;
    struct var *next;
}var;

typedef struct param{
    int line, col;
    char *id;
    char *type;
    struct param *next;
}param;

typedef struct sym_table{
    char *table_name;
    char *table_type;
    struct var *vars;
    struct param *params;
    struct sym_table *next;
} sym_table;

extern sym_table *table, *table2;   
extern int errors;

//------------------------------------------------------------------------------------

int yylex(void);
void yyerror(const char *s);

Node *create_node(node_type type, char *value, char *symbol, int line, int col);
token *create_token(char *value, int line, int col);
void free_token(token *aux);
void add_child(Node *parent, Node *child);
void add_next(Node* no, Node *next);
int count_child(Node *root); 
void print_tree(Node *root, int points);
void print_tree_anotated(Node *root, int points);
void print_table(sym_table *table1, sym_table *tabel2);
void clear_params(param *param);
void clear_vars(var *var);
void clear_table(sym_table *table1, sym_table *table2);
void create_table_end(Node *root);
sym_table *create_table(char *name, char *type);
var *create_var(char *name, char *type);
char *type(char *ntype);
char *search_var_type(sym_table *table, sym_table *table2, char *var_name);
void add_var(var *varList, var *new);
param *create_param_type(char *type, char *id);
char *search_var(param *params, char *var_name);
void add_param(param *paramList, param *new);
int search_function(sym_table *table_global, param *aux_paramTypes, int count_params, char *name);
void anote_ast(sym_table *table, sym_table *table2, Node *root);

#endif