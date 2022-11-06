/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1



/* First part of user prologue.  */
#line 1 "jucompiler.y"

	/*
		João Filipe Carnide de Jesus Nunes		2017247442
	*/
	
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdarg.h>

	typedef enum {
		node_raiz,
		node_var, 
		node_metodos, 
		node_statements, 
		node_operators, 
		node_terminais, 
		node_id
	} node_type;

	typedef struct node * no;
	typedef struct node {
		char * valor;
		char * s_type;
		node_type type;
		int num_node;
		no pai;
		no filho;
		no irmao;
	} node;

	int conta;
	no raiz;
	no aux;
	int flag_error = 0;
	extern int flag;

	int yylex(void);
    void yyerror(const char *s);

	no cria_node(node_type type, char * valor, char * s_type) {
		no novo = malloc(sizeof(node));
		novo->s_type = (char *)malloc(1 + strlen(s_type) * sizeof(char));
		strcpy(novo->s_type, s_type);
		novo->valor = (char *)malloc(1 + strlen(valor) * sizeof(char));
		strcpy(novo->valor, valor);
		novo->type = type;
		novo->num_node = 0;
		novo->pai = NULL;
		novo->filho = NULL;
		novo->irmao = NULL;
		return novo;
	}

	void adicionar_node(no pai, no novo) {
		if (novo == NULL) {
			return ;
		}
		pai->filho = novo;
		pai->num_node++;
		novo->pai = pai;
	}

	void adicionar_irmao(no node_a, no node_b) {
		if (node_a == NULL || node_b == NULL) {
			return ;
		}
		no aux;
		aux = node_a;
		while (aux->irmao != NULL) {
			aux = aux->irmao;
		}
		aux->irmao = node_b;
		if (node_a->pai != NULL) {
			node_b->pai = node_a->pai;
			node_b->pai->num_node++;
		}
	}

	int conta_irmaos(no raiz) {
		int conta = 0;
		no aux;
		aux = raiz;
		while (aux != NULL) {
			aux = aux->irmao;
			conta++;
		}
		return conta;
	}

	void arvore(no raiz, int pontos) {
		if (raiz == NULL) {
			return ;
		}
		int i = 0;
		no aux;
		if (raiz->type == node_raiz) {
			printf("%s\n", raiz->s_type);
		}
		else {
			while (i < pontos) {
				printf("..");
				i++;
			}
			if (strcmp(raiz->valor,"") != 0) {
				printf("%s(%s)\n", raiz->s_type, raiz->valor);
			}
			else {
				printf("%s\n", raiz->s_type);
			}
		}
		aux = raiz->filho;
		while (aux != NULL) {
			no aux_free = aux;
			arvore(aux, pontos+1);
			aux = aux->irmao;
			free(aux_free->valor);
			free(aux_free->s_type);
			free(aux_free);
		}
	}

