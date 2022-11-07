/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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
    Miguel Filipe de Andrade Sergio 2020225643
    Filipe David Amado Mendes 2020218797
    */

    #include "functions.h"
    extern int flag;
    int flag_error = 0;
    node_t root;
    node_t aux;

#line 84 "y.tab.c"

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

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    LPAR = 258,                    /* LPAR  */
    BOOL = 259,                    /* BOOL  */
    DOUBLE = 260,                  /* DOUBLE  */
    INT = 261,                     /* INT  */
    VOID = 262,                    /* VOID  */
    CLASS = 263,                   /* CLASS  */
    LBRACE = 264,                  /* LBRACE  */
    ARROW = 265,                   /* ARROW  */
    ASSIGN = 266,                  /* ASSIGN  */
    RESERVED = 267,                /* RESERVED  */
    RBRACE = 268,                  /* RBRACE  */
    PARSEINT = 269,                /* PARSEINT  */
    PUBLIC = 270,                  /* PUBLIC  */
    STATIC = 271,                  /* STATIC  */
    ELSE = 272,                    /* ELSE  */
    WHILE = 273,                   /* WHILE  */
    SEMICOLON = 274,               /* SEMICOLON  */
    RPAR = 275,                    /* RPAR  */
    STRING = 276,                  /* STRING  */
    COMMA = 277,                   /* COMMA  */
    LSQ = 278,                     /* LSQ  */
    RSQ = 279,                     /* RSQ  */
    IF = 280,                      /* IF  */
    RETURN = 281,                  /* RETURN  */
    PRINT = 282,                   /* PRINT  */
    PLUS = 283,                    /* PLUS  */
    MINUS = 284,                   /* MINUS  */
    STAR = 285,                    /* STAR  */
    DIV = 286,                     /* DIV  */
    MOD = 287,                     /* MOD  */
    AND = 288,                     /* AND  */
    OR = 289,                      /* OR  */
    XOR = 290,                     /* XOR  */
    LSHIFT = 291,                  /* LSHIFT  */
    RSHIFT = 292,                  /* RSHIFT  */
    EQ = 293,                      /* EQ  */
    GE = 294,                      /* GE  */
    GT = 295,                      /* GT  */
    LE = 296,                      /* LE  */
    LT = 297,                      /* LT  */
    NE = 298,                      /* NE  */
    NOT = 299,                     /* NOT  */
    DOTLENGTH = 300,               /* DOTLENGTH  */
    ID = 301,                      /* ID  */
    INTLIT = 302,                  /* INTLIT  */
    REALLIT = 303,                 /* REALLIT  */
    BOOLLIT = 304,                 /* BOOLLIT  */
    STRLIT = 305,                  /* STRLIT  */
    UNARY = 306                    /* UNARY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "jucompiler.y"

	char * id;
	struct node * node;

#line 244 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LPAR = 3,                       /* LPAR  */
  YYSYMBOL_BOOL = 4,                       /* BOOL  */
  YYSYMBOL_DOUBLE = 5,                     /* DOUBLE  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_CLASS = 8,                      /* CLASS  */
  YYSYMBOL_LBRACE = 9,                     /* LBRACE  */
  YYSYMBOL_ARROW = 10,                     /* ARROW  */
  YYSYMBOL_ASSIGN = 11,                    /* ASSIGN  */
  YYSYMBOL_RESERVED = 12,                  /* RESERVED  */
  YYSYMBOL_RBRACE = 13,                    /* RBRACE  */
  YYSYMBOL_PARSEINT = 14,                  /* PARSEINT  */
  YYSYMBOL_PUBLIC = 15,                    /* PUBLIC  */
  YYSYMBOL_STATIC = 16,                    /* STATIC  */
  YYSYMBOL_ELSE = 17,                      /* ELSE  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_SEMICOLON = 19,                 /* SEMICOLON  */
  YYSYMBOL_RPAR = 20,                      /* RPAR  */
  YYSYMBOL_STRING = 21,                    /* STRING  */
  YYSYMBOL_COMMA = 22,                     /* COMMA  */
  YYSYMBOL_LSQ = 23,                       /* LSQ  */
  YYSYMBOL_RSQ = 24,                       /* RSQ  */
  YYSYMBOL_IF = 25,                        /* IF  */
  YYSYMBOL_RETURN = 26,                    /* RETURN  */
  YYSYMBOL_PRINT = 27,                     /* PRINT  */
  YYSYMBOL_PLUS = 28,                      /* PLUS  */
  YYSYMBOL_MINUS = 29,                     /* MINUS  */
  YYSYMBOL_STAR = 30,                      /* STAR  */
  YYSYMBOL_DIV = 31,                       /* DIV  */
  YYSYMBOL_MOD = 32,                       /* MOD  */
  YYSYMBOL_AND = 33,                       /* AND  */
  YYSYMBOL_OR = 34,                        /* OR  */
  YYSYMBOL_XOR = 35,                       /* XOR  */
  YYSYMBOL_LSHIFT = 36,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 37,                    /* RSHIFT  */
  YYSYMBOL_EQ = 38,                        /* EQ  */
  YYSYMBOL_GE = 39,                        /* GE  */
  YYSYMBOL_GT = 40,                        /* GT  */
  YYSYMBOL_LE = 41,                        /* LE  */
  YYSYMBOL_LT = 42,                        /* LT  */
  YYSYMBOL_NE = 43,                        /* NE  */
  YYSYMBOL_NOT = 44,                       /* NOT  */
  YYSYMBOL_DOTLENGTH = 45,                 /* DOTLENGTH  */
  YYSYMBOL_ID = 46,                        /* ID  */
  YYSYMBOL_INTLIT = 47,                    /* INTLIT  */
  YYSYMBOL_REALLIT = 48,                   /* REALLIT  */
  YYSYMBOL_BOOLLIT = 49,                   /* BOOLLIT  */
  YYSYMBOL_STRLIT = 50,                    /* STRLIT  */
  YYSYMBOL_UNARY = 51,                     /* UNARY  */
  YYSYMBOL_YYACCEPT = 52,                  /* $accept  */
  YYSYMBOL_Program = 53,                   /* Program  */
  YYSYMBOL_Program2 = 54,                  /* Program2  */
  YYSYMBOL_MethodDecl = 55,                /* MethodDecl  */
  YYSYMBOL_FieldDecl = 56,                 /* FieldDecl  */
  YYSYMBOL_FieldDecl2 = 57,                /* FieldDecl2  */
  YYSYMBOL_Type = 58,                      /* Type  */
  YYSYMBOL_MethodHeader = 59,              /* MethodHeader  */
  YYSYMBOL_MethodHeader2 = 60,             /* MethodHeader2  */
  YYSYMBOL_FormalParams = 61,              /* FormalParams  */
  YYSYMBOL_FormalParams2 = 62,             /* FormalParams2  */
  YYSYMBOL_MethodBody = 63,                /* MethodBody  */
  YYSYMBOL_MethodBody2 = 64,               /* MethodBody2  */
  YYSYMBOL_VarDecl = 65,                   /* VarDecl  */
  YYSYMBOL_VarDecl2 = 66,                  /* VarDecl2  */
  YYSYMBOL_Statement = 67,                 /* Statement  */
  YYSYMBOL_Expr5 = 68,                     /* Expr5  */
  YYSYMBOL_Statement2 = 69,                /* Statement2  */
  YYSYMBOL_Statement3 = 70,                /* Statement3  */
  YYSYMBOL_Statement4 = 71,                /* Statement4  */
  YYSYMBOL_MethodInvocation = 72,          /* MethodInvocation  */
  YYSYMBOL_MethodInvocation2 = 73,         /* MethodInvocation2  */
  YYSYMBOL_MethodInvocation3 = 74,         /* MethodInvocation3  */
  YYSYMBOL_Assignment = 75,                /* Assignment  */
  YYSYMBOL_ParseArgs = 76,                 /* ParseArgs  */
  YYSYMBOL_Expr = 77,                      /* Expr  */
  YYSYMBOL_Expr2 = 78,                     /* Expr2  */
  YYSYMBOL_Expr3 = 79,                     /* Expr3  */
  YYSYMBOL_Expr4 = 80                      /* Expr4  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

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
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  176

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   306


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    46,    46,    53,    54,    55,    56,    59,    62,    76,
      79,    80,    83,    84,    85,    88,    89,    92,    93,    96,
      97,   100,   101,   104,   107,   114,   115,   118,   134,   135,
     138,   146,   158,   183,   194,   195,   196,   197,   200,   201,
     204,   211,   214,   215,   216,   217,   220,   221,   225,   226,
     229,   230,   233,   240,   244,   247,   248,   251,   252,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   282,   283,   286,   287,   288
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "LPAR", "BOOL",
  "DOUBLE", "INT", "VOID", "CLASS", "LBRACE", "ARROW", "ASSIGN",
  "RESERVED", "RBRACE", "PARSEINT", "PUBLIC", "STATIC", "ELSE", "WHILE",
  "SEMICOLON", "RPAR", "STRING", "COMMA", "LSQ", "RSQ", "IF", "RETURN",
  "PRINT", "PLUS", "MINUS", "STAR", "DIV", "MOD", "AND", "OR", "XOR",
  "LSHIFT", "RSHIFT", "EQ", "GE", "GT", "LE", "LT", "NE", "NOT",
  "DOTLENGTH", "ID", "INTLIT", "REALLIT", "BOOLLIT", "STRLIT", "UNARY",
  "$accept", "Program", "Program2", "MethodDecl", "FieldDecl",
  "FieldDecl2", "Type", "MethodHeader", "MethodHeader2", "FormalParams",
  "FormalParams2", "MethodBody", "MethodBody2", "VarDecl", "VarDecl2",
  "Statement", "Expr5", "Statement2", "Statement3", "Statement4",
  "MethodInvocation", "MethodInvocation2", "MethodInvocation3",
  "Assignment", "ParseArgs", "Expr", "Expr2", "Expr3", "Expr4", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-39)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-52)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
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

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
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

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -39,   -39,    28,   -39,   -39,   162,    -3,   -39,   187,   -39,
      45,   -39,     1,   -39,    58,   -32,   -39,   169,   -39,   -39,
     -26,   -39,    59,   -24,   -22,   -19,   -35,   -39,   -39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     9,    10,    11,    31,    40,    23,    50,    51,
     131,    27,    41,    42,   128,    43,    69,    57,    44,   121,
      70,   124,   158,    71,    72,    73,    74,    75,    76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
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
      20,   160,   161,    33,   166,   170,   169,   -26,    34,   171,
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
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

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
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

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
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


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: CLASS ID LBRACE Program2 RBRACE  */
#line 46 "jucompiler.y"
                                                                                                {root = create_node(node_root, "", "Program"); aux = create_node(node_id, (yyvsp[-3].id), "Id"); add_child(root, aux); add_next(aux, (yyvsp[-1].node)); (yyval.node) = root;
																	            if (flag == 2 && flag_error == 0) {
																		            print_tree((yyval.node), 0);
																	            }
                                                                            }
