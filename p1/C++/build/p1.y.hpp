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

#ifndef YY_YY_ECE566_PROJECTS_P1_C_BUILD_P1_Y_HPP_INCLUDED
# define YY_YY_ECE566_PROJECTS_P1_C_BUILD_P1_Y_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
    IN = 258,                      /* IN  */
    FINAL = 259,                   /* FINAL  */
    ERROR = 260,                   /* ERROR  */
    NUMBER = 261,                  /* NUMBER  */
    ID = 262,                      /* ID  */
    BINV = 263,                    /* BINV  */
    INV = 264,                     /* INV  */
    PLUS = 265,                    /* PLUS  */
    MINUS = 266,                   /* MINUS  */
    XOR = 267,                     /* XOR  */
    AND = 268,                     /* AND  */
    OR = 269,                      /* OR  */
    MUL = 270,                     /* MUL  */
    DIV = 271,                     /* DIV  */
    MOD = 272,                     /* MOD  */
    COMMA = 273,                   /* COMMA  */
    ENDLINE = 274,                 /* ENDLINE  */
    ASSIGN = 275,                  /* ASSIGN  */
    LBRACKET = 276,                /* LBRACKET  */
    RBRACKET = 277,                /* RBRACKET  */
    LPAREN = 278,                  /* LPAREN  */
    RPAREN = 279,                  /* RPAREN  */
    NONE = 280,                    /* NONE  */
    COLON = 281,                   /* COLON  */
    REDUCE = 282,                  /* REDUCE  */
    EXPAND = 283                   /* EXPAND  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 47 "p1.y"

  vector<string> *params_list;
  Value *union_value;
  char *union_id;
  int union_number;

#line 99 "/ece566/projects/p1/c++/build/p1.y.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_ECE566_PROJECTS_P1_C_BUILD_P1_Y_HPP_INCLUDED  */
