#include "functions.h"

// --------------------------------------------------------------------------------------------------------------------------

node_t create_node(node_type type, char *value, char *symbol){

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

void add_child(node_t parent, node_t child){
    if (child == NULL){
        return;
    }
    parent->child = child;
    parent->num_node++; 
    child->parent = parent;   
}

// --------------------------------------------------------------------------------------------------------------------------
// Adicionar irmão

void add_next(node_t node, node_t next){
    if (node == NULL || next == NULL)
        return;
    node_t aux;
    aux = node;
    while (aux->brother != NULL){
        aux = aux->brother;
    }
    aux->brother = next;
    if(node->parent != NULL){
        next->parent = node->parent;
        next->parent->num_node++;
    }
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
    if (root == NULL){
        return;
    }
    int i = 0;
    node_t aux;
    if (root->type == node_root){
        printf("%s\n", root->symbol);
    }
    else{
        while (i < points){
            printf("..");
            i++;
        }
        if (strcmp(root->value, "") != 0){
            printf("%s(%s)\n", root->symbol, root->value);
        }
        else{
            printf("%s\n", root->symbol);
        }
    }
    aux = root->child;
    while (aux != NULL){
        node_t aux_free = aux;
        print_tree(aux, points + 1);
        aux = aux->brother;
        free(aux_free->value);
        free(aux_free->symbol);
        free(aux_free);
    }
}