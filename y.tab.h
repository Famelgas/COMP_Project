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
    RBRACE = 267,                  /* RBRACE  */
    PARSEINT = 268,                /* PARSEINT  */
    PUBLIC = 269,                  /* PUBLIC  */
    STATIC = 270,                  /* STATIC  */
    ELSE = 271,                    /* ELSE  */
    WHILE = 272,                   /* WHILE  */
    SEMICOLON = 273,               /* SEMICOLON  */
    RPAR = 274,                    /* RPAR  */
    STRING = 275,                  /* STRING  */
    COMMA = 276,                   /* COMMA  */
    LSQ = 277,                     /* LSQ  */
    RSQ = 278,                     /* RSQ  */
    IF = 279,                      /* IF  */
    RETURN = 280,                  /* RETURN  */
    PRINT = 281,                   /* PRINT  */
    PLUS = 282,                    /* PLUS  */
    MINUS = 283,                   /* MINUS  */
    STAR = 284,                    /* STAR  */
    DIV = 285,                     /* DIV  */
    MOD = 286,                     /* MOD  */
    AND = 287,                     /* AND  */
    OR = 288,                      /* OR  */
    XOR = 289,                     /* XOR  */
    LSHIFT = 290,                  /* LSHIFT  */
    RSHIFT = 291,                  /* RSHIFT  */
    EQ = 292,                      /* EQ  */
    GE = 293,                      /* GE  */
    GT = 294,                      /* GT  */
    LE = 295,                      /* LE  */
    LT = 296,                      /* LT  */
    NE = 297,                      /* NE  */
    NOT = 298,                     /* NOT  */
    DOTLENGTH = 299,               /* DOTLENGTH  */
    ID = 300,                      /* ID  */
    INTLIT = 301,                  /* INTLIT  */
    REALLIT = 302,                 /* REALLIT  */
    BOOLLIT = 303,                 /* BOOLLIT  */
    STRLIT = 304,                  /* STRLIT  */
    UNARY = 305                    /* UNARY  */
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "jucompiler.y"

	char * id;
	struct node * node;

#line 172 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