#line 194 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    AND = 258,                     /* AND  */
    ASSIGN = 259,                  /* ASSIGN  */
    STAR = 260,                    /* STAR  */
    COMMA = 261,                   /* COMMA  */
    DIV = 262,                     /* DIV  */
    EQ = 263,                      /* EQ  */
    GE = 264,                      /* GE  */
    GT = 265,                      /* GT  */
    LBRACE = 266,                  /* LBRACE  */
    LE = 267,                      /* LE  */
    LPAR = 268,                    /* LPAR  */
    LSQ = 269,                     /* LSQ  */
    LT = 270,                      /* LT  */
    MINUS = 271,                   /* MINUS  */
    MOD = 272,                     /* MOD  */
    NE = 273,                      /* NE  */
    NOT = 274,                     /* NOT  */
    OR = 275,                      /* OR  */
    PLUS = 276,                    /* PLUS  */
    RBRACE = 277,                  /* RBRACE  */
    RPAR = 278,                    /* RPAR  */
    RSQ = 279,                     /* RSQ  */
    SEMICOLON = 280,               /* SEMICOLON  */
    ARROW = 281,                   /* ARROW  */
    LSHIFT = 282,                  /* LSHIFT  */
    RSHIFT = 283,                  /* RSHIFT  */
    XOR = 284,                     /* XOR  */
    CLASS = 285,                   /* CLASS  */
    DOTLENGTH = 286,               /* DOTLENGTH  */
    ELSE = 287,                    /* ELSE  */
    IF = 288,                      /* IF  */
    PRINT = 289,                   /* PRINT  */
    PARSEINT = 290,                /* PARSEINT  */
    PUBLIC = 291,                  /* PUBLIC  */
    RETURN = 292,                  /* RETURN  */
    STATIC = 293,                  /* STATIC  */
    STRING = 294,                  /* STRING  */
    VOID = 295,                    /* VOID  */
    WHILE = 296,                   /* WHILE  */
    INT = 297,                     /* INT  */
    DOUBLE = 298,                  /* DOUBLE  */
    BOOL = 299,                    /* BOOL  */
    RESERVED = 300,                /* RESERVED  */
    ID = 301,                      /* ID  */
    INTLIT = 302,                  /* INTLIT  */
    REALLIT = 303,                 /* REALLIT  */
    BOOLLIT = 304,                 /* BOOLLIT  */
    STRLIT = 305                   /* STRLIT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define AND 258
#define ASSIGN 259
#define STAR 260
#define COMMA 261
#define DIV 262
#define EQ 263
#define GE 264
#define GT 265
#define LBRACE 266
#define LE 267
#define LPAR 268
#define LSQ 269
#define LT 270
#define MINUS 271
#define MOD 272
#define NE 273
#define NOT 274
#define OR 275
#define PLUS 276
#define RBRACE 277
#define RPAR 278
#define RSQ 279
#define SEMICOLON 280
#define ARROW 281
#define LSHIFT 282
#define RSHIFT 283
#define XOR 284
#define CLASS 285
#define DOTLENGTH 286
#define ELSE 287
#define IF 288
#define PRINT 289
#define PARSEINT 290
#define PUBLIC 291
#define RETURN 292
#define STATIC 293
#define STRING 294
#define VOID 295
#define WHILE 296
#define INT 297
#define DOUBLE 298
#define BOOL 299
#define RESERVED 300
#define ID 301
#define INTLIT 302
#define REALLIT 303
#define BOOLLIT 304
#define STRLIT 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 124 "jucompiler.y"


#line 352 "y.tab.c"

/* Copy the first part of user declarations.  */
#line 1 "jucompiler.y"

    /*
    Miguel Filipe de Andrade Sergio 2020225643
    Filipe David Amado Mendes 2020218797
    */

    #include "functions.h"
    extern int flag;
    int flag_error = 0;
    node_t root;
    node_t aux;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 14 "jucompiler.y"
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_AND = 3,                        /* AND  */
  YYSYMBOL_ASSIGN = 4,                     /* ASSIGN  */
  YYSYMBOL_STAR = 5,                       /* STAR  */
  YYSYMBOL_COMMA = 6,                      /* COMMA  */
  YYSYMBOL_DIV = 7,                        /* DIV  */
  YYSYMBOL_EQ = 8,                         /* EQ  */
  YYSYMBOL_GE = 9,                         /* GE  */
  YYSYMBOL_GT = 10,                        /* GT  */
  YYSYMBOL_LBRACE = 11,                    /* LBRACE  */
  YYSYMBOL_LE = 12,                        /* LE  */
  YYSYMBOL_LPAR = 13,                      /* LPAR  */
  YYSYMBOL_LSQ = 14,                       /* LSQ  */
  YYSYMBOL_LT = 15,                        /* LT  */
  YYSYMBOL_MINUS = 16,                     /* MINUS  */
  YYSYMBOL_MOD = 17,                       /* MOD  */
  YYSYMBOL_NE = 18,                        /* NE  */
  YYSYMBOL_NOT = 19,                       /* NOT  */
  YYSYMBOL_OR = 20,                        /* OR  */
  YYSYMBOL_PLUS = 21,                      /* PLUS  */
  YYSYMBOL_RBRACE = 22,                    /* RBRACE  */
  YYSYMBOL_RPAR = 23,                      /* RPAR  */
  YYSYMBOL_RSQ = 24,                       /* RSQ  */
  YYSYMBOL_SEMICOLON = 25,                 /* SEMICOLON  */
  YYSYMBOL_ARROW = 26,                     /* ARROW  */
  YYSYMBOL_LSHIFT = 27,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 28,                    /* RSHIFT  */
  YYSYMBOL_XOR = 29,                       /* XOR  */
  YYSYMBOL_CLASS = 30,                     /* CLASS  */
  YYSYMBOL_DOTLENGTH = 31,                 /* DOTLENGTH  */
  YYSYMBOL_ELSE = 32,                      /* ELSE  */
  YYSYMBOL_IF = 33,                        /* IF  */
  YYSYMBOL_PRINT = 34,                     /* PRINT  */
  YYSYMBOL_PARSEINT = 35,                  /* PARSEINT  */
  YYSYMBOL_PUBLIC = 36,                    /* PUBLIC  */
  YYSYMBOL_RETURN = 37,                    /* RETURN  */
  YYSYMBOL_STATIC = 38,                    /* STATIC  */
  YYSYMBOL_STRING = 39,                    /* STRING  */
  YYSYMBOL_VOID = 40,                      /* VOID  */
  YYSYMBOL_WHILE = 41,                     /* WHILE  */
  YYSYMBOL_INT = 42,                       /* INT  */
  YYSYMBOL_DOUBLE = 43,                    /* DOUBLE  */
  YYSYMBOL_BOOL = 44,                      /* BOOL  */
  YYSYMBOL_RESERVED = 45,                  /* RESERVED  */
  YYSYMBOL_ID = 46,                        /* ID  */
  YYSYMBOL_INTLIT = 47,                    /* INTLIT  */
  YYSYMBOL_REALLIT = 48,                   /* REALLIT  */
  YYSYMBOL_BOOLLIT = 49,                   /* BOOLLIT  */
  YYSYMBOL_STRLIT = 50,                    /* STRLIT  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_Program = 52,                   /* Program  */
  YYSYMBOL_ProgramScript = 53,             /* ProgramScript  */
  YYSYMBOL_MethodDecl = 54,                /* MethodDecl  */
  YYSYMBOL_FieldDecl = 55,                 /* FieldDecl  */
  YYSYMBOL_FieldDecl2 = 56,                /* FieldDecl2  */
  YYSYMBOL_Type = 57,                      /* Type  */
  YYSYMBOL_MethodHeader = 58,              /* MethodHeader  */
  YYSYMBOL_MethodHeader2 = 59,             /* MethodHeader2  */
  YYSYMBOL_FormalParams = 60,              /* FormalParams  */
  YYSYMBOL_FormalParams2 = 61,             /* FormalParams2  */
  YYSYMBOL_MethodBody = 62,                /* MethodBody  */
  YYSYMBOL_MethodBody2 = 63,               /* MethodBody2  */
  YYSYMBOL_VarDecl = 64,                   /* VarDecl  */
  YYSYMBOL_VarDecl2 = 65,                  /* VarDecl2  */
  YYSYMBOL_Statement = 66,                 /* Statement  */
  YYSYMBOL_Statement2 = 67,                /* Statement2  */
  YYSYMBOL_ExprReturn = 68,                /* ExprReturn  */
  YYSYMBOL_Statement3 = 69,                /* Statement3  */
  YYSYMBOL_StatementPrint = 70,            /* StatementPrint  */
  YYSYMBOL_MethodInvocation = 71,          /* MethodInvocation  */
  YYSYMBOL_MethodInvocation2 = 72,         /* MethodInvocation2  */
  YYSYMBOL_MethodInvocationExpr = 73,      /* MethodInvocationExpr  */
  YYSYMBOL_Assignment = 74,                /* Assignment  */
  YYSYMBOL_ParseArgs = 75,                 /* ParseArgs  */
  YYSYMBOL_Expr = 76,                      /* Expr  */
  YYSYMBOL_ExprOperations = 77,            /* ExprOperations  */
  YYSYMBOL_Expr2 = 78,                     /* Expr2  */
  YYSYMBOL_ExprLit = 79                    /* ExprLit  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 229 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   406

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNRULES -- Number of states.  */
#define YYNSTATES  176

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    12,    15,    18,    19,    24,    31,
      34,    38,    39,    41,    43,    45,    51,    57,    59,    60,
      64,    69,    74,    75,    79,    82,    85,    86,    91,    95,
      96,   100,   106,   114,   120,   124,   127,   133,   136,   138,
     139,   142,   143,   145,   147,   149,   150,   152,   154,   159,
     164,   167,   168,   172,   173,   177,   185,   190,   192,   194,
     198,   202,   206,   210,   214,   218,   222,   226,   230,   234,
     238,   242,   246,   250,   254,   258,   261,   264,   267,   271,
     275,   277,   279,   282,   284,   286,   288,   290,   292
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,     8,    46,     9,    54,    13,    -1,    55,
      54,    -1,    56,    54,    -1,    19,    54,    -1,    -1,    15,
      16,    59,    63,    -1,    15,    16,    58,    46,    57,    19,
      -1,     1,    19,    -1,    22,    46,    57,    -1,    -1,     4,
      -1,     6,    -1,     5,    -1,    58,    46,     3,    60,    20,
      -1,     7,    46,     3,    60,    20,    -1,    61,    -1,    -1,
      58,    46,    62,    -1,    21,    23,    24,    46,    -1,    22,
      58,    46,    62,    -1,    -1,     9,    64,    13,    -1,    67,
      64,    -1,    65,    64,    -1,    -1,    58,    46,    66,    19,
      -1,    22,    46,    66,    -1,    -1,     9,    69,    13,    -1,
      25,     3,    77,    20,    67,    -1,    25,     3,    77,    20,
      67,    17,    67,    -1,    18,     3,    77,    20,    67,    -1,
      26,    68,    19,    -1,    70,    19,    -1,    27,     3,    71,
      20,    19,    -1,     1,    19,    -1,    77,    -1,    -1,    67,
      69,    -1,    -1,    72,    -1,    75,    -1,    76,    -1,    -1,
      77,    -1,    50,    -1,    46,     3,    73,    20,    -1,    46,
       3,     1,    20,    -1,    77,    74,    -1,    -1,    22,    77,
      74,    -1,    -1,    46,    11,    77,    -1,    14,     3,    46,
      23,    77,    24,    20,    -1,    14,     3,     1,    20,    -1,
      75,    -1,    78,    -1,    78,    28,    78,    -1,    78,    29,
      78,    -1,    78,    30,    78,    -1,    78,    31,    78,    -1,
      78,    32,    78,    -1,    78,    33,    78,    -1,    78,    34,
      78,    -1,    78,    35,    78,    -1,    78,    36,    78,    -1,
      78,    37,    78,    -1,    78,    38,    78,    -1,    78,    39,
      78,    -1,    78,    40,    78,    -1,    78,    41,    78,    -1,
      78,    42,    78,    -1,    78,    43,    78,    -1,    29,    78,
      -1,    28,    78,    -1,    44,    78,    -1,     3,    77,    20,
      -1,     3,     1,    20,    -1,    79,    -1,    46,    -1,    46,
      45,    -1,    80,    -1,    72,    -1,    76,    -1,    47,    -1,
      48,    -1,    49,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   155,   155,   165,   166,   168,   170,   173,   178,   193,
     196,   197,   201,   202,   203,   206,   212,   221,   222,   225,
     230,   236,   237,   244,   248,   249,   256,   260,   277,   278,
     282,   290,   302,   327,   337,   339,   340,   342,   345,   346,
     355,   356,   359,   360,   361,   362,   365,   366,   369,   373,
     377,   378,   382,   383,   392,   398,   402,   406,   407,   410,
     413,   416,   419,   422,   425,   428,   431,   434,   437,   440,
     443,   446,   449,   452,   455,   458,   460,   462,   464,   465,
     467,   468,   469,   471,   474,   475,   478,   479,   480
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "AND", "ASSIGN",
  "STAR", "COMMA", "DIV", "EQ", "GE", "GT", "LBRACE", "LE", "LPAR", "LSQ",
  "LT", "MINUS", "MOD", "NE", "NOT", "OR", "PLUS", "RBRACE", "RPAR", "RSQ",
  "SEMICOLON", "ARROW", "LSHIFT", "RSHIFT", "XOR", "CLASS", "DOTLENGTH",
  "ELSE", "IF", "PRINT", "PARSEINT", "PUBLIC", "RETURN", "STATIC",
  "STRING", "VOID", "WHILE", "INT", "DOUBLE", "BOOL", "RESERVED", "ID",
  "INTLIT", "REALLIT", "BOOLLIT", "STRLIT", "$accept", "Program",
  "ProgramScript", "MethodDecl", "FieldDecl", "FieldDecl2", "Type",
  "MethodHeader", "MethodHeader2", "FormalParams", "FormalParams2",
  "MethodBody", "MethodBody2", "VarDecl", "VarDecl2", "Statement",
  "Statement2", "ExprReturn", "Statement3", "StatementPrint",
  "MethodInvocation", "MethodInvocation2", "MethodInvocationExpr",
  "Assignment", "ParseArgs", "Expr", "ExprOperations", "Expr2", "ExprLit", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

