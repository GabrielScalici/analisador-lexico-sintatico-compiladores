/* A Bison parser, made by GNU Bison 3.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 84 "lalg.y"

	#define _GNU_SOURCE

	#include <stdlib.h>
	#include <stdio.h>
	#include <stdarg.h>
	#include <string.h>
	#include <search.h>

	#define SIZE_SYM_TABLE 1000

	/* Funcao definida no lalg.l */
	extern int yylex();

	/* Funcao para imprimir mensagem de erro */
	void yyerror(char *s, ...);

	/* Tabelas de simbolos: uma por escopo */
	struct hsearch_data *symtables = NULL;
	int scope = 0;
	
	/* Lista temporaria de variaveis (simbolos) */
	struct sym_s **varlist = NULL;
	int n_varlist = 0;

	/* Lista temporaria de parametros (simbolos) */
	struct sym_s **parlist = NULL;
	int n_parlist = 0;
	int last_par  = -1;

	/* Lista temporaria de argumentos (strings) */
	char **arglist = NULL;
	int n_arglist = 0;

	/* Flag que sinaliza se ocorreu operacao de divisao nas contas */
	int div_flag = 0;

#line 108 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 5 "lalg.y"


	#define MAX_LENGTH_IDENT   13 /* comprimento maximo para identificador  */
	#define MAX_LENGTH_INTEGER 13 /* comprimento maximo para numero inteiro */
	#define MAX_LENGTH_REAL    13 /* comprimento maximo para numero real    */

	/* Tipos de dados */	
	enum type_e {
		TYPE_PROGRAM,
		TYPE_FUNCTION,
		TYPE_STRING,
		TYPE_CONST,
		TYPE_INTEGER,
	 	TYPE_FLOAT,
		TYPE_CHAR,
		TYPE_VAR,
		TYPE_PROC,
		TYPE_NONE
	};

	/* Valores de dados */
	union val_u {
		int    intval;
		double floatval;
		char   charval;
		char   *strval;
	};

	/* Estrutura de dado que tem tipo e valor */
	struct data_s {
		enum type_e type;
		union val_u value;
	};

	/* Estrutura para guardar um simbolo */
	struct sym_s {
		int           scope;
		enum type_e   type; /* TYPE_VAR ou TYPE_PROC */
		char          id[MAX_LENGTH_IDENT + 1];
		struct data_s data;
		struct sym_s  **parlist;
		int           n_parlist;
	};

	/* Funcoes que manipulam tabelas de simbolos */
	void print_sym(const struct sym_s *sym);
	void set_sym_var(enum type_e type, struct sym_s *sym, const char *id, struct data_s data);
	void free_sym(struct sym_s *sym);
	struct entry *exist_sym(const char *id);
	int add_sym_var_s(struct sym_s *new_sym);
	void add_sym_var(enum type_e type, const char *id, struct data_s data);
	void update_sym_var(const char *id, struct data_s data);
	struct data_s get_sym_data(const char *id);
	int add_sym_proc(const char *id);
	void get_sym_and_print(const char *id, int scope);
	void free_symtables(int scope);

	/* Manipulacao de escopo */
	void sym_inc_scope();
	void sym_dec_scope();

	/* Lista de declaracao de variaveis */
	void add_varlist(enum type_e type, const char *id);
	void setnsave_varlist(enum type_e datatype);
	void free_varlist();
	void check_varlist_type();

	/* Lista de declaracao de parametros */
	void add_parlist(enum type_e type, const char *id);
	void set_parlist(enum type_e datatype);
	void save_parlist();
	void free_parlist();
	void empty_parlist();

	/* Lista de argumentos (usado em chamada de procedimento ou comando) */
	void add_arglist(const char *id);
	void check_arglist_proc(const char *id);
	void free_arglist();

#line 222 "y.tab.c"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    W_BEGIN = 258,
    W_CHAR = 259,
    W_CONST = 260,
    W_DO = 261,
    W_ELSE = 262,
    W_END = 263,
    W_FOR = 264,
    W_FUNCTION = 265,
    W_IF = 266,
    W_INTEGER = 267,
    W_PROCEDURE = 268,
    W_PROGRAM = 269,
    W_READ = 270,
    W_REAL = 271,
    W_REPEAT = 272,
    W_THEN = 273,
    W_TO = 274,
    W_UNTIL = 275,
    W_VAR = 276,
    W_WHILE = 277,
    W_WRITE = 278,
    COLON = 279,
    SEMICOLON = 280,
    DOT = 281,
    COMMA = 282,
    OPAR = 283,
    CPAR = 284,
    ATR = 285,
    GOE = 286,
    LOE = 287,
    DIFFERENT = 288,
    EQUAL = 289,
    GR = 290,
    LE = 291,
    PLUS = 292,
    MINUS = 293,
    MULT = 294,
    DIV = 295,
    IDENT = 296,
    INTEGER = 297,
    REAL = 298,
    CHAR = 299,
    UNKNOWN = 300
  };
#endif
/* Tokens.  */
#define W_BEGIN 258
#define W_CHAR 259
#define W_CONST 260
#define W_DO 261
#define W_ELSE 262
#define W_END 263
#define W_FOR 264
#define W_FUNCTION 265
#define W_IF 266
#define W_INTEGER 267
#define W_PROCEDURE 268
#define W_PROGRAM 269
#define W_READ 270
#define W_REAL 271
#define W_REPEAT 272
#define W_THEN 273
#define W_TO 274
#define W_UNTIL 275
#define W_VAR 276
#define W_WHILE 277
#define W_WRITE 278
#define COLON 279
#define SEMICOLON 280
#define DOT 281
#define COMMA 282
#define OPAR 283
#define CPAR 284
#define ATR 285
#define GOE 286
#define LOE 287
#define DIFFERENT 288
#define EQUAL 289
#define GR 290
#define LE 291
#define PLUS 292
#define MINUS 293
#define MULT 294
#define DIV 295
#define IDENT 296
#define INTEGER 297
#define REAL 298
#define CHAR 299
#define UNKNOWN 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 125 "lalg.y"

	struct data_s data;

#line 327 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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


#define YY_ASSERT(E) ((void) (0 && (E)))

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   323

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  296

#define YYUNDEFTOK  2
#define YYMAXUTOK   300

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   210,   210,   220,   221,   222,   223,   224,   228,   230,
     234,   237,   238,   241,   247,   248,   249,   252,   253,   256,
     261,   262,   263,   267,   268,   269,   273,   280,   281,   286,
     293,   294,   297,   298,   302,   308,   309,   313,   314,   316,
     317,   318,   319,   322,   328,   329,   331,   334,   338,   342,
     343,   344,   345,   349,   350,   354,   356,   357,   358,   362,
     363,   368,   372,   373,   374,   378,   379,   381,   385,   393,
     394,   396,   400,   401,   403,   407,   408,   411,   415,   418,
     421,   422,   423,   429,   434,   440,   441,   442,   447,   448,
     450,   451,   453,   455,   456,   457,   459,   460,   462,   463,
     464,   466,   467,   468,   469,   473,   477,   478,   479,   480,
     481,   482,   486,   516,   517,   518,   521,   548,   551,   562,
     563,   566,   603,   617,   651,   654,   664,   668,   669,   673,
     674,   675,   677,   681,   682
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"begin\"", "\"char\"", "\"const\"",
  "\"do\"", "\"else\"", "\"end\"", "\"for\"", "\"function\"", "\"if\"",
  "\"integer\"", "\"procedure\"", "\"program\"", "\"read\"", "\"real\"",
  "\"repeat\"", "\"then\"", "\"to\"", "\"until\"", "\"var\"", "\"while\"",
  "\"write\"", "\":\"", "\";\"", "\".\"", "\",\"", "\"(\"", "\")\"",
  "\":=\"", "\">=\"", "\"<=\"", "\"<>\"", "\"=\"", "\">\"", "\"<\"",
  "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"identificador\"",
  "\"valor inteiro\"", "\"valor real\"", "\"caractere\"",
  "\"token desconhecido\"", "$accept", "programa", "corpo", "dc", "dc_c",
  "dc_c0", "dc_v", "dc_v0", "tipo_var", "variaveis", "mais_var",
  "variaveis0", "mais_var0", "dc_p", "dc_p0", "dc_func", "parametros",
  "parametros0", "lista_par", "lista_par0", "mais_par", "corpo_p",
  "dc_loc", "dc_loc0", "lista_arg", "argumentos", "mais_ident", "pfalsa",
  "comandos", "comandos0", "cmd", "condicao", "relacao", "expressao",
  "op_un", "outros_termos", "outros_termos0", "op_ad", "termo", "termo0",
  "mais_fatores", "mais_fatores0", "op_mul", "fator", "numero", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF -103

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-103)))

