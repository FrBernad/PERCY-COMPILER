/* A Bison parser, made by GNU Bison 3.7.5.  */

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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
    NUMBER = 258,                  /* NUMBER  */
    IF = 259,                      /* IF  */
    ELSE = 260,                    /* ELSE  */
    FOR = 261,                     /* FOR  */
    DO = 262,                      /* DO  */
    WHILE = 263,                   /* WHILE  */
    RETURN = 264,                  /* RETURN  */
    OP_AND = 265,                  /* OP_AND  */
    OP_OR = 266,                   /* OP_OR  */
    OP_GREATER = 267,              /* OP_GREATER  */
    OP_GREATER_OR_EQ = 268,        /* OP_GREATER_OR_EQ  */
    OP_LESS = 269,                 /* OP_LESS  */
    OP_LESS_OR_EQ = 270,           /* OP_LESS_OR_EQ  */
    OP_EQ = 271,                   /* OP_EQ  */
    OP_NEQ = 272,                  /* OP_NEQ  */
    ELEMENT = 273,                 /* ELEMENT  */
    NEW = 274,                     /* NEW  */
    HTML = 275,                    /* HTML  */
    NAVBAR = 276,                  /* NAVBAR  */
    FOOTER = 277,                  /* FOOTER  */
    CONTAINER = 278,               /* CONTAINER  */
    HEADER = 279,                  /* HEADER  */
    MAIN = 280,                    /* MAIN  */
    ID = 281,                      /* ID  */
    OR = 282,                      /* OR  */
    AND = 283,                     /* AND  */
    LE = 284,                      /* LE  */
    GE = 285,                      /* GE  */
    EQ = 286,                      /* EQ  */
    NE = 287,                      /* NE  */
    UMINUS = 288                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUMBER 258
#define IF 259
#define ELSE 260
#define FOR 261
#define DO 262
#define WHILE 263
#define RETURN 264
#define OP_AND 265
#define OP_OR 266
#define OP_GREATER 267
#define OP_GREATER_OR_EQ 268
#define OP_LESS 269
#define OP_LESS_OR_EQ 270
#define OP_EQ 271
#define OP_NEQ 272
#define ELEMENT 273
#define NEW 274
#define HTML 275
#define NAVBAR 276
#define FOOTER 277
#define CONTAINER 278
#define HEADER 279
#define MAIN 280
#define ID 281
#define OR 282
#define AND 283
#define LE 284
#define GE 285
#define EQ 286
#define NE 287
#define UMINUS 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