#line 1456 "y.tab.c"
    break;

  case 3: /* Program2: MethodDecl Program2  */
#line 53 "jucompiler.y"
                                                                                                    {(yyval.node) = (yyvsp[-1].node); add_next((yyval.node), (yyvsp[0].node));}
#line 1462 "y.tab.c"
    break;

  case 4: /* Program2: FieldDecl Program2  */
#line 54 "jucompiler.y"
                                                                                                                            {(yyval.node) = (yyvsp[-1].node); add_next((yyval.node), (yyvsp[0].node));}
#line 1468 "y.tab.c"
    break;

  case 5: /* Program2: SEMICOLON Program2  */
#line 55 "jucompiler.y"
                                                                                                                            {(yyval.node) = (yyvsp[0].node);}
#line 1474 "y.tab.c"
    break;

  case 6: /* Program2: %empty  */
#line 56 "jucompiler.y"
                                                                                                                        {(yyval.node) = NULL;}
#line 1480 "y.tab.c"
    break;

  case 7: /* MethodDecl: PUBLIC STATIC MethodHeader MethodBody  */
#line 59 "jucompiler.y"
                                                                                                {(yyval.node) = create_node(node_methods, "", "MethodDecl"); add_child((yyval.node), (yyvsp[-1].node)); add_next((yyvsp[-1].node), (yyvsp[0].node));}
