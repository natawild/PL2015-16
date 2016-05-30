/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "gramatica.y" /* yacc.c:339  */
 
#include "compilador.h"
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include <stdlib.h>
#include "y.tab.h"




extern ccLine;
static int total;
FILE *f;
static Stack s;

int vars; 
int lvars; 



#line 88 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    WHILE = 259,
    FOR = 260,
    IF = 261,
    ELSE = 262,
    RETURN = 263,
    VOID = 264,
    PRINT = 265,
    SCAN = 266,
    DO = 267,
    num = 268,
    id = 269
  };
#endif
/* Tokens.  */
#define INT 258
#define WHILE 259
#define FOR 260
#define IF 261
#define ELSE 262
#define RETURN 263
#define VOID 264
#define PRINT 265
#define SCAN 266
#define DO 267
#define num 268
#define id 269

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 23 "gramatica.y" /* yacc.c:355  */

    char* var_nome;
    int valor;
    Tipo tipo;
    struct sVarAtr
    {
        char* var_nome;
        int valor;
        int size;
    } varAtr;   

#line 168 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 183 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   199

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   269

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,    15,     2,     2,    33,     2,
      16,    17,    32,    25,    20,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    21,
      28,    24,    27,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    22,     2,    23,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    18,    30,    19,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    56,    56,    57,    56,    62,    63,    66,    67,    70,
      71,    78,    78,    83,    84,    87,    90,    91,    93,    94,
      97,   103,   104,   108,   116,   121,   122,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   138,   143,   148,   152,
     158,   161,   165,   166,   167,   165,   171,   172,   177,   178,
     177,   184,   184,   190,   193,   194,   193,   199,   203,   204,
     205,   206,   207,   208,   209,   213,   214,   215,   216,   220,
     221,   222,   223,   226,   227,   229,   233,   234,   234,   237,
     240,   241,   244,   245,   248
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "WHILE", "FOR", "IF", "ELSE",
  "RETURN", "VOID", "PRINT", "SCAN", "DO", "num", "id", "'#'", "'('",
  "')'", "'{'", "'}'", "','", "';'", "'['", "']'", "'='", "'+'", "'!'",
  "'>'", "'<'", "'-'", "'|'", "'/'", "'*'", "'&'", "$accept", "Prog",
  "$@1", "$@2", "ListaDecla", "ListaFun", "ListInst", "Funcao", "$@3",
  "TipoFun", "IdFun", "ListaArg", "ListaArg2", "Tipo", "Decla", "Var",
  "ConjInst", "Inst", "Atrib", "Print", "Scan", "If", "$@4", "$@5", "$@6",
  "Else", "While", "$@7", "$@8", "DoWhile", "$@9", "For", "ForHeader",
  "$@10", "$@11", "ForAtrib", "ExpLog", "Exp", "Termo", "Fun", "$@12",
  "FunArgs", "FunArgs2", "TestExpLog", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,    35,    40,    41,   123,   125,
      44,    59,    91,    93,    61,    43,    33,    62,    60,    45,
     124,    47,    42,    38
};
# endif

#define YYPACT_NINF -95

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-95)))