#define YYPACT_NINF (-41)

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     2,     2,     0,     4,     6,     2,
       3,     0,     1,     1,     1,     5,     5,     1,     0,     3,
       4,     4,     0,     3,     2,     2,     0,     4,     3,     0,
       3,     5,     7,     5,     3,     2,     5,     2,     1,     0,
       2,     0,     1,     1,     1,     0,     1,     1,     4,     4,
       2,     0,     3,     0,     3,     7,     4,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     3,     3,
       1,     1,     2,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     9,     0,     5,     2,     3,     4,    12,    14,
      13,     0,     0,     0,     0,    11,     0,     7,    18,    18,
       0,     0,     0,     0,     0,     0,     0,    39,     0,     0,
       0,     0,     0,     0,     0,    42,    43,    44,     0,     0,
       0,    17,     0,    11,     8,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,    86,    87,    88,     0,
      84,    57,    85,    38,    58,    80,    83,     0,     0,     0,
      29,    23,    25,    24,    35,     0,    22,    16,    15,    10,
      40,    30,     0,     0,     0,     0,     0,     0,    81,    76,
      75,    77,    82,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,     0,    46,     0,     0,    53,    54,     0,     0,     0,
       0,    19,    56,     0,     0,     0,    79,    78,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,     0,    49,    48,     0,    50,    29,
      27,    20,     0,     0,    33,    31,    36,    53,    28,    22,
       0,     0,    52,    21,    55,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    10,    11,    31,    40,    23,    50,    51,
     131,    27,    41,    42,   128,    43,    69,    57,    44,   121,
      70,   124,   158,    71,    72,    73,    74,    75,    76
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -39
static const yytype_int16 yypact[] =
{
     -20,   -40,    12,     4,   -41,    73,     6,    73,    40,    11,
      73,    73,   -41,   -41,    15,   -41,   -41,   -41,    -7,   -41,
     -41,   -41,     7,    54,    83,    34,    27,   -41,   122,    51,
     122,    76,    78,   134,    94,    98,    99,   202,   102,     1,
      70,   109,    27,    27,   101,   -41,   -41,   -41,   105,    87,
     111,   -41,   118,   113,   -41,   -41,   134,   115,   202,   178,
       2,   141,   217,   217,   217,    41,   -41,   -41,   -41,   116,
     -41,   -41,   -41,   -41,   264,   -41,   -41,   202,   202,   104,
     137,   -41,   -41,   -41,   -41,   123,   143,   -41,   -41,   -41,
     -41,   -41,   117,   -41,   132,   -41,   135,   149,   147,   150,
      -5,   -41,   -41,   -41,   -41,   -41,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   151,   -41,   154,   155,   173,   138,   156,   139,
      33,   -41,   171,   158,   -41,   202,   -41,   -41,   316,   -41,
     -41,   365,   378,   378,   378,   378,    39,   -41,   365,   291,
      39,    97,    97,   341,   171,   -41,   -41,   202,   -41,   137,
     -41,   -41,   140,   160,   -41,   169,   -41,   173,   -41,   143,
     171,   172,   -41,   -41,   -41,   -41
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     9,     6,     0,     2,     4,     5,     0,    13,
      14,    12,     0,     0,     0,    10,     0,     7,    17,     0,
      17,     0,     0,     0,     0,     0,     0,    40,     0,     0,
       0,     0,     0,     0,     0,    43,    44,    45,     0,     0,
       0,    18,    10,     0,     8,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,    86,    87,    88,     0,
      84,    57,    85,    41,    58,    80,    83,     0,     0,     0,
      28,    23,    26,    25,    35,     0,    21,    16,    11,    15,
      39,    30,     0,    47,     0,    46,     0,     0,     0,     0,
      81,    76,    77,    75,    82,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,     0,     0,    52,     0,     0,     0,
       0,    19,     0,     0,    56,     0,    79,    78,    64,    61,
      62,    69,    70,    71,    72,    73,    60,    63,    74,    65,
      59,    67,    68,    66,     0,    49,    48,     0,    51,    28,
      27,    20,     0,    31,    36,     0,    33,    52,    29,    21,
       0,     0,    53,    22,    32,    55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -41,   -41,    56,   -41,   -41,   146,    -1,   -41,   170,   -41,
      32,   -41,     8,   -41,    43,   -32,   153,   -41,   -41,   -41,
     -26,   -41,    36,   -24,   -22,   -36,   -27,   -41,   -41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     9,    10,    11,    31,    40,    23,    50,    51,
     131,    27,    41,    42,   128,    43,    57,    69,    44,    94,
      70,   125,   158,    71,    72,    73,    74,    75,    76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    56,    46,    96,    47,    78,     3,    45,    79,    46,
       1,    47,     4,    22,    79,     5,    45,    45,    46,    46,
      47,    47,    92,    95,    56,    99,   104,    49,    32,    49,
      45,    12,    46,    15,    47,   101,   102,   103,    33,    24,
      29,   122,   123,   126,   107,    78,   108,    30,    97,   -24,
      82,    83,   -42,    25,    79,    18,   115,    19,    20,    21,
      34,    35,    36,    13,    37,    26,    16,    17,    38,    19,
      20,    21,   104,    39,     6,    19,    20,    21,    14,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -3,    28,    52,     7,   165,
     163,    54,   107,    55,   108,   124,    45,    58,    46,     8,
      47,    59,    60,   114,   115,    77,    80,    61,   118,    85,
      62,   167,   166,    63,    29,    64,    84,   -50,    45,   162,
      46,    81,    47,    86,    87,    32,    89,    91,   174,    36,
     132,   105,    98,   127,    45,    33,    46,   129,    47,   130,
      65,    66,    67,    68,    61,   133,   -38,    62,   134,   -42,
      63,    48,    64,   135,    19,    20,    21,    34,    35,    36,
     136,    37,    32,   137,   154,    38,    36,   155,   156,   157,
      39,   160,    33,   164,   159,   161,   169,    65,    66,    67,
      68,    61,   170,   171,    62,   175,   -42,    63,    88,    64,
      53,   173,   168,   172,    34,    35,    36,     0,    37,    90,
       0,     0,    38,    36,     0,    61,     0,    39,    62,     0,
       0,    63,     0,    64,    65,    66,    67,    68,    93,     0,
      61,     0,     0,    62,     0,     0,    63,    36,    64,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    66,
      67,    68,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,    66,    67,    68,   106,     0,   107,
       0,   108,   109,   110,   111,     0,   112,     0,     0,   113,
     114,   115,   116,     0,   117,   118,     0,     0,     0,     0,
       0,   119,   120,   121,   106,     0,   107,     0,   108,   109,
     110,   111,     0,   112,     0,     0,   113,   114,   115,   116,
       0,     0,   118,     0,     0,     0,     0,     0,   119,   120,
     121,   107,     0,   108,   109,   110,   111,     0,   112,     0,
       0,   113,   114,   115,   116,     0,     0,   118,     0,     0,
       0,     0,     0,   119,   120,   121,   107,     0,   108,   109,
     110,   111,     0,   112,     0,     0,   113,   114,   115,   116,
       0,     0,   118,     0,     0,     0,     0,     0,   119,   120,
     107,     0,   108,     0,   110,   111,     0,   112,     0,     0,
     113,   114,   115,   107,     0,   108,   118,     0,     0,     0,
       0,     0,   119,   120,   114,   115,     0,     0,     0,   118,
       0,     0,     0,     0,     0,   119,   120
};

