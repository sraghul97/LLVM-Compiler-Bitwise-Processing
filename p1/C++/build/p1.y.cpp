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
#line 1 "p1.y"

#include <cstdio>
#include <list>
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>
#include <unordered_map>

#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

#include "llvm/Bitcode/BitcodeReader.h"
#include "llvm/Bitcode/BitcodeWriter.h"
#include "llvm/Support/SystemUtils.h"
#include "llvm/Support/ToolOutputFile.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Support/FileSystem.h"

using namespace llvm;
using namespace std;


// Need for parser and scanner
extern FILE *yyin;
int yylex();
void yyerror(const char*);
int yyparse();
 
// Needed for LLVM
string funName;
Module *M;
LLVMContext TheContext;
IRBuilder<> Builder(TheContext);

unordered_map<string, Value *> id_mapping_table;

#line 114 "/ece566/projects/p1/c++/build/p1.y.cpp"

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

#include "p1.y.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IN = 3,                         /* IN  */
  YYSYMBOL_FINAL = 4,                      /* FINAL  */
  YYSYMBOL_ERROR = 5,                      /* ERROR  */
  YYSYMBOL_NUMBER = 6,                     /* NUMBER  */
  YYSYMBOL_ID = 7,                         /* ID  */
  YYSYMBOL_BINV = 8,                       /* BINV  */
  YYSYMBOL_INV = 9,                        /* INV  */
  YYSYMBOL_PLUS = 10,                      /* PLUS  */
  YYSYMBOL_MINUS = 11,                     /* MINUS  */
  YYSYMBOL_XOR = 12,                       /* XOR  */
  YYSYMBOL_AND = 13,                       /* AND  */
  YYSYMBOL_OR = 14,                        /* OR  */
  YYSYMBOL_MUL = 15,                       /* MUL  */
  YYSYMBOL_DIV = 16,                       /* DIV  */
  YYSYMBOL_MOD = 17,                       /* MOD  */
  YYSYMBOL_COMMA = 18,                     /* COMMA  */
  YYSYMBOL_ENDLINE = 19,                   /* ENDLINE  */
  YYSYMBOL_ASSIGN = 20,                    /* ASSIGN  */
  YYSYMBOL_LBRACKET = 21,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 22,                  /* RBRACKET  */
  YYSYMBOL_LPAREN = 23,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 24,                    /* RPAREN  */
  YYSYMBOL_NONE = 25,                      /* NONE  */
  YYSYMBOL_COLON = 26,                     /* COLON  */
  YYSYMBOL_REDUCE = 27,                    /* REDUCE  */
  YYSYMBOL_EXPAND = 28,                    /* EXPAND  */
  YYSYMBOL_YYACCEPT = 29,                  /* $accept  */
  YYSYMBOL_program = 30,                   /* program  */
  YYSYMBOL_inputs = 31,                    /* inputs  */
  YYSYMBOL_params_list = 32,               /* params_list  */
  YYSYMBOL_final = 33,                     /* final  */
  YYSYMBOL_endline_opt = 34,               /* endline_opt  */
  YYSYMBOL_statements_opt = 35,            /* statements_opt  */
  YYSYMBOL_statements = 36,                /* statements  */
  YYSYMBOL_statement = 37,                 /* statement  */
  YYSYMBOL_ensemble = 38,                  /* ensemble  */
  YYSYMBOL_expr = 39                       /* expr  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   117

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  41
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  95

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    79,    79,    85,   115,   131,   137,   144,   152,   153,
     156,   157,   160,   161,   164,   168,   187,   208,   212,   218,
     230,   245,   259,   277,   281,   285,   289,   293,   297,   301,
     305,   309,   313,   317,   321,   339,   344,   350,   362,   374,
     388,   407
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
  "\"end of file\"", "error", "\"invalid token\"", "IN", "FINAL", "ERROR",
  "NUMBER", "ID", "BINV", "INV", "PLUS", "MINUS", "XOR", "AND", "OR",
  "MUL", "DIV", "MOD", "COMMA", "ENDLINE", "ASSIGN", "LBRACKET",
  "RBRACKET", "LPAREN", "RPAREN", "NONE", "COLON", "REDUCE", "EXPAND",
  "$accept", "program", "inputs", "params_list", "final", "endline_opt",
  "statements_opt", "statements", "statement", "ensemble", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-20)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      22,    11,    57,    33,   -20,    42,   -15,   -20,    -4,    84,
      33,   -20,   -20,    92,   -20,    74,    14,    14,    14,   -20,
     -20,   -20,    14,   -20,     3,    14,    14,    14,    88,    86,
      -6,    39,    -7,    68,    85,   -20,    14,    64,    64,   -10,
      89,    90,    91,    93,    14,    14,   -20,    14,    14,    14,
      14,    14,    14,    14,    14,   101,    95,   -20,   -20,   -20,
      21,    96,    14,    14,    14,    14,    20,    56,    80,    80,
     -20,   -20,    80,   -20,   -20,   -20,   -20,    14,   -20,    14,
      40,    65,    66,    67,   -20,   102,    87,    41,   -20,   -20,
     -20,   -20,   -20,   -20,   -20
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    10,     5,     0,     0,     1,     0,     0,
      11,    12,     4,     0,     3,     0,     0,     0,     0,     2,
      13,     6,     0,    23,    21,     0,     0,     0,     0,     0,
       0,    17,     0,     8,     0,    22,     0,    30,    29,     0,
       0,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,     7,    15,
       0,    35,     0,     0,     0,     0,     0,    19,    24,    25,
      26,    27,    28,    31,    32,    33,    18,     0,    34,     0,
       0,     0,     0,     0,    41,     0,     0,     0,    40,    39,
      37,    38,    20,    16,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   100,   -17,
     -19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     6,    19,    58,     9,    10,    11,    30,
      31
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      32,    33,    15,    13,    14,    34,    37,    38,    45,    35,
      39,    45,    45,    46,    61,    56,    16,    17,     4,    60,
      23,    24,    25,    26,    36,     1,    67,    66,    68,    69,
      70,    71,    72,    73,    74,    75,     5,    27,    45,    45,
       8,    28,    29,    78,    84,    80,    81,    82,    83,    47,
      48,    49,    50,    51,    52,    53,    54,     7,    45,    45,
      86,    12,    87,    94,    88,    55,    47,    48,    49,    50,
      51,    52,    53,    54,    47,    48,    49,    50,    51,    52,
      53,    54,    85,    45,    45,    45,    45,    57,    18,    89,
      90,    91,    49,    50,    22,    52,    53,    54,    40,    21,
      41,    42,    43,    45,    59,    45,    93,    76,    92,    44,
      20,     0,    62,    63,    64,    77,    65,    79
};

static const yytype_int8 yycheck[] =
{
      17,    18,     6,    18,    19,    22,    25,    26,    18,     6,
      27,    18,    18,    19,    24,    22,    20,    21,     7,    36,
       6,     7,     8,     9,    21,     3,    45,    44,    47,    48,
      49,    50,    51,    52,    53,    54,    25,    23,    18,    18,
       7,    27,    28,    22,    24,    62,    63,    64,    65,    10,
      11,    12,    13,    14,    15,    16,    17,     0,    18,    18,
      77,    19,    79,    22,    24,    26,    10,    11,    12,    13,
      14,    15,    16,    17,    10,    11,    12,    13,    14,    15,
      16,    17,    26,    18,    18,    18,    18,    19,     4,    24,
      24,    24,    12,    13,    20,    15,    16,    17,    10,     7,
      12,    13,    14,    18,    19,    18,    19,     6,     6,    23,
      10,    -1,    23,    23,    23,    20,    23,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    30,    31,     7,    25,    32,     0,     7,    35,
      36,    37,    19,    18,    19,     6,    20,    21,     4,    33,
      37,     7,    20,     6,     7,     8,     9,    23,    27,    28,
      38,    39,    38,    38,    38,     6,    21,    39,    39,    38,
      10,    12,    13,    14,    23,    18,    19,    10,    11,    12,
      13,    14,    15,    16,    17,    26,    22,    19,    34,    19,
      38,    24,    23,    23,    23,    23,    38,    39,    39,    39,
      39,    39,    39,    39,    39,    39,     6,    20,    22,    21,
      38,    38,    38,    38,    24,    26,    38,    38,    24,    24,
      24,    24,     6,    19,    22
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    29,    30,    31,    31,    32,    32,    33,    34,    34,
      35,    35,    36,    36,    37,    37,    37,    38,    38,    38,
      38,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     3,     1,     3,     3,     0,     1,
       0,     1,     1,     2,     4,     5,     7,     1,     3,     3,
       5,     1,     2,     1,     3,     3,     3,     3,     3,     2,
       2,     3,     3,     3,     4,     3,     6,     5,     5,     5,
       5,     4
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
  case 2: /* program: inputs statements_opt final  */