#define YYTABLE_NINF -16

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -95,    17,    19,   -95,    33,   -95,   -95,    46,    49,   -95,
      70,     9,   153,   -95,    57,   -95,   -95,    91,   -95,    90,
     -95,   -95,    30,    95,    98,   -95,   -95,   153,    15,   -95,
      97,   101,   102,   -95,   -95,   -95,   -95,    78,   -95,   -95,
     117,   123,   122,   117,   -95,   125,    30,   -95,   129,    83,
       1,   -95,    30,   123,   122,   -95,    30,    30,   120,   -95,
     -95,   -95,   -95,   134,   137,    30,   -95,   -95,   133,   153,
     -95,   -95,    -9,   139,    30,   -95,    30,    30,   132,    30,
      30,   141,    -6,   160,   166,    36,   -16,   -95,   155,   176,
     163,    64,   122,   -95,    44,   122,   -95,    30,   119,     1,
       1,    30,   -95,   -95,    30,   -95,   -95,   117,    38,   161,
     -95,   164,   165,   123,   -95,   159,   162,    14,    71,   -95,
      30,   -95,   -95,   -16,   167,   168,   169,   -95,   -95,   171,
      30,    30,   -95,   172,   176,   -95,    30,    30,    30,   -16,
      30,   -16,   173,   180,   -95,    30,    30,   -95,   143,   -16,
     -95,   123,   -16,   -16,   -16,   -16,   -95,   122,   -95,   -16,
     146,   174,   124,   -95,   123,   -95,   -95,    30,    67,   178,
     -16,   -95,   -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     2,     1,     0,     7,     6,     0,     3,    21,
       0,     0,     0,     8,     0,    14,    13,     0,    48,     0,
      42,    35,     0,     0,     0,    51,    24,     4,     0,     9,
       0,     0,     0,    27,    28,    29,    30,     0,    15,    11,
       0,     0,    25,     0,    73,    24,     0,    77,    74,     0,
      65,    69,     0,     0,    25,    10,     0,     0,     0,    31,
      32,    33,    22,     0,     0,     0,    49,    57,     0,     0,
      53,    43,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,    37,     0,    16,
       0,    58,    25,    54,     0,    25,    79,    80,     0,    66,
      67,     0,    70,    71,     0,    40,    41,     0,     0,     0,
      20,     0,    17,     0,    84,     0,     0,     0,     0,    50,
       0,    26,    44,    82,     0,    81,    75,    68,    72,     0,
       0,     0,    23,     0,     0,    18,     0,     0,     0,    64,
       0,    63,     0,    46,    78,     0,     0,    52,     0,    38,
       5,     0,    59,    60,    61,    62,    55,    25,    45,    83,
       0,     0,     0,    19,     0,    47,    76,     0,     0,     0,
      39,    12,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,   -95,   -95,    39,   -95,   -64,   -95,   -95,   -95,
     179,   -95,   -95,    59,   -95,   -12,   -50,   -25,   -38,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,    35,   -94,   -21,    26,    41,
     -95,   -95,   -95,   -37
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     5,    12,     2,     8,    27,    13,    64,    17,
      47,   111,   112,   113,     6,    48,    70,    29,    30,    31,
      32,    33,    43,    95,   143,   158,    34,    40,    92,    35,
      54,    36,    42,   120,   164,    68,    90,    91,    50,    51,
      73,   124,   125,    66
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    49,    55,    67,    84,    94,    71,   127,    96,    76,
     128,   105,    15,    77,    78,    28,    76,     3,    16,    76,
      77,    78,     4,    77,    78,    72,   142,    44,    45,    28,
      46,    82,    79,    80,    81,    85,    86,    56,   138,    57,
      58,    83,   119,    44,    45,   122,    46,     7,    18,    19,
      20,    21,    22,    98,    23,    24,    25,    28,    26,   108,
     130,    76,   131,   121,    11,    77,    78,     9,    10,    55,
     129,    18,    19,    20,    21,    22,   123,    23,    24,    25,
      37,    26,    28,    14,    44,    45,   171,    46,   115,    76,
     116,   117,   118,    77,    78,   140,   139,   141,   168,    62,
      63,   135,    99,   100,    75,    38,    41,   165,    76,   148,
     149,    52,    77,    78,    53,   152,   153,   154,    59,   155,
     102,   103,    60,    61,   159,   160,    67,     4,    18,    19,
      20,    21,    22,    65,    23,    24,    25,    26,    26,   163,
      69,   -15,   126,    55,    76,    87,   170,    88,    77,    78,
      28,    74,    28,    89,    93,    97,    28,    18,    19,    20,
      21,    22,   101,    23,    24,    25,   161,    26,    76,   166,
     107,    76,    77,    78,   104,    77,    78,   106,   109,   110,
     114,   133,   132,   136,   144,   134,   137,   157,   145,   162,
     150,   146,   147,   151,   156,   172,    39,     0,   167,   169
};

