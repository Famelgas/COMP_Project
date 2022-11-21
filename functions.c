#include "functions.h"

// --------------------------------------------------------------------------------------------------------------------------

Node *create_node(node_type type, char *value, char *symbol){

    Node *new = (Node *) malloc(sizeof(Node));

    new->symbol = symbol;
    new->value = value;
    new->parent = NULL;
    new->child = NULL;
    new->brother = NULL;
    new->type = type;
    new->type_anoted = "";

    return new;
}

// --------------------------------------------------------------------------------------------------------------------------
// Adicionar filho

void add_child(Node* parent, Node* child){
    if (child == NULL){
        return;
    }
    parent->child = child;
    child->parent = parent;
}

// --------------------------------------------------------------------------------------------------------------------------
// Adicionar irmão

void add_next(Node* node, Node* next){
    if (node == NULL || next == NULL)
        return;
    Node* aux;
    aux = node;
    while (aux->brother != NULL){
        aux = aux->brother;
    }
    aux->brother = next;
    if (node->parent != NULL){
        next->parent = node->parent;
    }
}

// --------------------------------------------------------------------------------------------------------------------------

int count_children(Node* root){
    int count = 0;
    Node* aux;
    aux = root;
    while (aux != NULL){
        aux = aux->brother;
        count++;
    }
    return count;
}


void print_tree(Node * root, int points){
    if (root == NULL)    {
        return;
    }
    int i = 0;
    while (i < points){
        printf("..");
        i++;
    }
    if (strcmp(root->value, "") != 0)   {
        printf("%s(%s)\n", root->symbol, root->value);
    }
    else{
        printf("%s\n", root->symbol);
    }

    if(root->child != NULL){
        print_tree(root->child, points + 1);
    }
    if(root->brother != NULL){
        print_tree(root->brother, points);
    }

    free(root);
}

void print_tree_anotated(Node *root, int points){
    if (root == NULL){
        return;
    }
    int i = 0;
    while (i < points){
        printf("..");
        i++;
    }
    if (strcmp(root->value, "") != 0){
        printf("%s(%s)%s\n", root->symbol, root->value, root->type_anoted);
    }
    else{
        printf("%s%s\n", root->symbol, root->type_anoted);
    }

    if (root->child != NULL){
        print_tree_anotated(root->child, points + 1);
    }
    if (root->brother != NULL){
        print_tree_anotated(root->brother, points);
    }

    free(root);
}