#line 1486 "y.tab.c"
    break;

  case 8: /* FieldDecl: PUBLIC STATIC Type ID FieldDecl2 SEMICOLON  */
#line 62 "jucompiler.y"
                                                                                                {(yyval.node) = create_node(node_var, "", "FieldDecl"); add_child((yyval.node), (yyvsp[-3].node)); add_next((yyvsp[-3].node), create_node(node_id, (yyvsp[-2].id), "Id"));
																	            if ((yyvsp[-1].node) != NULL){
																		            aux = (yyvsp[-1].node);
																	    	        while (aux != NULL) {
																		    	        node_t aux1 = create_node(node_var, "", "FieldDecl");
																			            node_t aux2 = create_node((yyvsp[-3].node)->type, (yyvsp[-3].node)->value, (yyvsp[-3].node)->symbol);
																			            add_child(aux1, aux2);
																			            add_next(aux2, create_node(node_id, aux->value, "Id"));
																		                add_next((yyval.node), aux1);
																		                aux = aux->brother;
																    	            }
                                                                                    free(aux);
																	            }
                                                                            }
#line 1505 "y.tab.c"
    break;

  case 9: /* FieldDecl: error SEMICOLON  */
#line 76 "jucompiler.y"
                                                                                                                                {(yyval.node) = NULL; flag_error = 1;}
#line 1511 "y.tab.c"
    break;

  case 10: /* FieldDecl2: COMMA ID FieldDecl2  */
#line 79 "jucompiler.y"
                                                                                                                        {(yyval.node) = create_node(node_id, (yyvsp[-1].id), "Id"); add_next((yyval.node), (yyvsp[0].node));}