static const yytype_int16 yycheck[] =
{
      12,    22,    27,    41,    54,    69,    43,   101,    17,    25,
     104,    17,     3,    29,    30,    27,    25,     0,     9,    25,
      29,    30,     3,    29,    30,    46,   120,    13,    14,    41,
      16,    52,    31,    32,    33,    56,    57,    22,    24,    24,
      25,    53,    92,    13,    14,    95,    16,    14,     4,     5,
       6,     7,     8,    74,    10,    11,    12,    69,    14,    23,
      22,    25,    24,    19,    15,    29,    30,    21,    22,    94,
     107,     4,     5,     6,     7,     8,    97,    10,    11,    12,
      23,    14,    94,    13,    13,    14,    19,    16,    24,    25,
      26,    27,    28,    29,    30,    24,   117,   118,   162,    21,
      22,   113,    76,    77,    21,    14,    16,   157,    25,   130,
     131,    16,    29,    30,    16,   136,   137,   138,    21,   140,
      79,    80,    21,    21,   145,   146,   164,     3,     4,     5,
       6,     7,     8,    16,    10,    11,    12,    14,    14,   151,
      18,    16,    23,   168,    25,    25,   167,    13,    29,    30,
     162,    22,   164,    16,    21,    16,   168,     4,     5,     6,
       7,     8,    30,    10,    11,    12,    23,    14,    25,    23,
       4,    25,    29,    30,    33,    29,    30,    17,    23,     3,
      17,    17,    21,    24,    17,    20,    24,     7,    20,   150,
      18,    22,    21,   134,    21,    17,    17,    -1,    24,   164
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    35,    38,     0,     3,    36,    48,    14,    39,    21,
      22,    15,    37,    41,    13,     3,     9,    43,     4,     5,
       6,     7,     8,    10,    11,    12,    14,    40,    49,    51,
      52,    53,    54,    55,    60,    63,    65,    23,    14,    44,
      61,    16,    66,    56,    13,    14,    16,    44,    49,    71,
      72,    73,    16,    16,    64,    51,    22,    24,    25,    21,
      21,    21,    21,    22,    42,    16,    77,    52,    69,    18,
      50,    77,    71,    74,    22,    21,    25,    29,    30,    31,
      32,    33,    71,    49,    50,    71,    71,    25,    13,    16,
      70,    71,    62,    21,    40,    57,    17,    16,    71,    72,
      72,    30,    73,    73,    33,    17,    17,     4,    23,    23,
       3,    45,    46,    47,    17,    24,    26,    27,    28,    50,
      67,    19,    50,    71,    75,    76,    23,    70,    70,    77,
      22,    24,    21,    17,    20,    49,    24,    24,    24,    71,
      24,    71,    70,    58,    17,    20,    22,    21,    71,    71,
      18,    47,    71,    71,    71,    71,    21,     7,    59,    71,
      71,    23,    38,    49,    68,    50,    23,    24,    40,    69,
      71,    19,    17
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    36,    37,    35,    38,    38,    39,    39,    40,
      40,    42,    41,    43,    43,    44,    45,    45,    46,    46,
      47,    48,    48,    48,    49,    50,    50,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    52,    52,    52,    52,
      53,    54,    56,    57,    58,    55,    59,    59,    61,    62,
      60,    64,    63,    65,    67,    68,    66,    69,    70,    70,
      70,    70,    70,    70,    70,    71,    71,    71,    71,    72,
      72,    72,    72,    73,    73,    73,    73,    74,    73,    73,
      75,    75,    76,    76,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     5,     0,     2,     0,     2,     1,
       2,     0,    11,     1,     1,     1,     0,     1,     2,     4,
       1,     3,     6,     9,     1,     0,     3,     1,     1,     1,
       1,     2,     2,     2,     3,     1,     3,     3,     6,     9,
       4,     4,     0,     0,     0,     7,     0,     2,     0,     0,
       5,     0,     6,     3,     0,     0,     9,     1,     1,     4,
       4,     4,     4,     3,     3,     1,     3,     3,     4,     1,
       3,     3,     4,     1,     1,     4,     7,     0,     5,     3,
       0,     1,     1,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 56 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f,"start\n");fprintf(f,"jump inicio\n");}
#line 1381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 57 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f,"inicio:nop\n");}
#line 1387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 58 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f,"stop\n");}
#line 1393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 78 "gramatica.y" /* yacc.c:1646  */
    {inserFuncao((yyvsp[-1].tipo),(yyvsp[0].var_nome));}
