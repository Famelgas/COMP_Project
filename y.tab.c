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
     RBRACE = 267,
     PARSEINT = 268,
     PUBLIC = 269,
     STATIC = 270,
     ELSE = 271,
     WHILE = 272,
     SEMICOLON = 273,
     RPAR = 274,
     STRING = 275,
     COMMA = 276,
     LSQ = 277,
     RSQ = 278,
     IF = 279,
     RETURN = 280,
     PRINT = 281,
     PLUS = 282,
     MINUS = 283,
     STAR = 284,
     DIV = 285,
     MOD = 286,
     AND = 287,
     OR = 288,
     XOR = 289,
     LSHIFT = 290,
     RSHIFT = 291,
     EQ = 292,
     GE = 293,
     GT = 294,
     LE = 295,
     LT = 296,
     NE = 297,
     NOT = 298,
     DOTLENGTH = 299,
     ID = 300,
     INTLIT = 301,
     REALLIT = 302,
     BOOLLIT = 303,
     STRLIT = 304,
     UNARY = 305
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
#define RBRACE 267
#define PARSEINT 268
#define PUBLIC 269
#define STATIC 270
#define ELSE 271
#define WHILE 272
#define SEMICOLON 273
#define RPAR 274
#define STRING 275
#define COMMA 276
#define LSQ 277
#define RSQ 278
#define IF 279
#define RETURN 280
#define PRINT 281
#define PLUS 282
#define MINUS 283
#define STAR 284
#define DIV 285
#define MOD 286
#define AND 287
#define OR 288
#define XOR 289
#define LSHIFT 290
#define RSHIFT 291
#define EQ 292
#define GE 293
#define GT 294
#define LE 295
#define LT 296
#define NE 297
#define NOT 298
#define DOTLENGTH 299
#define ID 300
#define INTLIT 301
#define REALLIT 302
#define BOOLLIT 303
#define STRLIT 304
#define UNARY 305




