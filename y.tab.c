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

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     LPAR = 258,
     BOOL = 259,
     DOUBLE = 260,
     INT = 261,
     VOID = 262,
     CLASS = 263,
     LBRACE = 264,
     ARROW = 265,
     ASSIGN = 266,
     RESERVED = 267,
     RBRACE = 268,
     PARSEINT = 269,
     PUBLIC = 270,
     STATIC = 271,
     ELSE = 272,
     WHILE = 273,
     SEMICOLON = 274,
     RPAR = 275,
     STRING = 276,
     COMMA = 277,
     LSQ = 278,
     RSQ = 279,
     IF = 280,
     RETURN = 281,
     PRINT = 282,
     PLUS = 283,
     MINUS = 284,
     STAR = 285,
     DIV = 286,
     MOD = 287,
     AND = 288,
     OR = 289,
     XOR = 290,
     LSHIFT = 291,
     RSHIFT = 292,
     EQ = 293,
     GE = 294,
     GT = 295,
     LE = 296,
     LT = 297,
     NE = 298,
     NOT = 299,
     DOTLENGTH = 300,
     ID = 301,
     INTLIT = 302,
     REALLIT = 303,
     BOOLLIT = 304,
     STRLIT = 305,
     UNARY = 306
   };
#endif
/* Tokens.  */
#define LPAR 258
#define BOOL 259
#define DOUBLE 260
#define INT 261
#define VOID 262
#define CLASS 263
#define LBRACE 264
#define ARROW 265
#define ASSIGN 266
#define RESERVED 267
#define RBRACE 268
#define PARSEINT 269
#define PUBLIC 270
#define STATIC 271
#define ELSE 272
#define WHILE 273
#define SEMICOLON 274
#define RPAR 275
#define STRING 276
#define COMMA 277
#define LSQ 278
#define RSQ 279
#define IF 280
#define RETURN 281
#define PRINT 282
#define PLUS 283
#define MINUS 284
#define STAR 285
#define DIV 286
#define MOD 287
#define AND 288
#define OR 289
#define XOR 290
#define LSHIFT 291
#define RSHIFT 292
#define EQ 293
#define GE 294
#define GT 295
#define LE 296
#define LT 297
#define NE 298
#define NOT 299
#define DOTLENGTH 300
#define ID 301
#define INTLIT 302
#define REALLIT 303
#define BOOLLIT 304
#define STRLIT 305
#define UNARY 306




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
	char * id;
	struct node * node;
}
/* Line 193 of yacc.c.  */
#line 216 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



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
#define YYLAST   348

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
       0,    47,    47,    54,    55,    56,    57,    60,    63,    76,
      79,    80,    83,    84,    85,    88,    89,    92,    93,    96,
      97,   100,   101,   104,   107,   114,   115,   118,   133,   134,
     137,   146,   159,   184,   195,   196,   197,   198,   201,   202,
     205,   212,   215,   216,   217,   218,   221,   222,   226,   227,
     230,   231,   234,   241,   245,   248,   249,   252,   253,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   283,   284,   287,   288,   289
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LPAR", "BOOL", "DOUBLE", "INT", "VOID",
  "CLASS", "LBRACE", "ARROW", "ASSIGN", "RESERVED", "RBRACE", "PARSEINT",
  "PUBLIC", "STATIC", "ELSE", "WHILE", "SEMICOLON", "RPAR", "STRING",
  "COMMA", "LSQ", "RSQ", "IF", "RETURN", "PRINT", "PLUS", "MINUS", "STAR",
  "DIV", "MOD", "AND", "OR", "XOR", "LSHIFT", "RSHIFT", "EQ", "GE", "GT",
  "LE", "LT", "NE", "NOT", "DOTLENGTH", "ID", "INTLIT", "REALLIT",
  "BOOLLIT", "STRLIT", "UNARY", "$accept", "Program", "Program2",
  "MethodDecl", "FieldDecl", "FieldDecl2", "Type", "MethodHeader",
  "MethodHeader2", "FormalParams", "FormalParams2", "MethodBody",
  "MethodBody2", "VarDecl", "VarDecl2", "Statement", "Expr5", "Statement2",
  "Statement3", "Statement4", "MethodInvocation", "MethodInvocation2",
  "MethodInvocation3", "Assignment", "ParseArgs", "Expr", "Expr2", "Expr3",
  "Expr4", 0
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

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    54,    54,    55,    56,    56,
      57,    57,    58,    58,    58,    59,    59,    60,    60,    61,
      61,    62,    62,    63,    64,    64,    64,    65,    66,    66,
      67,    67,    67,    67,    67,    67,    67,    67,    68,    68,
      69,    69,    70,    70,    70,    70,    71,    71,    72,    72,
      73,    73,    74,    74,    75,    76,    76,    77,    77,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    79,    79,    80,    80,    80
};

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
       5,   -38,    35,    37,   -39,    36,    42,    40,    36,    49,
      36,    36,   -39,   171,   -39,   -39,   -39,   -39,   -39,   -39,
     -39,    18,    43,    88,    93,     9,   194,   -39,   100,   100,
      52,    99,   101,   209,   116,   119,   120,    19,   122,     3,
      83,   117,   194,   194,   113,   -39,   -39,   -39,   118,    94,
     124,   -39,   126,   128,   -39,   -39,   209,   152,     4,    19,
      19,   123,   145,   145,   145,    12,   -39,   -39,   -39,   147,
     -39,   -39,   -39,   -39,   242,   -39,   -39,   114,    87,    19,
     146,   -39,   -39,   -39,   -39,   155,   158,   -39,   -39,   -39,
     -39,   -39,   161,   159,   163,   164,   165,   166,     0,   -39,
     -39,   -39,   -39,   -39,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     -39,   167,   -39,   168,   170,   174,   -39,   151,   182,   156,
      48,   -39,   -39,    19,   223,   223,   -39,   -39,    55,    55,
     -39,   -39,   -39,   274,   258,   290,   125,   125,   306,    63,
      63,    63,    63,   306,   185,   -39,   -39,    19,   -39,   146,
     -39,   -39,   160,   181,   -39,   192,   -39,   174,   -39,   158,
     191,   223,   -39,   -39,   -39,   -39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -39,   -39,    28,   -39,   -39,   162,    -3,   -39,   187,   -39,
      45,   -39,     1,   -39,    58,   -32,   -39,   169,   -39,   -39,
     -26,   -39,    59,   -24,   -22,   -19,   -35,   -39,   -39
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -52
static const yytype_int16 yytable[] =
{
      45,    56,    46,    78,    47,    92,    78,    45,     3,    46,
      22,    47,    29,     1,    79,    78,    45,    45,    46,    46,
      47,    47,    61,    79,    56,    49,    49,    99,   100,   101,
      45,    30,    46,    34,    47,     4,    14,     6,    16,    17,
      94,    95,    97,    82,    83,   102,     5,    62,    63,    -6,
      93,     7,    18,    19,    20,     8,    13,   102,   122,   125,
     126,    12,    15,    64,    24,    65,    66,    67,    68,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   106,   107,   108,   123,    25,
      61,   104,   105,   106,   107,   108,    28,    26,    53,   112,
     113,    34,   164,   165,    18,    19,    20,   -51,    45,    45,
      46,    46,    47,    47,   163,    62,    63,    61,    54,    58,
      55,    48,    59,    60,    96,    77,    61,   162,    34,    80,
      81,    64,    84,    65,    66,    67,    68,    34,   167,   175,
      86,    85,    62,    63,    87,    45,    88,    46,    61,    47,
      30,    62,    63,   104,   105,   106,   107,   108,    64,    34,
      65,    66,    67,    68,   120,    91,   103,    64,   127,    65,
      66,    67,    68,    62,    63,    18,    19,    20,    21,   129,
     130,   132,   133,   134,   135,   136,   137,   154,   155,    64,
     156,    98,    66,    67,    68,    32,   157,   159,    18,    19,
      20,   160,   161,    33,   166,   170,   169,   -26,    34,   -52,
      32,   174,    35,   -45,   173,    89,    52,   168,    33,    36,
      37,    38,   -41,    34,    32,    90,   172,    35,   -45,     0,
       0,     0,    33,     0,    36,    37,    38,    34,     0,     0,
      39,    35,   -45,     0,     0,     0,     0,     0,    36,    37,
      38,     0,     0,     0,     0,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   104,   105,   106,   107,
     108,   109,     0,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   104,   105,   106,   107,   108,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   104,   105,
     106,   107,   108,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,   104,   105,   106,   107,   108,     0,
       0,     0,   112,   113,     0,   115,   116,   117,   118
};

