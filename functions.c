#include "functions.h"

Node *create_node(node_type type, char *value, char *symbol, int line, int col){

    Node *new = (Node *) malloc(sizeof(Node));

    new->symbol = symbol;
    new->value = value;
    new->parent = NULL;
    new->child = NULL;
    new->brother = NULL;
    new->type = type;
    new->line = line;
    new->col = col;
    new->nparams = -1;
    new->params = NULL;
    new->type_anoted = NULL;
    new->anote = 1;
    return new;
}

void add_child(Node* parent, Node* child){
    if (child == NULL){
        return;
    }
    parent->child = child;
    child->parent = parent;
}

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

int count_child(Node* root){
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
}

token *create_token(char *value, int line, int col){
    token *new = (token *)malloc(sizeof(token));
    
    new->value = (char *)strdup(value);
    new->line = line;
    new->col = col;
    return new;
}

void free_token(token *aux){
    free(aux->value);
    aux->value = NULL;

    free(aux);
    aux = NULL;
}

int expression(char *type){
    if (strcmp(type, "Assign") == 0 || strcmp(type, "Or") == 0 || strcmp(type, "And") == 0 || strcmp(type, "Eq") == 0 || strcmp(type, "Neq") == 0 || strcmp(type, "Lt") == 0 || strcmp(type, "Geq") == 0 || strcmp(type, "Add") == 0 || strcmp(type, "Sub") == 0 || strcmp(type, "Mul") == 0 || strcmp(type, "Div") == 0 || strcmp(type, "Mod") == 0 || strcmp(type, "Not") == 0 || strcmp(type, "Minus") == 0 || strcmp(type, "Plus") == 0 || strcmp(type, "Length") == 0 || strcmp(type, "Call") == 0 || strcmp(type, "ParseArgs") == 0 || strcmp(type, "BoolLit") == 0 || strcmp(type, "DecLit") == 0 || strcmp(type, "Id") == 0 || strcmp(type, "RealLit") == 0 || strcmp(type, "StrLit") == 0 || strcmp(type, "Gt") == 0 || strcmp(type, "Leq") == 0){
        return 1;
    }
    else{
        return 0;
    }
}

void print_tree_anotated(Node *root, int points){
    
    param *aux;
    int i = 0;

    if (root == NULL){
        return;
    }
    
    if (strcmp(root->symbol, "NULL") == 0){
        print_tree_anotated(root->brother, points);
        return;
    }
    else{
        while (i < points){
            printf("..");
            i++;
        }

        //printf("%s / %s \n",root->value, root->type_anoted);

        if(strcmp(root->value, "") != 0){
            if(root->params > 0 && expression(root->symbol) == 1){
                printf("%s(%s) - (", root->symbol, root->value);
                aux = root->params;
                while (aux != NULL){
                    printf("%s", aux->type);
                    if (aux->next != NULL){
                        printf(",");
                    }
                    aux = aux->next;
                }
                printf(")");
            }
            else if (root->type_anoted != NULL && expression(root->symbol) == 1){
                printf("%s(%s) - %s", root->symbol, root->value, root->type_anoted);
            }
            else{
                printf("%s(%s)", root->symbol, root->value);
            }
        }
        else{
            if (root->type_anoted != NULL && expression(root->symbol) == 1){
                printf("%s - %s", root->symbol, root->type_anoted);
            }
            else{
                printf("%s", root->symbol);
            }
        }

        printf("\n");
    }
    print_tree_anotated(root->child, points + 1);
    print_tree_anotated(root->brother, points);
}

void print_table(sym_table *table1, sym_table *tabel2){
    var *auxvar = table1->vars;
    param *auxparam;

    printf("===== %s %s Symbol Table =====\n", table1->table_type, table1->table_name);
    while (auxvar != NULL){
        if (auxvar->function == 1){
            auxparam = auxvar->param_types;
            printf("%s\t(", auxvar->name);
            while (auxparam != NULL){
                printf("%s", auxparam->type);
                if (auxparam->next != NULL){
                    printf(",");
                }
                auxparam = auxparam->next;
            }
            printf(")\t%s", auxvar->type);
        }
        else{
            printf("%s\t\t%s", auxvar->name, auxvar->type);
        }

        printf("\n");

        auxvar = auxvar->next;
    }
    printf("\n");

    sym_table *aux = tabel2;
    auxvar = NULL;
    auxparam = NULL;

    while (aux != NULL){
        auxvar = aux->vars;
        auxparam = aux->params;
        if (auxparam != NULL){
            printf("===== %s %s(", aux->table_type, aux->table_name);
            while (auxparam != NULL){
                printf("%s", auxparam->type);
                if (auxparam->next != NULL){
                    printf(",");
                }
                auxparam = auxparam->next;
            }
            printf(") Symbol Table =====\n");
        }
        else{
            printf("===== %s %s() Symbol Table =====\n", aux->table_type, aux->table_name);
        }
        while (auxvar != NULL){
            if (auxvar->flag == 1){
                printf("%s\t\t%s\t%s\n", auxvar->name, auxvar->type, "param");
            }
            else if (auxvar->flag != 2){
                printf("%s\t\t%s\n", auxvar->name, auxvar->type);
            }
            auxvar = auxvar->next;
        }
        printf("\n");
        aux = aux->next;
    }
}