/* Copy the first part of user declarations.  */
#line 1 "jucompiler.y"

    #include "functions.h"


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
#line 5 "jucompiler.y"
{
	char * id;
	struct node * node;
}
/* Line 193 of yacc.c.  */
#line 205 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 218 "y.tab.c"

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
#define YYLAST   450

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNRULES -- Number of states.  */
#define YYNSTATES  177

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    12,    15,    18,    19,    24,    31,
      34,    38,    39,    41,    43,    45,    51,    57,    59,    60,
      64,    69,    74,    75,    79,    82,    85,    86,    91,    95,
      96,   100,   106,   114,   120,   124,   127,   133,   136,   139,
     140,   142,   144,   146,   147,   149,   151,   156,   161,   164,
     165,   168,   169,   173,   181,   186,   188,   190,   194,   198,
     202,   206,   210,   214,   218,   222,   226,   230,   234,   238,
     242,   246,   250,   254,   257,   260,   263,   266,   268,   270,
     274,   278,   280,   282,   284,   286,   288
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,     8,    45,     9,    53,    12,    -1,    55,
      53,    -1,    54,    53,    -1,    18,    53,    -1,    -1,    14,
      15,    58,    62,    -1,    14,    15,    57,    45,    56,    18,
      -1,     1,    18,    -1,    21,    45,    56,    -1,    -1,     4,
      -1,     5,    -1,     6,    -1,    57,    45,     3,    59,    19,
      -1,     7,    45,     3,    59,    19,    -1,    60,    -1,    -1,
      57,    45,    61,    -1,    20,    22,    23,    45,    -1,    21,
      57,    45,    61,    -1,    -1,     9,    63,    12,    -1,    66,
      63,    -1,    64,    63,    -1,    -1,    57,    45,    65,    18,
      -1,    21,    45,    65,    -1,    -1,     9,    67,    12,    -1,
      24,     3,    75,    19,    66,    -1,    24,     3,    75,    19,
      66,    16,    66,    -1,    17,     3,    75,    19,    66,    -1,
      25,    75,    18,    -1,    68,    18,    -1,    26,     3,    69,
      19,    18,    -1,     1,    18,    -1,    66,    67,    -1,    -1,
      70,    -1,    73,    -1,    74,    -1,    -1,    75,    -1,    49,
      -1,    45,     3,    71,    19,    -1,    45,     3,     1,    19,
      -1,    75,    72,    -1,    -1,    75,    72,    -1,    -1,    45,
      11,    75,    -1,    13,     3,    45,    22,    75,    23,    19,
      -1,    13,     3,     1,    19,    -1,    73,    -1,    76,    -1,
      75,    27,    75,    -1,    75,    28,    75,    -1,    75,    29,
      75,    -1,    75,    30,    75,    -1,    75,    31,    75,    -1,
      75,    32,    75,    -1,    75,    33,    75,    -1,    75,    34,
      75,    -1,    75,    35,    75,    -1,    75,    36,    75,    -1,
      75,    37,    75,    -1,    75,    38,    75,    -1,    75,    39,
      75,    -1,    75,    40,    75,    -1,    75,    41,    75,    -1,
      75,    42,    75,    -1,    28,    75,    -1,    27,    75,    -1,
      43,    75,    -1,    45,    44,    -1,    45,    -1,    77,    -1,
       3,    75,    19,    -1,     3,     1,    19,    -1,    78,    -1,
      70,    -1,    74,    -1,    46,    -1,    47,    -1,    48,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    36,    36,    43,    44,    45,    46,    49,    52,    66,
      69,    70,    73,    74,    75,    78,    79,    82,    83,    86,
      87,    90,    91,    94,    97,   104,   105,   108,   124,   125,
     127,   135,   147,   172,   183,   184,   185,   186,   189,   196,
     199,   200,   201,   202,   205,   206,   210,   211,   214,   215,
     218,   219,   223,   226,   227,   231,   232,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   262,   263,   266,   267,   268
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LPAR", "BOOL", "DOUBLE", "INT", "VOID",
  "CLASS", "LBRACE", "ARROW", "ASSIGN", "RBRACE", "PARSEINT", "PUBLIC",
  "STATIC", "ELSE", "WHILE", "SEMICOLON", "RPAR", "STRING", "COMMA", "LSQ",
  "RSQ", "IF", "RETURN", "PRINT", "PLUS", "MINUS", "STAR", "DIV", "MOD",
  "AND", "OR", "XOR", "LSHIFT", "RSHIFT", "EQ", "GE", "GT", "LE", "LT",
  "NE", "NOT", "DOTLENGTH", "ID", "INTLIT", "REALLIT", "BOOLLIT", "STRLIT",
  "UNARY", "$accept", "Program", "Program2", "MethodDecl", "FieldDecl",
  "FieldDecl2", "Type", "MethodHeader", "MethodHeader2", "FormalParams",
  "FormalParams2", "MethodBody", "MethodBody2", "VarDecl", "VarDecl2",
  "Statement", "Statement2", "Statement3", "StatementPrint",
  "MethodInvocation", "MethodInvocation2", "MethodInvocation3",
  "Assignment", "ParseArgs", "Expr", "Expr2", "Expr3", "Expr4", 0
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
     305
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    54,    55,    55,
      56,    56,    57,    57,    57,    58,    58,    59,    59,    60,
      60,    61,    61,    62,    63,    63,    63,    64,    65,    65,
      66,    66,    66,    66,    66,    66,    66,    66,    67,    67,
      68,    68,    68,    68,    69,    69,    70,    70,    71,    71,
      72,    72,    73,    74,    74,    75,    75,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    77,    77,    78,    78,    78
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     2,     2,     0,     4,     6,     2,
       3,     0,     1,     1,     1,     5,     5,     1,     0,     3,
       4,     4,     0,     3,     2,     2,     0,     4,     3,     0,
       3,     5,     7,     5,     3,     2,     5,     2,     2,     0,
       1,     1,     1,     0,     1,     1,     4,     4,     2,     0,
       2,     0,     3,     7,     4,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     1,     1,     3,
       3,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     9,     0,     5,     2,     4,     3,    12,    13,
      14,     0,     0,     0,     0,    11,     0,     7,    18,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    40,    41,    42,     0,     0,
       0,    17,     0,    11,     8,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,    84,    85,    86,    82,
      55,    83,     0,    56,    78,    81,     0,     0,     0,    29,
      23,    25,    24,    35,     0,    22,    16,    15,    10,    38,
      30,     0,     0,     0,     0,     0,     0,    74,    73,    75,
      76,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,     0,
      44,     0,     0,    51,    52,     0,     0,     0,     0,    19,
      54,     0,     0,     0,    80,    79,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,     0,    47,    46,     0,     0,    48,    51,    29,
      27,    20,     0,     0,    33,    31,    36,    57,    58,    50,
      28,    22,     0,     0,    21,    53,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    10,    11,    31,    40,    23,    50,    51,
     129,    27,    41,    42,   126,    43,    57,    44,   119,    69,
     122,   157,    70,    71,   158,    73,    74,    75
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -36
static const yytype_int16 yypact[] =
{
      -3,   -35,    23,    27,   -36,   132,    -6,    18,   132,    37,
     132,   132,   -36,    98,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,     8,    22,    45,    66,     5,   197,   -36,   223,   223,
      46,    64,    72,   207,    90,    95,    96,    38,   109,     3,
      93,    44,   197,   197,   122,   -36,   -36,   -36,   121,   100,
     129,   -36,   141,   140,   -36,   -36,   207,   153,     2,    38,
      38,    49,    38,    38,    38,    24,   -36,   -36,   -36,   -36,
     -36,   -36,   237,   -36,   -36,   -36,   126,    12,    38,   147,
     -36,   -36,   -36,   -36,   170,   178,   -36,   -36,   -36,   -36,
     -36,   151,   183,   261,   285,   181,   309,   -36,   -36,   -36,
     -36,   -36,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,   -36,   185,
     345,   188,   198,   149,   -36,   173,   208,   189,    74,   -36,
     -36,    38,   236,   236,   -36,   -36,   101,   101,   -36,   -36,
     -36,   377,   361,   393,    15,    15,   409,   128,   128,   128,
     128,   409,   212,   -36,   -36,    38,    38,   -36,   149,   147,
     -36,   -36,   190,   329,   -36,   220,   -36,   105,   182,   -36,
     -36,   178,   219,   236,   -36,   -36,   -36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -36,   -36,    53,   -36,   -36,   186,     9,   -36,   211,   -36,
      70,   -36,   -14,   -36,    85,   -32,   191,   -36,   -36,   -26,
     -36,    88,   -24,   -22,    11,   -36,   -36,   -36
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -75
static const yytype_int16 yytable[] =
{
      45,    56,    46,    91,    47,     1,    77,    45,    29,    46,
       3,    47,    12,   121,    78,    61,    45,    45,    46,    46,
      47,    47,    22,     4,    56,    34,    30,    77,    81,    82,
      45,   -49,    46,    13,    47,    78,     5,    49,    49,    62,
      63,    61,   102,   103,   104,   105,   106,    92,    72,    15,
      95,    34,    61,    24,    26,    64,    80,    65,    66,    67,
      68,    14,    34,    16,    17,    62,    63,    25,   100,    28,
      93,    94,    96,    97,    98,    99,    62,    63,    18,    19,
      20,    64,    54,    65,    66,    67,    68,   120,   123,   124,
      55,    53,    64,    58,    65,    66,    67,    68,    59,    60,
     164,   165,    18,    19,    20,    21,    45,    45,    46,    46,
      47,    47,    76,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,    61,
     104,   105,   106,     6,   -74,   -74,   -74,   162,    79,    34,
      83,   176,   163,    84,    -6,    85,     7,    45,    86,    46,
       8,    47,    61,    62,    63,   102,   103,   104,   105,   106,
      87,    30,    34,   110,   111,    90,   167,   168,   125,    64,
     130,    65,    66,    67,    68,   118,   155,   156,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    64,   127,    65,    66,    67,    68,    32,   128,
     134,    18,    19,    20,   152,   131,    33,   153,    32,   -26,
      34,   -73,   -73,   -73,    35,   -43,    33,   154,   159,   -39,
      34,    36,    37,    38,    35,   -43,   160,    18,    19,    20,
     166,    36,    37,    38,   161,   171,   173,    32,   175,    88,
      52,   174,    39,    48,   170,    33,   169,    89,     0,    34,
       0,     0,    39,    35,   -43,   101,     0,     0,     0,     0,
      36,    37,    38,     0,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     132,    39,     0,     0,     0,     0,     0,     0,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   133,     0,     0,     0,     0,     0,
       0,     0,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   135,     0,
       0,     0,     0,     0,     0,     0,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   172,     0,     0,     0,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   102,   103,
     104,   105,   106,   107,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   102,   103,   104,   105,   106,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     102,   103,   104,   105,   106,     0,     0,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   102,   103,   104,   105,
     106,     0,     0,     0,   110,   111,     0,   113,   114,   115,
     116
};

static const yytype_int16 yycheck[] =
{
      26,    33,    26,     1,    26,     8,     3,    33,     3,    33,
      45,    33,    18,     1,    11,     3,    42,    43,    42,    43,
      42,    43,    13,     0,    56,    13,    21,     3,    42,    43,
      56,    19,    56,    15,    56,    11,     9,    28,    29,    27,
      28,     3,    27,    28,    29,    30,    31,    45,    37,    12,
       1,    13,     3,    45,     9,    43,    12,    45,    46,    47,
      48,     8,    13,    10,    11,    27,    28,    45,    44,     3,
      59,    60,    61,    62,    63,    64,    27,    28,     4,     5,
       6,    43,    18,    45,    46,    47,    48,    76,    77,    78,
      18,    45,    43,     3,    45,    46,    47,    48,     3,     3,
     132,   133,     4,     5,     6,     7,   132,   133,   132,   133,
     132,   133,     3,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,     3,
      29,    30,    31,     1,    29,    30,    31,   128,    45,    13,
      18,   173,   131,    22,    12,    45,    14,   173,    19,   173,
      18,   173,     3,    27,    28,    27,    28,    29,    30,    31,
      19,    21,    13,    35,    36,    12,   155,   156,    21,    43,
      19,    45,    46,    47,    48,    49,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    23,    45,    46,    47,    48,     1,    21,
      19,     4,     5,     6,    19,    22,     9,    19,     1,    12,
      13,    29,    30,    31,    17,    18,     9,    19,    45,    12,
      13,    24,    25,    26,    17,    18,    18,     4,     5,     6,
      18,    24,    25,    26,    45,    45,    16,     1,    19,    53,
      29,   171,    45,    20,   159,     9,   158,    56,    -1,    13,
      -1,    -1,    45,    17,    18,    18,    -1,    -1,    -1,    -1,
      24,    25,    26,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      19,    45,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    23,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    27,    28,
      29,    30,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    27,    28,    29,    30,    31,    -1,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    35,    36,    -1,    38,    39,    40,
      41
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    52,    45,     0,     9,     1,    14,    18,    53,
      54,    55,    18,    15,    53,    12,    53,    53,     4,     5,
       6,     7,    57,    58,    45,    45,     9,    62,     3,     3,
      21,    56,     1,     9,    13,    17,    24,    25,    26,    45,
      57,    63,    64,    66,    68,    70,    73,    74,    20,    57,
      59,    60,    59,    45,    18,    18,    66,    67,     3,     3,
       3,     3,    27,    28,    43,    45,    46,    47,    48,    70,
      73,    74,    75,    76,    77,    78,     3,     3,    11,    45,
      12,    63,    63,    18,    22,    45,    19,    19,    56,    67,
      12,     1,    45,    75,    75,     1,    75,    75,    75,    75,
      44,    18,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    49,    69,
      75,     1,    71,    75,    75,    21,    65,    23,    21,    61,
      19,    22,    19,    19,    19,    19,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    19,    19,    19,    27,    28,    72,    75,    45,
      18,    45,    57,    75,    66,    66,    18,    75,    75,    72,
      65,    45,    23,    16,    61,    19,    66
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
#line 36 "jucompiler.y"
    {(yyval.node) = root = create_node(node_root, "", "Program");aux = create_node(node_id, (yyvsp[(2) - (5)].id), "Id"); add_child(root, aux); add_next(aux, (yyvsp[(4) - (5)].node));
                                                                                if (flag && !flag_errorr) {
                                                                                    print_tree((yyval.node), 0);
                                                                                }
                                                                            }
    break;

  case 3:
#line 43 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (2)].node); add_next((yyval.node), (yyvsp[(2) - (2)].node));}
    break;

  case 4:
#line 44 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (2)].node); add_next((yyval.node), (yyvsp[(2) - (2)].node));}
    break;

  case 5:
#line 45 "jucompiler.y"
    {(yyval.node) = (yyvsp[(2) - (2)].node);}
    break;

  case 6:
#line 46 "jucompiler.y"
    {(yyval.node) = NULL;}
    break;

  case 7:
#line 49 "jucompiler.y"
    {(yyval.node) = create_node(node_methods, "", "MethodDecl"); add_child((yyval.node), (yyvsp[(3) - (4)].node)); add_next((yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node));}
    break;

  case 8:
#line 52 "jucompiler.y"
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
                                                                                    free(aux);
                                                                                }
                                                                            }
    break;

  case 9:
