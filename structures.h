#ifndef STRUCTURES_H
#define STRUCTURES_H

// this is a token, with a symbol (ID, FUNC, VARDECL etc) and with an optional value (for intlit, strlit etc)
typedef struct token {
	char *symbol;
	char *value;
	int column, line;
} token_t;

// a node has:
//		token [optional]
//		type  [from enum]
// 		children [pointer to the first child (list of nodes associated with this node)]
// 		next	 [pointer to the next child of the same father]
typedef struct node {
	int literal;
	token_t *token;
	char *noted_type;
	char *noted_params;
	struct node *children;
	struct node *next;
	int line, column;
	int isCallFunction;

	int printFuncParamsInNode;
	int printFuncParams;

	int invalidFuncDecl;
	
	char *funcTabName;
} node_t;

typedef struct elem {
	
	char *id;
	char *params;
	char *type;
	int tparam;
	int hits; // # of times this element was accessed for reading
	int column, line;
	int isDeclared; // boolean -> when element is created, this is 0. but when we find VarDecl when checking tree, this turns to 1. Elements found with this boolean set to 0 must not be considered. 
	int isFunction;
	
	struct elem *next;
	
} elem_t;


typedef struct symtab {
	char *name; // table name
	char *params;
	
	struct symtab *next;
	struct elem   *first_element;
} symtab_t;

typedef struct _s9
{
	char *id;
} is_write_statement;

typedef enum
{
	d_write
} disc_write;

typedef struct _s8
{
	disc_write disc_d;
	union
	{
		is_write_statement *u_write_statement;
	} data_statement;
} is_statement;

typedef struct _s7
{
	is_statement *val;
	struct _s7 *next;
} is_statement_list;

typedef struct _s4
{
	char *id;
} is_integer_dec;

typedef struct _s5
{
	char *id;
} is_character_dec;

typedef struct _s6
{
	char *id;
} is_double_dec;

typedef enum
{
	d_integer,
	d_character,
	d_double
} disc_vardec;

typedef struct _s3
{
	disc_vardec disc_d;
	union
	{ /* NOTA! Esta parte pode simplificar para ficar apenas um campo a char*. Mantemos assim para mostrar os metodo "comum"*/
		is_integer_dec *u_integer_dec;
		is_character_dec *u_character_dec;
		is_double_dec *u_double_dec;
	} data_vardec;
} is_vardec;

typedef struct _s2
{
	is_vardec *val;
	struct _s2 *next;
} is_vardec_list;

typedef struct _s1
{
	is_vardec_list *vlist;
	is_statement_list *slist;
} is_program;

#endif