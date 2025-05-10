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
    APP_NAME = 258,                /* APP_NAME  */
    USERS = 259,                   /* USERS  */
    SETTINGS = 260,                /* SETTINGS  */
    PERMISSIONS = 261,             /* PERMISSIONS  */
    EQUALS = 262,                  /* EQUALS  */
    OPEN_BRACE = 263,              /* OPEN_BRACE  */
    CLOSED_BRACE = 264,            /* CLOSED_BRACE  */
    LIST_START = 265,              /* LIST_START  */
    LIST_END = 266,                /* LIST_END  */
    COMMA = 267,                   /* COMMA  */
    SEMICOLON = 268,               /* SEMICOLON  */
    STRING = 269,                  /* STRING  */
    TRUE = 270,                    /* TRUE  */
    FALSE = 271,                   /* FALSE  */
    NUMBER = 272,                  /* NUMBER  */
    NAME = 273,                    /* NAME  */
    AGE = 274,                     /* AGE  */
    MODE = 275,                    /* MODE  */
    LOGGING = 276,                 /* LOGGING  */
    MAX_USERS = 277,               /* MAX_USERS  */
    USER = 278,                    /* USER  */
    RIGHTS = 279                   /* RIGHTS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define APP_NAME 258
#define USERS 259
#define SETTINGS 260
#define PERMISSIONS 261
#define EQUALS 262
#define OPEN_BRACE 263
#define CLOSED_BRACE 264
#define LIST_START 265
#define LIST_END 266
#define COMMA 267
#define SEMICOLON 268
#define STRING 269
#define TRUE 270
#define FALSE 271
#define NUMBER 272
#define NAME 273
#define AGE 274
#define MODE 275
#define LOGGING 276
#define MAX_USERS 277
#define USER 278
#define RIGHTS 279

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 45 "yacc_source.y"

    char* str;
    int number;

#line 120 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