static const yytype_int16 yycheck[] =
{
      26,    33,    26,     1,    26,     4,    46,    33,    13,    33,
      30,    33,     0,    14,    13,    11,    42,    43,    42,    43,
      42,    43,    58,    59,    56,    61,    31,    28,     1,    30,
      56,    25,    56,    22,    56,    62,    63,    64,    11,    46,
       6,    77,    78,    79,     5,     4,     7,    13,    46,    22,
      42,    43,    25,    46,    13,    40,    17,    42,    43,    44,
      33,    34,    35,     7,    37,    11,    10,    11,    41,    42,
      43,    44,    31,    46,     1,    42,    43,    44,    38,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    22,    13,    46,    25,   135,
     132,    25,     5,    25,     7,     1,   132,    13,   132,    36,
     132,    13,    13,    16,    17,    13,    46,    13,    21,    14,
      16,   157,   154,    19,     6,    21,    25,    23,   154,   130,
     154,    22,   154,    46,    23,     1,    23,    22,   170,    35,
      23,    25,     1,     6,   170,    11,   170,    24,   170,     6,
      46,    47,    48,    49,    13,    23,    22,    16,    23,    25,
      19,    39,    21,    14,    42,    43,    44,    33,    34,    35,
      23,    37,     1,    23,    23,    41,    35,    23,    23,     6,
      46,    25,    11,    25,    46,    46,    46,    46,    47,    48,
      49,    13,    32,    24,    16,    23,    25,    19,    52,    21,
      30,   169,   159,   167,    33,    34,    35,    -1,    37,    56,
      -1,    -1,    41,    35,    -1,    13,    -1,    46,    16,    -1,
      -1,    19,    -1,    21,    46,    47,    48,    49,    50,    -1,
      13,    -1,    -1,    16,    -1,    -1,    19,    35,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,     3,    -1,     5,
      -1,     7,     8,     9,    10,    -1,    12,    -1,    -1,    15,
      16,    17,    18,    -1,    20,    21,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,     3,    -1,     5,    -1,     7,     8,
       9,    10,    -1,    12,    -1,    -1,    15,    16,    17,    18,
      -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,     5,    -1,     7,     8,     9,    10,    -1,    12,    -1,
      -1,    15,    16,    17,    18,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,     5,    -1,     7,     8,
       9,    10,    -1,    12,    -1,    -1,    15,    16,    17,    18,
      -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    27,    28,
       5,    -1,     7,    -1,     9,    10,    -1,    12,    -1,    -1,
      15,    16,    17,     5,    -1,     7,    21,    -1,    -1,    -1,
      -1,    -1,    27,    28,    16,    17,    -1,    -1,    -1,    21,
      -1,    -1,    -1,    -1,    -1,    27,    28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    52,    46,     0,    11,     1,    25,    36,    53,
      54,    55,    25,    53,    38,    22,    53,    53,    40,    42,
      43,    44,    57,    58,    46,    46,    11,    62,    13,     6,
      13,    56,     1,    11,    33,    34,    35,    37,    41,    46,
      57,    63,    64,    66,    69,    71,    74,    75,    39,    57,
      59,    60,    46,    59,    25,    25,    66,    67,    13,    13,
      13,    13,    16,    19,    21,    46,    47,    48,    49,    68,
      71,    74,    75,    76,    77,    78,    79,    13,     4,    13,
      46,    22,    63,    63,    25,    14,    46,    23,    56,    23,
      67,    22,    76,    50,    70,    76,     1,    46,     1,    76,
      46,    77,    77,    77,    31,    25,     3,     5,     7,     8,
       9,    10,    12,    15,    16,    17,    18,    20,    21,    27,
      28,    29,    76,    76,     1,    72,    76,     6,    65,    24,
       6,    61,    23,    23,    23,    14,    23,    23,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    23,    23,    23,     6,    73,    46,
      25,    46,    57,    66,    25,    76,    66,    76,    65,    46,
      32,    24,    73,    61,    66,    23
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     0,     2,     2,     2,     4,     6,     2,
       0,     3,     1,     1,     1,     5,     5,     0,     1,     3,
       4,     0,     4,     3,     0,     2,     2,     4,     0,     3,
       3,     5,     7,     5,     3,     2,     5,     2,     0,     2,
       0,     1,     0,     1,     1,     1,     1,     1,     4,     4,
       0,     2,     0,     3,     3,     7,     4,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     3,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     1
};