#line 80 "p1.y"
{
  YYACCEPT;
}
#line 1198 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 3: /* inputs: IN params_list ENDLINE  */
#line 86 "p1.y"
{  
  std::vector<Type*> param_types;
  for(auto s: *(yyvsp[-1].params_list))
    {
      param_types.push_back(Builder.getInt32Ty());
    }
  ArrayRef<Type*> Params (param_types);
  
  // Create int function type with no arguments
  FunctionType *FunType = 
    FunctionType::get(Builder.getInt32Ty(),Params,false);

  // Create a main function
  Function *Function = Function::Create(FunType,GlobalValue::ExternalLinkage,funName,M);

  int arg_no=0;
  for(auto &a: Function->args()) {
    // iterate over arguments of function
    // match name to position
    Value *arg_ptr = &a;   // as it loops, refers first to a, then b, then c and so on
    id_mapping_table[(yyvsp[-1].params_list)->at(arg_no)] = arg_ptr;   // Store the argument pointer in the map
    arg_no++;       // Move to the next argument position
  }
  
  //Add a basic block to main to hold instructions, and set Builder
  //to insert there
  Builder.SetInsertPoint(BasicBlock::Create(TheContext, "entry", Function));

}
#line 1232 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 4: /* inputs: IN NONE ENDLINE  */
#line 116 "p1.y"
{ 
  // Create int function type with no arguments
  FunctionType *FunType = 
    FunctionType::get(Builder.getInt32Ty(),false);

  // Create a main function
  Function *Function = Function::Create(FunType,  
         GlobalValue::ExternalLinkage,funName,M);

  //Add a basic block to main to hold instructions, and set Builder
  //to insert there
  Builder.SetInsertPoint(BasicBlock::Create(TheContext, "entry", Function));
}
#line 1250 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 5: /* params_list: ID  */
#line 132 "p1.y"
{
  (yyval.params_list) = new vector<string>;
  // add the ID to vector
  (yyval.params_list)->push_back((yyvsp[0].union_id));
}
#line 1260 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 6: /* params_list: params_list COMMA ID  */
#line 138 "p1.y"
{
  // add the ID to $1
  (yyval.params_list)->push_back((yyvsp[0].union_id));
}
#line 1269 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 7: /* final: FINAL ensemble endline_opt  */
#line 145 "p1.y"
{
  
  Builder.CreateRet((yyvsp[-1].union_value));
  return 0; /* program is done */
}
#line 1279 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 14: /* statement: ID ASSIGN ensemble ENDLINE  */
#line 165 "p1.y"
{
  id_mapping_table[(yyvsp[-3].union_id)] = (yyvsp[-1].union_value);
}
#line 1287 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 15: /* statement: ID NUMBER ASSIGN ensemble ENDLINE  */
#line 169 "p1.y"
{
  if (id_mapping_table.find((yyvsp[-4].union_id)) == id_mapping_table.end())
  {
    // Check if key $1 is not found in id_mapping_table
    printf("ERROR! It’s illegal to set a bit of '%s' before defining '%s'\n",string((yyvsp[-4].union_id)).c_str(), string((yyvsp[-4].union_id)).c_str());
    YYABORT; // Abort parsing if key $1 is not found
  }
  Value *id_value = id_mapping_table[(yyvsp[-4].union_id)]; // Get the value corresponding to key $1
  Value *ensemble_value_1 = Builder.CreateSRem(Builder.getInt32((yyvsp[-3].union_number)), Builder.getInt32(32));
  Value *ensemble_value_2 = Builder.CreateAnd((yyvsp[-1].union_value), Builder.getInt32(1));
  ensemble_value_2 = Builder.CreateShl(ensemble_value_2, ensemble_value_1); // Shift ensemble_value_2 left by ensemble_value_1
  
  Value *bit_mask = Builder.CreateNot(Builder.CreateShl(Builder.getInt32(1), ensemble_value_1));  // Create a bitmask by shifting 1 left by ensemble_value_1 and then negating it
  id_value = Builder.CreateAnd(id_value, bit_mask); // Clear the bit in id_value at ensemble_value_1 position
  id_value = Builder.CreateOr(id_value, ensemble_value_2); // Set the bit in id_value at ensemble_value_1 position
  id_mapping_table[(yyvsp[-4].union_id)] = id_value; // Update the value in id_mapping_table for key $1
  (yyval.union_value) = id_mapping_table[(yyvsp[-4].union_id)]; // Set the return value to the updated value for key $1
}
#line 1310 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 16: /* statement: ID LBRACKET ensemble RBRACKET ASSIGN ensemble ENDLINE  */
#line 188 "p1.y"
{
  if (id_mapping_table.find((yyvsp[-6].union_id)) == id_mapping_table.end())
  {
    // Check if key $1 is not found in id_mapping_table
    printf("ERROR! It’s illegal to set a bit of '%s' before defining '%s'\n",string((yyvsp[-6].union_id)).c_str(), string((yyvsp[-6].union_id)).c_str());
    YYABORT; // Abort parsing if key $1 is not found
  }
  Value *id_value = id_mapping_table[(yyvsp[-6].union_id)]; // Get the value corresponding to key $1
  Value *ensemble_value_1 = Builder.CreateSRem((yyvsp[-4].union_value), Builder.getInt32(32)); // Calculate the remainder of $3 divided by 32
  Value *ensemble_value_2 = Builder.CreateAnd((yyvsp[-1].union_value), Builder.getInt32(1)); // Extract the least significant bit of $6
  ensemble_value_2 = Builder.CreateShl(ensemble_value_2, ensemble_value_1); // Shift ensemble_value_2 left by ensemble_value_1

  Value *bit_mask = Builder.CreateNot(Builder.CreateShl(Builder.getInt32(1), ensemble_value_1)); // Create a bitmask for clearing the bit at ensemble_value_1
  id_value = Builder.CreateAnd(id_value, bit_mask); // Clear the bit in id_value at ensemble_value_1 position
  id_value = Builder.CreateOr(id_value, ensemble_value_2); // Set the bit in id_value at ensemble_value_1 position
  id_mapping_table[(yyvsp[-6].union_id)] = id_value; // Update the value in id_mapping_table for key $1
  (yyval.union_value) = id_mapping_table[(yyvsp[-6].union_id)]; // Set the return value to the updated value for key $1
}
#line 1333 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 17: /* ensemble: expr  */
#line 209 "p1.y"
{
  (yyval.union_value) = (yyvsp[0].union_value);
}
#line 1341 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 18: /* ensemble: expr COLON NUMBER  */
#line 213 "p1.y"
{
  Value *value_expr = Builder.CreateShl((yyvsp[-2].union_value), Builder.getInt32((yyvsp[0].union_number))); // Shift the value of $1 left by $3 bits

  (yyval.union_value) = value_expr; // Set the return value to the shifted value
}
#line 1351 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 19: /* ensemble: ensemble COMMA expr  */
#line 219 "p1.y"
{
  Value *value_expr = (yyvsp[0].union_value); // Store $3 in value_expr
  Value *ensemble_value = (yyvsp[-2].union_value); // Store $1 in ensemble_value
  Value *final_value; // Declare final_value

  value_expr = Builder.CreateShl(value_expr, Builder.getInt32(0)); // Shift value_expr left by 0 bits (no effect)
  ensemble_value = Builder.CreateShl(ensemble_value, Builder.getInt32(1)); // Shift ensemble_value left by 1 bit
  final_value = Builder.CreateOr(ensemble_value, value_expr); // OR ensemble_value with value_expr

  (yyval.union_value) = final_value; // Set the return value to final_value
}
#line 1367 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 20: /* ensemble: ensemble COMMA expr COLON NUMBER  */
#line 231 "p1.y"
{
  Value *value_expr = (yyvsp[-2].union_value); // Store $3 in value_expr
  Value *ensemble_value = (yyvsp[-4].union_value); // Store $1 in ensemble_value
  Value *final_value; // Declare final_value

  value_expr = Builder.CreateShl(value_expr, (yyvsp[0].union_number)); // Shift value_expr left by $5 bits (NUMBER)
  ensemble_value = Builder.CreateShl(ensemble_value, (yyvsp[0].union_number)); // Shift ensemble_value left by $5 bits  (NUMBER)
  ensemble_value = Builder.CreateShl(ensemble_value, Builder.getInt32(1)); // Shift ensemble_value left by 1 bit (COMMA)
  final_value = Builder.CreateOr(ensemble_value, value_expr); // OR ensemble_value with value_expr

  (yyval.union_value) = final_value; // Set the return value to final_value
}
#line 1384 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 21: /* expr: ID  */
#line 246 "p1.y"
{
  if (id_mapping_table.find((yyvsp[0].union_id)) == id_mapping_table.end())
  {
    printf("ERROR! It’s illegal to get/read '%s' before defining '%s'\n",string((yyvsp[0].union_id)).c_str(), string((yyvsp[0].union_id)).c_str());
    (yyval.union_value) = Builder.getInt32(0); 
    //return 0; 
    //YYABORT;
  }
  else
  {
    (yyval.union_value) = id_mapping_table[(yyvsp[0].union_id)]; 
  }
}
#line 1402 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 22: /* expr: ID NUMBER  */
#line 260 "p1.y"
{
  if (id_mapping_table.find((yyvsp[-1].union_id)) == id_mapping_table.end())
  {
    printf("ERROR! It’s illegal to get/read a bit of '%s' before defining '%s'\n",string((yyvsp[-1].union_id)).c_str(), string((yyvsp[-1].union_id)).c_str());
    (yyval.union_value) = Builder.getInt32(0); 
    //return 0; 
    //YYABORT; 
  }
  else
  {
    Value *id_value = id_mapping_table[(yyvsp[-1].union_id)]; // Get value from id_mapping_table for key $1
    Value *number_value = Builder.CreateSRem(Builder.getInt32((yyvsp[0].union_number)), Builder.getInt32(32)); // Get remainder of $2 divided by 32
    Value *Final_Value = Builder.CreateLShr(id_value, number_value); // Logical shift right id_value by number_value bits
    Final_Value = Builder.CreateAnd(Final_Value, Builder.getInt32(1)); // Perform bitwise AND with 1
    (yyval.union_value) = Final_Value; // Set the return value to Final_Value
  }
}
#line 1424 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 23: /* expr: NUMBER  */
#line 278 "p1.y"
{
  (yyval.union_value) = Builder.getInt32((yyvsp[0].union_number));  
}
#line 1432 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 24: /* expr: expr PLUS expr  */
#line 282 "p1.y"
{
  (yyval.union_value) = Builder.CreateAdd((yyvsp[-2].union_value),(yyvsp[0].union_value));
}
#line 1440 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 25: /* expr: expr MINUS expr  */
#line 286 "p1.y"
{
  (yyval.union_value) = Builder.CreateSub((yyvsp[-2].union_value),(yyvsp[0].union_value));
}
#line 1448 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 26: /* expr: expr XOR expr  */
#line 290 "p1.y"
{
  (yyval.union_value) = Builder.CreateXor((yyvsp[-2].union_value),(yyvsp[0].union_value)); 
}
#line 1456 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 27: /* expr: expr AND expr  */
#line 294 "p1.y"
{
  (yyval.union_value) = Builder.CreateAnd((yyvsp[-2].union_value),(yyvsp[0].union_value));
}
#line 1464 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 28: /* expr: expr OR expr  */
#line 298 "p1.y"
{
  (yyval.union_value) = Builder.CreateOr((yyvsp[-2].union_value),(yyvsp[0].union_value));
}
#line 1472 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 29: /* expr: INV expr  */
#line 302 "p1.y"
{
  (yyval.union_value) = Builder.CreateNot((yyvsp[0].union_value));
}
#line 1480 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 30: /* expr: BINV expr  */
#line 306 "p1.y"
{
  (yyval.union_value) = Builder.CreateXor(Builder.getInt32(1), (yyvsp[0].union_value));
}
#line 1488 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 31: /* expr: expr MUL expr  */
#line 310 "p1.y"
{
  (yyval.union_value) = Builder.CreateMul((yyvsp[-2].union_value),(yyvsp[0].union_value));
}
#line 1496 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 32: /* expr: expr DIV expr  */
#line 314 "p1.y"
{
  (yyval.union_value) = Builder.CreateUDiv((yyvsp[-2].union_value),(yyvsp[0].union_value));
}
#line 1504 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 33: /* expr: expr MOD expr  */
#line 318 "p1.y"
{
  (yyval.union_value) = Builder.CreateSRem((yyvsp[-2].union_value),(yyvsp[0].union_value)); //Getting reminder $1 % $3
}
#line 1512 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 34: /* expr: ID LBRACKET ensemble RBRACKET  */
#line 322 "p1.y"
{
  if (id_mapping_table.find((yyvsp[-3].union_id)) == id_mapping_table.end())
  {
    printf("ERROR! It’s illegal to get/read a bit of '%s' before defining '%s'\n",string((yyvsp[-3].union_id)).c_str(), string((yyvsp[-3].union_id)).c_str());
    (yyval.union_value) = Builder.getInt32(0);
    //return 0; 
    //YYABORT;  
  }
  else
  {
    Value *id_value = id_mapping_table[(yyvsp[-3].union_id)]; // Get value from id_mapping_table for key $1
    Value *number_value = Builder.CreateSRem((yyvsp[-1].union_value), Builder.getInt32(32)); // Get remainder of $3 divided by 32
    Value *Final_Value = Builder.CreateLShr(id_value, number_value); // Logical shift right id_value by number_value bits
    Final_Value = Builder.CreateAnd(Final_Value, Builder.getInt32(1)); // Perform bitwise AND with 1
    (yyval.union_value) = Final_Value; // Set the return value to Final_Value
  }
}
#line 1534 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 35: /* expr: LPAREN ensemble RPAREN  */
#line 340 "p1.y"
{
  (yyval.union_value) = (yyvsp[-1].union_value);
}
#line 1542 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 36: /* expr: LPAREN ensemble RPAREN LBRACKET ensemble RBRACKET  */
#line 345 "p1.y"
{ 
  Value *Final_Value = Builder.CreateLShr((yyvsp[-4].union_value), (yyvsp[-1].union_value)); // Logical shift right $2 by $5 bits
  Final_Value = Builder.CreateAnd(Final_Value, Builder.getInt32(1)); // Perform bitwise AND with 1
  (yyval.union_value) = Final_Value; // Set the return value to Final_Value
}
#line 1552 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 37: /* expr: REDUCE AND LPAREN ensemble RPAREN  */
#line 351 "p1.y"
{
  Value *temp_value; // Declare temporary value
  Value *final_value = Builder.getInt32(1); // Initialize final_value to 1
  for (int LoopCounter = 0; LoopCounter < 32; LoopCounter++) // Loop from 0 to 31
  {
    temp_value =  Builder.CreateLShr((yyvsp[-1].union_value), Builder.getInt32(LoopCounter)); // Shift $4 right by LoopCounter bits
    temp_value =  Builder.CreateAnd(temp_value, Builder.getInt32(1)); // Perform bitwise AND with 1
    final_value = Builder.CreateAnd(final_value, temp_value); // Perform bitwise AND with temp_value
  } 
  (yyval.union_value) = final_value; // Set the return value to final_value
}
#line 1568 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 38: /* expr: REDUCE OR LPAREN ensemble RPAREN  */
#line 363 "p1.y"
{
  Value *temp_value; // Declare temporary value
  Value *final_value = Builder.getInt32(0); // Initialize final_value to 0
  for (int LoopCounter = 0; LoopCounter < 32; LoopCounter++) // Loop from 0 to 31
  {
    temp_value =  Builder.CreateLShr((yyvsp[-1].union_value), Builder.getInt32(LoopCounter)); // Shift $4 right by LoopCounter bits
    temp_value =  Builder.CreateAnd(temp_value, Builder.getInt32(1)); // Perform bitwise AND with 1
    final_value = Builder.CreateOr(final_value, temp_value); // Perform bitwise OR with temp_value
  } 
  (yyval.union_value) = final_value; // Set the return value to final_value
}
#line 1584 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 39: /* expr: REDUCE XOR LPAREN ensemble RPAREN  */
#line 375 "p1.y"
{
  Value *temp_value = Builder.CreateLShr((yyvsp[-1].union_value), Builder.getInt32(0)); // Shift $4 right by 0 bits
  temp_value =  Builder.CreateAnd(temp_value, Builder.getInt32(1)); // Perform bitwise AND with 1
  Value *final_value = temp_value; // Initialize final_value with temp_value

  for (int LoopCounter = 1; LoopCounter < 32; LoopCounter++) // Loop from 1 to 31
  {
    temp_value =  Builder.CreateLShr((yyvsp[-1].union_value), Builder.getInt32(LoopCounter)); // Shift $4 right by LoopCounter bits
    temp_value =  Builder.CreateAnd(temp_value, Builder.getInt32(1)); // Perform bitwise AND with 1
    final_value = Builder.CreateXor(final_value, temp_value); // Perform bitwise XOR with temp_value
  } 
  (yyval.union_value) = final_value; // Set the return value to final_value
}
#line 1602 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 40: /* expr: REDUCE PLUS LPAREN ensemble RPAREN  */
#line 389 "p1.y"
{
  Value *temp_value; // Declare a temporary Value pointer
  Value *final_value; // Declare the final Value pointer
  for (int LoopCounter = 0; LoopCounter < 32; LoopCounter++) // Loop through each bit position
  {
    temp_value =  Builder.CreateLShr((yyvsp[-1].union_value), Builder.getInt32(LoopCounter)); // Shift $4 right by LoopCounter bits
    temp_value =  Builder.CreateAnd(temp_value, Builder.getInt32(1)); // Perform bitwise AND with 1   
    if (LoopCounter == 0) // If it's the first iteration
    {
      final_value = temp_value; // Assign temp_value to final_value
    }
    else // For subsequent iterations
    {
      final_value = Builder.CreateAdd(final_value, temp_value); // Add temp_value to final_value
    }
  } 
  (yyval.union_value) = final_value; // Set the return value to final_value
}
#line 1625 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;

  case 41: /* expr: EXPAND LPAREN ensemble RPAREN  */
