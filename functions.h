#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

int yylex(void);
void yyerror(const char *s);

typedef enum {
    node_id,
    node_root,
    node_var,
    node_methods,
    node_statements,
    node_operators,
    node_terminals
} node_type;

typedef struct node *node_t;

typedef struct node {
    char * value;
    char * symbol;
    node_type type;
    int num_node;
    node_t parent;
    node_t child;
    node_t brother;
} node;

node_t root;
node_t aux;
int flag_errorr = 0;
int flag;

node_t create_node(node_type type, char *value, char *symbol);
void add_child(node_t parent, node_t child); 
void add_next(node_t node, node_t next);
int count_children(node_t root);
void print_tree(node_t root, int points);

#endif