#define YYTABLE_NINF -125

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     152,   -26,    19,    17,     0,     2,    85,  -103,   169,   169,
     169,   175,    -8,     4,    51,   102,   139,   169,   107,   177,
     116,    71,   149,    12,  -103,    76,    21,   199,   139,  -103,
    -103,  -103,  -103,  -103,  -103,   168,   168,   168,    76,    27,
     206,    30,    76,   211,    33,    93,   157,    76,   193,   221,
     225,   103,    28,   243,   199,  -103,  -103,  -103,   229,   230,
      89,   101,   226,    18,  -103,  -103,   239,   198,    11,   209,
     112,   217,    34,   155,   206,   217,    35,   156,    39,    78,
    -103,  -103,  -103,  -103,  -103,   204,   217,  -103,   204,   183,
     231,    22,    40,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,   206,   206,   206,    15,  -103,  -103,  -103,  -103,
    -103,  -103,   206,  -103,   206,  -103,  -103,  -103,  -103,  -103,
    -103,   209,   206,  -103,  -103,  -103,  -103,   112,    11,   232,
     233,   234,    70,   206,   235,   236,   237,   238,  -103,  -103,
    -103,   240,    63,   241,  -103,  -103,  -103,  -103,  -103,   246,
    -103,   247,   248,   249,    41,   250,  -103,   251,   252,   231,
     231,   259,   260,   261,  -103,   253,  -103,   254,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,   262,
    -103,  -103,  -103,  -103,   244,   244,  -103,  -103,  -103,  -103,
    -103,  -103,   135,   255,   110,   257,   256,   263,   263,   263,
     264,   265,   245,   258,    13,    48,  -103,  -103,    76,  -103,
    -103,   204,  -103,   266,  -103,   204,   185,  -103,    42,  -103,
      43,  -103,   287,   263,  -103,  -103,   204,   201,   285,   286,
     288,   208,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
     269,  -103,   271,   111,    76,  -103,   272,   273,    95,   293,
     296,   298,   299,   300,   204,   204,   203,   190,   243,   243,
     167,   243,    76,    76,    76,    76,    76,   279,   280,   281,
     283,   129,   100,  -103,  -103,  -103,  -103,  -103,   301,   302,
     303,   304,   305,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
       0,     0,     0,     0,     0,     0,    18,     0,     0,     0,
       0,     0,     0,     0,     3,    76,     0,    33,    18,    11,
       4,     5,     6,     7,     2,     0,     0,     0,    76,     0,
     115,     0,    76,     0,     0,     0,     0,    76,     0,     0,
      28,     0,     0,    38,    33,    17,   133,   134,     0,     0,
       0,     0,     0,     0,   113,   114,     0,     0,     0,   117,
       0,     0,     0,     0,   115,     0,     0,   115,     0,   115,
      84,     9,     8,    75,    77,     0,     0,    26,     0,     0,
      45,     0,     0,    10,    32,    14,    15,    16,    13,    96,
      85,    97,   115,   115,   115,     0,   108,   109,   107,   106,
     110,   111,   115,   132,   115,   129,   122,   130,   119,   120,
     112,   117,   115,   126,   127,   128,   121,     0,     0,     0,
       0,     0,   115,   115,     0,     0,     0,     0,    93,    95,
      94,     0,     0,     0,    83,    82,    25,    24,    23,     0,
      27,     0,     0,     0,     0,     0,    43,     0,     0,    45,
      45,     0,     0,     0,    92,    73,   105,     0,   116,   118,
     123,   125,    88,    89,    78,   100,    99,    98,    86,     0,
      90,    91,    79,    67,     0,     0,    68,    65,    20,    21,
      22,    19,     0,    31,     0,     0,    54,    60,    60,    60,
       0,     0,     0,     0,     0,     0,    81,   131,     0,    71,
      69,     0,    46,     0,    29,    52,     0,    44,     0,    47,
       0,    35,     0,    60,    36,    34,     0,     0,     0,     0,
       0,     0,    74,    72,    80,    49,    30,    50,    51,    48,
       0,    53,     0,     0,    76,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    38,
      38,    38,    76,    76,    76,    76,    76,     0,     0,     0,
       0,     0,     0,    39,    40,    42,    41,    37,     0,     0,
       0,     0,     0,    62,    63,    64,    61,    57,    56,    58,
      55,   101,   102,   103,   104,    87
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -103,  -103,   212,  -103,   297,  -103,   289,  -103,   -87,   -65,
    -103,   105,  -103,   267,  -103,   -23,   -86,  -103,    97,  -103,
    -103,    50,    96,  -103,  -103,    66,  -103,  -103,   -38,  -103,
    -102,   -66,  -103,    59,  -103,   195,  -103,  -103,   200,  -103,
     196,  -103,  -103,   192,   205
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    14,    15,    16,    17,    27,    28,   149,    51,
      87,   194,   214,    53,    54,    93,   155,   156,   195,   196,
     219,   221,   222,   223,    80,   143,   186,   206,    46,    47,
      48,    66,   112,    67,    68,   120,   121,   122,    69,    70,
     126,   127,   128,   116,   117
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      61,   151,   153,   165,    73,   158,   129,   131,   134,    83,
     135,   137,   113,    36,   230,     4,   164,     7,    38,   103,
       5,   150,    49,   157,    39,     8,    40,     9,    62,    90,
      41,    71,    42,    22,    75,   130,   136,    43,    44,   114,
     141,   159,   192,   240,   242,    23,    37,   -45,   104,   232,
     154,    38,   115,    56,    57,   231,    45,    39,    72,    40,
       6,    76,    50,    41,   184,    42,   177,   178,    63,    91,
      43,    44,    33,   200,   201,    50,    50,    24,   175,    38,
     142,   160,   193,   193,    50,    39,    10,    40,   185,    45,
      97,    41,   -70,    42,    77,   176,   260,    34,    43,    44,
     -66,   289,    99,   233,    88,    25,   234,    64,    65,   100,
      11,   215,   255,   123,    98,    64,    65,    45,   -66,  -124,
     261,    78,   144,    79,   235,   290,   101,    89,   237,   239,
    -124,  -124,   287,    30,   216,   256,   140,  -124,   145,   246,
     248,  -124,    32,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,   124,   125,     1,   288,   243,   132,    22,    81,   211,
      26,   161,   162,   163,   212,    82,     2,   267,   268,   270,
      12,   166,   -12,   167,    13,   133,    20,    92,   -12,   -12,
      13,   138,   -12,    35,   152,   -12,   238,   146,   -12,   146,
     -12,   271,   275,    64,    65,   147,   -12,   147,   272,   148,
     139,   148,   247,    31,   269,   146,   257,   146,   146,   252,
      56,    57,    52,   147,   253,   147,   147,   148,    84,   148,
     148,    18,    19,    21,   278,   279,   280,   281,   282,   106,
     107,   108,   109,   110,   111,   273,   274,   276,   277,    74,
      58,    59,    60,    64,    65,    85,   118,   119,   224,   225,
     209,   210,    86,    92,    95,    96,   102,   105,    50,   154,
     205,   172,   173,   174,   179,   180,   181,   182,   208,   183,
     187,   188,   189,   190,   191,   197,   198,   199,   202,   203,
     204,   218,   213,   207,   220,   142,   217,   228,   226,   227,
     244,   249,   250,   211,   251,   254,   262,   258,   259,   263,
     229,   264,   265,   266,   283,   284,   285,   193,   286,   291,
     292,   293,   294,   295,    29,   241,   168,    55,   236,   245,
     171,    94,   169,   170
};