#line 1517 "y.tab.c"
    break;

  case 11: /* FieldDecl2: %empty  */
#line 80 "jucompiler.y"
                                                                                                                        {(yyval.node) = NULL;}
#line 1523 "y.tab.c"
    break;

  case 12: /* Type: BOOL  */
#line 83 "jucompiler.y"
                                                                                                                                {(yyval.node) = create_node(node_terminals, "", "Bool");}
#line 1529 "y.tab.c"
    break;

  case 13: /* Type: INT  */
#line 84 "jucompiler.y"
                                                                                                                                                {(yyval.node) = create_node(node_terminals, "", "Int");}
#line 1535 "y.tab.c"
    break;

  case 14: /* Type: DOUBLE  */
#line 85 "jucompiler.y"
                                                                                                                                        {(yyval.node) = create_node(node_terminals, "", "Double");}
#line 1541 "y.tab.c"
    break;

  case 15: /* MethodHeader: Type ID LPAR MethodHeader2 RPAR  */
#line 88 "jucompiler.y"
                                                                                                {(yyval.node) = create_node(node_methods, "", "MethodHeader"); add_child((yyval.node),(yyvsp[-4].node)); add_next((yyvsp[-4].node), create_node(node_id, (yyvsp[-3].id), "Id"));aux = create_node(node_methods, "", "MethodParams"); add_next((yyvsp[-4].node), aux); add_child(aux, (yyvsp[-1].node));}
#line 1547 "y.tab.c"
    break;

  case 16: /* MethodHeader: VOID ID LPAR MethodHeader2 RPAR  */
#line 89 "jucompiler.y"
                                                                                                {(yyval.node) = create_node(node_methods, "", "MethodHeader"); aux = create_node(node_terminals, "", "Void"); add_child((yyval.node), aux); add_next(aux, create_node(node_id, (yyvsp[-3].id), "Id")); node_t aux2 = create_node(node_methods, "", "MethodParams"); add_next(aux, aux2); add_child(aux2, (yyvsp[-1].node));}
#line 1553 "y.tab.c"
    break;

  case 17: /* MethodHeader2: FormalParams  */
#line 92 "jucompiler.y"
                                                                                                                    {(yyval.node) = (yyvsp[0].node);}
#line 1559 "y.tab.c"
    break;

  case 18: /* MethodHeader2: %empty  */
#line 93 "jucompiler.y"
                                                                                                                        {(yyval.node) = NULL;}
#line 1565 "y.tab.c"
    break;

  case 19: /* FormalParams: Type ID FormalParams2  */
#line 96 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_methods, "", "ParamDecl"); add_child((yyval.node), (yyvsp[-2].node)); aux = create_node(node_id, (yyvsp[-1].id), "Id"); add_next((yyvsp[-2].node), aux); add_next((yyval.node), (yyvsp[0].node));}
#line 1571 "y.tab.c"
    break;

  case 20: /* FormalParams: STRING LSQ RSQ ID  */
#line 97 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_methods, "", "ParamDecl"); aux = create_node(node_methods, "", "StringArray"); add_child((yyval.node), aux); add_next(aux, create_node(node_id, (yyvsp[0].id), "Id"));}
#line 1577 "y.tab.c"
    break;

  case 21: /* FormalParams2: COMMA Type ID FormalParams2  */
#line 100 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_methods, "", "ParamDecl"); aux = create_node(node_id, (yyvsp[-1].id), "Id"); add_child((yyval.node), (yyvsp[-2].node)); add_next((yyvsp[-2].node), aux); add_next((yyval.node), (yyvsp[0].node));}
#line 1583 "y.tab.c"
    break;

  case 22: /* FormalParams2: %empty  */
#line 101 "jucompiler.y"
                                                                            {(yyval.node) = NULL;}
#line 1589 "y.tab.c"
    break;

  case 23: /* MethodBody: LBRACE MethodBody2 RBRACE  */
#line 104 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_methods, "", "MethodBody"); add_child((yyval.node), (yyvsp[-1].node));}
#line 1595 "y.tab.c"
    break;

  case 24: /* MethodBody2: Statement MethodBody2  */
#line 107 "jucompiler.y"
                                                                            {if ((yyvsp[-1].node) != NULL){
																		        (yyval.node) = (yyvsp[-1].node);
																		        add_next((yyval.node), (yyvsp[0].node));
																		    }
																	        else {
																		        (yyval.node) = (yyvsp[0].node);
																	        }}
#line 1607 "y.tab.c"
    break;

  case 25: /* MethodBody2: VarDecl MethodBody2  */
#line 114 "jucompiler.y"
                                                                            {(yyval.node) = (yyvsp[-1].node); add_next((yyval.node), (yyvsp[0].node));}
#line 1613 "y.tab.c"
    break;

  case 26: /* MethodBody2: %empty  */
