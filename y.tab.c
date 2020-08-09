/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "yaccfile1.y" /* yacc.c:339  */
 
  #include<bits/stdc++.h>
  #include<iostream>
  #include<cstring>
  #include "node.h"
  
  using namespace std;

  extern int yylex();

    void yyerror(char *); 
    int yylex(void); 
    stack<string>stk;
    map <string,string>typecheck;
  vector<char *>vars;
  map<string,string> values;
    int tc=1,lc=1,casef=0;
    string t;
    string begin1;
string getassignop(int a)
{ 
	string ss;
   switch(a)
  {
  case 1:{ss="=";break;}
  case 2:{ss="+=";break;}
  case 3:{ss="-=";break;}
  case 4:{ss="*=";break;}
  case 5:{ss="/=";break;}

  }
  return ss;
}

string gen(string s1,string s2)
{
	string temp="";
	temp.append(s1);
	temp.append(s2);
	temp.append("\n");
	return temp;
}

string gen(string s1,string s2,string s3,string s4,string s5)
{
	string temp="";
	temp.append(s1);
	temp+=s2;
	temp.append(s3);
	temp+=s4;
	temp.append(s5);
	temp+=";";
	temp+="\n";
	return temp;
}

string gen(string s1,string s2,string s3,string s4)
{
	string temp="";
	temp.append(s1);
	temp.append(s2);
	temp.append(s3);
	temp.append(s4);
	temp.append("\n");
	return temp;
}

int isdeclared(char *a, char *b)
{
	
	string sa,sb;
	sa="";sb="";
	sa.append(a);sb.append(b);
	
	if(typecheck.find(sa)==typecheck.end())
	{cout<<"the variable "<<a<<" is not declared "<< endl;exit(0);}
	if(typecheck.find(sb)==typecheck.end())
	{cout<<"the variable "<<b<<" is not declared "<< endl;exit(0);}
	string ta=typecheck[sa];
	string tb=typecheck[sb];
		if(ta=="bool" && tb=="bool")return 0;
		if(ta=="bool" || tb=="bool"){cout<<"boolean variable used in arithematic expression"<<endl;exit(0);}
		if(ta=="int"&&tb=="float")return 1;
		if(ta=="float"&&tb=="int")return 1;
		if(ta=="float"&&tb=="float")return 1;
		if(ta=="int" && tb=="int")return 2;
	
}

int iscompatible(char *a,char *b)
{
	string ta,tb;
	if(typecheck.find(a)==typecheck.end())
	{cout<<"the variable "<<a<<" is not declared "<< endl;exit(0);}
	if(typecheck.find(b)==typecheck.end())
	{cout<<"the variable "<<b<<" is not declared "<< endl;exit(0);}
	ta=typecheck[a];
	tb=typecheck[b];
	if(ta=="bool"&&(tb=="int"||tb=="float")){cout<<"incompatible type conversion"<<endl;exit(0);}
	if(tb=="bool"&&(ta=="int"||ta=="float")){cout<<"incompatible type conversion"<<endl;exit(0);}
}
 

#line 170 "y.tab.c" /* yacc.c:339  */

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
    NOT = 258,
    OR = 259,
    AND = 260,
    op = 261,
    VARIABLE = 262,
    INTEG = 263,
    WHILE = 264,
    FOR = 265,
    IF = 266,
    THEN = 267,
    ELSE = 268,
    BOOL = 269,
    INT = 270,
    FLOAT = 271,
    SWITCH = 272,
    CASE = 273,
    BREAK = 274
  };
#endif
/* Tokens.  */
#define NOT 258
#define OR 259
#define AND 260
#define op 261
#define VARIABLE 262
#define INTEG 263
#define WHILE 264
#define FOR 265
#define IF 266
#define THEN 267
#define ELSE 268
#define BOOL 269
#define INT 270
#define FLOAT 271
#define SWITCH 272
#define CASE 273
#define BREAK 274

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 106 "yaccfile1.y" /* yacc.c:355  */
    
    DATA d;