static const yytype_int16 yycheck[] =
{
      26,    33,    26,     3,    26,     1,     3,    33,    46,    33,
      13,    33,     3,     8,    11,     3,    42,    43,    42,    43,
      42,    43,     3,    11,    56,    28,    29,    62,    63,    64,
      56,    22,    56,    14,    56,     0,     8,     1,    10,    11,
      59,    60,    61,    42,    43,    45,     9,    28,    29,    13,
      46,    15,     4,     5,     6,    19,    16,    45,    77,    78,
      79,    19,    13,    44,    46,    46,    47,    48,    49,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,    30,    31,    32,     1,    46,
       3,    28,    29,    30,    31,    32,     3,     9,    46,    36,
      37,    14,   134,   135,     4,     5,     6,    20,   134,   135,
     134,   135,   134,   135,   133,    28,    29,     3,    19,     3,
      19,    21,     3,     3,     1,     3,     3,   130,    14,    46,
      13,    44,    19,    46,    47,    48,    49,    14,   157,   171,
      46,    23,    28,    29,    20,   171,    20,   171,     3,   171,
      22,    28,    29,    28,    29,    30,    31,    32,    44,    14,
      46,    47,    48,    49,    50,    13,    19,    44,    22,    46,
      47,    48,    49,    28,    29,     4,     5,     6,     7,    24,
      22,    20,    23,    20,    20,    20,    20,    20,    20,    44,
      20,    46,    47,    48,    49,     1,    22,    46,     4,     5,
       6,    19,    46,     9,    19,    24,    46,    13,    14,    17,
       1,    20,    18,    19,   169,    53,    29,   159,     9,    25,
      26,    27,    13,    14,     1,    56,   167,    18,    19,    -1,
      -1,    -1,     9,    -1,    25,    26,    27,    14,    -1,    -1,
      46,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,    26,
      27,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    28,    29,    30,    31,    32,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    36,    37,    -1,    39,    40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    53,    46,     0,     9,     1,    15,    19,    54,
      55,    56,    19,    16,    54,    13,    54,    54,     4,     5,
       6,     7,    58,    59,    46,    46,     9,    63,     3,     3,
      22,    57,     1,     9,    14,    18,    25,    26,    27,    46,
      58,    64,    65,    67,    70,    72,    75,    76,    21,    58,
      60,    61,    60,    46,    19,    19,    67,    69,     3,     3,
       3,     3,    28,    29,    44,    46,    47,    48,    49,    68,
      72,    75,    76,    77,    78,    79,    80,     3,     3,    11,
      46,    13,    64,    64,    19,    23,    46,    20,    20,    57,
      69,    13,     1,    46,    77,    77,     1,    77,    46,    78,
      78,    78,    45,    19,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      50,    71,    77,     1,    73,    77,    77,    22,    66,    24,
      22,    62,    20,    23,    20,    20,    20,    20,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    20,    20,    20,    22,    74,    46,
      19,    46,    58,    77,    67,    67,    19,    77,    66,    46,
      24,    17,    74,    62,    20,    67
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


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
        case 2:
#line 47 "jucompiler.y"
    {root = create_node(node_root, "", "Program"); aux = create_node(node_id, (yyvsp[(2) - (5)].id), "Id"); add_child(root, aux); add_next(aux, (yyvsp[(4) - (5)].node)); (yyval.node) = root;
																	            if (flag == 2 && flag_error == 0) {
																		            print_tree((yyval.node), 0);
																	            }
                                                                            }
    break;

  case 3:
#line 54 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (2)].node); add_next((yyval.node), (yyvsp[(2) - (2)].node));}
    break;

  case 4:
#line 55 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (2)].node); add_next((yyval.node), (yyvsp[(2) - (2)].node));}
    break;

  case 5:
#line 56 "jucompiler.y"
    {(yyval.node) = (yyvsp[(2) - (2)].node);}
    break;

  case 6:
#line 57 "jucompiler.y"
    {(yyval.node) = NULL;}
    break;

  case 7:
#line 60 "jucompiler.y"
    {(yyval.node) = create_node(node_methods, "", "MethodDecl"); add_child((yyval.node), (yyvsp[(3) - (4)].node)); add_next((yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node));}
    break;

  case 8:
#line 63 "jucompiler.y"
    {(yyval.node) = create_node(node_var, "", "FieldDecl"); add_child((yyval.node), (yyvsp[(3) - (6)].node)); add_next((yyvsp[(3) - (6)].node), create_node(node_id, (yyvsp[(4) - (6)].id), "Id"));
																	            if ((yyvsp[(5) - (6)].node) != NULL){
																		            aux = (yyvsp[(5) - (6)].node);
																	    	        while (aux != NULL) {
																		    	        node_t aux1 = create_node(node_var, "", "FieldDecl");
																			            node_t aux2 = create_node((yyvsp[(3) - (6)].node)->type, (yyvsp[(3) - (6)].node)->value, (yyvsp[(3) - (6)].node)->symbol);
																			            add_child(aux1, aux2);
																			            add_next(aux2, create_node(node_id, aux->value, "Id"));
																		                add_next((yyval.node), aux1);
																		                aux = aux->brother;
																    	            }
																	            }
                                                                            }
    break;

  case 9:
#line 76 "jucompiler.y"
    {(yyval.node) = NULL; flag_error = 1;}
    break;

  case 10:
#line 79 "jucompiler.y"
    {(yyval.node) = create_node(node_id, (yyvsp[(2) - (3)].id), "Id"); add_next((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 11:
#line 80 "jucompiler.y"
    {(yyval.node) = NULL;}
    break;

  case 12:
#line 83 "jucompiler.y"
    {(yyval.node) = create_node(node_terminals, "", "Bool");}
    break;

  case 13:
#line 84 "jucompiler.y"
    {(yyval.node) = create_node(node_terminals, "", "Int");}
    break;

  case 14:
#line 85 "jucompiler.y"
    {(yyval.node) = create_node(node_terminals, "", "Double");}
    break;

  case 15:
#line 88 "jucompiler.y"
    {(yyval.node) = create_node(node_methods, "", "MethodHeader"); add_child((yyval.node),(yyvsp[(1) - (5)].node)); add_next((yyvsp[(1) - (5)].node), create_node(node_id, (yyvsp[(2) - (5)].id), "Id"));aux = create_node(node_methods, "", "MethodParams"); add_next((yyvsp[(1) - (5)].node), aux); add_child(aux, (yyvsp[(4) - (5)].node));}
    break;

  case 16:
#line 89 "jucompiler.y"
    {(yyval.node) = create_node(node_methods, "", "MethodHeader"); aux = create_node(node_terminals, "", "Void"); add_child((yyval.node), aux); add_next(aux, create_node(node_id, (yyvsp[(2) - (5)].id), "Id")); node_t aux2 = create_node(node_methods, "", "MethodParams"); add_next(aux, aux2); add_child(aux2, (yyvsp[(4) - (5)].node));}
    break;

  case 17:
#line 92 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 18:
#line 93 "jucompiler.y"
    {(yyval.node) = NULL;}
    break;

  case 19:
#line 96 "jucompiler.y"
    {(yyval.node) = create_node(node_methods, "", "ParamDecl"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); aux = create_node(node_id, (yyvsp[(2) - (3)].id), "Id"); add_next((yyvsp[(1) - (3)].node), aux); add_next((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 20:
#line 97 "jucompiler.y"
    {(yyval.node) = create_node(node_methods, "", "ParamDecl"); aux = create_node(node_methods, "", "StringArray"); add_child((yyval.node), aux); add_next(aux, create_node(node_id, (yyvsp[(4) - (4)].id), "Id"));}
    break;

  case 21:
#line 100 "jucompiler.y"
    {(yyval.node) = create_node(node_methods, "", "ParamDecl"); aux = create_node(node_id, (yyvsp[(3) - (4)].id), "Id"); add_child((yyval.node), (yyvsp[(2) - (4)].node)); add_next((yyvsp[(2) - (4)].node), aux); add_next((yyval.node), (yyvsp[(4) - (4)].node));}
    break;

  case 22:
#line 101 "jucompiler.y"
    {(yyval.node) = NULL;}
    break;

  case 23:
#line 104 "jucompiler.y"
    {(yyval.node) = create_node(node_methods, "", "MethodBody"); add_child((yyval.node), (yyvsp[(2) - (3)].node));}
    break;

  case 24:
#line 107 "jucompiler.y"
    {if ((yyvsp[(1) - (2)].node) != NULL){
																		        (yyval.node) = (yyvsp[(1) - (2)].node);
																		        add_next((yyval.node), (yyvsp[(2) - (2)].node));
																		    }
																	        else {
																		        (yyval.node) = (yyvsp[(2) - (2)].node);
																	        }}
    break;

  case 25:
#line 114 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (2)].node); add_next((yyval.node), (yyvsp[(2) - (2)].node));}
    break;

  case 26:
#line 115 "jucompiler.y"
    {(yyval.node) = NULL;}
    break;

  case 27:
#line 118 "jucompiler.y"
    {(yyval.node) = create_node(node_methods, "", "VarDecl"); add_child((yyval.node), (yyvsp[(1) - (4)].node)); add_next((yyvsp[(1) - (4)].node), create_node(node_id, (yyvsp[(2) - (4)].id), "Id"));
																	            if ((yyvsp[(3) - (4)].node) != NULL){
																		            aux = (yyvsp[(3) - (4)].node);
																		            while (aux != NULL) {
																			            node_t aux1 = create_node(node_methods, "", "VarDecl");
																			            node_t aux2 = create_node((yyvsp[(1) - (4)].node)->type, (yyvsp[(1) - (4)].node)->value, (yyvsp[(1) - (4)].node)->symbol);
																			            add_child(aux1, aux2);
																			            add_next(aux2, create_node(node_id, aux->value, "Id"));
																			            add_next((yyval.node), aux1);
																			            aux = aux->brother;
																		            }
																	            }
                                                                            }
    break;

  case 28:
#line 133 "jucompiler.y"
    {(yyval.node) = create_node(node_id, (yyvsp[(2) - (3)].id), "Id"); add_next((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 29:
#line 134 "jucompiler.y"
    {(yyval.node) = NULL;}
    break;

  case 30:
#line 137 "jucompiler.y"
    {if (count_children((yyvsp[(2) - (3)].node)) > 1) {
                                                                                aux = create_node(node_statements, "", "Block");
                                                                                (yyval.node) = aux;
                                                                                add_child(aux, (yyvsp[(2) - (3)].node));
                                                                            }
                                                                            else {
                                                                                (yyval.node) = (yyvsp[(2) - (3)].node);
                                                                            }
                                                                            }
    break;

  case 31:
#line 146 "jucompiler.y"
    {(yyval.node) = create_node(node_statements, "", "If");
                                                                                add_child((yyval.node),(yyvsp[(3) - (5)].node));
                                                                                aux = create_node(node_statements, "", "Block");
                                                                                if (count_children((yyvsp[(5) - (5)].node)) == 1 && (yyvsp[(5) - (5)].node) != NULL) {
                                                                                    add_next((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));
                                                                                    add_next((yyvsp[(5) - (5)].node), aux);
                                                                                }
                                                                                else {
                                                                                    add_next((yyvsp[(3) - (5)].node), aux);
                                                                                    add_child(aux, (yyvsp[(5) - (5)].node));
                                                                                    add_next(aux, create_node(node_statements, "", "Block"));
                                                                                }
                                                                            }
    break;

  case 32:
#line 159 "jucompiler.y"
    {(yyval.node) = create_node(node_statements, "", "If");
                                                                            add_child((yyval.node),(yyvsp[(3) - (7)].node));
                                                                            aux = create_node(node_statements, "", "Block");
                                                                            if (count_children((yyvsp[(5) - (7)].node)) == 1 && (yyvsp[(5) - (7)].node) != NULL) {
                                                                                add_next((yyvsp[(3) - (7)].node), (yyvsp[(5) - (7)].node));
                                                                                if (count_children((yyvsp[(7) - (7)].node)) == 1 && (yyvsp[(7) - (7)].node) != NULL) {
                                                                                    add_next((yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node));
                                                                                }
                                                                                else {
                                                                                    add_next((yyvsp[(5) - (7)].node), aux);
                                                                                    add_child(aux, (yyvsp[(7) - (7)].node));
                                                                                }
                                                                            }
                                                                            else {
                                                                                add_next((yyvsp[(3) - (7)].node), aux);
                                                                                add_child(aux, (yyvsp[(5) - (7)].node));
                                                                                if (count_children((yyvsp[(7) - (7)].node)) == 1 && (yyvsp[(7) - (7)].node) != NULL) {
                                                                                    add_next(aux, (yyvsp[(7) - (7)].node));
                                                                                }
                                                                                else {
                                                                                    node_t aux2 = create_node(node_statements, "", "Block");
                                                                                    add_next(aux, aux2);
                                                                                    add_child(aux2, (yyvsp[(7) - (7)].node));
                                                                                }
                                                                            }}
    break;

  case 33:
#line 184 "jucompiler.y"
    {(yyval.node) = create_node(node_statements, "", "While");
                                                                                add_child((yyval.node), (yyvsp[(3) - (5)].node));
                                                                                if (count_children((yyvsp[(5) - (5)].node)) == 1 && (yyvsp[(5) - (5)].node) != NULL) {
                                                                                    add_next((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));
                                                                                }
                                                                                else {
                                                                                    aux = create_node(node_statements, "", "Block");
                                                                                    add_next((yyvsp[(3) - (5)].node), aux);
                                                                                    add_child(aux, (yyvsp[(5) - (5)].node));
                                                                                }
                                                                            }
    break;

  case 34:
#line 195 "jucompiler.y"
    {(yyval.node) = create_node(node_statements, "", "Return"); add_child((yyval.node), (yyvsp[(2) - (3)].node));}
    break;

  case 35:
#line 196 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (2)].node);}
    break;

  case 36:
#line 197 "jucompiler.y"
    {(yyval.node) = create_node(node_statements, "", "Print"); add_child((yyval.node), (yyvsp[(3) - (5)].node));}
    break;

  case 37:
#line 198 "jucompiler.y"
    {(yyval.node) = NULL; flag_error = 1;}
    break;

  case 38:
#line 201 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 39:
#line 202 "jucompiler.y"
    {(yyval.node) = NULL;}
    break;

  case 40:
#line 205 "jucompiler.y"
    {if ((yyvsp[(1) - (2)].node) != NULL) {
																		        (yyval.node) = (yyvsp[(1) - (2)].node);
																		        add_next((yyval.node), (yyvsp[(2) - (2)].node));
                                                                            }
                                                                            else {
                                                                                (yyval.node) = (yyvsp[(2) - (2)].node);
                                                                            }}
    break;

  case 41:
#line 212 "jucompiler.y"
    {(yyval.node) = NULL;}
    break;

  case 42:
#line 215 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 43:
#line 216 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 44:
#line 217 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 45:
#line 218 "jucompiler.y"
    {(yyval.node) = NULL;}
    break;

  case 46:
#line 221 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 47:
#line 222 "jucompiler.y"
    {(yyval.node) = create_node(node_terminals, (yyvsp[(1) - (1)].id), "StrLit");}
    break;

  case 48:
#line 226 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Call"); aux = create_node(node_id, (yyvsp[(1) - (4)].id), "Id"); add_child((yyval.node), aux); add_next(aux, (yyvsp[(3) - (4)].node));}
    break;

  case 49:
#line 227 "jucompiler.y"
    {(yyval.node) = NULL; flag_error = 1;}
    break;

  case 50:
#line 230 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (2)].node); add_next((yyval.node), (yyvsp[(2) - (2)].node));}
    break;

  case 51:
#line 231 "jucompiler.y"
    {(yyval.node) = NULL;}
    break;

  case 52:
#line 234 "jucompiler.y"
    {if((yyvsp[(2) - (3)].node)!=NULL) {
                                                                                (yyval.node)=(yyvsp[(2) - (3)].node); 
                                                                                add_next((yyval.node), (yyvsp[(3) - (3)].node));
                                                                            }
                                                                            else {
                                                                                (yyval.node)=(yyvsp[(2) - (3)].node);
                                                                            }}
    break;

  case 53:
#line 241 "jucompiler.y"
    {(yyval.node) = NULL;}
    break;

  case 54:
#line 245 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Assign"); aux = create_node(node_id, (yyvsp[(1) - (3)].id), "Id"); add_child((yyval.node), aux); add_next(aux, (yyvsp[(3) - (3)].node));}
    break;

  case 55:
#line 248 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "ParseArgs"); aux = create_node(node_id, (yyvsp[(3) - (7)].id), "Id"); add_child((yyval.node), aux); add_next(aux, (yyvsp[(5) - (7)].node));}
    break;

  case 56:
#line 249 "jucompiler.y"
    {(yyval.node) = NULL; flag_error = 1;}
    break;

  case 57:
#line 252 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 58:
#line 253 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 59:
#line 256 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Add"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 60:
#line 257 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Sub"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 61:
#line 258 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Mul"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 62:
#line 259 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Div"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 63:
#line 260 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Mod"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 64:
#line 261 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "And"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 65:
#line 262 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Or"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 66:
#line 263 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Xor"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 67:
#line 264 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Lshift"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 68:
#line 265 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Rshift"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 69:
#line 266 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Eq"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 70:
#line 267 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Ge"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 71:
#line 268 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Gt"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 72:
#line 269 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Le"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 73:
#line 270 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Lt"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 74:
#line 271 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Ne"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 75:
#line 272 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Minus"); add_child((yyval.node), (yyvsp[(2) - (2)].node));}
    break;

  case 76:
#line 273 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Plus"); add_child((yyval.node), (yyvsp[(2) - (2)].node));}
    break;

  case 77:
#line 274 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Not"); add_child((yyval.node), (yyvsp[(2) - (2)].node));}
    break;

  case 78:
#line 275 "jucompiler.y"
    {(yyval.node) = (yyvsp[(2) - (3)].node);}
    break;

  case 79:
#line 276 "jucompiler.y"
    {(yyval.node) = NULL; flag_error = 1;}
    break;

  case 80:
#line 277 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 81:
#line 278 "jucompiler.y"
    {(yyval.node) = create_node(node_id, (yyvsp[(1) - (1)].id), "Id");}
    break;

  case 82:
#line 279 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Length"); add_child((yyval.node), create_node(node_id, (yyvsp[(1) - (2)].id), "Id"));}
    break;

  case 83:
#line 280 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 84:
#line 283 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 85:
#line 284 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 86:
#line 287 "jucompiler.y"
    {(yyval.node) = create_node(node_terminals, (yyvsp[(1) - (1)].id), "DecLit");}
    break;

  case 87:
#line 288 "jucompiler.y"
    {(yyval.node) = create_node(node_terminals, (yyvsp[(1) - (1)].id), "RealLit");}
    break;

  case 88:
#line 289 "jucompiler.y"
    {(yyval.node) = create_node(node_terminals, (yyvsp[(1) - (1)].id), "BoolLit");}
    break;


/* Line 1267 of yacc.c.  */
#line 2148 "y.tab.c"
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


#line 292 "jucompiler.y"