#line 115 "jucompiler.y"
                                                                            {(yyval.node) = NULL;}
#line 1619 "y.tab.c"
    break;

  case 27: /* VarDecl: Type ID VarDecl2 SEMICOLON  */
#line 118 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_methods, "", "VarDecl"); add_child((yyval.node), (yyvsp[-3].node)); add_next((yyvsp[-3].node), create_node(node_id, (yyvsp[-2].id), "Id"));
																	            if ((yyvsp[-1].node) != NULL){
																		            aux = (yyvsp[-1].node);
																		            while (aux != NULL) {
																			            node_t aux1 = create_node(node_methods, "", "VarDecl");
																			            node_t aux2 = create_node((yyvsp[-3].node)->type, (yyvsp[-3].node)->value, (yyvsp[-3].node)->symbol);
																			            add_child(aux1, aux2);
																			            add_next(aux2, create_node(node_id, aux->value, "Id"));
																			            add_next((yyval.node), aux1);
																			            aux = aux->brother;
																		            }
                                                                                    free(aux);
																	            }
                                                                            }
#line 1638 "y.tab.c"
    break;

  case 28: /* VarDecl2: COMMA ID VarDecl2  */
#line 134 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_id, (yyvsp[-1].id), "Id"); add_next((yyval.node), (yyvsp[0].node));}
#line 1644 "y.tab.c"
    break;

  case 29: /* VarDecl2: %empty  */
#line 135 "jucompiler.y"
                                                                            {(yyval.node) = NULL;}
#line 1650 "y.tab.c"
    break;

  case 30: /* Statement: LBRACE Statement2 RBRACE  */
#line 138 "jucompiler.y"
                                                                                                                {if (count_children((yyvsp[-1].node)) > 1) {
                                                                                aux = create_node(node_statements, "", "Block");
                                                                                (yyval.node) = aux;
                                                                                add_child(aux, (yyvsp[-1].node));
                                                                            }
                                                                            else {
                                                                                (yyval.node) = (yyvsp[-1].node);
                                                                            }}
#line 1663 "y.tab.c"
    break;

  case 31: /* Statement: IF LPAR Expr RPAR Statement  */
#line 146 "jucompiler.y"
                                                                                                {(yyval.node) = create_node(node_statements, "", "If");
                                                                                add_child((yyval.node),(yyvsp[-2].node));
                                                                                aux = create_node(node_statements, "", "Block");
                                                                                if (count_children((yyvsp[0].node)) == 1 && (yyvsp[0].node) != NULL) {
                                                                                    add_next((yyvsp[-2].node), (yyvsp[0].node));
                                                                                    add_next((yyvsp[0].node), aux);
                                                                                }
                                                                                else {
                                                                                    add_next((yyvsp[-2].node), aux);
                                                                                    add_child(aux, (yyvsp[0].node));
                                                                                    add_next(aux, create_node(node_statements, "", "Block"));
                                                                            }}
#line 1680 "y.tab.c"
    break;

  case 32: /* Statement: IF LPAR Expr RPAR Statement ELSE Statement  */
#line 158 "jucompiler.y"
                                                                                                {(yyval.node) = create_node(node_statements, "", "If");
                                                                            add_child((yyval.node),(yyvsp[-4].node));
                                                                            aux = create_node(node_statements, "", "Block");
                                                                            if (count_children((yyvsp[-2].node)) == 1 && (yyvsp[-2].node) != NULL) {
                                                                                add_next((yyvsp[-4].node), (yyvsp[-2].node));
                                                                                if (count_children((yyvsp[0].node)) == 1 && (yyvsp[0].node) != NULL) {
                                                                                    add_next((yyvsp[-2].node), (yyvsp[0].node));
                                                                                }
                                                                                else {
                                                                                    add_next((yyvsp[-2].node), aux);
                                                                                    add_child(aux, (yyvsp[0].node));
                                                                                }
                                                                            }
                                                                            else {
                                                                                add_next((yyvsp[-4].node), aux);
                                                                                add_child(aux, (yyvsp[-2].node));
                                                                                if (count_children((yyvsp[0].node)) == 1 && (yyvsp[0].node) != NULL) {
                                                                                    add_next(aux, (yyvsp[0].node));
                                                                                }
                                                                                else {
                                                                                    node_t aux2 = create_node(node_statements, "", "Block");
                                                                                    add_next(aux, aux2);
                                                                                    add_child(aux2, (yyvsp[0].node));
                                                                                }
                                                                            }}
#line 1710 "y.tab.c"
    break;

  case 33: /* Statement: WHILE LPAR Expr RPAR Statement  */