/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: CLASS ID LBRACE ProgramScript RBRACE  */
#line 155 "jucompiler.y"
                                                                                        {raiz = cria_node(node_raiz, "", "Program");
																	aux = cria_node(node_id, (yyvsp[-3].id), "Id");
																	adicionar_node(raiz, aux);
																	adicionar_irmao(aux, (yyvsp[-1].node));
																	(yyval.node) = raiz;
																	if (flag == 2 && flag_error == 0) {
																		arvore((yyval.node), 0);
																	}}
#line 1578 "y.tab.c"
    break;

  case 3: /* ProgramScript: %empty  */
#line 165 "jucompiler.y"
                                                                                                                {(yyval.node) = NULL;}
#line 1584 "y.tab.c"
    break;

  case 4: /* ProgramScript: MethodDecl ProgramScript  */
#line 166 "jucompiler.y"
                                                                                                                {(yyval.node) = (yyvsp[-1].node);
																	adicionar_irmao((yyval.node), (yyvsp[0].node));}
#line 1591 "y.tab.c"
    break;

  case 5: /* ProgramScript: FieldDecl ProgramScript  */
#line 168 "jucompiler.y"
                                                                                                                {(yyval.node) = (yyvsp[-1].node);
																	adicionar_irmao((yyval.node), (yyvsp[0].node));}
#line 1598 "y.tab.c"
    break;

  case 6: /* ProgramScript: SEMICOLON ProgramScript  */
#line 170 "jucompiler.y"
                                                                                                                {(yyval.node) = (yyvsp[0].node);}
#line 1604 "y.tab.c"
    break;

  case 7: /* MethodDecl: PUBLIC STATIC MethodHeader MethodBody  */
#line 173 "jucompiler.y"
                                                                                        {(yyval.node) = cria_node(node_metodos, "", "MethodDecl");
																	adicionar_node((yyval.node), (yyvsp[-1].node));
																	adicionar_irmao((yyvsp[-1].node), (yyvsp[0].node));}
#line 1612 "y.tab.c"
    break;

  case 8: /* FieldDecl: PUBLIC STATIC Type ID FieldDecl2 SEMICOLON  */
#line 178 "jucompiler.y"
                                                                                        {(yyval.node) = cria_node(node_var, "", "FieldDecl");
																	adicionar_node((yyval.node), (yyvsp[-3].node));
																	adicionar_irmao((yyvsp[-3].node), cria_node(node_id, (yyvsp[-2].id), "Id"));
																	if ((yyvsp[-1].node) != NULL){
																		aux = (yyvsp[-1].node);
																		while (aux != NULL) {
																			no aux1 = cria_node(node_var, "", "FieldDecl");
																			no aux2 = cria_node((yyvsp[-3].node)->type, (yyvsp[-3].node)->valor, (yyvsp[-3].node)->s_type);
																			adicionar_node(aux1, aux2);
																			adicionar_irmao(aux2, cria_node(node_id, aux->valor, "Id"));
																			adicionar_irmao((yyval.node), aux1);
																			aux = aux->irmao;
																		}
																		free(aux);
																	}}
#line 1632 "y.tab.c"
    break;

  case 9: /* FieldDecl: error SEMICOLON  */
#line 193 "jucompiler.y"
                                                                                                                        {(yyval.node) = NULL; flag_error = 1;}
#line 1638 "y.tab.c"
    break;

  case 10: /* FieldDecl2: %empty  */
#line 196 "jucompiler.y"
                                                                                                                        {(yyval.node) = NULL;}
#line 1644 "y.tab.c"
    break;

  case 11: /* FieldDecl2: COMMA ID FieldDecl2  */
#line 197 "jucompiler.y"
                                                                                                                        {(yyval.node) = cria_node(node_id, (yyvsp[-1].id), "Id");
																	adicionar_irmao((yyval.node), (yyvsp[0].node));}
#line 1651 "y.tab.c"
    break;

  case 12: /* Type: BOOL  */
#line 201 "jucompiler.y"
                                                                                                                        {(yyval.node) = cria_node(node_terminais, "", "Bool");}
#line 1657 "y.tab.c"
    break;

  case 13: /* Type: INT  */
#line 202 "jucompiler.y"
                                                                                                                                        {(yyval.node) = cria_node(node_terminais, "", "Int");}
#line 1663 "y.tab.c"
    break;

  case 14: /* Type: DOUBLE  */
#line 203 "jucompiler.y"
                                                                                                                                {(yyval.node) = cria_node(node_terminais, "", "Double");}
#line 1669 "y.tab.c"
    break;

  case 15: /* MethodHeader: Type ID LPAR MethodHeader2 RPAR  */
#line 206 "jucompiler.y"
                                                                                        {(yyval.node) = cria_node(node_metodos, "", "MethodHeader");
																	adicionar_node((yyval.node),(yyvsp[-4].node));
																	adicionar_irmao((yyvsp[-4].node), cria_node(node_id, (yyvsp[-3].id), "Id"));
																	aux = cria_node(node_metodos, "", "MethodParams");
																	adicionar_irmao((yyvsp[-4].node), aux);
																	adicionar_node(aux, (yyvsp[-1].node));}
#line 1680 "y.tab.c"
    break;

  case 16: /* MethodHeader: VOID ID LPAR MethodHeader2 RPAR  */
#line 212 "jucompiler.y"
                                                                                                        {(yyval.node) = cria_node(node_metodos, "", "MethodHeader");
																	aux = cria_node(node_terminais, "", "Void");
																	adicionar_node((yyval.node), aux);
																	adicionar_irmao(aux, cria_node(node_id, (yyvsp[-3].id), "Id"));
																	no aux2 = cria_node(node_metodos, "", "MethodParams");
																	adicionar_irmao(aux, aux2);
																	adicionar_node(aux2, (yyvsp[-1].node));}
#line 1692 "y.tab.c"
    break;

  case 17: /* MethodHeader2: %empty  */
#line 221 "jucompiler.y"
                                                                                                                {(yyval.node) = NULL;}
#line 1698 "y.tab.c"
    break;

  case 18: /* MethodHeader2: FormalParams  */
#line 222 "jucompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 1704 "y.tab.c"
    break;

  case 19: /* FormalParams: Type ID FormalParams2  */