#line 1399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 80 "gramatica.y" /* yacc.c:1646  */
    {fim();}
#line 1405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 83 "gramatica.y" /* yacc.c:1646  */
    {(yyval.tipo) =_VOID;}
#line 1411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 84 "gramatica.y" /* yacc.c:1646  */
    {(yyval.tipo) =_INTS;}
#line 1417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 97 "gramatica.y" /* yacc.c:1646  */
    {(yyval.tipo) =_INTS;}
#line 1423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 103 "gramatica.y" /* yacc.c:1646  */
    {decVar((yyvsp[-1].var_nome),1,'S');fprintf(f,"pushi 0\n"); vars++; }
#line 1429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 104 "gramatica.y" /* yacc.c:1646  */
    {if(testeColuna((yyvsp[-2].valor))==1) 
                                                                {decVar((yyvsp[-4].var_nome),(yyvsp[-2].valor),'A');fprintf(f,"pushn%d\n",(yyvsp[-2].valor));}
                                                                else {yyerror("Tamanho menor que 1");}
                                                            }
#line 1438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 108 "gramatica.y" /* yacc.c:1646  */
    {if(testeMatriz((yyvsp[-5].valor),(yyvsp[-2].valor))==1) 
                                                                {decVar((yyvsp[-7].var_nome),(yyvsp[-5].valor)*(yyvsp[-2].valor),'M');fprintf(f,"pushn %d\n",(yyvsp[-5].valor)*(yyvsp[-2].valor));}
                                                                else {yyerror("Tamanho menor que 1");}        
                                                                }
#line 1447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 116 "gramatica.y" /* yacc.c:1646  */
    {Endereco a=getEndereco((yyvsp[0].var_nome)); (yyval.varAtr).var_nome=strdup((yyvsp[0].var_nome)); (yyval.varAtr).valor=1;}
