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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 14 "jucompiler.y"
{
	char * id;
	struct node * node;
}
/* Line 1529 of yacc.c.  */
#line 156 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

