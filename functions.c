#include "functions.h"

// --------------------------------------------------------------------------------------------------------------------------

node_t create_node(node_type type, char *value, char *symbol)
{

    node_t new = malloc(sizeof(node_t));
    new->symbol = (char *)malloc(1 + strlen(symbol) * sizeof(char));
    new->value = (char *)malloc(1 + strlen(value) * sizeof(char));

    strcpy(new->symbol, symbol);
    new->parent = NULL;
    new->child = NULL;
    new->brother = NULL;
    new->num_node = 0;
    strcpy(new->value, value);
    new->symbol = symbol;
    new->type = type;

    return new;
}

// --------------------------------------------------------------------------------------------------------------------------
// Adicionar filho

void add_child(node_t parent, node_t child)
{
    if (parent->child == NULL)
    {
        parent->child = child;
    }
    else
    {
        node_t last_child;
        last_child = parent->child;
        for (; last_child->brother != NULL; last_child = last_child->brother)
            ;
        last_child->brother = child;
    }
}

// --------------------------------------------------------------------------------------------------------------------------
// Adicionar irmão

void add_next(node_t node, node_t next)
{
    if (node == NULL || next == NULL)
        return;
    for (; node->child != NULL; node = node->child)
        ;
    node->child = next;
}

// --------------------------------------------------------------------------------------------------------------------------

int count_children(node_t root){
    int count = 0;
    node_t aux;
    aux = root;
    while (aux != NULL){
        aux = aux->child;
        count++;
    }
    return count;
}

void print_tree(node_t root, int points){
    int depth = points;
    for (int i = 0; i < depth; i++)
        printf("..");
    if (root->num_node == 0)
        printf("%s\n", root->symbol);
    else if (strcmp(root->symbol, "StrLit") == 0)
        printf("StrLit(\"%s\")\n", root->value);
    else
        printf("%s(%s)\n", root->symbol, root->value);
    if (root->child != NULL)
        print_tree(root->child, depth + 1);
    if (root->brother != NULL)
        print_tree(root->brother, depth);
}