void clear_params(param *param){
    if (param == NULL){
        return;
    }
    
    free(param->type);
    param->type = NULL;

    free(param->id);
    param->id = NULL;

    clear_params(param->next);

    free(param);
    param = NULL;
}

void clear_vars(var *var){
    if (var == NULL){
        return;
    }

    free(var->type);
    var->type = NULL;

    free(var->name);
    var->name = NULL;

    clear_params(var->param_types);
    clear_vars(var->next);

    free(var);
    var = NULL;
}

void clear_table(sym_table *table1, sym_table *table2){
    if (table != NULL){
        if (table->table_name != NULL){
            free(table->table_name);
            table->table_name = NULL;
        }
        if (table->table_type != NULL){
            free(table->table_type);
            table->table_type = NULL;
        }

        clear_vars(table->vars);

        free(table);
        table = NULL;
    }
    while(table2 != NULL){
        if (table2 == NULL){
            return;
        }

        free(table2->table_name);
        table2->table_name = NULL;
        
        free(table2->table_type);
        table2->table_type = NULL;

        clear_params(table2->params->next);
        
        free(table2->params->type);
        table2->params->type = NULL;

        free(table2->params->id);
        table2->params->id = NULL;

        free(table2->params);
        table2->params = NULL;
        
        clear_vars(table2->vars->next);

        free(table2->vars->type);
        table2->vars->type = NULL;
            
        free(table2->vars->name);
        table2->vars->name = NULL;

        free(table2->vars);
        table2->vars = NULL;
        
        table2 = table2->next;
    }
    free(table2);
    table2 = NULL;
}