#line 183 "jucompiler.y"
                                                                                                                {(yyval.node) = create_node(node_statements, "", "While");
                                                                                add_child((yyval.node), (yyvsp[-2].node));
                                                                                if (count_children((yyvsp[0].node)) == 1 && (yyvsp[0].node) != NULL) {
                                                                                    add_next((yyvsp[-2].node), (yyvsp[0].node));
                                                                                }
                                                                                else {
                                                                                    aux = create_node(node_statements, "", "Block");
                                                                                    add_next((yyvsp[-2].node), aux);
                                                                                    add_child(aux, (yyvsp[0].node));
                                                                                }
                                                                            }
#line 1726 "y.tab.c"
    break;

  case 34: /* Statement: RETURN Expr5 SEMICOLON  */
#line 194 "jucompiler.y"
                                                                                                                    {(yyval.node) = create_node(node_statements, "", "Return"); add_child((yyval.node), (yyvsp[-1].node));}
#line 1732 "y.tab.c"
    break;

  case 35: /* Statement: Statement3 SEMICOLON  */
#line 195 "jucompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1738 "y.tab.c"
    break;

  case 36: /* Statement: PRINT LPAR Statement4 RPAR SEMICOLON  */
#line 196 "jucompiler.y"
                                                                                        {(yyval.node) = create_node(node_statements, "", "Print"); add_child((yyval.node), (yyvsp[-2].node));}
#line 1744 "y.tab.c"
    break;

  case 37: /* Statement: error SEMICOLON  */
#line 197 "jucompiler.y"
                                                                                                                                {(yyval.node) = NULL; flag_error = 1;}
#line 1750 "y.tab.c"
    break;

  case 38: /* Expr5: Expr  */
#line 200 "jucompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 1756 "y.tab.c"
    break;

  case 39: /* Expr5: %empty  */
#line 201 "jucompiler.y"
                                                                                                                                    {(yyval.node) = NULL;}
#line 1762 "y.tab.c"
    break;

  case 40: /* Statement2: Statement Statement2  */
#line 204 "jucompiler.y"
                                                                            {if ((yyvsp[-1].node) != NULL) {
																		        (yyval.node) = (yyvsp[-1].node);
																		        add_next((yyval.node), (yyvsp[0].node));
                                                                            }
                                                                            else {
                                                                                (yyval.node) = (yyvsp[0].node);
                                                                            }}
#line 1774 "y.tab.c"
    break;

  case 41: /* Statement2: %empty  */
#line 211 "jucompiler.y"
                                                                            {(yyval.node) = NULL;}
#line 1780 "y.tab.c"
    break;

  case 42: /* Statement3: MethodInvocation  */
#line 214 "jucompiler.y"
                                                                                                                {(yyval.node) = (yyvsp[0].node);}
#line 1786 "y.tab.c"
    break;

  case 43: /* Statement3: Assignment  */
#line 215 "jucompiler.y"
                                                                                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 1792 "y.tab.c"
    break;

  case 44: /* Statement3: ParseArgs  */
#line 216 "jucompiler.y"
                                                                                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 1798 "y.tab.c"
    break;

  case 45: /* Statement3: %empty  */
#line 217 "jucompiler.y"
                                                                            {(yyval.node) = NULL;}
#line 1804 "y.tab.c"
    break;

  case 46: /* Statement4: Expr  */
#line 220 "jucompiler.y"
                                                                                                                            {(yyval.node) = (yyvsp[0].node);}
#line 1810 "y.tab.c"
    break;

  case 47: /* Statement4: STRLIT  */
#line 221 "jucompiler.y"
                                                                                                                            {(yyval.node) = create_node(node_terminals, (yyvsp[0].id), "StrLit");}
#line 1816 "y.tab.c"
    break;

  case 48: /* MethodInvocation: ID LPAR MethodInvocation2 RPAR  */
#line 225 "jucompiler.y"
                                                                                                {(yyval.node) = create_node(node_operators, "", "Call"); aux = create_node(node_id, (yyvsp[-3].id), "Id"); add_child((yyval.node), aux); add_next(aux, (yyvsp[-1].node));}
#line 1822 "y.tab.c"
    break;

  case 49: /* MethodInvocation: ID LPAR error RPAR  */
#line 226 "jucompiler.y"
                                                                                                                                {(yyval.node) = NULL; flag_error = 1;}
#line 1828 "y.tab.c"
    break;

  case 50: /* MethodInvocation2: Expr MethodInvocation3  */
#line 229 "jucompiler.y"
                                                                                                    {(yyval.node) = (yyvsp[-1].node); add_next((yyval.node), (yyvsp[0].node));}
#line 1834 "y.tab.c"
    break;

  case 51: /* MethodInvocation2: %empty  */
#line 230 "jucompiler.y"
                                                                                                                                        {(yyval.node) = NULL;}