#line 225 "jucompiler.y"
                                                                                                {(yyval.node) = cria_node(node_metodos, "", "ParamDecl");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	aux = cria_node(node_id, (yyvsp[-1].id), "Id");
																	adicionar_irmao((yyvsp[-2].node), aux);
																	adicionar_irmao((yyval.node), (yyvsp[0].node));}
#line 1714 "y.tab.c"
    break;

  case 20: /* FormalParams: STRING LSQ RSQ ID  */
#line 230 "jucompiler.y"
                                                                                                                        {(yyval.node) = cria_node(node_metodos, "", "ParamDecl");
																	aux = cria_node(node_metodos, "", "StringArray");
																	adicionar_node((yyval.node), aux);
																	adicionar_irmao(aux, cria_node(node_id, (yyvsp[0].id), "Id"));}
#line 1723 "y.tab.c"
    break;

  case 21: /* FormalParams2: %empty  */
#line 236 "jucompiler.y"
                                                                                                                {(yyval.node) = NULL;}
#line 1729 "y.tab.c"
    break;

  case 22: /* FormalParams2: COMMA Type ID FormalParams2  */
#line 237 "jucompiler.y"
                                                                                                        {(yyval.node) = cria_node(node_metodos, "", "ParamDecl");
																	aux = cria_node(node_id, (yyvsp[-1].id), "Id");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), aux);
																	adicionar_irmao((yyval.node), (yyvsp[0].node));}
#line 1739 "y.tab.c"
    break;

  case 23: /* MethodBody: LBRACE MethodBody2 RBRACE  */
#line 244 "jucompiler.y"
                                                                                                        {(yyval.node) = cria_node(node_metodos, "", "MethodBody");
																	adicionar_node((yyval.node), (yyvsp[-1].node));}
#line 1746 "y.tab.c"
    break;

  case 24: /* MethodBody2: %empty  */
#line 248 "jucompiler.y"
                                                                                                                {(yyval.node) = NULL;}
#line 1752 "y.tab.c"
    break;

  case 25: /* MethodBody2: Statement MethodBody2  */
#line 249 "jucompiler.y"
                                                                                                                {if ((yyvsp[-1].node) != NULL){
																		(yyval.node) = (yyvsp[-1].node);
																		adicionar_irmao((yyval.node), (yyvsp[0].node));
																		}
																	else {
																		(yyval.node) = (yyvsp[0].node);
																	}}
#line 1764 "y.tab.c"
    break;

  case 26: /* MethodBody2: VarDecl MethodBody2  */
#line 256 "jucompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[-1].node);
																	adicionar_irmao((yyval.node), (yyvsp[0].node));}
#line 1771 "y.tab.c"
    break;

  case 27: /* VarDecl: Type ID VarDecl2 SEMICOLON  */
#line 260 "jucompiler.y"
                                                                                                        {(yyval.node) = cria_node(node_metodos, "", "VarDecl");
																	adicionar_node((yyval.node), (yyvsp[-3].node));
																	adicionar_irmao((yyvsp[-3].node), cria_node(node_id, (yyvsp[-2].id), "Id"));
																	if ((yyvsp[-1].node) != NULL){
																		aux = (yyvsp[-1].node);
																		while (aux != NULL) {
																			no aux1 = cria_node(node_metodos, "", "VarDecl");
																			no aux2 = cria_node((yyvsp[-3].node)->type, (yyvsp[-3].node)->valor, (yyvsp[-3].node)->s_type);
																			adicionar_node(aux1, aux2);
																			adicionar_irmao(aux2, cria_node(node_id, aux->valor, "Id"));
																			adicionar_irmao((yyval.node), aux1);
																			aux = aux->irmao;
																		}
																		free(aux);
																	}}
#line 1791 "y.tab.c"
    break;

  case 28: /* VarDecl2: %empty  */
#line 277 "jucompiler.y"
                                                                                                                        {(yyval.node) = NULL;}
#line 1797 "y.tab.c"
    break;

  case 29: /* VarDecl2: COMMA ID VarDecl2  */
#line 278 "jucompiler.y"
                                                                                                                        {(yyval.node) = cria_node(node_id, (yyvsp[-1].id), "Id");
																	adicionar_irmao((yyval.node), (yyvsp[0].node));}
#line 1804 "y.tab.c"
    break;

  case 30: /* Statement: LBRACE Statement2 RBRACE  */
#line 282 "jucompiler.y"
                                                                                                        {if (conta_irmaos((yyvsp[-1].node)) > 1) {
																		aux = cria_node(node_statements, "", "Block");
																		(yyval.node) = aux;
																		adicionar_node(aux, (yyvsp[-1].node));
																	}
																	else {
																		(yyval.node) = (yyvsp[-1].node);
																	}}
#line 1817 "y.tab.c"
    break;

  case 31: /* Statement: IF LPAR Expr RPAR Statement  */
#line 290 "jucompiler.y"
                                                                                                {(yyval.node) = cria_node(node_statements, "", "If");
																	adicionar_node((yyval.node),(yyvsp[-2].node));
																	aux = cria_node(node_statements, "", "Block");
																	if (conta_irmaos((yyvsp[0].node)) == 1 && (yyvsp[0].node) != NULL) {
																		adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));
																		adicionar_irmao((yyvsp[0].node), aux);
																	}
																	else {
																		adicionar_irmao((yyvsp[-2].node), aux);
																		adicionar_node(aux, (yyvsp[0].node));
																		adicionar_irmao(aux, cria_node(node_statements, "", "Block"));
																	}}
#line 1834 "y.tab.c"
    break;

  case 32: /* Statement: IF LPAR Expr RPAR Statement ELSE Statement  */
#line 302 "jucompiler.y"
                                                                                                {(yyval.node) = cria_node(node_statements, "", "If");
																	adicionar_node((yyval.node),(yyvsp[-4].node));
																	aux = cria_node(node_statements, "", "Block");
																	if (conta_irmaos((yyvsp[-2].node)) == 1 && (yyvsp[-2].node) != NULL) {
																		adicionar_irmao((yyvsp[-4].node), (yyvsp[-2].node));
																		if (conta_irmaos((yyvsp[0].node)) == 1 && (yyvsp[0].node) != NULL) {
																			adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));
																		}
																		else {
																			adicionar_irmao((yyvsp[-2].node), aux);
																			adicionar_node(aux, (yyvsp[0].node));
																		}
																	}
																	else {
																		adicionar_irmao((yyvsp[-4].node), aux);
																		adicionar_node(aux, (yyvsp[-2].node));
																		if (conta_irmaos((yyvsp[0].node)) == 1 && (yyvsp[0].node) != NULL) {
																			adicionar_irmao(aux, (yyvsp[0].node));
																		}
																		else {
																			no aux2 = cria_node(node_statements, "", "Block");
																			adicionar_irmao(aux, aux2);
																			adicionar_node(aux2, (yyvsp[0].node));
																		}
																	}}
#line 1864 "y.tab.c"
    break;

  case 33: /* Statement: WHILE LPAR Expr RPAR Statement  */