void create_table_end(Node *root){
    char *aux;
    int error;
    sym_table *aux_table;
    var *aux_var, *aux_var2, *aux_add_var;
    param *aux_param, *aux_param_print, *aux_add_param;
    Node *aux1,*aux2, *aux3, *aux4, *aux5, *aux6, *aux_program;
    int count_params;
    errors = 0;

    if (root == NULL){
        return;
    }
    
    if (strcmp(root->symbol, "Program") == 0){
        aux1 = root->child;

        table = create_table(aux1->value, "Class");

        aux_program = aux1->brother; 
        root = aux1->brother;

        while (root != NULL){ 
            if (strcmp(root->symbol, "FieldDecl") == 0){
                aux1 = root->child;
                aux2 = aux1->brother;
                aux_var = create_var(aux2->value, type(aux1->symbol));
                if (search_var_type(table, table, aux2->value) != NULL){
                    errors = 1;
                    printf("Line %d, col %d: Symbol %s already defined\n", aux2->line, aux2->col, aux2->value);
                    clear_vars(aux_var);
                }
                else{
                    if (table->vars == NULL){
                        table->vars = aux_var;
                    }
                    else{
                        aux_add_var = table->vars;
                        if (aux_add_var == NULL){
                            table->vars = aux_var;
                        }
                        while (aux_add_var->next != NULL)
                        {
                            aux_add_var = aux_add_var->next;
                        }
                        aux_add_var->next = aux_var;
                    }
                }
            }
            if (strcmp(root->symbol, "MethodDecl") == 0){       
                aux1 = root->child;
                count_params = 0;
                while (aux1 != NULL){
                    if (strcmp(aux1->symbol, "MethodHeader") == 0){
                        aux2 = aux1->child;
                        aux3 = aux2->brother;
                        aux_var = create_var(aux3->value, type(aux2->symbol)); 
                        aux4 = aux3->brother;
                        aux5 = aux4->child;
                        while (aux5 != NULL){
                            if (strcmp(aux5->symbol, "NULL") != 0){
                                count_params++;
                                aux_param = create_param_type(type(aux5->child->symbol), aux5->child->brother->value);
                                aux = search_var(aux_var->param_types, aux5->child->brother->value);
                                if (aux != NULL)
                                {
                                    errors = 1;
                                    printf("Line %d, col %d: Symbol %s already defined\n", aux5->child->brother->line, aux5->child->brother->col, aux5->child->brother->value);
                                }
                                if (aux_var->param_types == NULL)
                                {
                                    aux_var->param_types = aux_param;
                                }
                                else{
                                    aux_add_param = aux_var->param_types;
                                    if (aux == NULL){
                                        aux_var->param_types = aux_param;
                                    }
                                    while (aux_add_param->next != NULL){
                                        aux_add_param = aux_add_param->next;
                                    }
                                    aux_add_param->next = aux_param;
                                }
                            }
                            aux5 = aux5->brother;
                        }
                        aux_var->function = 1;
                        aux_var->params = count_params;
                        if (search_function(table, aux_var->param_types, count_params, aux3->value) == 1)
                        {
                            errors = 1;
                            printf("Line %d, col %d: Symbol %s(", aux3->line, aux3->col, aux3->value);
                            aux_param_print = aux_var->param_types;
                            while (aux_param_print != NULL)
                            {
                                printf("%s", aux_param_print->type);
                                if (aux_param_print->next != NULL)
                                {
                                    printf(",");
                                }
                                aux_param_print = aux_param_print->next;
                            }
                            printf(") already defined\n");
                            aux3->anote = 0;
                            clear_vars(aux_var);
                        }
                        else
                        {
                            if (table->vars == NULL)
                            {
                                table->vars = aux_var;
                            }
                            else{

                                aux_add_var = table->vars;
                                if (aux_add_var == NULL)
                                {
                                    table->vars = aux_var;
                                }
                                while (aux_add_var->next != NULL){
                                    aux_add_var = aux_add_var->next;
                                }
                                aux_add_var->next = aux_var;
                            }
                        }
                    }

                    aux1 = aux1->brother;
                }
            }
            root = root->brother;
        }
        root = aux_program;
        while (root != NULL){
            if (strcmp(root->symbol, "MethodDecl") == 0){
                error = 0;
                aux1 = root->child;
                while (aux1 != NULL){                    
                    if (strcmp(aux1->symbol, "MethodHeader") == 0){
                        aux2 = aux1->child;
                        aux3 = aux2->brother;
                        if (aux3->anote == 0){
                            error = 1;
                            break;
                        }
                        aux_table = create_table(aux3->value, "Method");
                        aux_var = create_var("return", type(aux2->symbol));
                        aux_var->flag = 0;
                        aux_table->vars = aux_var;

                        aux4 = aux3->brother;
                        aux5 = aux4->child;
                        while (aux5 != NULL){
                            if (strcmp(aux5->symbol, "NULL") != 0){
                                aux_param = create_param_type(type(aux5->child->symbol), aux5->child->brother->value);
                                aux = search_var(aux_var->param_types, aux5->child->brother->value);
                                if (aux_var->param_types == NULL){
                                    aux_var->param_types = aux_param;
                                }
                                else{
                                    aux_add_param = aux_var->param_types;
                                    if (aux == NULL){
                                        aux_var->param_types = aux_param;
                                    }
                                    while (aux_add_param->next != NULL)
                                    {
                                        aux_add_param = aux_add_param->next;
                                    }

                                    aux_add_param->next = aux_param;
                                }
                                aux6 = aux5->child->brother;
                                aux_var2 = create_var(aux6->value, type(aux5->child->symbol));
                                if (aux != NULL){
                                    aux_var2->flag = 2;
                                }
                                else{
                                    aux_var2->flag = 1;
                                }
                                aux_table->params = aux_var->param_types;

                                var *aux = aux_table->vars;
                                if (aux == NULL)
                                {
                                    aux_table->vars = aux_var2;
                                    return;
                                }
                                while (aux->next != NULL)
                                {
                                    aux = aux->next;
                                }
                                aux->next = aux_var2;
                            }
                            aux5 = aux5->brother;
                        }
                    }
                    if (strcmp(aux1->symbol, "MethodBody") == 0){
                        aux2 = aux1->child;
                        while (aux2 != NULL){
                            if (strcmp(aux2->symbol, "VarDecl") == 0){
                                aux3 = aux2->child;
                                aux4 = aux3->brother;

                                if (search_var_type(NULL, aux_table, aux4->value) != NULL){
                                    errors = 1;
                                    printf("Line %d, col %d: Symbol %s already defined\n", aux4->line, aux4->col, aux4->value);
                                }
                                else{
                                    aux_var = create_var(aux4->value, type(aux3->symbol));
                                    aux_var->flag = 0;
                                    aux_add_var = aux_table->vars;
                                    if (aux_add_var == NULL){
                                        aux_table->vars = aux_var;
                                    }
                                    while (aux_add_var->next != NULL){
                                        aux_add_var = aux_add_var->next;
                                    }
                                    aux_add_var->next = aux_var;
                                }
                            }
                            else{
                                if (!(strcmp(aux2->symbol, "NULL") == 0))
                                {
                                    anote_ast(table, aux_table, aux2);
                                }
                            }

                            aux2 = aux2->brother;
                        }
                    }

                    aux1 = aux1->brother;
                }

                if (error != 1){
                    if (table2 == NULL){
                        table2 = aux_table;
                    }
                    else{
                        sym_table *aux = table2;
                        if (aux == NULL){
                            table2 = aux_table;
                            return;
                        }
                        while (aux->next != NULL){
                            aux = aux->next;
                        }
                        aux->next = aux_table;
                    }
                }
            }
            root = root->brother;
        }
    }
}