#line 1840 "y.tab.c"
    break;

  case 52: /* MethodInvocation3: COMMA Expr MethodInvocation3  */
#line 233 "jucompiler.y"
                                                                                                    {if((yyvsp[-1].node)!=NULL) {
                                                                                (yyval.node)=(yyvsp[-1].node); 
                                                                                add_next((yyval.node), (yyvsp[0].node));
                                                                            }
                                                                            else {
                                                                                (yyval.node)=(yyvsp[-1].node);
                                                                            }}
#line 1852 "y.tab.c"
    break;

  case 53: /* MethodInvocation3: %empty  */
#line 240 "jucompiler.y"
                                                                                                                                        {(yyval.node) = NULL;}
#line 1858 "y.tab.c"
    break;

  case 54: /* Assignment: ID ASSIGN Expr  */
#line 244 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_operators, "", "Assign"); aux = create_node(node_id, (yyvsp[-2].id), "Id"); add_child((yyval.node), aux); add_next(aux, (yyvsp[0].node));}
#line 1864 "y.tab.c"
    break;

  case 55: /* ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR  */
#line 247 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_operators, "", "ParseArgs"); aux = create_node(node_id, (yyvsp[-4].id), "Id"); add_child((yyval.node), aux); add_next(aux, (yyvsp[-2].node));}
#line 1870 "y.tab.c"
    break;

  case 56: /* ParseArgs: PARSEINT LPAR error RPAR  */
#line 248 "jucompiler.y"
                                                                            {(yyval.node) = NULL; flag_error = 1;}
#line 1876 "y.tab.c"
    break;

  case 57: /* Expr: Assignment  */
#line 251 "jucompiler.y"
                                                                            {(yyval.node) = (yyvsp[0].node);}
#line 1882 "y.tab.c"
    break;

  case 58: /* Expr: Expr2  */
#line 252 "jucompiler.y"
                                                                            {(yyval.node) = (yyvsp[0].node);}
#line 1888 "y.tab.c"
    break;

  case 59: /* Expr2: Expr2 PLUS Expr2  */
#line 255 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_operators, "", "Add"); add_child((yyval.node), (yyvsp[-2].node)); add_next((yyvsp[-2].node), (yyvsp[0].node));}
#line 1894 "y.tab.c"
    break;

  case 60: /* Expr2: Expr2 MINUS Expr2  */
#line 256 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_operators, "", "Sub"); add_child((yyval.node), (yyvsp[-2].node)); add_next((yyvsp[-2].node), (yyvsp[0].node));}
#line 1900 "y.tab.c"
    break;

  case 61: /* Expr2: Expr2 STAR Expr2  */
#line 257 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_operators, "", "Mul"); add_child((yyval.node), (yyvsp[-2].node)); add_next((yyvsp[-2].node), (yyvsp[0].node));}
#line 1906 "y.tab.c"
    break;

  case 62: /* Expr2: Expr2 DIV Expr2  */
#line 258 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_operators, "", "Div"); add_child((yyval.node), (yyvsp[-2].node)); add_next((yyvsp[-2].node), (yyvsp[0].node));}
#line 1912 "y.tab.c"
    break;

  case 63: /* Expr2: Expr2 MOD Expr2  */
#line 259 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_operators, "", "Mod"); add_child((yyval.node), (yyvsp[-2].node)); add_next((yyvsp[-2].node), (yyvsp[0].node));}
#line 1918 "y.tab.c"
    break;

  case 64: /* Expr2: Expr2 AND Expr2  */
#line 260 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_operators, "", "And"); add_child((yyval.node), (yyvsp[-2].node)); add_next((yyvsp[-2].node), (yyvsp[0].node));}
#line 1924 "y.tab.c"
    break;

  case 65: /* Expr2: Expr2 OR Expr2  */
#line 261 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_operators, "", "Or"); add_child((yyval.node), (yyvsp[-2].node)); add_next((yyvsp[-2].node), (yyvsp[0].node));}
#line 1930 "y.tab.c"
    break;

  case 66: /* Expr2: Expr2 XOR Expr2  */
#line 262 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_operators, "", "Xor"); add_child((yyval.node), (yyvsp[-2].node)); add_next((yyvsp[-2].node), (yyvsp[0].node));}
#line 1936 "y.tab.c"
    break;

  case 67: /* Expr2: Expr2 LSHIFT Expr2  */
#line 263 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_operators, "", "Lshift"); add_child((yyval.node), (yyvsp[-2].node)); add_next((yyvsp[-2].node), (yyvsp[0].node));}
#line 1942 "y.tab.c"
    break;

  case 68: /* Expr2: Expr2 RSHIFT Expr2  */
#line 264 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_operators, "", "Rshift"); add_child((yyval.node), (yyvsp[-2].node)); add_next((yyvsp[-2].node), (yyvsp[0].node));}
#line 1948 "y.tab.c"
    break;

  case 69: /* Expr2: Expr2 EQ Expr2  */
