#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

typedef enum
{
    node_id,
    node_root,
    node_var,
    node_methods,
    node_statements,
    node_operators,
    node_terminals
} node_type;

typedef struct Node
{
    char *value;
    char *symbol;
    struct Node *parent;
    struct Node *child;
    struct Node *brother;
    node_type type;
    char *type_anoted; 
} Node;

int yylex(void);
void yyerror(const char *s);

Node *create_node(node_type type, char *value, char *symbol);
void add_child(Node* parent, Node* child);
void add_next(Node* no, Node *next);
int count_children(Node *root);
void print_tree(Node *root, int points);
void freeTree(Node *root);
void print_tree_anotated(Node *root, int points);

#endif