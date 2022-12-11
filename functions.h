#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>//To get INT_MAX
#include <float.h>//To get DBL_MAX

//Token struct just need the value and the line and column where it was found
typedef struct token{
    char *value;
    int line, col;
} token;

//Enum used in first as identify of nodes later in devolopment become unused
typedef enum{
    node_id,
    node_root,
    node_var,
    node_methods,
    node_statements,
    node_operators,
    node_terminals
} node_type;

/*Struct of tree
type_anoted is the variable wher will be save the anoted  made in anote_ast
anote is a flag to know if the node was anoted
nparams is the number of parameters 
params is a list of parameters
*/
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

/*var is a list of variables
type is the type of the variable(int, boolean, double etc)
name is the name of the variable
function is a flag to know if the variable is from a function
flag is a flag to know if the variable is a parameter
params is the number of parameters
param_types is a list of parameters
*/
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

/*param is a list of parameters
type is the type of the parameter(int, boolean, double etc)
id is the name of the parameter
*/
typedef struct param{
    int line, col;
    char *id;
    char *type;
    struct param *next;
}param;

/*sym_table is a list of tables
table_name is the name of the table
table_type is the type of the table(int, boolean, double, String[] etc)
vars is a list of variables in the table
params is a list of parameters in the table
*/
typedef struct sym_table{
    char *table_name;
    char *table_type;
    struct var *vars;
    struct param *params;
    struct sym_table *next;
} sym_table;

//Global variables
extern sym_table *table, *table2;   
extern int errors;

//------------------------------------------------------------------------------------

int yylex(void);
void yyerror(const char *s);

//create a node
Node *create_node(node_type type, char *value, char *symbol, int line, int col);
//create a token
token *create_token(char *value, int line, int col);
//free a token
void free_token(token *aux);
//add a child to a node
void add_child(Node *parent, Node *child);
//add a brother to a node
void add_next(Node* no, Node *next);
//count all childs of a node
int count_child(Node *root); 
//print the ast tree
void print_tree(Node *root, int points);
//print the ast tree with the anotations
void print_tree_anotated(Node *root, int points);
//print the tabels
void print_table(sym_table *table1, sym_table *tabel2);
//clear a parms list
void clear_params(param *param);
//clear a var list
void clear_vars(var *var);
//clear the two tables
void clear_table(sym_table *table1, sym_table *table2);
// assist to clear_table
void clear_table2(sym_table *table2);
//create all the tabels
void create_table_end(Node *root);
//initalize a struct sym_table
sym_table *create_table(char *name, char *type);
//initialize a struct var
var *create_var(char *name, char *type);
//Change the aparention of a type to be printed
char *type(char *ntype);
//serche a var in the tables
char *search_var_type(sym_table *table, sym_table *table2, char *var_name);
//add a var to a table
void add_var(var *varList, var *new);
//initialize a struct param
param *create_param_type(char *type, char *id);
//serche a var in a params list
char *search_var(param *params, char *var_name);
//add a param to a params list
void add_param(param *paramList, param *new);
//search a var that is a function in the tables
int search_function(sym_table *table_global, param *aux_paramTypes, int count_params, char *name);
//anote the ast tree with the types
void anote_ast(sym_table *table, sym_table *table2, Node *root);

#endif