#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structures.h"

node_t* create_node(char* symbol, int line, int column);
void add_child(node_t *father, node_t *child);
void add_next(node_t *node, node_t *next);



#endif