#line 249 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 266 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   313

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  39
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   274

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    31,     2,     2,     5,     2,
      35,    36,    10,     8,    34,     9,     2,    11,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    39,    33,
       7,     2,     6,     2,    12,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     4,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     3,    38,    13,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   129,   129,   137,   139,   143,   147,   153,   161,   168,
     199,   209,   223,   224,   228,   244,   265,   290,   313,   335,
     351,   364,   383,   386,   407,   428,   448,   468,   489,   510,
     530,   549,   566,   584,   601,   612,   629,   646,   659,   672
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'|'", "'^'", "'&'", "'>'", "'<'", "'+'",
  "'-'", "'*'", "'/'", "'@'", "'~'", "NOT", "OR", "AND", "op", "VARIABLE",
  "INTEG", "WHILE", "FOR", "IF", "THEN", "ELSE", "BOOL", "INT", "FLOAT",
  "SWITCH", "CASE", "BREAK", "'#'", "'\\n'", "';'", "','", "'('", "')'",
  "'{'", "'}'", "':'", "$accept", "program", "type", "decls", "decl",
  "vals", "newline", "statement", "cases", "expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   124,    94,    38,    62,    60,    43,    45,
      42,    47,    64,   126,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,    35,    10,    59,    44,    40,    41,   123,   125,    58
};
# endif

#define YYPACT_NINF -48

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-48)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      45,   -48,   -48,   -48,    12,    -4,    45,     6,   -48,    -4,
      -4,   -48,   -48,    -4,    15,   189,    23,     7,   -48,     1,
      52,   116,   -48,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    21,    29,    40,    42,
      19,   260,   -48,   -48,   274,   286,   297,    73,    73,    -9,
      -9,     1,     1,     1,    62,   -48,   -48,    -4,    23,    -4,
      -4,    47,    -4,   139,    53,   153,   175,   -48,   -48,   209,
      50,    -4,    54,    58,    47,    47,   223,    47,    64,    23,
      23,    23,    23,   -48,   -48,    59,    65,    60,     8,    47,
      63,    47,    70,    74,    23,    47,   227,   -48,    -4,   -48,
      23,    78,   -48,   102,    91,    47,    79,    47,    23,    47,
      23,    92,    23,   -48,    47,   103,    23,   101,   -48,    47,
      97,   104,   -48
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     6,     4,     5,     0,     0,     3,     0,     1,     0,
       0,    38,    39,     0,     0,    10,    20,     0,     8,    33,
      37,     0,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,    34,    28,    30,    29,    31,    32,    23,
      24,    25,    26,    27,    36,    35,    11,     0,    20,     0,
       0,    13,     0,     0,     0,     0,     0,    12,     2,     0,
       0,     0,     0,     0,    13,    13,     0,    13,     0,    20,
      20,    20,    20,    22,    19,     0,     0,     0,    13,    13,
       0,    13,     0,     0,    20,    13,    20,    18,     0,    17,
      20,     0,    14,     0,     0,    13,     0,    13,    20,    13,
      20,     0,    20,    16,    13,     0,    20,     0,    15,    13,
       0,     0,    21
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -48,   131,   -48,   -48,   132,   105,   -15,   -47,   -48,    -5
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    14,    68,    40,    88,    41
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      15,    30,    31,    32,    19,    20,    33,    34,    21,     9,
      10,    64,     8,    32,    11,    12,    33,    34,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      15,    13,    84,    85,    86,    87,     9,    10,    18,    42,
      67,    11,    12,    36,    37,    38,    92,    99,    22,   102,
      61,    39,    63,   104,    65,    66,    57,    69,    13,    79,
      80,   111,    82,   113,    58,   115,    76,    33,    34,   118,
       1,     2,     3,    93,    94,    59,    96,    60,    34,    67,
     100,    28,    29,    30,    31,    32,    71,    75,    33,    34,
     108,    77,   110,   103,   112,    78,    83,    89,    91,   116,
      95,    90,    97,    98,   120,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,   105,   109,    33,    34,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,   107,
     114,    33,    34,   117,   119,   121,   122,    16,    17,     0,
      56,   106,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    43,     0,    33,    34,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,     0,     0,    33,    34,
       0,     0,     0,     0,     0,    70,     0,     0,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     0,    72,
      33,    34,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,     0,     0,    33,    34,     0,     0,     0,     0,
       0,    73,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,     0,    35,    33,    34,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,     0,     0,    33,    34,
       9,    10,    74,     0,     0,    11,    12,    36,    37,    38,
       0,   101,     0,     0,     0,    39,    81,     0,     0,     0,
       0,     0,    13,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,     0,     0,    33,    34,    62,    24,    25,
      26,    27,    28,    29,    30,    31,    32,     0,     0,    33,
      34,    25,    26,    27,    28,    29,    30,    31,    32,     0,
       0,    33,    34,    26,    27,    28,    29,    30,    31,    32,
       0,     0,    33,    34
};