#line 66 "jucompiler.y"
    {(yyval.node) = NULL; flag_errorr = 1;}
    break;

  case 10:
#line 69 "jucompiler.y"
    {(yyval.node) = create_node(node_id, (yyvsp[(2) - (3)].id), "Id"); add_next((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 11:
#line 70 "jucompiler.y"
    {(yyval.node) = NULL;}
    break;

  case 12:
#line 73 "jucompiler.y"
    {(yyval.node) = create_node(node_terminals, "", "Bool");}
    break;

  case 13:
#line 74 "jucompiler.y"
    {(yyval.node) = create_node(node_terminals, "", "Double");}
    break;

  case 14:
#line 75 "jucompiler.y"
    {(yyval.node) = create_node(node_terminals, "", "Int");}
    break;

  case 15:
#line 78 "jucompiler.y"
    {(yyval.node) = create_node(node_methods, "", "MethodHeader"); add_child((yyval.node),(yyvsp[(1) - (5)].node)); add_next((yyvsp[(1) - (5)].node), create_node(node_id, (yyvsp[(2) - (5)].id), "Id"));aux = create_node(node_methods, "", "MethodParams"); add_next((yyvsp[(1) - (5)].node), aux); add_child(aux, (yyvsp[(4) - (5)].node));}
    break;

  case 16:
#line 79 "jucompiler.y"
    {(yyval.node) = create_node(node_methods, "", "MethodHeader"); node_t aux2 = create_node(node_methods, "", "MethodParams"); add_next(aux, aux2); add_child(aux2, (yyvsp[(4) - (5)].node));}
    break;

  case 17:
#line 82 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 18:
#line 83 "jucompiler.y"
    {(yyval.node) = NULL;}
    break;

  case 19:
#line 86 "jucompiler.y"
    {(yyval.node) = create_node(node_methods, "", "ParamDecl"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); aux = create_node(node_id, (yyvsp[(2) - (3)].id), "Id"); add_next((yyvsp[(1) - (3)].node), aux); add_next((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 20:
#line 87 "jucompiler.y"
    {(yyval.node) = create_node(node_methods, "", "ParamDecl"); aux = create_node(node_methods, "", "StringArray"); add_child((yyval.node), aux); add_next(aux, create_node(node_id, (yyvsp[(4) - (4)].id), "Id"));}
    break;

  case 21:
#line 90 "jucompiler.y"
    {(yyval.node) = create_node(node_methods, "", "ParamDecl"); aux = create_node(node_id, (yyvsp[(3) - (4)].id), "Id"); add_child((yyval.node), (yyvsp[(2) - (4)].node)); add_next((yyvsp[(2) - (4)].node), aux); add_next((yyval.node), (yyvsp[(4) - (4)].node));}
    break;

  case 22:
#line 91 "jucompiler.y"
    {(yyval.node) = NULL;}
    break;

  case 23:
#line 94 "jucompiler.y"
    {(yyval.node) = create_node(node_methods, "", "MethodBody"); add_child((yyval.node), (yyvsp[(2) - (3)].node));}
    break;

  case 24:
#line 97 "jucompiler.y"
    {if ((yyvsp[(1) - (2)].node) != NULL){
																		        (yyval.node) = (yyvsp[(1) - (2)].node);
																		        add_child((yyval.node), (yyvsp[(2) - (2)].node));
																		    }
																	        else {
																		        (yyval.node) = (yyvsp[(2) - (2)].node);
																	        }}
    break;

  case 25:
#line 104 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (2)].node); add_next((yyval.node), (yyvsp[(2) - (2)].node));}
    break;

  case 26:
#line 105 "jucompiler.y"
    {(yyval.node) = NULL;}
    break;

  case 27:
#line 108 "jucompiler.y"
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
																		            free(aux);
																	            }
                                                                            }
    break;

  case 28:
#line 124 "jucompiler.y"
    {(yyval.node) = create_node(node_id, (yyvsp[(2) - (3)].id), "Id"); add_next((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 29:
#line 125 "jucompiler.y"
    {(yyval.node) = NULL;}
    break;

  case 30:
#line 127 "jucompiler.y"
    {if (count_children((yyvsp[(2) - (3)].node)) > 1) {
                                                                                aux = create_node(node_statements, "", "Block");
                                                                                (yyval.node) = aux;
                                                                                add_child(aux, (yyvsp[(2) - (3)].node));
                                                                            }
                                                                            else {
                                                                                (yyval.node) = (yyvsp[(2) - (3)].node);
                                                                            }}
    break;

  case 31:
#line 135 "jucompiler.y"
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
                                                                            }}
    break;

  case 32:
#line 147 "jucompiler.y"
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
                                                                                    node aux2 = create_node(node_statements, "", "Block");
                                                                                    add_next(aux, aux2);
                                                                                    add_child(aux2, (yyvsp[(7) - (7)].node));
                                                                                }
                                                                            }}
    break;

  case 33:
#line 172 "jucompiler.y"
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
#line 183 "jucompiler.y"
    {(yyval.node) = create_node(node_statements, "", "Return"); add_child((yyval.node), (yyvsp[(2) - (3)].node));}
    break;

  case 35:
#line 184 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (2)].node);}
    break;

  case 36:
#line 185 "jucompiler.y"
    {(yyval.node) = create_node(node_statements, "", "Print"); add_child((yyval.node), (yyvsp[(3) - (5)].node));}
    break;

  case 37:
#line 186 "jucompiler.y"
    {(yyval.node) = NULL; flag_error = 1;}
    break;

  case 38:
#line 189 "jucompiler.y"
    {if ((yyvsp[(1) - (2)].node) != NULL) {
																		        (yyval.node) = (yyvsp[(1) - (2)].node);
																		        add_next((yyval.node), (yyvsp[(2) - (2)].node));
                                                                            }
                                                                            else {
                                                                                (yyval.node) = (yyvsp[(2) - (2)].node);
                                                                            }}
    break;

  case 39:
#line 196 "jucompiler.y"
    {(yyval.node) = NULL;}
    break;

  case 40:
#line 199 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 41:
#line 200 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 42:
#line 201 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 43:
#line 202 "jucompiler.y"
    {(yyval.node) = NULL;}
    break;

  case 44:
#line 205 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 45:
#line 206 "jucompiler.y"
    {(yyval.node) = create_node(node_terminais, (yyvsp[(1) - (1)].id), "StrLit");}
    break;

  case 46:
#line 210 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Call"); aux = create_node(node_id, (yyvsp[(1) - (4)].id), "Id"); add_child((yyval.node), aux); add_next(aux, (yyvsp[(3) - (4)].node));}
    break;

  case 47:
#line 211 "jucompiler.y"
    {(yyval.node) = NULL; flag_error = 1;}
    break;

  case 48:
#line 214 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (2)].node); add_next((yyval.node), (yyvsp[(2) - (2)].node));}
    break;

  case 49:
#line 215 "jucompiler.y"
    {(yyval.node) = NULL;}
    break;

  case 50:
#line 218 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (2)].node); add_next((yyval.node), (yyvsp[(2) - (2)].node));}
    break;

  case 51:
#line 219 "jucompiler.y"
    {(yyval.node) = NULL;}
    break;

  case 52:
#line 223 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Assign"); aux = create_node(node_id, (yyvsp[(1) - (3)].id), "Id"); add_child((yyval.node), aux); add_next(aux, (yyvsp[(3) - (3)].node));}
    break;

  case 53:
#line 226 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "ParseArgs"); aux = create_node(node_id, (yyvsp[(3) - (7)].id), "Id"); add_child((yyval.node), aux); add_next(aux, (yyvsp[(5) - (7)].node));}
    break;

  case 54:
#line 227 "jucompiler.y"
    {(yyval.node) = NULL; flag_errorr = 1;}
    break;

  case 55:
#line 231 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 56:
#line 232 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 57:
#line 235 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Add"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 58:
#line 236 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Sub"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 59:
#line 237 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Mul"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 60:
#line 238 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Div"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 61:
#line 239 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Mod"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 62:
#line 240 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "And"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 63:
#line 241 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Or"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 64:
#line 242 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Xor"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 65:
#line 243 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Lshift"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 66:
#line 244 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Rshift"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 67:
#line 245 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Eq"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 68:
#line 246 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Ge"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 69:
#line 247 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Gt"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 70:
#line 248 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Le"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 71:
#line 249 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Lt"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 72:
#line 250 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Ne"); add_child((yyval.node), (yyvsp[(1) - (3)].node)); add_next((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 73:
#line 251 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Minus"); add_child((yyval.node), (yyvsp[(2) - (2)].node));}
    break;

  case 74:
#line 252 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Plus"); add_child((yyval.node), (yyvsp[(2) - (2)].node));}
    break;

  case 75:
#line 253 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Not"); add_child((yyval.node), (yyvsp[(2) - (2)].node));}
    break;

  case 76:
#line 254 "jucompiler.y"
    {(yyval.node) = create_node(node_operators, "", "Length"); add_child((yyval.node), create_node(node_id, (yyvsp[(1) - (2)].id), "Id"));}
    break;

  case 77:
#line 255 "jucompiler.y"
    {(yyval.node) = create_node(node_id, (yyvsp[(1) - (1)].id), "Id");}
    break;

  case 78:
#line 256 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 79:
#line 257 "jucompiler.y"
    {(yyval.node) = (yyvsp[(2) - (3)].node);}
    break;

  case 80:
#line 258 "jucompiler.y"
    {(yyval.node) = NULL; flag_errorr = 1;}
    break;

  case 81:
#line 259 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 82:
#line 262 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 83:
#line 263 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 84:
#line 266 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].id); (yyval.node) = create_node(node_terminais, (yyvsp[(1) - (1)].id), "DecLit");}
    break;

  case 85:
#line 267 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].id); (yyval.node) = create_node(node_terminais, (yyvsp[(1) - (1)].id), "RealLit");}
    break;

  case 86:
#line 268 "jucompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].id); (yyval.node) = create_node(node_terminais, (yyvsp[(1) - (1)].id), "BoolLit");}
    break;


/* Line 1267 of yacc.c.  */
#line 2141 "y.tab.c"
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


#line 271 "jucompiler.y"