#line 265 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_operators, "", "Eq"); add_child((yyval.node), (yyvsp[-2].node)); add_next((yyvsp[-2].node), (yyvsp[0].node));}
#line 1954 "y.tab.c"
    break;

  case 70: /* Expr2: Expr2 GE Expr2  */
#line 266 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_operators, "", "Ge"); add_child((yyval.node), (yyvsp[-2].node)); add_next((yyvsp[-2].node), (yyvsp[0].node));}
#line 1960 "y.tab.c"
    break;

  case 71: /* Expr2: Expr2 GT Expr2  */
#line 267 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_operators, "", "Gt"); add_child((yyval.node), (yyvsp[-2].node)); add_next((yyvsp[-2].node), (yyvsp[0].node));}
#line 1966 "y.tab.c"
    break;

  case 72: /* Expr2: Expr2 LE Expr2  */
#line 268 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_operators, "", "Le"); add_child((yyval.node), (yyvsp[-2].node)); add_next((yyvsp[-2].node), (yyvsp[0].node));}
#line 1972 "y.tab.c"
    break;

  case 73: /* Expr2: Expr2 LT Expr2  */
#line 269 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_operators, "", "Lt"); add_child((yyval.node), (yyvsp[-2].node)); add_next((yyvsp[-2].node), (yyvsp[0].node));}
#line 1978 "y.tab.c"
    break;

  case 74: /* Expr2: Expr2 NE Expr2  */
#line 270 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_operators, "", "Ne"); add_child((yyval.node), (yyvsp[-2].node)); add_next((yyvsp[-2].node), (yyvsp[0].node));}
#line 1984 "y.tab.c"
    break;

  case 75: /* Expr2: MINUS Expr2  */
#line 271 "jucompiler.y"
                                                                              {(yyval.node) = create_node(node_operators, "", "Minus"); add_child((yyval.node), (yyvsp[0].node));}
#line 1990 "y.tab.c"
    break;

  case 76: /* Expr2: PLUS Expr2  */
#line 272 "jucompiler.y"
                                                                              {(yyval.node) = create_node(node_operators, "", "Plus"); add_child((yyval.node), (yyvsp[0].node));}
#line 1996 "y.tab.c"
    break;

  case 77: /* Expr2: NOT Expr2  */
#line 273 "jucompiler.y"
                                                                                       {(yyval.node) = create_node(node_operators, "", "Not"); add_child((yyval.node), (yyvsp[0].node));}
#line 2002 "y.tab.c"
    break;

  case 78: /* Expr2: LPAR Expr RPAR  */
#line 274 "jucompiler.y"
                                                                            {(yyval.node) = (yyvsp[-1].node);}
#line 2008 "y.tab.c"
    break;

  case 79: /* Expr2: LPAR error RPAR  */
#line 275 "jucompiler.y"
                                                                            {(yyval.node) = NULL; flag_error = 1;}
#line 2014 "y.tab.c"
    break;

  case 80: /* Expr2: Expr3  */
#line 276 "jucompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 2020 "y.tab.c"
    break;

  case 81: /* Expr2: ID  */
#line 277 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_id, (yyvsp[0].id), "Id");}
#line 2026 "y.tab.c"
    break;

  case 82: /* Expr2: ID DOTLENGTH  */
#line 278 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_operators, "", "Length"); add_child((yyval.node), create_node(node_id, (yyvsp[-1].id), "Id"));}
#line 2032 "y.tab.c"
    break;

  case 83: /* Expr2: Expr4  */
#line 279 "jucompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 2038 "y.tab.c"
    break;

  case 84: /* Expr3: MethodInvocation  */
#line 282 "jucompiler.y"
                                                                            {(yyval.node) = (yyvsp[0].node);}
#line 2044 "y.tab.c"
    break;

  case 85: /* Expr3: ParseArgs  */
#line 283 "jucompiler.y"
                                                                            {(yyval.node) = (yyvsp[0].node);}
#line 2050 "y.tab.c"
    break;

  case 86: /* Expr4: INTLIT  */
#line 286 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_terminals, (yyvsp[0].id), "DecLit");}
#line 2056 "y.tab.c"
    break;

  case 87: /* Expr4: REALLIT  */
#line 287 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_terminals, (yyvsp[0].id), "RealLit");}
#line 2062 "y.tab.c"
    break;

  case 88: /* Expr4: BOOLLIT  */
#line 288 "jucompiler.y"
                                                                            {(yyval.node) = create_node(node_terminals, (yyvsp[0].id), "BoolLit");}
#line 2068 "y.tab.c"
    break;


#line 2072 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 291 "jucompiler.y"