static const yytype_int8 yycheck[] =
{
       5,    10,    11,    12,     9,    10,    15,    16,    13,    13,
      14,    58,     0,    12,    18,    19,    15,    16,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    35,    79,    80,    81,    82,    13,    14,    32,    32,
      32,    18,    19,    20,    21,    22,    38,    94,    33,    96,
      31,    28,    57,   100,    59,    60,    35,    62,    35,    74,
      75,   108,    77,   110,    35,   112,    71,    15,    16,   116,
      25,    26,    27,    88,    89,    35,    91,    35,    16,    32,
      95,     8,     9,    10,    11,    12,    33,    37,    15,    16,
     105,    37,   107,    98,   109,    37,    32,    38,    38,   114,
      37,    36,    32,    29,   119,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    37,    37,    15,    16,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    38,
      38,    15,    16,    30,    33,    38,    32,     6,     6,    -1,
      35,    39,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    36,    -1,    15,    16,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    -1,    15,    16,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    36,
      15,    16,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,
      -1,    36,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    34,    15,    16,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    -1,    15,    16,
      13,    14,    33,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    24,    -1,    -1,    -1,    28,    33,    -1,    -1,    -1,
      -1,    -1,    35,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    -1,    15,    16,    17,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    -1,    15,
      16,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      -1,    15,    16,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    15,    16
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    26,    27,    41,    42,    43,    44,     0,    13,
      14,    18,    19,    35,    45,    49,    41,    44,    32,    49,
      49,    49,    33,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    15,    16,    34,    20,    21,    22,    28,
      47,    49,    32,    36,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    45,    35,    35,    35,
      35,    31,    17,    49,    47,    49,    49,    32,    46,    49,
      36,    33,    36,    36,    33,    37,    49,    37,    37,    46,
      46,    33,    46,    32,    47,    47,    47,    47,    48,    38,
      36,    38,    38,    46,    46,    37,    46,    32,    29,    47,
      46,    24,    47,    49,    47,    37,    39,    38,    46,    37,
      46,    47,    46,    47,    38,    47,    46,    30,    47,    33,
      46,    38,    32
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    41,    42,    42,    42,    43,    43,    44,
      45,    45,    46,    46,    47,    47,    47,    47,    47,    47,
      47,    48,    48,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     0,     1,     1,     1,     3,     2,     3,
       1,     3,     1,     0,    10,    16,    14,    10,     9,     6,
       0,    13,     0,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     2,     1,     1
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
#line 129 "yaccfile1.y" /* yacc.c:1646  */
    {
        									
        									   cout<<"end of the input"<<endl;
        									   cout<<(yyvsp[-4].d).code<<endl;

        									   cout<<(yyvsp[-2].d).code<<endl<<endl;
                     
                                }
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 137 "yaccfile1.y" /* yacc.c:1646  */
    {}
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 139 "yaccfile1.y" /* yacc.c:1646  */
    {		string code1="int";
					(yyval.d).code=new char[code1.length()];
                    strcpy((yyval.d).code,code1.c_str());
              }
#line 1469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 143 "yaccfile1.y" /* yacc.c:1646  */
    {		string code1="float";
					(yyval.d).code=new char[code1.length()];
                    strcpy((yyval.d).code,code1.c_str());
              	}
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 147 "yaccfile1.y" /* yacc.c:1646  */
    {		string code1="bool";
					(yyval.d).code=new char[code1.length()];
                    strcpy((yyval.d).code,code1.c_str());
              	}
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 153 "yaccfile1.y" /* yacc.c:1646  */
    {string code1="";
								code1.append((yyvsp[-2].d).code);
								code1.append("\n");
								code1.append((yyvsp[-1].d).code);
								code1.append("\n");
								(yyval.d).code=new char[code1.length()];
                       			strcpy((yyval.d).code,code1.c_str());
                       			}
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 161 "yaccfile1.y" /* yacc.c:1646  */
    {string code1="";
					code1.append((yyvsp[-1].d).code);
					(yyval.d).code=new char[code1.length()];
                    strcpy((yyval.d).code,code1.c_str());
                  }
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 168 "yaccfile1.y" /* yacc.c:1646  */
    {
								
								string code1="";string ty="";ty.append((yyvsp[-2].d).code);
								code1.append((yyvsp[-2].d).code);
								code1.append(" ");
								code1.append((yyvsp[-1].d).code);
								code1.append("; ");

								//cout<<ty<<endl;
								
								(yyval.d).code=new char[code1.length()];
                        strcpy((yyval.d).code,code1.c_str());
                        map<string, string>::iterator it;
                        //for(it=typecheck.begin();it!=typecheck.end();it++)
                        //	cout<<it->first<<" "<<it->second<<endl;
                        for(int i=0;i<vars.size();i++)
                        { 
                        	string ss="";
                        	ss.append(vars[i]);
                        	if(typecheck.find(ss)==typecheck.end())
                        	typecheck[ss]=ty;
                        	else
                        		{cout<<ss<<" variable has been declared more than once"<<endl;exit(1);}
                        	
                        }
                        
                        
						vars.clear();		
						 }
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 199 "yaccfile1.y" /* yacc.c:1646  */
    {				
								if((yyvsp[0].d).flag==2)
								{cout<<"error in declaration!! :("<<endl;exit(0);}
								string code1="";
								vars.push_back((yyvsp[0].d).place);
								code1.append((yyvsp[0].d).place);
								
								(yyval.d).code=new char[code1.length()];
                        strcpy((yyval.d).code,code1.c_str());
          	}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 209 "yaccfile1.y" /* yacc.c:1646  */
    {
								if((yyvsp[-2].d).flag==2)
								{cout<<"error in declaration!! :("<<endl;exit(0);}
								string code1="";
								vars.push_back((yyvsp[-2].d).place);
								
								code1.append((yyvsp[-2].d).place);
								code1.append(", ");
								code1.append((yyvsp[0].d).code);
								(yyval.d).code=new char[code1.length()];
                        strcpy((yyval.d).code,code1.c_str());
							}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 223 "yaccfile1.y" /* yacc.c:1646  */
    {}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 224 "yaccfile1.y" /* yacc.c:1646  */
    { }
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 228 "yaccfile1.y" /* yacc.c:1646  */
    {
																
																string snext="l"+to_string(lc++);
																string code1="";
																code1.append((yyvsp[-7].d).code);
																code1+=gen("if ",(yyvsp[-7].d).place," = ","0 ");
																code1+=gen("goto ",snext);
																code1.append((yyvsp[-3].d).code);
																code1.append("\n");
																code1+=gen(snext,":");
																code1.append((yyvsp[0].d).code);
																(yyval.d).code=new char[code1.length()];
			                                    				strcpy((yyval.d).code,code1.c_str());
			                                    				
															}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 244 "yaccfile1.y" /* yacc.c:1646  */
    {
																
																string s2next="l"+to_string(lc++);
																string snext="l"+to_string(lc++);
																string code1="";
																code1.append((yyvsp[-13].d).code);
																code1+=gen("if ",(yyvsp[-13].d).place," = ","0 ");
																code1+=gen("goto ",s2next);
																code1.append((yyvsp[-9].d).code);
																code1.append("\n");
																code1+=gen("goto",snext);
																code1+=gen(s2next,":");
																//code1.append("\n");
																code1.append((yyvsp[-3].d).code);
																code1.append("\n");
																code1+=gen(snext,":");
																code1.append((yyvsp[0].d).code);
																(yyval.d).code=new char[code1.length()];
                                    							strcpy((yyval.d).code,code1.c_str());
															}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 265 "yaccfile1.y" /* yacc.c:1646  */
    {
		  														
		  														string sbegin="l"+to_string(lc++);
																string safter="l"+to_string(lc++);
																string ebegin="l"+to_string(lc++);
																string code1="";
																code1+=gen(sbegin,":");
																code1.append((yyvsp[-11].d).code);
																code1.append("\n");
																code1+=gen(ebegin,":");
																code1.append((yyvsp[-9].d).code);
																code1+=gen("if ",(yyvsp[-9].d).place," = ","0 ");
																code1+=gen("goto ",safter);
																code1.append((yyvsp[-3].d).code);
																code1.append("\n");
																code1.append((yyvsp[-7].d).code);
																code1.append("\n");
																code1+=gen("goto ",ebegin);
																code1+=gen(safter,":");
																code1.append((yyvsp[0].d).code);
																(yyval.d).code=new char[code1.length()];
                                    				strcpy((yyval.d).code,code1.c_str());

		  														}
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 290 "yaccfile1.y" /* yacc.c:1646  */
    {
																

																
																string begin="l"+to_string(lc++);
																string after="l"+to_string(lc++);
																string code1="";
																code1+=gen(begin,":");
																code1.append((yyvsp[-7].d).code);
																code1+=gen("if ",(yyvsp[-7].d).place," = ","0 ");
																code1+=gen("goto ",after);
																code1.append((yyvsp[-3].d).code);
																//code1.append(";");
																code1.append("\n");
																code1+=gen("goto ",begin);
																code1+=gen(after," :");
																code1.append((yyvsp[0].d).code);
																
																
																(yyval.d).code=new char[code1.length()];
                                    				strcpy((yyval.d).code,code1.c_str());
                                    							
														  }
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 313 "yaccfile1.y" /* yacc.c:1646  */
    {
															
															//string place1="t"+to_string(tc++);
															string code1="";
															
															code1.append((yyvsp[-6].d).code);
															code1.append("\n");
															map<string,string>::iterator it;
															for(it=values.begin();it!=values.end();it++){
																code1+=gen("\nif ",(yyvsp[-6].d).place," = ",it->first);
																code1+=gen("goto ",it->second);
															}
															
															code1.append((yyvsp[-2].d).code);
															code1.append("\n");
															code1.append(begin1);
															code1.append(": \n");
															(yyval.d).code=new char[code1.length()];
															strcpy((yyval.d).code,code1.c_str());


															}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 335 "yaccfile1.y" /* yacc.c:1646  */
    { 
         									
         							int x=iscompatible((yyvsp[-5].d).place,(yyvsp[-3].d).place);
                                       
                                    string code1="";
                                    code1.append((yyvsp[-3].d).code);
                                    code1.append((yyvsp[-5].d).place);
                                    code1.append(getassignop((yyvsp[-4].d).val));
                                    code1.append((yyvsp[-3].d).place);
                                    code1.append(";\n");
                                    code1.append((yyvsp[0].d).code);
                                    (yyval.d).code=new char[code1.length()];
                                    strcpy((yyval.d).code,code1.c_str());
                                    
                                    
                                  }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 351 "yaccfile1.y" /* yacc.c:1646  */
    {
         	string code1="";
         	(yyval.d).code=new char[code1.length()];
          	strcpy((yyval.d).code,code1.c_str());
           }
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 364 "yaccfile1.y" /* yacc.c:1646  */
    {
													string code1="";
													code1.append((yyvsp[-12].d).code);
													if(casef==0){
														begin1="l"+to_string(lc++);
														casef=1;

													}
													string begin="l"+to_string(lc++);
													code1+=gen(begin,":");
													code1.append((yyvsp[-5].d).code);
													
													
													code1+=gen("goto ",begin1);
													code1.append("\n");
												    (yyval.d).code=new char[code1.length()];
                                    				strcpy((yyval.d).code,code1.c_str());
													values[(yyvsp[-9].d).place]=begin;
													}
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 383 "yaccfile1.y" /* yacc.c:1646  */
    {string code1="";(yyval.d).code=new char[code1.length()];strcpy((yyval.d).code,code1.c_str());}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 386 "yaccfile1.y" /* yacc.c:1646  */
    {   	(yyval.d).flag=2; 
                                       string code1="";
													string place1="";
													int x=isdeclared((yyvsp[-2].d).place,(yyvsp[0].d).place);
													(yyval.d).place=new char[place1.length()];
													place1="t"+to_string(tc++);
													strcpy((yyval.d).place,place1.c_str());
                                       (yyval.d).code=new char[code1.length()];
                                       code1.append((yyvsp[-2].d).code);
                                       code1.append((yyvsp[0].d).code);
                                       code1+=gen((yyval.d).place," = ",(yyvsp[-2].d).place," + ",(yyvsp[0].d).place);
                                       if(x==1)
                                       typecheck[(yyval.d).place]="float";
                                       else if(x==2)
                                       typecheck[(yyval.d).place]="int";
                                       else if(x==0)
                                       {cout<<"boolean variable used in arithematic expression"<<endl;exit(0);}
                                       (yyval.d).code=new char[code1.length()];
													strcpy((yyval.d).code,code1.c_str());
                                  }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 407 "yaccfile1.y" /* yacc.c:1646  */
    {	(yyval.d).flag=2;
         										string code1="";
													string place1="";
													int x=isdeclared((yyvsp[-2].d).place,(yyvsp[0].d).place);
													(yyval.d).place=new char[place1.length()];
													place1="t"+to_string(tc++);
													strcpy((yyval.d).place,place1.c_str());
                                       (yyval.d).code=new char[code1.length()];
                                       code1.append((yyvsp[-2].d).code);
                                       code1.append((yyvsp[0].d).code);
                                       code1+=gen((yyval.d).place," = ",(yyvsp[-2].d).place," - ",(yyvsp[0].d).place);
                                       if(x==1)
                                       typecheck[(yyval.d).place]="float";
                                       else if(x==2)
                                       typecheck[(yyval.d).place]="int";
                                       else if(x==0)
                                       {cout<<"boolean variable used in arithematic expression"<<endl;exit(0);}
                                       (yyval.d).code=new char[code1.length()];
													strcpy((yyval.d).code,code1.c_str());
                                      
                                   }
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 428 "yaccfile1.y" /* yacc.c:1646  */
    { 	(yyval.d).flag=2; 
                                       string code1="";
													string place1="";
													int x=isdeclared((yyvsp[-2].d).place,(yyvsp[0].d).place);
													(yyval.d).place=new char[place1.length()];
													place1="t"+to_string(tc++);
													strcpy((yyval.d).place,place1.c_str());
                                       (yyval.d).code=new char[code1.length()];
                                       code1.append((yyvsp[-2].d).code);
                                       code1.append((yyvsp[0].d).code);
                                       code1+=gen((yyval.d).place," = ",(yyvsp[-2].d).place," * ",(yyvsp[0].d).place);
                                       if(x==1)
                                       typecheck[(yyval.d).place]="float";
                                       else if(x==2)
                                       typecheck[(yyval.d).place]="int";
                                       else if(x==0)
                                       {cout<<"boolean variable used in arithematic expression"<<endl;exit(0);}
                                       (yyval.d).code=new char[code1.length()];
													strcpy((yyval.d).code,code1.c_str());
                                   }
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 448 "yaccfile1.y" /* yacc.c:1646  */
    {	(yyval.d).flag=2;
                                       string code1="";
													string place1="";
													int x=isdeclared((yyvsp[-2].d).place,(yyvsp[0].d).place);
													(yyval.d).place=new char[place1.length()];
													place1="t"+to_string(tc++);
													strcpy((yyval.d).place,place1.c_str());
                                       (yyval.d).code=new char[code1.length()];
                                       code1.append((yyvsp[-2].d).code);
                                       code1.append((yyvsp[0].d).code);
                                       code1+=gen((yyval.d).place," = ",(yyvsp[-2].d).place," / ",(yyvsp[0].d).place);
                                       if(x==1)
                                       typecheck[(yyval.d).place]="float";
                                       else if(x==2)
                                       typecheck[(yyval.d).place]="int";
                                       else if(x==0)
                                       {cout<<"boolean variable used in arithematic expression"<<endl;exit(0);}
                                       (yyval.d).code=new char[code1.length()];
													strcpy((yyval.d).code,code1.c_str());
                                   }
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 468 "yaccfile1.y" /* yacc.c:1646  */
    {	(yyval.d).flag=2;
                                       string code1="";
													string place1="";
													int x=isdeclared((yyvsp[-2].d).place,(yyvsp[0].d).place);
													
													(yyval.d).place=new char[place1.length()];
													place1="t"+to_string(tc++);
													strcpy((yyval.d).place,place1.c_str());
                                       (yyval.d).code=new char[code1.length()];
                                       code1.append((yyvsp[-2].d).code);
                                       code1.append((yyvsp[0].d).code);
                                       code1+=gen((yyval.d).place," = ",(yyvsp[-2].d).place," @ ",(yyvsp[0].d).place);
                                       if(x==1)
                                       typecheck[(yyval.d).place]="float";
                                       else if(x==2)
                                       typecheck[(yyval.d).place]="int";
                                       else if(x==0)
                                       {cout<<"boolean variable used in arithematic expression"<<endl;exit(0);}
                                       (yyval.d).code=new char[code1.length()];
													strcpy((yyval.d).code,code1.c_str());
                                   }
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 489 "yaccfile1.y" /* yacc.c:1646  */
    {	(yyval.d).flag=2;
         										string code1="";
													string place1="";
													int x=isdeclared((yyvsp[-2].d).place,(yyvsp[0].d).place);
													(yyval.d).place=new char[place1.length()];
													place1="t"+to_string(tc++);
													strcpy((yyval.d).place,place1.c_str());
                                       (yyval.d).code=new char[code1.length()];
                                       code1.append((yyvsp[-2].d).code);
                                       code1.append((yyvsp[0].d).code);
                                       code1+=gen((yyval.d).place," = ",(yyvsp[-2].d).place," | ",(yyvsp[0].d).place);
                                       if(x==1)
                                       typecheck[(yyval.d).place]="float";
                                       else if(x==2)
                                       typecheck[(yyval.d).place]="int";
                                       else if(x==0)
                                       {cout<<"boolean variable used in arithematic expression"<<endl;exit(0);}
                                       (yyval.d).code=new char[code1.length()];
													strcpy((yyval.d).code,code1.c_str());
                                      
                                   }
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 510 "yaccfile1.y" /* yacc.c:1646  */
    {		(yyval.d).flag=2;
                                       string code1="";
													string place1="";
													int x=isdeclared((yyvsp[-2].d).place,(yyvsp[0].d).place);
													(yyval.d).place=new char[place1.length()];
													place1="t"+to_string(tc++);
													strcpy((yyval.d).place,place1.c_str());
                                       code1.append((yyvsp[-2].d).code);
                                       code1.append((yyvsp[0].d).code);
                                       code1+=gen((yyval.d).place," = ",(yyvsp[-2].d).place," & ",(yyvsp[0].d).place);
                                       if(x==1)
                                       typecheck[(yyval.d).place]="float";
                                       else if(x==2)
                                       typecheck[(yyval.d).place]="int";
                                       else if(x==0)
                                       {cout<<"boolean variable used in arithematic expression"<<endl;exit(0);}
                                       (yyval.d).code=new char[code1.length()];
													strcpy((yyval.d).code,code1.c_str());
                                  }
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 530 "yaccfile1.y" /* yacc.c:1646  */
    {		(yyval.d).flag=2;
                                       string code1="";
													string place1="";
													int x=isdeclared((yyvsp[-2].d).place,(yyvsp[0].d).place);
													(yyval.d).place=new char[place1.length()];
													place1="t"+to_string(tc++);
													strcpy((yyval.d).place,place1.c_str());
                                       code1.append((yyvsp[-2].d).code);
                                       code1.append((yyvsp[0].d).code);
                                       code1+=gen((yyval.d).place," = ",(yyvsp[-2].d).place," ^ ",(yyvsp[0].d).place);
                                       if(x==1)
                                       typecheck[(yyval.d).place]="float";
                                       else if(x==2)
                                       typecheck[(yyval.d).place]="int";
                                       else if(x==0)
                                       {cout<<"boolean variable used in arithematic expression"<<endl;exit(0);}
                                       (yyval.d).code=new char[code1.length()];
													strcpy((yyval.d).code,code1.c_str());
                                  }
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 549 "yaccfile1.y" /* yacc.c:1646  */
    {		(yyval.d).flag=2;
        										   string code1="";
													string place1="";
													int x=isdeclared((yyvsp[-2].d).place,(yyvsp[0].d).place);
													(yyval.d).place=new char[place1.length()];
													place1="t"+to_string(tc++);
													strcpy((yyval.d).place,place1.c_str());
													code1.append((yyvsp[-2].d).code);
                                       code1.append((yyvsp[0].d).code);
                                       code1+=gen((yyval.d).place," = ",(yyvsp[-2].d).place," > ",(yyvsp[0].d).place);
                                       if(x==1 && x==2)
                                       typecheck[(yyval.d).place]="bool";
                                       else if(x==0)
                                       {cout<<"boolean variable used in arithematic expression"<<endl;exit(0);}
                                       (yyval.d).code=new char[code1.length()];
                                       strcpy((yyval.d).code,code1.c_str());
        									 }
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 566 "yaccfile1.y" /* yacc.c:1646  */
    {		(yyval.d).flag=2;
        										   string code1="";
													string place1="";
													
													int x=isdeclared((yyvsp[-2].d).place,(yyvsp[0].d).place);
													(yyval.d).place=new char[place1.length()];
													place1="t"+to_string(tc++);
													strcpy((yyval.d).place,place1.c_str());
													code1.append((yyvsp[-2].d).code);
                                       code1.append((yyvsp[0].d).code);
                                       code1+=gen((yyval.d).place," = ",(yyvsp[-2].d).place," < ",(yyvsp[0].d).place);
                                       if(x==1 && x==2)
                                       typecheck[(yyval.d).place]="bool";
                                       else if(x==0)
                                       {cout<<"boolean variable used in arithematic expression"<<endl;exit(0);}
                                       (yyval.d).code=new char[code1.length()];
                                       strcpy((yyval.d).code,code1.c_str());
        									 }
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 584 "yaccfile1.y" /* yacc.c:1646  */
    {		(yyval.d).flag=2;
        											string code1="";
													string place1="";
													
                                    	place1="t"+to_string(tc++);
                                    	strcpy((yyval.d).place,place1.c_str());
                                    	code1.append((yyval.d).place);
                                    	code1+=" = ~";
                                    	code1+=(yyvsp[0].d).place;
                                    	code1+="\n";
                                    	if(typecheck.find((yyvsp[0].d).place)!=typecheck.end())
                                    	typecheck[(yyval.d).place]=typecheck[(yyvsp[0].d).place];
                                    	else
                                    	{cout<<"Not declared !!"<<endl;exit(0);}
                                    	(yyval.d).code=new char[code1.length()];
                                    	strcpy((yyval.d).code,code1.c_str());
                                   }
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 601 "yaccfile1.y" /* yacc.c:1646  */
    {	(yyval.d).flag=2;
													string code1="";
                                       (yyval.d).code=new char[code1.length()];
                                       strcpy((yyval.d).code,code1.c_str());
                                       (yyval.d).place=new char[strlen((yyvsp[-1].d).place)];
                                    	strcpy((yyval.d).place,(yyvsp[-1].d).place);
                                    	if(typecheck.find((yyvsp[-1].d).place)!=typecheck.end())
                                    	typecheck[(yyval.d).place]=typecheck[(yyvsp[-1].d).place];
                                    	else
                                    	{cout<<"Not declared !!"<<endl;exit(0);}
                                   }
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 612 "yaccfile1.y" /* yacc.c:1646  */
    {	(yyval.d).flag=2;
         										string code1="";
													string place1="";
													int x=isdeclared((yyvsp[-2].d).place,(yyvsp[0].d).place);
													(yyval.d).place=new char[place1.length()];
													place1="t"+to_string(tc++);
													strcpy((yyval.d).place,place1.c_str());
                                       (yyval.d).code=new char[code1.length()];
                                       code1.append((yyvsp[-2].d).code);
                                       code1.append((yyvsp[0].d).code);
                                       code1+=gen((yyval.d).place," = ",(yyvsp[-2].d).place," AND ",(yyvsp[0].d).place);
                                       if(x==0 && x==1 && x==2)
													typecheck[(yyval.d).place]="bool";
                                       (yyval.d).code=new char[code1.length()];
													strcpy((yyval.d).code,code1.c_str());
                                      
                                   }
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 629 "yaccfile1.y" /* yacc.c:1646  */
    {	(yyval.d).flag=2;
         										string code1="";
													string place1="";
													int x=isdeclared((yyvsp[-2].d).place,(yyvsp[0].d).place);
													(yyval.d).place=new char[place1.length()];
													place1="t"+to_string(tc++);
													strcpy((yyval.d).place,place1.c_str());
                                       (yyval.d).code=new char[code1.length()];
                                       code1.append((yyvsp[-2].d).code);
                                       code1.append((yyvsp[0].d).code);
                                       code1+=gen((yyval.d).place," = ",(yyvsp[-2].d).place," OR ",(yyvsp[0].d).place);
                                       if(x==0 && x==1 && x==2)
													typecheck[(yyval.d).place]="bool";
                                       (yyval.d).code=new char[code1.length()];
													strcpy((yyval.d).code,code1.c_str());
                                      
                                   }
#line 2106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 646 "yaccfile1.y" /* yacc.c:1646  */
    {		(yyval.d).flag=2;
        											string code1="";
													string place1="";
                                    	place1="t"+to_string(tc++);
                                    	strcpy((yyval.d).place,place1.c_str());
                                    	code1.append((yyval.d).place);
                                    	code1+=" = NOT";
                                    	code1+=(yyvsp[0].d).place;
                                    	code1+="\n";
                                    	(yyval.d).code=new char[code1.length()];
                                    	strcpy((yyval.d).code,code1.c_str());
                                   }
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 659 "yaccfile1.y" /* yacc.c:1646  */
    {	
         									(yyval.d).flag=1;
                                    string code1;
                                    string place1;
                                    code1.append("");
                                    place1.append((yyvsp[0].d).place);
                                    
                                    (yyval.d).code=new char[code1.length()];
                                    strcpy((yyval.d).code,code1.c_str());
                                    (yyval.d).place=new char[strlen((yyvsp[0].d).place)];
                                    strcpy((yyval.d).place,(yyvsp[0].d).place);
												
                                }
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 672 "yaccfile1.y" /* yacc.c:1646  */
    {		(yyval.d).flag=2;
                                    string code1;
                                    string place1;
                                    code1.append("");
                                    place1.append((yyvsp[0].d).place);
                                    (yyval.d).code=new char[code1.length()];
                                    strcpy((yyval.d).code,code1.c_str());
                                    (yyval.d).place=new char[place1.length()];
                                    strcpy((yyval.d).place,place1.c_str());
                               }
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2160 "y.tab.c" /* yacc.c:1646  */
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
#line 686 "yaccfile1.y" /* yacc.c:1906  */
 



void yyerror(char *s) {
    cout<<"error"<<endl;fprintf(stderr, "%s\n", s);
} 
int main(void) { 
  cout<<"in main"<<endl;return yyparse(); 
} 													

