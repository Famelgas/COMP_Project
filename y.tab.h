/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
    STRLIT = 304,                  /* STRLIT  */
    BOOLLIT = 305,                 /* BOOLLIT  */
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
#define STRLIT 304
#define BOOLLIT 305
#define UNARY 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "jucompiler.y"

	char *id;
	struct Node *node;

#line 174 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