#line 1453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 132 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f,"storel %d\n",decFunRetAddr());fprintf(f,"return\n");}
#line 1459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 133 "gramatica.y" /* yacc.c:1646  */
    { yyerror("'Else' sem um 'If' anteriormente");return 0;}
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 138 "gramatica.y" /* yacc.c:1646  */
    {Endereco a = getEndereco((yyvsp[-2].varAtr).var_nome); 
                                                    if(a.tipo == _INTS){ fprintf(f,"store%c %d\n",a.tipoVar, a.addr);} 
                                                        else {yyerror("Tipos incompativeis");return 0;  }  
                                                }
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 143 "gramatica.y" /* yacc.c:1646  */
    {Endereco a = getEndereco((yyvsp[-2].varAtr).var_nome); 
                                                    if(a.tipo ==_INTS){fprintf(f,"pushi 1\n push%c %d\n add\n store%c %d\n",a.tipoVar,a.addr, a.tipoVar, a.addr);}
                                                    else{yyerror("Tipos incompativeis"); return 0; } 
                                                }
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 148 "gramatica.y" /* yacc.c:1646  */
    {Endereco a = getEndereco((yyvsp[-5].varAtr).var_nome); fprintf(f, "push%cp \n push%c %d padd\n",(a.tipoVar=='l')? 'f' : 'g', 
                                                a.tipoVar, a.addr); fprintf(f, "storen\n");}
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 152 "gramatica.y" /* yacc.c:1646  */
    {Endereco a = getEndereco((yyvsp[-8].varAtr).var_nome); fprintf(f, "push%cp \n push%c %d padd\n",(a.tipoVar=='l')? 'f' : 'g', 
                                                a.tipoVar, a.addr);}
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 158 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f,"writei\n");}
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 161 "gramatica.y" /* yacc.c:1646  */
    {Endereco a= getEndereco((yyvsp[-1].varAtr).var_nome); fprintf(f,"read\n atoi\n store%c %d\n",a.tipoVar, a.addr);}
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 165 "gramatica.y" /* yacc.c:1646  */
    {total++; push(s,total);}
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 166 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f,"jz endCond%d\n", get(s));}
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 167 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f," endCond%d\n", pop(s));}
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 177 "gramatica.y" /* yacc.c:1646  */
    {total++; push(s,total); fprintf(f, "ciclo%d: NOP\n", get(s));}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 178 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f, "jz endciclo%d\n", get(s)); }
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 179 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f, "jump ciclo%d\n endCiclo%d\n", get(s), get(s));  pop(s); }
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 184 "gramatica.y" /* yacc.c:1646  */
    {total++; push(s,total); fprintf(f, "ciclo%d: NOP\n", get(s));}
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 185 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f, "jz endciclo%d\n jump ciclo%d\n endciclo%d: NOP\n", get(s),get(s),get(s));pop(s);}
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 190 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f,"jump ciclo%dA\nendciclo%d\n", get(s), get(s)); pop(s);}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 193 "gramatica.y" /* yacc.c:1646  */
    {total++; push(s,total); fprintf(f,"ciclo%d: nop\n", get(s));}
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 194 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f,"jz endciclo%d\njump ciclo%dB\nciclo%dA: nop\n", get(s), get(s), get(s));}
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 195 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f,"jump ciclo%d\nciclo%dB: nop\n", get(s), get(s));}
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 204 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f,"equal\n");}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 205 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f,"equal\npushi 0\nequal\n");}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 206 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f,"supeq\n");}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 207 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f,"infeq\n");}
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 208 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f,"inf\n");}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 209 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f,"sup\n");}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 214 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f,"add\n");}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 215 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f,"sub\n");}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 216 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f, "add\n jz endCond%d:nop\n",get(s));}
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 221 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f,"div\n");}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 222 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f,"mul\n");}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 223 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f, "pushi 1\nequal\njz endCond%d: nop\n",get(s));}
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 226 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f, "pushi %d\n",(yyvsp[0].valor) );}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 227 "gramatica.y" /* yacc.c:1646  */
    {Endereco a = getEndereco((yyvsp[0].varAtr).var_nome); fprintf(f, "push%c %d\n",a.tipoVar, a.addr);}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 229 "gramatica.y" /* yacc.c:1646  */
    {Endereco a = getEndereco((yyvsp[-3].varAtr).var_nome); 
                                        fprintf(f, "push%cp\npush%c %d\npadd\n",(a.tipoVar=='l')?'f':'g', a.tipoVar, a.addr);
                                        fprintf(f, "loadn\n");}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 234 "gramatica.y" /* yacc.c:1646  */
    {funcaoExiste((yyvsp[0].var_nome)); fprintf(f, "pushi 0\n");}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 235 "gramatica.y" /* yacc.c:1646  */
    {fprintf(f, "call %s\n",(yyvsp[-4].var_nome)); fprintf(f, "pop%d\n",numeroArgumentos());}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 244 "gramatica.y" /* yacc.c:1646  */
    {proximoArgumento(_INTS);}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 245 "gramatica.y" /* yacc.c:1646  */
    {proximoArgumento(_INTS);}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1701 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
  return yyresult;
}
#line 252 "gramatica.y" /* yacc.c:1906  */


int testeMatriz(int linha, int coluna) {

    if(linha<=0) {
        
        return -1;
    }

    else {
                if(coluna<=0) {

                        
                            return -1;

                }

                else return 1;


    }
}

int testeColuna(int linha) {

    if(linha<=0) {
        
        return -1;
    }

    else return 1;
}



#include "lex.yy.c"



/*
int yyerror(char* s) {
    printf("\n\x1b[10;01m%s (line %d) \x1b[0m\n", s, yylineno);
    return 0;
}
*/


int yyerror(char *s) {
	
    fprintf(stderr,"ERRO: Syntax LINHA: %d MSG: %s\n",ccLine,s);
   return 0;
}


/*

int  yyerror(char *s){
    fprintf(stderr,"ERRO: Syntax LINHA: %d MSG: %s\n",ccLine,s);
    exit(0);
    return 0; 
}

*/

/*

void inicio()
{
    s = initStack();
    total = 0;
    f = fopen("assembly.out", "w");
}
*/


int main(int argc, char* argv[]){
	total=0; 
	lvars=0;
    vars=0;
    initVGlobalMap(); 
  s=initStack();

	f=fopen("assembly.txt","w+");
		yyparse();
		fclose(f); 
        free(s);
		return 0; 
	}