static const yytype_uint16 yycheck[] =
{
      38,    88,    89,   105,    42,    91,    71,    72,    74,    47,
      75,    76,     1,     1,     1,    41,     1,     0,     3,     1,
       1,    86,     1,     1,     9,    25,    11,    25,     1,     1,
      15,     1,    17,    41,     1,     1,     1,    22,    23,    28,
       1,     1,     1,     1,     1,    41,    34,    25,    30,     1,
      28,     3,    41,    42,    43,    42,    41,     9,    28,    11,
      41,    28,    41,    15,     1,    17,   132,   133,    41,    41,
      22,    23,     1,   159,   160,    41,    41,    26,     8,     3,
      41,    41,    41,    41,    41,     9,     1,    11,    25,    41,
       1,    15,    29,    17,     1,    25,     1,    26,    22,    23,
       7,     1,     1,   205,     1,     3,   208,    37,    38,     8,
      25,     1,     1,     1,    25,    37,    38,    41,    25,     7,
      25,    28,    44,    30,   211,    25,    25,    24,   215,   216,
      18,    19,     3,    26,    24,    24,    77,    25,    79,   226,
     227,    29,    26,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     1,    25,   220,     1,    41,     1,    24,
      21,   102,   103,   104,    29,     8,    14,   254,   255,   256,
       1,   112,     3,   114,     5,    20,     1,    10,     3,    10,
       5,    25,    13,    34,     1,    10,     1,     4,    13,     4,
      21,     1,    25,    37,    38,    12,    21,    12,     8,    16,
      44,    16,     1,    26,     1,     4,   244,     4,     4,     1,
      42,    43,    13,    12,     6,    12,    12,    16,    25,    16,
      16,     9,    10,    11,   262,   263,   264,   265,   266,    31,
      32,    33,    34,    35,    36,   258,   259,   260,   261,    28,
      35,    36,    37,    37,    38,    24,    37,    38,   198,   199,
     184,   185,    27,    10,    25,    25,    30,    18,    41,    28,
       7,    29,    29,    29,    29,    29,    29,    29,     6,    29,
      29,    25,    25,    25,    25,    25,    25,    25,    19,    19,
      19,    25,    27,    29,    21,    41,    29,    42,    24,    24,
       3,     6,     6,    24,     6,    24,     3,    25,    25,     3,
      42,     3,     3,     3,    25,    25,    25,    41,    25,     8,
       8,     8,     8,     8,    17,   218,   121,    28,   213,   223,
     128,    54,   122,   127
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    14,    47,    41,     1,    41,     0,    25,    25,
       1,    25,     1,     5,    48,    49,    50,    51,    48,    48,
       1,    48,    41,    41,    26,     3,    21,    52,    53,    50,
      26,    26,    26,     1,    26,    34,     1,    34,     3,     9,
      11,    15,    17,    22,    23,    41,    74,    75,    76,     1,
      41,    55,    13,    59,    60,    52,    42,    43,    90,    90,
      90,    74,     1,    41,    37,    38,    77,    79,    80,    84,
      85,     1,    28,    74,    28,     1,    28,     1,    28,    30,
      70,     1,     8,    74,    25,    24,    27,    56,     1,    24,
       1,    41,    10,    61,    59,    25,    25,     1,    25,     1,
       8,    25,    30,     1,    30,    18,    31,    32,    33,    34,
      35,    36,    78,     1,    28,    41,    89,    90,    37,    38,
      81,    82,    83,     1,    39,    40,    86,    87,    88,    55,
       1,    55,     1,    20,    77,    55,     1,    55,    25,    44,
      79,     1,    41,    71,    44,    79,     4,    12,    16,    54,
      55,    54,     1,    54,    28,    62,    63,     1,    62,     1,
      41,    79,    79,    79,     1,    76,    79,    79,    81,    84,
      86,    89,    29,    29,    29,     8,    25,    77,    77,    29,
      29,    29,    29,    29,     1,    25,    72,    29,    25,    25,
      25,    25,     1,    41,    57,    64,    65,    25,    25,    25,
      62,    62,    19,    19,    19,     7,    73,    29,     6,    71,
      71,    24,    29,    27,    58,     1,    24,    29,    25,    66,
      21,    67,    68,    69,    67,    67,    24,    24,    42,    42,
       1,    42,     1,    76,    76,    54,    57,    54,     1,    54,
       1,    64,     1,    55,     3,    68,    54,     1,    54,     6,
       6,     6,     1,     6,    24,     1,    24,    74,    25,    25,
       1,    25,     3,     3,     3,     3,     3,    54,    54,     1,
      54,     1,     8,    61,    61,    25,    61,    61,    74,    74,
      74,    74,    74,    25,    25,    25,    25,     3,    25,     1,
      25,     8,     8,     8,     8,     8
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    47,    47,    47,    47,    48,    48,
      49,    50,    50,    51,    51,    51,    51,    52,    52,    53,
      53,    53,    53,    54,    54,    54,    55,    56,    56,    57,
      58,    58,    59,    59,    60,    60,    60,    61,    61,    61,
      61,    61,    61,    62,    63,    63,    63,    64,    65,    65,
      65,    65,    65,    66,    66,    67,    67,    67,    67,    68,
      68,    69,    69,    69,    69,    70,    70,    70,    71,    72,
      72,    72,    73,    73,    73,    74,    74,    75,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    77,    78,    78,    78,    78,
      78,    78,    79,    80,    80,    80,    81,    81,    82,    83,
      83,    84,    85,    86,    86,    87,    87,    88,    88,    89,
      89,    89,    89,    90,    90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     5,     5,     5,     5,     5,     4,     4,
       4,     2,     0,     5,     5,     5,     5,     2,     0,     5,
       5,     5,     5,     1,     1,     1,     2,     2,     0,     2,
       2,     0,     2,     0,     5,     5,     5,     7,     0,     7,
       7,     7,     7,     1,     3,     0,     3,     2,     3,     3,
       3,     3,     2,     2,     0,     5,     5,     5,     5,     2,
       0,     5,     5,     5,     5,     3,     0,     3,     2,     2,
       0,     2,     2,     0,     2,     2,     0,     2,     4,     4,
       6,     5,     3,     3,     2,     3,     4,    10,     4,     4,
       4,     4,     4,     3,     3,     3,     3,     3,     4,     4,
       4,    10,    10,    10,    10,     3,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     0,     2,     0,     2,     1,
       1,     2,     2,     2,     0,     2,     1,     1,     1,     1,
       1,     3,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

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
  *++yylsp = yylloc;
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 210 "lalg.y"
    {
                    /* Cria procedimento para o nome do programa */
                    struct data_s data;
                    data.type = TYPE_PROGRAM;
                    memset(&data.value, 0, sizeof(union val_u));

                    /* Adiciona procedimento com o nome do programa */
                    add_sym_var(TYPE_PROC, (yyvsp[-3].data).value.strval, data); free((yyvsp[-3].data).value.strval);
              }
#line 1748 "y.tab.c"
    break;

  case 3:
#line 220 "lalg.y"
    { yyerrok; free((yyvsp[-3].data).value.strval); }
#line 1754 "y.tab.c"
    break;

  case 4:
#line 221 "lalg.y"
    { yyerrok; }
#line 1760 "y.tab.c"
    break;

  case 5:
#line 222 "lalg.y"
    { yyerrok; free((yyvsp[-3].data).value.strval); }
#line 1766 "y.tab.c"
    break;

  case 6:
#line 223 "lalg.y"
    { yyerrok; free((yyvsp[-3].data).value.strval); }
#line 1772 "y.tab.c"
    break;

  case 7:
#line 224 "lalg.y"
    { yyerrok; free((yyvsp[-3].data).value.strval); }
#line 1778 "y.tab.c"
    break;

  case 8:
#line 228 "lalg.y"
    {;}
#line 1784 "y.tab.c"
    break;

  case 9:
#line 230 "lalg.y"
    { yyerrok; }
#line 1790 "y.tab.c"
    break;

  case 10:
#line 234 "lalg.y"
    {;}
#line 1796 "y.tab.c"
    break;

  case 11:
#line 237 "lalg.y"
    {;}
#line 1802 "y.tab.c"
    break;

  case 12:
#line 238 "lalg.y"
    {;}
#line 1808 "y.tab.c"
    break;

  case 13:
#line 241 "lalg.y"
    {
                    /* Adiciona uma constante na tabela de simbolos    */
                    /* O datatype da constante e' o mesmo de "numbero" */
                    add_sym_var(TYPE_CONST, (yyvsp[-3].data).value.strval, (yyvsp[-1].data)); free((yyvsp[-3].data).value.strval);
              }
#line 1818 "y.tab.c"
    break;

  case 14:
#line 247 "lalg.y"
    { yyerrok; free((yyvsp[-3].data).value.strval); }
#line 1824 "y.tab.c"
    break;

  case 15:
#line 248 "lalg.y"
    { yyerrok; free((yyvsp[-3].data).value.strval); }
#line 1830 "y.tab.c"
    break;

  case 16:
#line 249 "lalg.y"
    { yyerrok; free((yyvsp[-3].data).value.strval); }
#line 1836 "y.tab.c"
    break;

  case 17:
#line 252 "lalg.y"
    {;}
#line 1842 "y.tab.c"
    break;

  case 18:
#line 253 "lalg.y"
    {;}
#line 1848 "y.tab.c"
    break;

  case 19:
#line 256 "lalg.y"
    {
                    /* Define datatype da lista de variaveis */
                    setnsave_varlist((yyvsp[-1].data).type);
              }
#line 1857 "y.tab.c"
    break;

  case 20:
#line 261 "lalg.y"
    { yyerrok; }
#line 1863 "y.tab.c"
    break;

  case 21:
#line 262 "lalg.y"
    { yyerrok; }
#line 1869 "y.tab.c"
    break;

  case 22:
#line 263 "lalg.y"
    { yyerrok; }
#line 1875 "y.tab.c"
    break;

  case 23:
#line 267 "lalg.y"
    { (yyval.data).type = TYPE_FLOAT;   }
#line 1881 "y.tab.c"
    break;

  case 24:
#line 268 "lalg.y"
    { (yyval.data).type = TYPE_INTEGER; }
#line 1887 "y.tab.c"
    break;

  case 25:
#line 269 "lalg.y"
    { (yyval.data).type = TYPE_CHAR;    }
#line 1893 "y.tab.c"
    break;

  case 26:
#line 273 "lalg.y"
    {
                    /* Adiciona uma variavel numa lista temporaria */
                    add_varlist(TYPE_VAR, (yyvsp[-1].data).value.strval);
                    free((yyvsp[-1].data).value.strval);
              }
#line 1903 "y.tab.c"
    break;

  case 27:
#line 280 "lalg.y"
    {;}
#line 1909 "y.tab.c"
    break;

  case 28:
#line 281 "lalg.y"
    {;}
#line 1915 "y.tab.c"
    break;

  case 29:
#line 286 "lalg.y"
    {
                    /* Adiciona parametros numa lista temporaria */
                    add_parlist(TYPE_VAR, (yyvsp[-1].data).value.strval);
                    free((yyvsp[-1].data).value.strval);
              }
#line 1925 "y.tab.c"
    break;

  case 30:
#line 293 "lalg.y"
    {;}
#line 1931 "y.tab.c"
    break;

  case 31:
#line 294 "lalg.y"
    {;}
#line 1937 "y.tab.c"
    break;

  case 32:
#line 297 "lalg.y"
    {;}
#line 1943 "y.tab.c"
    break;

  case 33:
#line 298 "lalg.y"
    {;}
#line 1949 "y.tab.c"
    break;

  case 34:
#line 302 "lalg.y"
    {
                    sym_dec_scope();
                    add_sym_proc((yyvsp[-3].data).value.strval);
                    free((yyvsp[-3].data).value.strval);
              }
#line 1959 "y.tab.c"
    break;

  case 35:
#line 308 "lalg.y"
    { yyerrok; }
#line 1965 "y.tab.c"
    break;

  case 36:
#line 309 "lalg.y"
    { yyerrok; free((yyvsp[-3].data).value.strval); }
#line 1971 "y.tab.c"
    break;

  case 37:
#line 313 "lalg.y"
    { free((yyvsp[-5].data).value.strval); }
#line 1977 "y.tab.c"
    break;

  case 38:
#line 314 "lalg.y"
    {;}
#line 1983 "y.tab.c"
    break;

  case 39:
#line 316 "lalg.y"
    { yyerrok; }
#line 1989 "y.tab.c"
    break;

  case 40:
#line 317 "lalg.y"
    { yyerrok; free((yyvsp[-5].data).value.strval); }
#line 1995 "y.tab.c"
    break;

  case 41:
#line 318 "lalg.y"
    { yyerrok; free((yyvsp[-5].data).value.strval); }
#line 2001 "y.tab.c"
    break;

  case 42:
#line 319 "lalg.y"
    { yyerrok; free((yyvsp[-5].data).value.strval); }
#line 2007 "y.tab.c"
    break;

  case 43:
#line 322 "lalg.y"
    {
                    sym_inc_scope();
                    save_parlist(); /* salva parametros na tabela de simbolos */
              }
#line 2016 "y.tab.c"
    break;

  case 44:
#line 328 "lalg.y"
    {;}
#line 2022 "y.tab.c"
    break;

  case 45:
#line 329 "lalg.y"
    { free_parlist(); /* caso nao tenha parametros, libera lista */ }
#line 2028 "y.tab.c"
    break;

  case 46:
#line 331 "lalg.y"
    { yyerrok; }
#line 2034 "y.tab.c"
    break;

  case 47:
#line 334 "lalg.y"
    {;}
#line 2040 "y.tab.c"
    break;

  case 48:
#line 338 "lalg.y"
    {
                    set_parlist((yyvsp[0].data).type); /* define tipo dos parametros ate agora */
              }
#line 2048 "y.tab.c"
    break;

  case 49:
#line 342 "lalg.y"
    { yyerrok; }
#line 2054 "y.tab.c"
    break;

  case 50:
#line 343 "lalg.y"
    { yyerrok; }
#line 2060 "y.tab.c"
    break;

  case 51:
#line 344 "lalg.y"
    { yyerrok; }
#line 2066 "y.tab.c"
    break;

  case 52:
#line 345 "lalg.y"
    { yyerrok; }
#line 2072 "y.tab.c"
    break;

  case 53:
#line 349 "lalg.y"
    {;}
#line 2078 "y.tab.c"
    break;

  case 54:
#line 350 "lalg.y"
    {;}
#line 2084 "y.tab.c"
    break;

  case 55:
#line 354 "lalg.y"
    {;}
#line 2090 "y.tab.c"
    break;

  case 56:
#line 356 "lalg.y"
    { yyerrok; }
#line 2096 "y.tab.c"
    break;

  case 57:
#line 357 "lalg.y"
    { yyerrok; }
#line 2102 "y.tab.c"
    break;

  case 58:
#line 358 "lalg.y"
    { yyerrok; }
#line 2108 "y.tab.c"
    break;

  case 59:
#line 362 "lalg.y"
    {;}
#line 2114 "y.tab.c"
    break;

  case 60:
#line 363 "lalg.y"
    {;}
#line 2120 "y.tab.c"
    break;

  case 61:
#line 368 "lalg.y"
    {
                    setnsave_varlist((yyvsp[-1].data).type);
              }
#line 2128 "y.tab.c"
    break;

  case 62:
#line 372 "lalg.y"
    { yyerrok; }
#line 2134 "y.tab.c"
    break;

  case 63:
#line 373 "lalg.y"
    { yyerrok; }
#line 2140 "y.tab.c"
    break;

  case 64:
#line 374 "lalg.y"
    { yyerrok; }
#line 2146 "y.tab.c"
    break;

  case 65:
#line 378 "lalg.y"
    {;}
#line 2152 "y.tab.c"
    break;

  case 66:
#line 379 "lalg.y"
    { free_arglist(); /* se nao tem argumentos, libera lista */ }
#line 2158 "y.tab.c"
    break;

  case 67:
#line 381 "lalg.y"
    { yyerrok; }
#line 2164 "y.tab.c"
    break;

  case 68:
#line 385 "lalg.y"
    {
                    /* Adiciona um argumento (string) na lista */
                    add_arglist((yyvsp[-1].data).value.strval);
                    free((yyvsp[-1].data).value.strval);
              }
#line 2174 "y.tab.c"
    break;

  case 69:
#line 393 "lalg.y"
    {;}
#line 2180 "y.tab.c"
    break;

  case 70:
#line 394 "lalg.y"
    {;}
#line 2186 "y.tab.c"
    break;

  case 71:
#line 396 "lalg.y"
    { yyerrok; }
#line 2192 "y.tab.c"
    break;

  case 72:
#line 400 "lalg.y"
    {;}
#line 2198 "y.tab.c"
    break;

  case 73:
#line 401 "lalg.y"
    {;}
#line 2204 "y.tab.c"
    break;

  case 74:
#line 403 "lalg.y"
    { yyerrok; }
#line 2210 "y.tab.c"
    break;

  case 75:
#line 407 "lalg.y"
    {;}
#line 2216 "y.tab.c"
    break;

  case 76:
#line 408 "lalg.y"
    {;}
#line 2222 "y.tab.c"
    break;

  case 77:
#line 411 "lalg.y"
    {;}
#line 2228 "y.tab.c"
    break;

  case 78:
#line 415 "lalg.y"
    {
                    check_varlist_type();
              }
#line 2236 "y.tab.c"
    break;

  case 79:
#line 418 "lalg.y"
    {
                    check_varlist_type();
              }
#line 2244 "y.tab.c"
    break;

  case 80:
#line 421 "lalg.y"
    {;}
#line 2250 "y.tab.c"
    break;

  case 81:
#line 422 "lalg.y"
    {;}
#line 2256 "y.tab.c"
    break;

  case 82:
#line 423 "lalg.y"
    {
                    /* Atribuicao de expressao */
                    /* "expressao" foi resolvido, portanto tem tipo e valor */
              	    update_sym_var((yyvsp[-2].data).value.strval, (yyvsp[0].data));
                    free((yyvsp[-2].data).value.strval);
              }
#line 2267 "y.tab.c"
    break;

  case 83:
#line 429 "lalg.y"
    {
                    /* Atribuicao de char */
                    update_sym_var((yyvsp[-2].data).value.strval, (yyvsp[0].data));
                    free((yyvsp[-2].data).value.strval);
              }
#line 2277 "y.tab.c"
    break;

  case 84:
#line 434 "lalg.y"
    {
                    /* Checa se argumentos informados casam com os do procedimento */
                    check_arglist_proc((yyvsp[-1].data).value.strval);
                    free_arglist();
                    free((yyvsp[-1].data).value.strval);
              }
#line 2288 "y.tab.c"
    break;

  case 85:
#line 440 "lalg.y"
    {;}
#line 2294 "y.tab.c"
    break;

  case 86:
#line 441 "lalg.y"
    {;}
#line 2300 "y.tab.c"
    break;

  case 87:
#line 442 "lalg.y"
    {
                    update_sym_var((yyvsp[-8].data).value.strval, (yyvsp[-6].data));
                    free((yyvsp[-8].data).value.strval);
              }
#line 2309 "y.tab.c"
    break;

  case 88:
#line 447 "lalg.y"
    { yyerrok; }
#line 2315 "y.tab.c"
    break;

  case 89:
#line 448 "lalg.y"
    { yyerrok; }
#line 2321 "y.tab.c"
    break;

  case 90:
#line 450 "lalg.y"
    { yyerrok; }
#line 2327 "y.tab.c"
    break;

  case 91:
#line 451 "lalg.y"
    { yyerrok; }
#line 2333 "y.tab.c"
    break;

  case 92:
#line 453 "lalg.y"
    { yyerrok; }
#line 2339 "y.tab.c"
    break;

  case 93:
#line 455 "lalg.y"
    { yyerrok; free((yyvsp[-2].data).value.strval); }
#line 2345 "y.tab.c"
    break;

  case 94:
#line 456 "lalg.y"
    { yyerrok; free((yyvsp[-2].data).value.strval); }
#line 2351 "y.tab.c"
    break;

  case 95:
#line 457 "lalg.y"
    { yyerrok; free((yyvsp[-2].data).value.strval); }
#line 2357 "y.tab.c"
    break;

  case 96:
#line 459 "lalg.y"
    { yyerrok; }
#line 2363 "y.tab.c"
    break;

  case 97:
#line 460 "lalg.y"
    { yyerrok; }
#line 2369 "y.tab.c"
    break;

  case 98:
#line 462 "lalg.y"
    { yyerrok; }
#line 2375 "y.tab.c"
    break;

  case 99:
#line 463 "lalg.y"
    { yyerrok; }
#line 2381 "y.tab.c"
    break;

  case 100:
#line 464 "lalg.y"
    { yyerrok; }
#line 2387 "y.tab.c"
    break;

  case 101:
#line 466 "lalg.y"
    { yyerrok; }
#line 2393 "y.tab.c"
    break;

  case 102:
#line 467 "lalg.y"
    { yyerrok; free((yyvsp[-8].data).value.strval); }
#line 2399 "y.tab.c"
    break;

  case 103:
#line 468 "lalg.y"
    { yyerrok; free((yyvsp[-8].data).value.strval); }
#line 2405 "y.tab.c"
    break;

  case 104:
#line 469 "lalg.y"
    { yyerrok; free((yyvsp[-8].data).value.strval); }
#line 2411 "y.tab.c"
    break;

  case 105:
#line 473 "lalg.y"
    {;}
#line 2417 "y.tab.c"
    break;

  case 106:
#line 477 "lalg.y"
    {;}
#line 2423 "y.tab.c"
    break;

  case 107:
#line 478 "lalg.y"
    {;}
#line 2429 "y.tab.c"
    break;

  case 108:
#line 479 "lalg.y"
    {;}
#line 2435 "y.tab.c"
    break;

  case 109:
#line 480 "lalg.y"
    {;}
#line 2441 "y.tab.c"
    break;

  case 110:
#line 481 "lalg.y"
    {;}
#line 2447 "y.tab.c"
    break;

  case 111:
#line 482 "lalg.y"
    {;}
#line 2453 "y.tab.c"
    break;

  case 112:
#line 486 "lalg.y"
    {
                    if ((yyvsp[0].data).type == TYPE_NONE) {
                        (yyval.data) = (yyvsp[-1].data);

                    } else {

	                    (yyval.data).type = (yyvsp[0].data).type;

	                    if ((yyvsp[-1].data).type == TYPE_INTEGER && (yyvsp[0].data).type == TYPE_INTEGER) {
	                        (yyval.data).value.intval = (yyvsp[-1].data).value.intval + (yyvsp[0].data).value.intval;

	                    } else if ((yyvsp[-1].data).type == TYPE_FLOAT && (yyvsp[0].data).type == TYPE_FLOAT) {
	                        (yyval.data).value.floatval = (yyvsp[-1].data).value.floatval + (yyvsp[0].data).value.floatval;

	                    } else {
	                        if ((yyvsp[-1].data).type == TYPE_INTEGER) {
	                            (yyvsp[-1].data).value.floatval = (double)(yyvsp[-1].data).value.intval;
	                        }
	                        if ((yyvsp[0].data).type == TYPE_INTEGER) {
	                            (yyvsp[0].data).value.floatval = (double)(yyvsp[0].data).value.intval;
	                        }

	                        (yyval.data).type = TYPE_FLOAT;
	                        (yyval.data).value.floatval = (yyvsp[-1].data).value.floatval + (yyvsp[0].data).value.floatval;
	                    }
	                }
              }
#line 2485 "y.tab.c"
    break;

  case 113:
#line 516 "lalg.y"
    { (yyval.data).type = TYPE_INTEGER; (yyval.data).value.intval =  1; }
#line 2491 "y.tab.c"
    break;

  case 114:
#line 517 "lalg.y"
    { (yyval.data).type = TYPE_INTEGER; (yyval.data).value.intval = -1; }
#line 2497 "y.tab.c"
    break;

  case 115:
#line 518 "lalg.y"
    { (yyval.data).type = TYPE_INTEGER; (yyval.data).value.intval =  1; }
#line 2503 "y.tab.c"
    break;

  case 116:
#line 521 "lalg.y"
    {
                    if ((yyvsp[0].data).type == TYPE_NONE) {
                        (yyval.data) = (yyvsp[-1].data);

                    } else {

	                    (yyval.data).type = (yyvsp[0].data).type;

	                    if ((yyvsp[-1].data).type == TYPE_INTEGER && (yyvsp[0].data).type == TYPE_INTEGER) {
	                        (yyval.data).value.intval = (yyvsp[-1].data).value.intval + (yyvsp[0].data).value.intval;

	                    } else if ((yyvsp[-1].data).type == TYPE_FLOAT && (yyvsp[0].data).type == TYPE_FLOAT) {
	                        (yyval.data).value.floatval = (yyvsp[-1].data).value.floatval + (yyvsp[0].data).value.floatval;

	                    } else {
	                        if ((yyvsp[-1].data).type == TYPE_INTEGER) {
	                            (yyvsp[-1].data).value.floatval = (double)(yyvsp[-1].data).value.intval;
	                        }
	                        if ((yyvsp[0].data).type == TYPE_INTEGER) {
	                            (yyvsp[0].data).value.floatval = (double)(yyvsp[0].data).value.intval;
	                        }

	                        (yyval.data).type = TYPE_FLOAT;
	                        (yyval.data).value.floatval = (yyvsp[-1].data).value.floatval + (yyvsp[0].data).value.floatval;
	                    }
	                }
              }
#line 2535 "y.tab.c"
    break;

  case 117:
#line 548 "lalg.y"
    { (yyval.data).type = TYPE_NONE; (yyval.data).value.floatval = 0.0; }
#line 2541 "y.tab.c"
    break;

  case 118:
#line 551 "lalg.y"
    {
                    (yyval.data) = (yyvsp[0].data);
                    if ((yyvsp[-1].data).value.intval == -1 && (yyvsp[0].data).type == TYPE_INTEGER) {
                        (yyval.data).value.intval = -(yyvsp[0].data).value.intval;
                    } else if ((yyvsp[-1].data).value.intval == -1 && (yyvsp[0].data).type == TYPE_FLOAT) {
                    	(yyval.data).value.floatval = -(yyvsp[0].data).value.floatval;
                    }
              }
#line 2554 "y.tab.c"
    break;

  case 119:
#line 562 "lalg.y"
    { (yyval.data).type = TYPE_INTEGER; (yyval.data).value.intval =  1; }
#line 2560 "y.tab.c"
    break;

  case 120:
#line 563 "lalg.y"
    { (yyval.data).type = TYPE_INTEGER; (yyval.data).value.intval = -1; }
#line 2566 "y.tab.c"
    break;

  case 121:
#line 566 "lalg.y"
    {
                    if ((yyvsp[0].data).type == TYPE_NONE) {
                        (yyval.data) = (yyvsp[-1].data);

                    } else {

	                    (yyval.data).type = (yyvsp[0].data).type;

	                    if ((yyvsp[-1].data).type == TYPE_INTEGER && (yyvsp[0].data).type == TYPE_INTEGER) {
	                        (yyval.data).value.intval = (yyvsp[-1].data).value.intval * (yyvsp[0].data).value.intval;

	                    } else if ((yyvsp[-1].data).type == TYPE_FLOAT && (yyvsp[0].data).type == TYPE_FLOAT) {
	                        (yyval.data).value.floatval = (yyvsp[-1].data).value.floatval * (yyvsp[0].data).value.floatval;
	                        if (div_flag == 1) {
	                        	yyerror("division with non-integer numerator");
	                        	div_flag = 0;
	                        }

	                    } else {
	                        if ((yyvsp[-1].data).type == TYPE_INTEGER) {
	                            (yyvsp[-1].data).value.floatval = (double)(yyvsp[-1].data).value.intval;
	                        }
	                        if ((yyvsp[0].data).type == TYPE_INTEGER) {
	                            (yyvsp[0].data).value.floatval = (double)(yyvsp[0].data).value.intval;
	                        }

	                        (yyval.data).type = TYPE_FLOAT;
	                        (yyval.data).value.floatval = (yyvsp[-1].data).value.floatval * (yyvsp[0].data).value.floatval;
	                        if (div_flag == 1) {
	                        	yyerror("division with non-integer numerator");
	                        	div_flag = 0;
	                        }
	                    }
	                }
              }
#line 2606 "y.tab.c"
    break;

  case 122:
#line 603 "lalg.y"
    {

                    if ((yyvsp[-1].data).value.intval == -1 && (yyvsp[0].data).type == TYPE_INTEGER) {
                    	(yyvsp[0].data).value.intval = -(yyvsp[0].data).value.intval;
                    }
                    if ((yyvsp[-1].data).value.intval == -1 && (yyvsp[0].data).type == TYPE_FLOAT) {
                        (yyvsp[0].data).value.floatval = -(yyvsp[0].data).value.floatval;
                    }
                    
                    (yyval.data) = (yyvsp[0].data);
              }
#line 2622 "y.tab.c"
    break;

  case 123:
#line 617 "lalg.y"
    {
                    if ((yyvsp[0].data).type == TYPE_NONE) {
                        (yyval.data) = (yyvsp[-1].data);

                    } else {
	                    (yyval.data).type = (yyvsp[0].data).type;

	                    if ((yyvsp[-1].data).type == TYPE_INTEGER && (yyvsp[0].data).type == TYPE_INTEGER) {
	                        (yyval.data).value.intval = (yyvsp[-1].data).value.intval * (yyvsp[0].data).value.intval;

	                    } else if ((yyvsp[-1].data).type == TYPE_FLOAT && (yyvsp[0].data).type == TYPE_FLOAT) {
	                        (yyval.data).value.floatval = (yyvsp[-1].data).value.floatval * (yyvsp[0].data).value.floatval;
	                        if (div_flag == 1) {
	                        	yyerror("division with non-integer numerator");
	                        	div_flag = 0;
	                        }

	                    } else {
	                        if ((yyvsp[-1].data).type == TYPE_INTEGER) {
	                            (yyvsp[-1].data).value.floatval = (double)(yyvsp[-1].data).value.intval;
	                        }
	                        if ((yyvsp[0].data).type == TYPE_INTEGER) {
	                            (yyvsp[0].data).value.floatval = (double)(yyvsp[0].data).value.intval;
	                        }

	                        (yyval.data).type = TYPE_FLOAT;
	                        (yyval.data).value.floatval = (yyvsp[-1].data).value.floatval * (yyvsp[0].data).value.floatval;
	                        if (div_flag == 1) {
	                        	yyerror("division with non-integer numerator");
	                        	div_flag = 0;
	                        }
	                    }
	                }
              }
#line 2661 "y.tab.c"
    break;

  case 124:
#line 651 "lalg.y"
    { (yyval.data).type = TYPE_NONE; (yyval.data).value.floatval = 1.0; }
#line 2667 "y.tab.c"
    break;

  case 125:
#line 654 "lalg.y"
    {
                    (yyval.data) = (yyvsp[0].data);
                    if ((yyvsp[-1].data).value.intval == -1 && (yyvsp[0].data).type == TYPE_INTEGER) {
                        (yyval.data).value.intval = 1/(yyvsp[0].data).value.intval;
                    } else if ((yyvsp[-1].data).value.intval == -1 && (yyvsp[0].data).type == TYPE_FLOAT) {
                    	(yyval.data).value.floatval = 1.0/(yyvsp[0].data).value.floatval;
                    	yyerror("division with non-integer denominator");
                    }
              }
#line 2681 "y.tab.c"
    break;

  case 126:
#line 664 "lalg.y"
    { yyerrok; }
#line 2687 "y.tab.c"
    break;

  case 127:
#line 668 "lalg.y"
    { (yyval.data).type = TYPE_INTEGER; (yyval.data).value.intval =  1; div_flag = 0; }
#line 2693 "y.tab.c"
    break;

  case 128:
#line 669 "lalg.y"
    { (yyval.data).type = TYPE_INTEGER; (yyval.data).value.intval = -1; div_flag = 1; }
#line 2699 "y.tab.c"
    break;

  case 129:
#line 673 "lalg.y"
    { (yyval.data) = get_sym_data((yyvsp[0].data).value.strval); free((yyvsp[0].data).value.strval); }
#line 2705 "y.tab.c"
    break;

  case 130:
#line 674 "lalg.y"
    { (yyval.data) = (yyvsp[0].data); }
#line 2711 "y.tab.c"
    break;

  case 131:
#line 675 "lalg.y"
    { (yyval.data) = (yyvsp[-1].data);}
#line 2717 "y.tab.c"
    break;

  case 132:
#line 677 "lalg.y"
    { yyerrok; }
#line 2723 "y.tab.c"
    break;

  case 133:
#line 681 "lalg.y"
    { (yyval.data) = (yyvsp[0].data); }
#line 2729 "y.tab.c"
    break;

  case 134:
#line 682 "lalg.y"
    { (yyval.data) = (yyvsp[0].data); }
#line 2735 "y.tab.c"
    break;


#line 2739 "y.tab.c"

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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 684 "lalg.y"

	/* ============================================================ */
	/* Codigo do usuario */
	/* ============================================================ */
int main()
{
	int i;

	/* Aloca primeira tabela de simbolos (escopo 0) */
	sym_inc_scope();

	/* Executa o analisador semantico */
	yyparse();

	/* DEBUG para o arquivo "./test/sim/test1.lalg" */
	/*
	get_sym_and_print("test1", 0);
	get_sym_and_print("a",  0);
	get_sym_and_print("b",  0);
	get_sym_and_print("k",  0);
	get_sym_and_print("x",  0);
	get_sym_and_print("y",  0);
	get_sym_and_print("c",  0);
	get_sym_and_print("i",  0);
	get_sym_and_print("j",  0);
	get_sym_and_print("my_proc",  0);
	*/

	/* Libera a tabela de variaveis */
	free_symtables(0);

	return 0;
}

	/* Imprime mensagem de erro com localizacao (linha-coluna) */
void yyerror(char *s, ...) {
	va_list ap;
	va_start(ap, s);

	if (yylloc.first_line)
		fprintf(stderr, "[%2d,%-2d]: ", yylloc.first_line, yylloc.first_column);
	
	vfprintf(stderr, s, ap);
	fprintf(stderr, "\n");
}

/* ================================================= */
/*  Funcoes que manipulam tabelas de simbolos        */
/* ================================================= */

	/* Imprime um simbolo. Usado para debug */
void print_sym(const struct sym_s *sym)
{
	printf("sym.scope      : %d\n", sym->scope);
	printf("sym.type       : ");
	     if (sym->type == TYPE_VAR)   printf("var\n");
	else if (sym->type == TYPE_CONST) printf("const\n");
	else if (sym->type == TYPE_PROC)  printf("proc\n");
	printf("sym.id         : %s\n", sym->id);
	printf("sym.data.type  : ");

	switch (sym->data.type) {
		case TYPE_PROGRAM:
			printf("program\n");
			printf("sym.data.value : nenhum\n");
			break;

		case TYPE_CONST:
			printf("const\n");
			printf("sym.data.value : %d\n", sym->data.value.intval);
			break;

		case TYPE_INTEGER:
			printf("integer\n");
			printf("sym.data.value : %d\n", sym->data.value.intval);
			break;

		case TYPE_FLOAT:
			printf("float\n");
			printf("sym.data.value : %lf\n", sym->data.value.floatval);
			break;

		case TYPE_CHAR:
			printf("char\n");
			printf("sym.data.value : %c\n", sym->data.value.charval);
			break;
		
		default:
			printf("nao definido\b");
			printf("sym.data.value : nenhum\n");
			break;
	}
	printf("\n");
}

	/* Define valores de uma variavel */
void set_sym_var(enum type_e type, struct sym_s *sym, const char *id, struct data_s data)
{
	sym->scope = scope-1;
	sym->type  = type;
	strcpy(sym->id, id);
	sym->data = data;
}

	/* Libera dados de um simbolo */
void free_sym(struct sym_s *sym)
{
	int i;
	if (sym != NULL && sym->parlist != NULL) {
		for (i = 0; i < sym->n_parlist; i++) {
			if (sym->parlist[i] != NULL) {
				free(sym->parlist[i]);
			}
		}
		free(sym->parlist);
	}
}

	/* Confere se simbolo ja existe na tabela */
struct entry *exist_sym(const char *id)
{
	struct entry item, *ret;

	item.key = strdup(id);
	hsearch_r(item, FIND, &ret, &symtables[scope-1]);
	free(item.key);

	return ret;
}

	/* Adiciona uma variavel na tabela de simbolos */
int add_sym_var_s(struct sym_s *new_sym)
{
	ENTRY item, *ret;

	/* Confere se variavel ja existe na tabela */
	if (exist_sym(new_sym->id) != NULL) {
		if (new_sym->type == TYPE_CONST) {
			yyerror("constant '%s' has already been declared", new_sym->id);
		} else {
			yyerror("variable '%s' has already been declared", new_sym->id);
		}
		return 0;
	}

	item.key  = strdup(new_sym->id);
	item.data = new_sym;

	/* Tenta inserir na tabela de simbolos */
	if (hsearch_r(item, ENTER, &ret, &symtables[scope-1]) == 0) {
		yyerror("couldn't add '%s' to the symbols' table", new_sym->id);
		return 0;
	}

	return 1;
}

	/* Adiciona uma variavel na tabela de simbolos */
void add_sym_var(enum type_e type, const char *id, struct data_s data)
{
	/* Cria nova variavel */
	struct sym_s *new_sym = (struct sym_s *)malloc(sizeof(struct sym_s));

	/* Definie valores */
	set_sym_var(type, new_sym, id, data);

	/* Tenta adicionar */
	if (!add_sym_var_s(new_sym)) {
		free_sym(new_sym);
	}
}

	/* Atualiza valor de um variavel */
void update_sym_var(const char *id, struct data_s data)
{
	ENTRY *ret = exist_sym(id);

	/* Recupera variavel da tabela de simbolos */
	if (ret == NULL) {
		yyerror("undeclared variable '%s'", id);
		return;
	}

	struct sym_s *sym = (struct sym_s *)(ret->data);

	/* Confere se tipos de dados sao iguais */
	if (sym->data.type != data.type) {
		yyerror("incompatible type for variable '%s'", sym->id);
		return;
	}

	/* Atribui valor */
	sym->data = data;
}

	/* Retorna dado de uma variavel */
struct data_s get_sym_data(const char *id)
{
	struct entry  *ret = exist_sym(id);
	struct data_s data;

	/* Recupera variavel da tabela de simbolos */
	if (ret == NULL) {
		yyerror("undeclared variable '%s'\n", id);
		return data;
	}

	/* Retorna copia de seu dado */
	struct sym_s *sym = (struct sym_s *)(ret->data);
	data = sym->data;

	return data;
}

	/* Adiciona procedimento na tabela de simbolos */
int add_sym_proc(const char *id)
{
	struct sym_s *new_sym = (struct sym_s *)malloc(sizeof(struct sym_s));
	ENTRY item, *ret;

	new_sym->type  = TYPE_PROC;
	new_sym->scope = scope-1;
	strcpy(new_sym->id, id);

	/* Pega lista atual de parametros e atribui ao procedimento */
	new_sym->parlist = parlist;
	new_sym->n_parlist = n_parlist;
	
	empty_parlist();

	/* Confere se procedimento ja existe */
	if (exist_sym(new_sym->id) != NULL) {
		yyerror("procedure '%s' has already been declared", new_sym->id);
		return 0;
	}

	/* Tenta adicionar */
	item.key  = strdup(new_sym->id);
	item.data = new_sym;

	if (hsearch_r(item, ENTER, &ret, &symtables[scope-1]) == 0) {
		yyerror("couldn't add '%s' to the symbols' table", new_sym->id);
		return 0;
	}

	return 1;
}

	/* Busca um simbolo e imprime. Usado para debug */
void get_sym_and_print(const char *id, int scope)
{
	ENTRY e, *ep;

	e.key = strdup(id);
	hsearch_r(e, FIND, &ep, &symtables[scope]);
	if (ep != NULL && ep->data != NULL)
		print_sym((const struct sym_s *)ep->data);
	free(e.key);
}

	/* Libera dados de um escopo da tabela de simbolos */
void free_symtables(int scope)
{
	/* TODO */
}

/* ================================================= */
/*  Manipulacao de escopo                            */
/* ================================================= */

	/* Incrementa o escopo, ou seja, aloca mais uma tabela de simbolos */
void sym_inc_scope()
{
	symtables = (struct hsearch_data *)realloc(symtables, sizeof(struct hsearch_data) * (scope + 1));
	memset(&symtables[scope], 0, sizeof(struct hsearch_data));
	hcreate_r(SIZE_SYM_TABLE, &symtables[scope]);
	scope++;
}

	/* Incrementa o escopo, ou seja, libera a ultima tabela de simbolos alocada */
void sym_dec_scope()
{
	scope--;
	free_symtables(scope);
	hdestroy_r(&symtables[scope]);
	symtables = (struct hsearch_data *)realloc(symtables, sizeof(struct hsearch_data) * scope);
}

/* ================================================= */
/*  Lista de declaracao de variaveis                 */
/* ================================================= */

	/* Adiciona uma variavel na lista temporaria */
void add_varlist(enum type_e type, const char *id)
{
	varlist = (struct sym_s **)realloc(varlist, sizeof(struct sym_s *) * (n_varlist + 1));
	varlist[n_varlist] = (struct sym_s *)malloc(sizeof(struct sym_s));
	
	varlist[n_varlist]->type  = type;
	strcpy(varlist[n_varlist]->id, id);

	n_varlist++;
}

	/* Define tipo da variaveis da lista e salva elas na tabela de simbolos */
void setnsave_varlist(enum type_e datatype)
{
	int i;
	for (i = 0; i < n_varlist; i++) {
		varlist[i]->scope = scope-1;
	    varlist[i]->data.type = datatype;
	    add_sym_var_s(varlist[i]);
	}

	free_varlist();
}

	/* Libera a lista de variaveis */
void free_varlist()
{
	/* Libera lista de simbolos */
	free(varlist);
	varlist = NULL;
	n_varlist = 0;
}

	/* Confere se as variaveis da lista sao do mesmo tipo */
void check_varlist_type()
{
	struct entry  *ret;
	struct sym_s  *sym;
	struct data_s data;
	int i, flag = 0;
	enum type_e type_prev;

	if (n_varlist > 1) {
		for (i = 0; i < n_varlist; i++) {
			
			/* Recupera variavel */
			ret = exist_sym(varlist[i]->id);

			if (ret == NULL) {
				yyerror("undeclared variable '%s'\n", varlist[i]->id);
			
			} else {
				sym  = (struct sym_s *)(ret->data);
				
				if (flag == 0) {
					type_prev = sym->data.type;
					flag = 1;
				}

				/* Confere tipo */
				if (type_prev != sym->data.type) {
					yyerror("read/write command with different variable types");
				}

				type_prev = sym->data.type;
			}
		}
	}

	free_varlist();
}

/* ================================================= */
/*  Lista de declaracao de parametros                */
/* ================================================= */

void add_parlist(enum type_e type, const char *id)
{
	parlist = (struct sym_s **)realloc(parlist, sizeof(struct sym_s *) * (n_parlist + 1));
	parlist[n_parlist] = (struct sym_s *)malloc(sizeof(struct sym_s));
	
	parlist[n_parlist]->type  = type;
	strcpy(parlist[n_parlist]->id, id);

	n_parlist++;
}

	/* Define tipo dos parametros da lista, mas ainda nao salva eles */
void set_parlist(enum type_e datatype)
{
	int i;
	for (i = last_par+1; i < n_parlist; i++) {
	    parlist[i]->data.type = datatype;
	}
	last_par = i-1; /* guarda a posicao do ultimo */
}

	/* Salva lista de parametros na tabela de simbolos */
void save_parlist()
{
	int i;
	for (i = 0; i < n_parlist; i++) {
		parlist[i]->scope = scope-1;
	    add_sym_var_s(parlist[i]);
	}
}

	/* Libera lista de parametros */
void free_parlist()
{
	/* TODO */
	empty_parlist();
}

void empty_parlist()
{
	parlist = NULL;
	n_parlist = 0;
	last_par  = -1;
}

/* ================================================= */
/*  Lista de argumentos                              */
/* ================================================= */

void add_arglist(const char *id)
{
	arglist = (char **)realloc(arglist, sizeof(char *) * (n_arglist + 1));
	arglist[n_arglist] = (char *)malloc(sizeof(MAX_LENGTH_IDENT + 1));

	strcpy(arglist[n_arglist], id);

	n_arglist++;
}

	/* Confere se argumentos casam com os paramentros do procedimento informado */
void check_arglist_proc(const char *id)
{
	ENTRY *ret;
	struct sym_s **parlist;
	int n_parlist;

	ret = exist_sym(id);

	if (ret == NULL) {
		yyerror("undeclared procedure '%s'", id);
		return;
	}

	parlist = ((struct sym_s *)(ret->data))->parlist;
	n_parlist = ((struct sym_s *)(ret->data))->n_parlist;

	if (n_arglist < n_parlist) {
		yyerror("insufficient number of arguments for procedure '%s'", id);
		return;
	}

	if (n_arglist > n_parlist) {
		yyerror("too much arguments for procedure '%s'", id);
	}

	int i;
	for (i = 0; i < n_parlist; i++) {
		ret = exist_sym(arglist[n_arglist-1-i]);
		if (ret == NULL) {
			yyerror("undeclared variable '%s' in argument %d for '%s' procedure", arglist[n_arglist-1-i], i+1, id);
			continue;
		}

		if (parlist[i]->data.type != ((struct sym_s *)(ret->data))->data.type) {
			yyerror("incompatible type in argument %d for '%s' procedure", i+1, id);
			continue;
		}
	}
}

	/* Libera lista de argumentos */
void free_arglist()
{
	int i;
	if (arglist != NULL) {
		for (i = 0; i < n_arglist; i++) {
			if (arglist[i] != NULL) {
				free(arglist[i]);
			}
		}
		free(arglist);
	}

	arglist = NULL;
	n_arglist = 0;
}