#line 408 "p1.y"
{
  Value *ensemble_value = Builder.CreateAnd((yyvsp[-1].union_value), Builder.getInt32(1)); // Get the LSB of $3
  Value *condition = Builder.CreateICmpEQ(ensemble_value, Builder.getInt32(0)); // Check if LSB is 0
  (yyval.union_value) = Builder.CreateSelect(condition, Builder.getInt32(0), Builder.getInt32(0xFFFFFFFF)); // If LSB is 0, return 0; otherwise, return 0xFFFFFFFF
}
#line 1635 "/ece566/projects/p1/c++/build/p1.y.cpp"
    break;


#line 1639 "/ece566/projects/p1/c++/build/p1.y.cpp"

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

#line 415 "p1.y"


unique_ptr<Module> parseP1File(const string &InputFilename)
{
  funName = InputFilename;
  if (funName.find_last_of('/') != string::npos)
    funName = funName.substr(funName.find_last_of('/')+1);
  if (funName.find_last_of('.') != string::npos)
    funName.resize(funName.find_last_of('.'));
    
  //errs() << "Function will be called " << funName << ".\n";
  
  // unique_ptr will clean up after us, call destructor, etc.
  unique_ptr<Module> Mptr(new Module(funName.c_str(), TheContext));

  // set global module
  M = Mptr.get();
  
  /* this is the name of the file to generate, you can also use
     this string to figure out the name of the generated function */
  yyin = fopen(InputFilename.c_str(),"r");

  //yydebug = 1;
  if (yyparse() != 0)
    // errors, so discard module
    Mptr.reset();
  else
    // Dump LLVM IR to the screen for debugging
    M->print(errs(),nullptr,false,true);
  
  return Mptr;
}

void yyerror(const char* msg)
{
  printf("%s\n",msg);
}