sym_table *create_table(char *name, char *type){
    sym_table *aux = (sym_table *)malloc(sizeof(sym_table));
    aux->table_name = (char *)strdup(name);
    aux->table_type = (char *)strdup(type);

    aux->vars = NULL;
    aux->params = NULL;
    aux->next = NULL;
    return aux;
}

var *create_var(char *name, char *type){
    var *new = (var *)malloc(sizeof(var));
    new->name = (char *)strdup(name);
    new->type = (char *)strdup(type);

    new->function = 0;
    new->flag = 0;
    new->params = 0;
    new->param_types = NULL;
    new->next = NULL;
    return new;
}

char *type(char *type){
    if (strcmp(type, "Int") == 0){
        type = "int";
        return type;
    }
    else if (strcmp(type, "Double") == 0){
        type = "double";
        return type;
    }
    else if (strcmp(type, "Bool") == 0){
        type = "boolean";
        return type;
    }
    else if (strcmp(type, "Void") == 0){
        type = "void";
        return type;
    }
    else if (strcmp(type, "StringArray") == 0){
        type = "String[]";
        return type;
    }
    return type;
}

char *search_var_type(sym_table *table, sym_table *table2, char *var_name){
    if (table == NULL || table2 == NULL){
        return NULL;
    }
    var *aux = table->vars;

    while (aux != NULL){
        if (strcmp(aux->name, var_name) == 0 && aux->function != 1){
            if (aux->type != NULL){
                return aux->type;
            }
        }
        aux = aux->next;
    }

    aux = table2->vars;
    while (aux != NULL){
        if (strcmp(aux->name, var_name) == 0 && aux->function != 1){
            if (aux->type != NULL){
                return aux->type;
            }
        }
        aux = aux->next;
    }

    return NULL;
}

param *create_param_type(char *type, char *id){
    param *new = (param *)malloc(sizeof(param));
    new->type = (char *)strdup(type);
    new->id = (char *)strdup(id);
    
    new->next = NULL;
    return new;
}

char *search_var(param *params, char *var_name){
    if (params == NULL){
        return NULL;
    }
    param *aux = params;

    while (aux != NULL){
        if (strcmp(aux->id, var_name) == 0){
            return aux->type;
        }
        aux = aux->next;
    }

    return NULL;
}

void add_param(param *paramList, param *new){
    param *aux = paramList;
    if (aux == NULL){
        paramList = new;
        return;
    }
    while (aux->next != NULL){
        aux = aux->next;
    }

    aux->next = new;
}