#line 327 "jucompiler.y"
                                                                                                        {(yyval.node) = cria_node(node_statements, "", "While");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	if (conta_irmaos((yyvsp[0].node)) == 1 && (yyvsp[0].node) != NULL) {
																		adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));
																	}
																	else {
																		aux = cria_node(node_statements, "", "Block");
																		adicionar_irmao((yyvsp[-2].node), aux);
																		adicionar_node(aux, (yyvsp[0].node));
																	}}
#line 1879 "y.tab.c"
    break;

  case 34: /* Statement: RETURN ExprReturn SEMICOLON  */
#line 337 "jucompiler.y"
                                                                                                                {(yyval.node) = cria_node(node_statements, "", "Return");
																	adicionar_node((yyval.node), (yyvsp[-1].node));}
#line 1886 "y.tab.c"
    break;

  case 35: /* Statement: Statement3 SEMICOLON  */
#line 339 "jucompiler.y"
                                                                                                                {(yyval.node) = (yyvsp[-1].node);}
#line 1892 "y.tab.c"
    break;

  case 36: /* Statement: PRINT LPAR StatementPrint RPAR SEMICOLON  */
#line 340 "jucompiler.y"
                                                                                                {(yyval.node) = cria_node(node_statements, "", "Print");
																	adicionar_node((yyval.node), (yyvsp[-2].node));}
#line 1899 "y.tab.c"
    break;

  case 37: /* Statement: error SEMICOLON  */
#line 342 "jucompiler.y"
                                                                                                                        {(yyval.node) = NULL; flag_error = 1;}
#line 1905 "y.tab.c"
    break;

  case 38: /* Statement2: %empty  */
#line 345 "jucompiler.y"
                                                                                                                        {(yyval.node) = NULL;}
#line 1911 "y.tab.c"
    break;

  case 39: /* Statement2: Statement Statement2  */
#line 346 "jucompiler.y"
                                                                                                                {if ((yyvsp[-1].node) != NULL) {
																		(yyval.node) = (yyvsp[-1].node);
																		adicionar_irmao((yyval.node), (yyvsp[0].node));
																	}
																	else {
																		(yyval.node) = (yyvsp[0].node);
																	}}
#line 1923 "y.tab.c"
    break;

  case 40: /* ExprReturn: %empty  */
#line 355 "jucompiler.y"
                                                                                                                        {(yyval.node) = NULL;}
#line 1929 "y.tab.c"
    break;

  case 41: /* ExprReturn: Expr  */
#line 356 "jucompiler.y"
                                                                                                                                {(yyval.node) = (yyvsp[0].node);}
#line 1935 "y.tab.c"
    break;

  case 42: /* Statement3: %empty  */
#line 359 "jucompiler.y"
                                                                                                                        {(yyval.node) = NULL;}
#line 1941 "y.tab.c"
    break;

  case 43: /* Statement3: MethodInvocation  */
#line 360 "jucompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 1947 "y.tab.c"
    break;

  case 44: /* Statement3: Assignment  */
#line 361 "jucompiler.y"
                                                                                                                                {(yyval.node) = (yyvsp[0].node);}
#line 1953 "y.tab.c"
    break;

  case 45: /* Statement3: ParseArgs  */
#line 362 "jucompiler.y"
                                                                                                                                {(yyval.node) = (yyvsp[0].node);}
#line 1959 "y.tab.c"
    break;

  case 46: /* StatementPrint: Expr  */
#line 365 "jucompiler.y"
                                                                                                                {(yyval.node) = (yyvsp[0].node);}
#line 1965 "y.tab.c"
    break;

  case 47: /* StatementPrint: STRLIT  */
#line 366 "jucompiler.y"
                                                                                                                                {(yyval.node) = cria_node(node_terminais, (yyvsp[0].id), "StrLit");}
#line 1971 "y.tab.c"
    break;

  case 48: /* MethodInvocation: ID LPAR MethodInvocation2 RPAR  */
#line 369 "jucompiler.y"
                                                                                        {(yyval.node) = cria_node(node_operators, "", "Call");
																	aux = cria_node(node_id, (yyvsp[-3].id), "Id");
																	adicionar_node((yyval.node), aux);
																	adicionar_irmao(aux, (yyvsp[-1].node));}
#line 1980 "y.tab.c"
    break;

  case 49: /* MethodInvocation: ID LPAR error RPAR  */
#line 373 "jucompiler.y"
                                                                                                                        {(yyval.node) = NULL;
																	flag_error = 1;}
#line 1987 "y.tab.c"
    break;

  case 50: /* MethodInvocation2: %empty  */
#line 377 "jucompiler.y"
                                                                                                                {(yyval.node) = NULL;}
#line 1993 "y.tab.c"
    break;

  case 51: /* MethodInvocation2: Expr MethodInvocationExpr  */
#line 378 "jucompiler.y"
                                                                                                                {(yyval.node) = (yyvsp[-1].node);
																	adicionar_irmao((yyval.node), (yyvsp[0].node));}
#line 2000 "y.tab.c"
    break;

  case 52: /* MethodInvocationExpr: %empty  */
#line 382 "jucompiler.y"
                                                                                                        {(yyval.node) = NULL;}
#line 2006 "y.tab.c"
    break;

  case 53: /* MethodInvocationExpr: COMMA Expr MethodInvocationExpr  */
#line 383 "jucompiler.y"
                                                                                                        {if((yyvsp[-1].node)!=NULL) {
																		(yyval.node)=(yyvsp[-1].node);
																		adicionar_irmao((yyval.node), (yyvsp[0].node));
																	}
																	else {
																		(yyval.node)=(yyvsp[-1].node);
																	}}
#line 2018 "y.tab.c"
    break;

  case 54: /* Assignment: ID ASSIGN Expr  */
#line 392 "jucompiler.y"
                                                                                                                {(yyval.node) = cria_node(node_operators, "", "Assign");
																	aux = cria_node(node_id, (yyvsp[-2].id), "Id");
																	adicionar_node((yyval.node), aux);
																	adicionar_irmao(aux, (yyvsp[0].node));}
#line 2027 "y.tab.c"
    break;

  case 55: /* ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR  */
#line 398 "jucompiler.y"
                                                                                                {(yyval.node) = cria_node(node_operators, "", "ParseArgs");
																	aux = cria_node(node_id, (yyvsp[-4].id), "Id");
																	adicionar_node((yyval.node), aux);
																	adicionar_irmao(aux, (yyvsp[-2].node));}
#line 2036 "y.tab.c"
    break;

  case 56: /* ParseArgs: PARSEINT LPAR error RPAR  */
#line 402 "jucompiler.y"
                                                                                                                {(yyval.node) = NULL;
																	flag_error = 1;}
#line 2043 "y.tab.c"
    break;

  case 57: /* Expr: Assignment  */
#line 406 "jucompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 2049 "y.tab.c"
    break;

  case 58: /* Expr: ExprOperations  */
#line 407 "jucompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 2055 "y.tab.c"
    break;

  case 59: /* ExprOperations: ExprOperations PLUS ExprOperations  */
