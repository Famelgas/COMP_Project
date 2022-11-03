/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 7 "jucompiler.y"
{
	char * id;
	struct node * node;
}
/* Line 1529 of yacc.c.  */
#line 154 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