int search_function(sym_table *table, param *aux_paramTypes, int count_params, char *name){
    var *aux_vars;
    param *aux_params1, *aux_params2;
    int count_equals = 0;

    aux_vars = table->vars;
    while (aux_vars != NULL){
        if (aux_vars->function == 1 && aux_vars->params == count_params && strcmp(aux_vars->name, name) == 0){
            count_equals = 0;
            aux_params1 = aux_vars->param_types;
            aux_params2 = aux_paramTypes;
            while (aux_params1 != NULL){
                if (strcmp(aux_params1->type, aux_params2->type) == 0){
                    count_equals++;
                }
                aux_params1 = aux_params1->next;
                aux_params2 = aux_params2->next;
            }
            if (count_equals == count_params){
                return 1;
            }
        }
        aux_vars = aux_vars->next;
    }
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------------

void anote_ast(sym_table *table, sym_table *table2, Node *root){
    char *aux;
    param *aux_params, *final_params;
    var *aux_vars;
    int count_params, count_equals, count_all_equals, find_function;
    Node *aux1, *aux2, *aux3, *ant;

    if (root == NULL){
        return;
    }

    if (strcmp(root->symbol, "NULL") == 0){
        return;
    }
    else if (strcmp(root->symbol, "Id") == 0){
        //printf("Id: symbol-> %s , value -> %s , line -> %d , col -> %d , parent -> %s \n", root->symbol, root->value, root->line, root->col, root->parent->symbol);
        aux = search_var_type(table, table2, root->value);
        if (aux != NULL){
            root->type_anoted = aux;
        }
        else{
            errors = 1;
            printf("Line %d, col %d: Cannot find symbol %s\n", root->line, root->col, root->value);
            root->type_anoted = "undef";
        }
    }
    else if (strcmp(root->symbol, "If") == 0)
    {
        aux1 = root->child;
        anote_ast(table, table2, aux1);
        aux1 = aux1->brother;

        aux2 = root->child;
        if (strcmp(aux2->type_anoted, "boolean"))
        {
            errors = 1;
            printf("Line %d, col %d: Incompatible type %s in if statement\n", aux2->line, aux2->col, aux2->type_anoted);
        }

        while (aux1 != NULL)
        {
            anote_ast(table, table2, aux1);
            aux1 = aux1->brother;
        }
    }
    else if (strcmp(root->symbol, "Block") == 0)
    {
        aux1 = root->child;
        while (aux1 != NULL)
        {
            anote_ast(table, table2, aux1);
            aux1 = aux1->brother;
        }
    }
    else if (strcmp(root->symbol, "While") == 0)
    {
        // dentro do while() só pode estar um boolit, gt, eq, get, leq, lt, neq
        aux1 = root->child;
        anote_ast(table, table2, aux1);
        aux1 = aux1->brother;

        aux2 = root->child;
        if (strcmp(aux2->type_anoted, "boolean"))
        {
            errors = 1;
            printf("Line %d, col %d: Incompatible type %s in while statement\n", aux2->line, aux2->col, aux2->type_anoted);
            root->type_anoted = "boolean";
        }
        else
        {
            root->type_anoted = "boolean";
        }

        while (aux1 != NULL)
        {
            anote_ast(table, table2, aux1);
            aux1 = aux1->brother;
        }
    }
    else if (strcmp(root->symbol, "DoWhile") == 0)
    {
        aux1 = root->child;
        while (aux1 != NULL)
        {
            anote_ast(table, table2, aux1);
            if (strcmp(aux1->symbol, "NULL"))
            {
                ant = aux1;
            }
            aux1 = aux1->brother;
        }

        aux2 = ant;
        if (strcmp(aux2->type_anoted, "boolean"))
        {
            errors = 1;
            printf("Line %d, col %d: Incompatible type %s in do statement\n", aux2->line, aux2->col, aux2->type_anoted);
            root->type_anoted = "boolean";
        }
        else
        {
            root->type_anoted = "boolean";
        }
    }
    else if (strcmp(root->symbol, "Print") == 0)
    {
        aux1 = root->child;
        while (aux1 != NULL)
        {
            anote_ast(table, table2, aux1);
            aux1 = aux1->brother;
        }

        aux2 = root->child;
        if (strcmp(aux2->type_anoted, "undef") == 0 || strcmp(aux2->type_anoted, "String[]") == 0 || strcmp(aux2->type_anoted, "void") == 0)
        {
            errors = 1;
            printf("Line %d, col %d: Incompatible type %s in System.out.println statement\n", aux2->line, aux2->col, aux2->type_anoted);
            root->type_anoted = "String[]";
        }
    }
    else if (strcmp(root->symbol, "Return") == 0)
    {
        aux1 = root->child;
        while (aux1 != NULL)
        {
            anote_ast(table, table2, aux1);
            aux1 = aux1->brother;
        }

        aux2 = root->child;
        if (aux2 != NULL)
        {
            if (strcmp(table2->vars->type, "void") == 0)
            {
                errors = 1;
                printf("Line %d, col %d: Incompatible type %s in return statement\n", aux2->line, aux2->col, aux2->type_anoted);
            }
            else if (strcmp(table2->vars->type, aux2->type_anoted) == 0)
            {
                return;
            }
            else if (strcmp(table2->vars->type, "double") == 0)
            {
                if ((strcmp(aux2->type_anoted, "int") && strcmp(aux2->type_anoted, "double")))
                {
                    errors = 1;
                    printf("Line %d, col %d: Incompatible type %s in return statement\n", aux2->line, aux2->col, aux2->type_anoted);
                }
            }
            else
            {
                errors = 1;
                printf("Line %d, col %d: Incompatible type %s in return statement\n", aux2->line, aux2->col, aux2->type_anoted);
            }
        }
        else
        {
            if (strcmp(table2->vars->type, "void"))
            {
                errors = 1;
                printf("Line %d, col %d: Incompatible type void in return statement\n", root->line, root->col);
            }
        }
    }
    else if (strcmp(root->symbol, "Assign") == 0){
        aux1 = root->child;
        while (aux1 != NULL)
        {
            anote_ast(table, table2, aux1);
            aux1 = aux1->brother;
        }

        aux2 = root->child;
        root->type_anoted = aux2->type_anoted;
        aux2 = root->child;
        aux3 = aux2->brother;

        root->type_anoted = aux2->type_anoted;

        if (strcmp(aux2->type_anoted, aux3->type_anoted) == 0 && strcmp(aux2->type_anoted, "undef") && strcmp(aux2->type_anoted, "String[]")){
            return;
        }
        else if (strcmp(aux2->type_anoted, "double") == 0 && strcmp(aux3->type_anoted, "int") == 0){
            return;
        }
        else
        {
            errors = 1;
            printf("Line %d, col %d: Operator = cannot be applied to types %s, %s\n", root->line, root->col, aux2->type_anoted, aux3->type_anoted);
        }
    }
    else if (strcmp(root->symbol, "Call") == 0)
    {
        count_params = 0;
        count_equals = 0;
        count_all_equals = 0;
        find_function = 0;
        aux1 = (root->child)->brother;
        while (aux1 != NULL)
        {
            if (strcmp(aux1->symbol, "NULL"))
            {
                count_params++;
            }
            anote_ast(table, table2, aux1);
            aux1 = aux1->brother;
        }

        aux_vars = table->vars;
        while (aux_vars != NULL)
        {
            count_equals = 0;
            count_all_equals = 0;
            if (aux_vars->function == 1 && aux_vars->params == count_params && strcmp(aux_vars->name, root->child->value) == 0)
            {
                aux_params = aux_vars->param_types;
                aux1 = (root->child)->brother;
                while (aux1 != NULL)
                {
                    if (strcmp(aux1->symbol, "NULL"))
                    {
                        if (strcmp(aux_params->type, aux1->type_anoted) == 0)
                        {
                            count_all_equals++;
                            count_equals++;
                        }
                        else if (strcmp(aux1->type_anoted, "int") == 0 && strcmp(aux_params->type, "double") == 0)
                        {
                            count_equals++;
                        }
                        else
                        {
                            break;
                        }
                        aux_params = aux_params->next;
                    }
                    aux1 = aux1->brother;
                }
                if (count_all_equals == count_params)
                {
                    find_function = 1;
                    aux = aux_vars->type;
                    final_params = aux_vars->param_types;
                    break;
                }
                else if (count_equals == count_params)
                {
                    aux = aux_vars->type;
                    final_params = aux_vars->param_types;
                    find_function++;
                }
            }
            aux_vars = aux_vars->next;
        }

        if (find_function == 1)
        {
            root->child->nparams = count_params;
            if (final_params == NULL)
            {
                root->child->params = NULL;
            }
            else
            {
                root->child->params = final_params;
            }
            root->type_anoted = aux;
        }
        else if (find_function > 1)
        {
            errors = 1;

            printf("Line %d, col %d: Reference to method %s(", root->child->line, root->child->col, root->child->value);
            aux1 = (root->child)->brother;
            while (aux1 != NULL)
            {
                if (strcmp(aux1->symbol, "NULL"))
                {
                    printf("%s", aux1->type_anoted);
                    if (aux1->brother != NULL)
                    {
                        printf(",");
                    }
                }
                aux1 = aux1->brother;
            }
            printf(") is ambiguous\n");
            root->type_anoted = "undef";
            root->child->type_anoted = "undef";
        }
        else
        {
            root->child->type_anoted = "undef";
            root->child->params = NULL;
            root->type_anoted = "undef";

            errors = 1;

            printf("Line %d, col %d: Cannot find symbol %s(", root->child->line, root->child->col, root->child->value);
            aux1 = (root->child)->brother;
            while (aux1 != NULL)
            {
                if (strcmp(aux1->symbol, "NULL"))
                {
                    printf("%s", aux1->type_anoted);
                    if (count_params != 1)
                    {
                        printf(",");
                    }
                    count_params--;
                }
                aux1 = aux1->brother;
            }
            printf(")\n");
        }
    }
    else if (strcmp(root->symbol, "ParseArgs") == 0)
    {
        aux1 = root->child;
        while (aux1 != NULL)
        {
            anote_ast(table, table2, aux1);
            aux1 = aux1->brother;
        }

        aux2 = root->child;
        aux3 = aux2->brother;
        if (strcmp(aux2->type_anoted, "String[]")){
            errors = 1;
            printf("Line %d, col %d: Operator Integer.parseInt cannot be applied to types %s, %s\n", root->line, root->col, aux2->type_anoted, aux3->type_anoted);
            root->type_anoted = "String[]";
        }
        else if (strcmp(aux3->type_anoted, "int")){
            errors = 1;
            printf("Line %d, col %d: Operator Integer.parseInt cannot be applied to types %s, %s\n", root->line, root->col, aux2->type_anoted, aux3->type_anoted);
            root->type_anoted = "int";
        }

        root->type_anoted = "int";
    }
    else if (strcmp(root->symbol, "And") == 0 || strcmp(root->symbol, "Or") == 0)
    {
        aux1 = root->child;
        while (aux1 != NULL)
        {
            anote_ast(table, table2, aux1);
            aux1 = aux1->brother;
        }

        aux2 = root->child;
        aux3 = aux2->brother;
        if (strcmp(aux2->type_anoted, "boolean") && strcmp(root->symbol, "And") == 0)
        {
            errors = 1;
            printf("Line %d, col %d: Operator && cannot be applied to types %s, %s\n", root->line, root->col, aux2->type_anoted, aux3->type_anoted);
        }
        else if (strcmp(aux2->type_anoted, "boolean") && strcmp(root->symbol, "Or") == 0)
        {
            errors = 1;
            printf("Line %d, col %d: Operator || cannot be applied to types %s, %s\n", root->line, root->col, aux2->type_anoted, aux3->type_anoted);
        }
        else if (strcmp(aux3->type_anoted, "boolean") && strcmp(root->symbol, "And") == 0)
        {
            errors = 1;
            printf("Line %d, col %d: Operator && cannot be applied to types %s, %s\n", root->line, root->col, aux2->type_anoted, aux3->type_anoted);
        }
        else if (strcmp(aux3->type_anoted, "boolean") && strcmp(root->symbol, "Or") == 0)
        {
            errors = 1;
            printf("Line %d, col %d: Operator || cannot be applied to types %s, %s\n", root->line, root->col, aux2->type_anoted, aux3->type_anoted);
        }

        root->type_anoted = "boolean";
    }
    else if (strcmp(root->symbol, "Eq") == 0 || strcmp(root->symbol, "Gt") == 0 || strcmp(root->symbol, "Geq") == 0 || strcmp(root->symbol, "Leq") == 0 || strcmp(root->symbol, "Lt") == 0 || strcmp(root->symbol, "Neq") == 0)
    {

        aux1 = root->child;
        while (aux1 != NULL)
        {
            anote_ast(table, table2, aux1);
            aux1 = aux1->brother;
        }

        aux2 = root->child;
        aux3 = aux2->brother;

        root->type_anoted = "boolean";

        if (strcmp(root->symbol, "Eq") == 0)
        {
            aux = "==";
        }
        else if (strcmp(root->symbol, "Gt") == 0)
        {
            aux = ">";
        }
        else if (strcmp(root->symbol, "Geq") == 0)
        {
            aux = ">=";
        }
        else if (strcmp(root->symbol, "Leq") == 0)
        {
            aux = "<=";
        }
        else if (strcmp(root->symbol, "Lt") == 0)
        {
            aux = "<";
        }
        else if (strcmp(root->symbol, "Neq") == 0)
        {
            aux = "!=";
        }

        if (strcmp(root->symbol, "Eq") == 0 || strcmp(root->symbol, "Neq") == 0)
        {
            if (strcmp(aux2->type_anoted, "boolean") == 0 && strcmp(aux3->type_anoted, "boolean") == 0)
            {
                return;
            }
        }

        if (strcmp(aux2->type_anoted, "int") && strcmp(aux2->type_anoted, "double"))
        {
            errors = 1;
            printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", root->line, root->col, aux, aux2->type_anoted, aux3->type_anoted);
        }
        else if (strcmp(aux3->type_anoted, "double") && strcmp(aux3->type_anoted, "int"))
        {
            errors = 1;
            printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", root->line, root->col, aux, aux2->type_anoted, aux3->type_anoted);
        }
    }
    else if (strcmp(root->symbol, "Add") == 0 || strcmp(root->symbol, "Sub") == 0 || strcmp(root->symbol, "Mul") == 0 || strcmp(root->symbol, "Div") == 0 || strcmp(root->symbol, "Mod") == 0)
    {

        aux1 = root->child;
        while (aux1 != NULL)
        {
            anote_ast(table, table2, aux1);
            aux1 = aux1->brother;
        }

        aux2 = root->child;
        aux3 = aux2->brother;

        if (strcmp(root->symbol, "Add") == 0)
        {
            aux = "+";
        }
        else if (strcmp(root->symbol, "Sub") == 0)
        {
            aux = "-";
        }
        else if (strcmp(root->symbol, "Mul") == 0)
        {
            aux = "*";
        }
        else if (strcmp(root->symbol, "Div") == 0)
        {
            aux = "/";
        }
        else
        {
            aux = "%";
        }

        if (strcmp(aux2->type_anoted, "int") == 0)
        {
            if (strcmp(aux3->type_anoted, "int") == 0)
            {
                root->type_anoted = "int";
            }
            else if (strcmp(aux3->type_anoted, "double") == 0)
            {
                root->type_anoted = "double";
            }
            else
            {
                errors = 1;
                printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", root->line, root->col, aux, aux2->type_anoted, aux3->type_anoted);
                root->type_anoted = "undef";
            }
        }
        else if (strcmp(aux2->type_anoted, "double") == 0)
        {
            if (strcmp(aux3->type_anoted, "int") && strcmp(aux3->type_anoted, "double"))
            {
                errors = 1;
                printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", root->line, root->col, aux, aux2->type_anoted, aux3->type_anoted);
                root->type_anoted = "undef";
            }
            else
            {
                root->type_anoted = "double";
            }
        }
        else
        {
            errors = 1;
            printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", root->line, root->col, aux, aux2->type_anoted, aux3->type_anoted);
            root->type_anoted = "undef";
        }
    }
    else if (strcmp(root->symbol, "Plus") == 0 || strcmp(root->symbol, "Minus") == 0)
    {
        aux1 = root->child;
        while (aux1 != NULL)
        {
            anote_ast(table, table2, aux1);
            aux1 = aux1->brother;
        }

        aux2 = root->child;
        root->type_anoted = aux2->type_anoted;
        if (strcmp(aux2->type_anoted, "int") == 0 || strcmp(aux2->type_anoted, "double") == 0)
        {
            root->type_anoted = aux2->type_anoted;
        }
        else
        {
            root->type_anoted = "undef";
            if (strcmp(root->symbol, "Plus") == 0)
            {
                errors = 1;
                printf("Line %d, col %d: Operator + cannot be applied to type %s\n", root->line, root->col, aux2->type_anoted);
            }
            else
            {
                errors = 1;
                printf("Line %d, col %d: Operator - cannot be applied to type %s\n", root->line, root->col, aux2->type_anoted);
            }
        }
    }
    else if (strcmp(root->symbol, "Not") == 0)
    {
        aux1 = root->child;
        while (aux1 != NULL)
        {
            anote_ast(table, table2, aux1);
            aux1 = aux1->brother;
        }

        aux2 = root->child;
        if (strcmp(aux2->type_anoted, "boolean"))
        {
            errors = 1;
            printf("Line %d, col %d: Operator ! cannot be applied to type %s\n", root->line, root->col, aux2->type_anoted);
        }

        root->type_anoted = "boolean";
    }
    else if (strcmp(root->symbol, "Length") == 0)
    {
        aux1 = root->child;
        while (aux1 != NULL)
        {
            anote_ast(table, table2, aux1);
            aux1 = aux1->brother;
        }

        aux2 = root->child;
        if (strcmp(aux2->type_anoted, "String[]")){
            errors = 1;
            printf("Line %d, col %d: Operator .length cannot be applied to type %s\n", root->line, root->col, aux2->type_anoted);
            root->type_anoted = "String[]";
        }
        root->type_anoted = "int";
    }
    else if (strcmp(root->symbol, "BoolLit") == 0)
    {
        root->type_anoted = "boolean";
    }
    else if (strcmp(root->symbol, "DecLit") == 0)
    {

        long l = strtol(root->value, NULL, 10);
        if (l >= 0 && l <= INT_MAX)
        {
            root->type_anoted = "int";
        }
        else
        {
            errors = 1;
            printf("Line %d, col %d: Number %s out of bounds\n", root->line, root->col, root->value);
        }

        root->type_anoted = "int";
    }
    else if (strcmp(root->symbol, "RealLit") == 0)
    {
        char *value = root->value;
        char *aux = (char *)malloc(sizeof(char) * 1024);
        int found = 0, zeros = 1, i = 0, j = 0;

        while (value[i] != '\0')
        {
            if ((value[i] >= '0' && value[i] <= '9') || value[i] == 'e' || value[i] == 'E' || value[i] == '.' || value[i] == '-')
            {
                if (value[i] == 'e' || value[i] == 'E')
                {
                    found = 1;
                }
                if (value[i] != '.' && value[i] != '0' && !found)
                {
                    zeros = 0;
                }
                aux[j] = value[i];
                j++;
            }
            i++;
        }
        aux[j] = '\0';

        if (!zeros)
        {
            double d = atof(aux);
            if (isinf(d) || d == 0 || d > DBL_MAX)
            {
                errors = 1;
                printf("Line %d, col %d: Number %s out of bounds\n", root->line, root->col, root->value);
            }
        }

        root->type_anoted = "double";

        free(aux);
        aux = NULL;
    }
    else if (strcmp(root->symbol, "StrLit") == 0)
    {
        root->type_anoted = "String";
    }
}