#line 410 "jucompiler.y"
                                                                                        {(yyval.node) = cria_node(node_operators, "", "Add");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2063 "y.tab.c"
    break;

  case 60: /* ExprOperations: ExprOperations MINUS ExprOperations  */
#line 413 "jucompiler.y"
                                                                                                        {(yyval.node) = cria_node(node_operators, "", "Sub");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2071 "y.tab.c"
    break;

  case 61: /* ExprOperations: ExprOperations STAR ExprOperations  */
#line 416 "jucompiler.y"
                                                                                                        {(yyval.node) = cria_node(node_operators, "", "Mul");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2079 "y.tab.c"
    break;

  case 62: /* ExprOperations: ExprOperations DIV ExprOperations  */
#line 419 "jucompiler.y"
                                                                                                        {(yyval.node) = cria_node(node_operators, "", "Div");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2087 "y.tab.c"
    break;

  case 63: /* ExprOperations: ExprOperations MOD ExprOperations  */
#line 422 "jucompiler.y"
                                                                                                        {(yyval.node) = cria_node(node_operators, "", "Mod");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2095 "y.tab.c"
    break;

  case 64: /* ExprOperations: ExprOperations AND ExprOperations  */
#line 425 "jucompiler.y"
                                                                                                        {(yyval.node) = cria_node(node_operators, "", "And");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2103 "y.tab.c"
    break;

  case 65: /* ExprOperations: ExprOperations OR ExprOperations  */
#line 428 "jucompiler.y"
                                                                                                        {(yyval.node) = cria_node(node_operators, "", "Or");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2111 "y.tab.c"
    break;

  case 66: /* ExprOperations: ExprOperations XOR ExprOperations  */
#line 431 "jucompiler.y"
                                                                                                        {(yyval.node) = cria_node(node_operators, "", "Xor");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2119 "y.tab.c"
    break;

  case 67: /* ExprOperations: ExprOperations LSHIFT ExprOperations  */
#line 434 "jucompiler.y"
                                                                                                {(yyval.node) = cria_node(node_operators, "", "Lshift");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2127 "y.tab.c"
    break;

  case 68: /* ExprOperations: ExprOperations RSHIFT ExprOperations  */
#line 437 "jucompiler.y"
                                                                                                {(yyval.node) = cria_node(node_operators, "", "Rshift");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2135 "y.tab.c"
    break;

  case 69: /* ExprOperations: ExprOperations EQ ExprOperations  */
#line 440 "jucompiler.y"
                                                                                                        {(yyval.node) = cria_node(node_operators, "", "Eq");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2143 "y.tab.c"
    break;

  case 70: /* ExprOperations: ExprOperations GE ExprOperations  */
#line 443 "jucompiler.y"
                                                                                                        {(yyval.node) = cria_node(node_operators, "", "Ge");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2151 "y.tab.c"
    break;

  case 71: /* ExprOperations: ExprOperations GT ExprOperations  */
#line 446 "jucompiler.y"
                                                                                                        {(yyval.node) = cria_node(node_operators, "", "Gt");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2159 "y.tab.c"
    break;

  case 72: /* ExprOperations: ExprOperations LE ExprOperations  */
#line 449 "jucompiler.y"
                                                                                                        {(yyval.node) = cria_node(node_operators, "", "Le");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2167 "y.tab.c"
    break;

  case 73: /* ExprOperations: ExprOperations LT ExprOperations  */
#line 452 "jucompiler.y"
                                                                                                        {(yyval.node) = cria_node(node_operators, "", "Lt");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2175 "y.tab.c"
    break;

  case 74: /* ExprOperations: ExprOperations NE ExprOperations  */
#line 455 "jucompiler.y"
                                                                                                        {(yyval.node) = cria_node(node_operators, "", "Ne");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2183 "y.tab.c"
    break;

  case 75: /* ExprOperations: PLUS ExprOperations  */
#line 458 "jucompiler.y"
                                                                                                        {(yyval.node) = cria_node(node_operators, "", "Plus");
																	adicionar_node((yyval.node), (yyvsp[0].node));}
#line 2190 "y.tab.c"
    break;

  case 76: /* ExprOperations: MINUS ExprOperations  */
#line 460 "jucompiler.y"
                                                                                                        {(yyval.node) = cria_node(node_operators, "", "Minus");
																	adicionar_node((yyval.node), (yyvsp[0].node));}
#line 2197 "y.tab.c"
    break;

  case 77: /* ExprOperations: NOT ExprOperations  */
#line 462 "jucompiler.y"
                                                                                                                        {(yyval.node) = cria_node(node_operators, "", "Not");
																	adicionar_node((yyval.node), (yyvsp[0].node));}
#line 2204 "y.tab.c"
    break;

  case 78: /* ExprOperations: LPAR Expr RPAR  */
#line 464 "jucompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[-1].node);}
#line 2210 "y.tab.c"
    break;

  case 79: /* ExprOperations: LPAR error RPAR  */
#line 465 "jucompiler.y"
                                                                                                                        {(yyval.node) = NULL;
																	flag_error = 1;}
#line 2217 "y.tab.c"
    break;

  case 80: /* ExprOperations: Expr2  */
#line 467 "jucompiler.y"
                                                                                                                                {(yyval.node) = (yyvsp[0].node);}
#line 2223 "y.tab.c"
    break;

  case 81: /* ExprOperations: ID  */
#line 468 "jucompiler.y"
                                                                                                                                        {(yyval.node) = cria_node(node_id, (yyvsp[0].id), "Id");}
#line 2229 "y.tab.c"
    break;

  case 82: /* ExprOperations: ID DOTLENGTH  */
#line 469 "jucompiler.y"
                                                                                                                        {(yyval.node) = cria_node(node_operators, "", "Length");
																	adicionar_node((yyval.node), cria_node(node_id, (yyvsp[-1].id), "Id"));}
#line 2236 "y.tab.c"
    break;

  case 83: /* ExprOperations: ExprLit  */
#line 471 "jucompiler.y"
                                                                                                                                {(yyval.node) = (yyvsp[0].node);}
#line 2242 "y.tab.c"
    break;

  case 84: /* Expr2: MethodInvocation  */
#line 474 "jucompiler.y"
                                                                                                                {(yyval.node) = (yyvsp[0].node);}
#line 2248 "y.tab.c"
    break;

  case 85: /* Expr2: ParseArgs  */
#line 475 "jucompiler.y"
                                                                                                                                {(yyval.node) = (yyvsp[0].node);}
#line 2254 "y.tab.c"
    break;

  case 86: /* ExprLit: INTLIT  */
#line 478 "jucompiler.y"
                                                                                                                        {(yyval.node) = cria_node(node_terminais, (yyvsp[0].id), "DecLit");}
#line 2260 "y.tab.c"
    break;

  case 87: /* ExprLit: REALLIT  */
#line 479 "jucompiler.y"
                                                                                                                                {(yyval.node) = cria_node(node_terminais, (yyvsp[0].id), "RealLit");}
#line 2266 "y.tab.c"
    break;

  case 88: /* ExprLit: BOOLLIT  */
#line 480 "jucompiler.y"
                                                                                                                                {(yyval.node) = cria_node(node_terminais, (yyvsp[0].id), "BoolLit");}
#line 2272 "y.tab.c"
    break;


#line 2276 "y.tab.c"

#line 2054 "y.tab.c"

      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}

#line 483 "jucompiler.y"
