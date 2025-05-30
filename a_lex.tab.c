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
#line 1 "a_lex.y"

#include "listaCodigo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listaSimbolos.h"
Lista tablaSimb;
int contCadenas = 0;
void imprimirTablaS();
void yyerror();
int analisis_ok();
int errores;
int erroresLexicos = 0; /* Si luego no nos va probar con extern */
int erroresSemanticos = 0;
int erroresSintacticos = 0;
Tipo tipo;
extern int yylex();
extern int yylineno;
void insertaTablaString(char* id, int tipo);
int esConstante(char* id);
void insertaTablaIdentificador(char* nombre, int tipo);
int perteneceTabla(char* id);

/*MANEJO DE REGISTROS*/
char registros[10]; // 10 registros temporales
void inicializarRegistros();
char *elegirRegistroDisponible();
void liberarRegistro(char *reg);
char* concatena(char* str1, char* str2);


/*GENERACIÓN DE CÓDIGO*/
char* concatena(char* str1, char* str2);
void generarOperacionUnaria(ListaC $$, ListaC $1, char *operador);
void generarOperacionBinaria(ListaC $$, ListaC $1, ListaC $3, char *operador);


void imprimirLC(ListaC codigo);

#line 111 "a_lex.tab.c"

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

#include "a_lex.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VAR = 3,                        /* VAR  */
  YYSYMBOL_CONST = 4,                      /* CONST  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_PRINT = 9,                      /* PRINT  */
  YYSYMBOL_READ = 10,                      /* READ  */
  YYSYMBOL_LPAREN = 11,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 12,                    /* RPAREN  */
  YYSYMBOL_SEMICOLON = 13,                 /* SEMICOLON  */
  YYSYMBOL_COMA = 14,                      /* COMA  */
  YYSYMBOL_IGUAL = 15,                     /* IGUAL  */
  YYSYMBOL_INTERROGACION = 16,             /* INTERROGACION  */
  YYSYMBOL_DOSPUNTOS = 17,                 /* DOSPUNTOS  */
  YYSYMBOL_LKEY = 18,                      /* LKEY  */
  YYSYMBOL_RKEY = 19,                      /* RKEY  */
  YYSYMBOL_ID = 20,                        /* ID  */
  YYSYMBOL_INTLITERAL = 21,                /* INTLITERAL  */
  YYSYMBOL_STRING = 22,                    /* STRING  */
  YYSYMBOL_PLUSOP = 23,                    /* PLUSOP  */
  YYSYMBOL_MINUSOP = 24,                   /* MINUSOP  */
  YYSYMBOL_ASTERISCO = 25,                 /* ASTERISCO  */
  YYSYMBOL_BARRA = 26,                     /* BARRA  */
  YYSYMBOL_UMENOS = 27,                    /* UMENOS  */
  YYSYMBOL_YYACCEPT = 28,                  /* $accept  */
  YYSYMBOL_programa = 29,                  /* programa  */
  YYSYMBOL_30_1 = 30,                      /* $@1  */
  YYSYMBOL_declaraciones = 31,             /* declaraciones  */
  YYSYMBOL_tipo = 32,                      /* tipo  */
  YYSYMBOL_lista_variables = 33,           /* lista_variables  */
  YYSYMBOL_lista_ctes = 34,                /* lista_ctes  */
  YYSYMBOL_lista_instrucciones = 35,       /* lista_instrucciones  */
  YYSYMBOL_instruccion = 36,               /* instruccion  */
  YYSYMBOL_lista_impresion = 37,           /* lista_impresion  */
  YYSYMBOL_item_impreso = 38,              /* item_impreso  */
  YYSYMBOL_lista_lectura = 39,             /* lista_lectura  */
  YYSYMBOL_expresion = 40                  /* expresion  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   121

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  36
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  90

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


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
      25,    26,    27
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    68,    68,    68,    88,    95,   102,   107,   112,   121,
     133,   140,   146,   147,   152,   174,   175,   176,   177,   178,
     179,   180,   185,   186,   190,   191,   196,   198,   204,   210,
     216,   222,   228,   231,   238,   241,   259
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
  "\"end of file\"", "error", "\"invalid token\"", "VAR", "CONST", "INT",
  "IF", "ELSE", "WHILE", "PRINT", "READ", "LPAREN", "RPAREN", "SEMICOLON",
  "COMA", "IGUAL", "INTERROGACION", "DOSPUNTOS", "LKEY", "RKEY", "ID",
  "INTLITERAL", "STRING", "PLUSOP", "MINUSOP", "ASTERISCO", "BARRA",
  "UMENOS", "$accept", "programa", "$@1", "declaraciones", "tipo",
  "lista_variables", "lista_ctes", "lista_instrucciones", "instruccion",
  "lista_impresion", "item_impreso", "lista_lectura", "expresion", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-58)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -58,     4,    28,   -58,    13,    27,    38,   -58,     6,    64,
      64,    17,   -58,    51,    54,    63,    59,    82,    95,    96,
     -58,   -58,    93,   -58,   -58,     7,    94,    16,   -58,    -8,
      -8,    -5,    90,    41,    -8,   -58,    91,    -8,   -58,    92,
      -8,   -58,   -58,    -8,    61,    66,   -58,    26,   -58,    79,
     -58,    50,   -58,    75,   -58,    79,    98,    56,   -58,    57,
      -8,    -8,    -8,    -8,    57,   101,    -5,   102,    97,   -58,
      -8,   -58,    -8,   109,    19,    19,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,    79,    29,    57,    -8,   -58,    71,   -58
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     6,    13,     0,
       0,     0,     7,     0,     0,     0,     0,     0,     0,     0,
      13,     3,     0,    12,     8,     0,     0,     0,    21,     0,
       0,     0,     0,     0,     0,     4,     0,     0,     5,     0,
       0,    35,    36,     0,     0,     0,    25,     0,    22,    24,
      26,     0,    15,     0,     9,    10,     0,     0,    33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
       0,    34,     0,    17,    28,    29,    30,    31,    18,    19,
      23,    20,    27,    11,     0,     0,     0,    16,     0,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -58,   -58,   -58,   -58,   108,   -58,   -58,    99,   -57,   -58,
      55,   -58,   -29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     8,    13,    25,    27,    11,    23,    47,
      48,    51,    49
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      44,    45,    73,    40,     3,    53,    40,    78,    55,     9,
      10,    57,    41,    42,    58,    41,    42,    46,    15,    43,
      35,    36,    43,    16,     5,    17,    18,    19,    87,    38,
      39,    74,    75,    76,    77,    20,    21,    22,    65,     6,
      66,    83,    15,    84,    62,    63,    86,    16,     4,    17,
      18,    19,    60,    61,    62,    63,     7,    88,    15,    20,
      52,    22,    67,    16,    68,    17,    18,    19,    71,    12,
      29,    24,    72,    59,    26,    20,    28,    22,    64,    60,
      61,    62,    63,    89,    60,    61,    62,    63,    69,    60,
      61,    62,    63,    30,    60,    61,    62,    63,    60,    61,
      62,    63,    60,    61,    62,    63,    31,    32,    34,    37,
      50,    54,    56,    70,    79,    81,    85,    82,    14,    33,
       0,    80
};

static const yytype_int8 yycheck[] =
{
      29,    30,    59,    11,     0,    34,    11,    64,    37,     3,
       4,    40,    20,    21,    43,    20,    21,    22,     1,    27,
      13,    14,    27,     6,    11,     8,     9,    10,    85,    13,
      14,    60,    61,    62,    63,    18,    19,    20,    12,    12,
      14,    70,     1,    72,    25,    26,    17,     6,    20,     8,
       9,    10,    23,    24,    25,    26,    18,    86,     1,    18,
      19,    20,    12,     6,    14,     8,     9,    10,    12,     5,
      11,    20,    16,    12,    20,    18,    13,    20,    12,    23,
      24,    25,    26,    12,    23,    24,    25,    26,    13,    23,
      24,    25,    26,    11,    23,    24,    25,    26,    23,    24,
      25,    26,    23,    24,    25,    26,    11,    11,    15,    15,
      20,    20,    20,    15,    13,    13,     7,    20,    10,    20,
      -1,    66
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    29,    30,     0,    20,    11,    12,    18,    31,     3,
       4,    35,     5,    32,    32,     1,     6,     8,     9,    10,
      18,    19,    20,    36,    20,    33,    20,    34,    13,    11,
      11,    11,    11,    35,    15,    13,    14,    15,    13,    14,
      11,    20,    21,    27,    40,    40,    22,    37,    38,    40,
      20,    39,    19,    40,    20,    40,    20,    40,    40,    12,
      23,    24,    25,    26,    12,    12,    14,    12,    14,    13,
      15,    12,    16,    36,    40,    40,    40,    40,    36,    13,
      38,    13,    20,    40,    40,     7,    17,    36,    40,    12
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    28,    30,    29,    31,    31,    31,    32,    33,    33,
      34,    34,    35,    35,    36,    36,    36,    36,    36,    36,
      36,    36,    37,    37,    38,    38,    39,    39,    40,    40,
      40,    40,    40,    40,    40,    40,    40
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     8,     5,     5,     0,     1,     1,     3,
       3,     5,     2,     0,     4,     3,     7,     5,     5,     5,
       5,     2,     1,     3,     1,     1,     1,     3,     3,     3,
       3,     3,     7,     2,     3,     1,     1
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
  case 2: /* $@1: %empty  */
#line 68 "a_lex.y"
                  {
		tablaSimb=creaLS(); 
		inicializarRegistros();
	}
#line 1194 "a_lex.tab.c"
    break;

  case 3: /* programa: $@1 ID LPAREN RPAREN LKEY declaraciones lista_instrucciones RKEY  */
#line 72 "a_lex.y"
                                                                     {
		imprimirTablaS(); 									// Imprime la tabla de símbolos
		concatenaLC((yyvsp[-2].codigo), (yyvsp[-1].codigo));  								// Concatena declaraciones e instrucciones
		//imprimirLC($6), 									// Imprime el código intermedio resultante
		liberarRegistro(recuperaResLC((yyvsp[-2].codigo))),  				// Libera registro de la última expresión evaluada 
		liberarRegistro(recuperaResLC((yyvsp[-1].codigo))),  				// Libera registro de la última expresión evaluada
		liberaLC((yyvsp[-2].codigo));										// Libera la lista de código intermedio
		liberaLC((yyvsp[-1].codigo));										// Libera la lista de código intermedio
		liberaLS(tablaSimb); 								// Limpia la tabla de símbolos
		printf("Fin del programa");
		;
	}
#line 1211 "a_lex.tab.c"
    break;

  case 4: /* declaraciones: declaraciones VAR tipo lista_variables SEMICOLON  */
#line 88 "a_lex.y"
                                                                 {
			if(analisis_ok()) {
				(yyval.codigo) = (yyvsp[-4].codigo);
				concatenaLC((yyval.codigo), (yyvsp[-1].codigo)); // Concatena la lista de instrucciones
				liberaLC((yyvsp[-1].codigo));
			}
		}
#line 1223 "a_lex.tab.c"
    break;

  case 5: /* declaraciones: declaraciones CONST tipo lista_ctes SEMICOLON  */
#line 95 "a_lex.y"
                                                                { /*const int x,y,z*/ 
			if (analisis_ok()) {
            	(yyval.codigo) = (yyvsp[-4].codigo);
         	    concatenaLC((yyval.codigo), (yyvsp[-1].codigo));
            	liberaLC((yyvsp[-1].codigo));
        }
		}
#line 1235 "a_lex.tab.c"
    break;

  case 6: /* declaraciones: %empty  */
#line 102 "a_lex.y"
                  { (yyval.codigo) = creaLC(); }
#line 1241 "a_lex.tab.c"
    break;

  case 8: /* lista_variables: ID  */
#line 112 "a_lex.y"
                   {
			if (!perteneceTabla((yyvsp[0].cad))) { 
				insertaTablaIdentificador((yyvsp[0].cad), VARIABLE);
				(yyval.codigo) = creaLC();
			} else {
				printf ("Variable %s ya declarada \n", (yyvsp[0].cad));
				(yyval.codigo) = creaLC();  // No hay inicialización, lista vacía
			}
		}
#line 1255 "a_lex.tab.c"
    break;

  case 9: /* lista_variables: lista_variables COMA ID  */
#line 121 "a_lex.y"
                                          {
			if (!perteneceTabla((yyvsp[0].cad))) {
				insertaTablaIdentificador((yyvsp[0].cad), VARIABLE); 
			} else { 
				printf ("Variable %s ya declarada \n", (yyvsp[0].cad)); /*a,b*/
			}
			(yyval.codigo) = (yyvsp[-2].codigo);
		}
#line 1268 "a_lex.tab.c"
    break;

  case 10: /* lista_ctes: ID IGUAL expresion  */
#line 133 "a_lex.y"
                                   {
			if (!perteneceTabla((yyvsp[-2].cad))) { 
				insertaTablaIdentificador((yyvsp[-2].cad), CONSTANTE);
			} else {
				printf ("Constante %s ya declarada \n", (yyvsp[-2].cad));	
			}  
		}
#line 1280 "a_lex.tab.c"
    break;

  case 11: /* lista_ctes: lista_ctes COMA ID IGUAL expresion  */
#line 140 "a_lex.y"
                                                     {if (!perteneceTabla((yyvsp[-2].cad))) insertaTablaIdentificador((yyvsp[-2].cad), CONSTANTE);
							                  else printf ("Constante %s ya declarada \n", (yyvsp[-2].cad));}
#line 1287 "a_lex.tab.c"
    break;

  case 13: /* lista_instrucciones: %empty  */
#line 147 "a_lex.y"
                  { (yyval.codigo) = creaLC(); }
#line 1293 "a_lex.tab.c"
    break;

  case 14: /* instruccion: ID IGUAL expresion SEMICOLON  */
#line 152 "a_lex.y"
                                             {
			if (!perteneceTabla((yyvsp[-3].cad))) {
				printf("Variable %s no declarada \n",(yyvsp[-3].cad));
				(yyval.codigo) = creaLC();
				liberaLC((yyvsp[-1].codigo));			
			} else if  (esConstante((yyvsp[-3].cad))) {
				printf("Asignacióin a constante %s no permitida\n", (yyvsp[-3].cad));
				(yyval.codigo) = creaLC();
				liberaLC((yyvsp[-1].codigo));			
			 	/* {printf($1)...} Impirmir todos los ID para ver los lexemas y depurar */
			} else {
				(yyval.codigo) = (yyvsp[-1].codigo);
				Operacion operacion;
				operacion.op = "sw";
				operacion.res = recuperaResLC((yyvsp[-1].codigo));
				operacion.arg1 = concatena("_", (yyvsp[-3].cad));
				operacion.arg2 = NULL;

				insertaLC((yyval.codigo), finalLC((yyval.codigo)), operacion);
				liberarRegistro(operacion.res);
			}
		}
#line 1320 "a_lex.tab.c"
    break;

  case 25: /* item_impreso: STRING  */
#line 191 "a_lex.y"
                         {insertaTablaString((yyvsp[0].cad), CADENA);}
#line 1326 "a_lex.tab.c"
    break;

  case 26: /* lista_lectura: ID  */
#line 196 "a_lex.y"
                   {if (!perteneceTabla((yyvsp[0].cad))) printf ("Variable %s no declarada \n", (yyvsp[0].cad));
			else if (esConstante((yyvsp[0].cad))) printf ("Asignación a constante \n");}
#line 1333 "a_lex.tab.c"
    break;

  case 27: /* lista_lectura: lista_lectura COMA ID  */
#line 198 "a_lex.y"
                                        {if (!perteneceTabla((yyvsp[0].cad))) printf ("Variable %s no declarada \n", (yyvsp[0].cad));
	                             else if (esConstante((yyvsp[0].cad))) printf ("Asignación a constante \n");}
#line 1340 "a_lex.tab.c"
    break;

  case 28: /* expresion: expresion PLUSOP expresion  */
#line 204 "a_lex.y"
                                           {
		    if (analisis_ok()) {
        		(yyval.codigo) = creaLC(); // No sé si hay que crear una nueva lista o reutilizar la de la izquierda 
        		generarOperacionBinaria((yyval.codigo), (yyvsp[-2].codigo), (yyvsp[0].codigo), "add");
    		}
		}
#line 1351 "a_lex.tab.c"
    break;

  case 29: /* expresion: expresion MINUSOP expresion  */
#line 210 "a_lex.y"
                                              {
		    if (analisis_ok()) {
        		(yyval.codigo) = creaLC();
        		generarOperacionBinaria((yyval.codigo), (yyvsp[-2].codigo), (yyvsp[0].codigo), "sub");
    		}
		}
#line 1362 "a_lex.tab.c"
    break;

  case 30: /* expresion: expresion ASTERISCO expresion  */
#line 216 "a_lex.y"
                                                {
		    if (analisis_ok()) {
        		(yyval.codigo) = creaLC();
        		generarOperacionBinaria((yyval.codigo), (yyvsp[-2].codigo), (yyvsp[0].codigo), "mul");
    		}
		}
#line 1373 "a_lex.tab.c"
    break;

  case 31: /* expresion: expresion BARRA expresion  */
#line 222 "a_lex.y"
                                            {
		    if (analisis_ok()) {
        		(yyval.codigo) = creaLC();
        		generarOperacionBinaria((yyval.codigo), (yyvsp[-2].codigo), (yyvsp[0].codigo), "div");
    		}
		}
#line 1384 "a_lex.tab.c"
    break;

  case 32: /* expresion: LPAREN expresion INTERROGACION expresion DOSPUNTOS expresion RPAREN  */
#line 228 "a_lex.y"
                                                                                      {
			/* TERNARIA MÁS ADELANTE */
		}
#line 1392 "a_lex.tab.c"
    break;

  case 33: /* expresion: UMENOS expresion  */
#line 231 "a_lex.y"
                                   {
	    	if (analisis_ok()) {
        		(yyval.codigo) = creaLC();                  		// Crea una nueva lista
        		generarOperacionUnaria((yyval.codigo), (yyvsp[0].codigo), "neg");  // Genera la operación unaria (-x)
        		liberaLC((yyvsp[0].codigo));                  			// Libera la lista de $2
    		}
		}
#line 1404 "a_lex.tab.c"
    break;

  case 34: /* expresion: LPAREN expresion RPAREN  */
#line 238 "a_lex.y"
                                          { 
			(yyval.codigo) = (yyvsp[-1].codigo); 
		}
#line 1412 "a_lex.tab.c"
    break;

  case 35: /* expresion: ID  */
#line 241 "a_lex.y"
                     {
    		if (analisis_ok() && perteneceTabla((yyvsp[0].cad))) {
				(yyval.codigo) = creaLC();

				Operacion operacion;
				operacion.op = strdup("lw");
				char *varName;
		        asprintf(&varName, "_%s", (yyvsp[0].cad));
        		operacion.arg1 = varName;
				operacion.arg2 = NULL;
				operacion.res = elegirRegistroDisponible();

				insertaLC((yyval.codigo), finalLC((yyval.codigo)), operacion);
				guardaResLC((yyval.codigo), operacion.res);
			} else {
				printf("Variable %s no declarada \n", (yyvsp[0].cad));
			}
		}
#line 1435 "a_lex.tab.c"
    break;

  case 36: /* expresion: INTLITERAL  */
#line 259 "a_lex.y"
                             {    
			if (analisis_ok()) {
				(yyval.codigo) = creaLC();

				Operacion operacion;
				operacion.op = "li";
				operacion.arg1 = strdup((yyvsp[0].cad));
				operacion.arg2 = NULL;
				operacion.res = elegirRegistroDisponible();

				insertaLC((yyval.codigo), finalLC((yyval.codigo)), operacion);
				guardaResLC((yyval.codigo), operacion.res);
    		}
		}
#line 1454 "a_lex.tab.c"
    break;


#line 1458 "a_lex.tab.c"

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

#line 275 "a_lex.y"
 
/*Después de este %% es la sección de código*/

void imprimirTablaS() {
    printf("\t.data\n\n");  

    // Primero imprime las cadenas
    printf("# Cadenas del programa\n");
    PosicionLista p = inicioLS(tablaSimb);
    while (p != finalLS(tablaSimb)) {
        Simbolo aux = recuperaLS(tablaSimb, p);
        if (aux.tipo == CADENA) {
            printf("$str%d:\n", aux.valor);
            printf("\t.asciiz \"%s\"\n", aux.nombre);
        }
        p = siguienteLS(tablaSimb, p);
    }

    // Luego las variables y constantes
    printf("\n# Variables y constantes\n");
    p = inicioLS(tablaSimb);
    while (p != finalLS(tablaSimb)) {
        Simbolo aux = recuperaLS(tablaSimb, p);
        if (aux.tipo != CADENA) {
            printf("_%s:\n", aux.nombre);
            printf("\t.word %d\n", aux.valor);
        }
        p = siguienteLS(tablaSimb, p);
    }
}


/*COMPRUEBA SI YA ESTÁ EN LA TABLA*/
int perteneceTabla(char* id) {
	int pertenece = 0;
	
	PosicionLista posicion = buscaLS(tablaSimb, id);
	if(posicion != finalLS(tablaSimb)) {
		pertenece = 1;	
		errores++;
	}
	return pertenece;	
}


/* INSERTA CUANDO SE HA COMPROBADO PREVIAMENTE CON perteneceTabla que no está definida */
void insertaTablaIdentificador(char* nombre, int tipo) {
	if (tipo != CADENA) {
		Simbolo simbolo;
		simbolo.nombre = nombre;
		simbolo.tipo = tipo;
		
		insertaLS(tablaSimb, finalLS(tablaSimb), simbolo);
	}
}


int esConstante(char* id) {
	// llamar a buscaLS que lo recupera y entonces ver el tipo 
	PosicionLista p = buscaLS(tablaSimb, id);
	Simbolo aux;
	if (p != finalLS(tablaSimb)) {
		Simbolo aux = recuperaLS(tablaSimb, p);
		errores++;
	}	
	return (aux.tipo==CONSTANTE);
}


void insertaTablaString(char* id, int tipo) {
	if (tipo == CADENA) {
		Simbolo simbolo;
		simbolo.nombre = id;
		simbolo.tipo = tipo;
		simbolo.valor = ++contCadenas;
		insertaLS(tablaSimb, finalLS(tablaSimb), simbolo);
	}
}


void yyerror(const char *msg) {
    extern char *yytext;
    fprintf(stderr, "Error sintáctico en '%s' en línea %d: %s\n", yytext, yylineno, msg);
	errores++;
}


/*FUNCIONES PARA MANEJAR LOS REGISTROS*/
/*Inicializa el array con los 10 registros (0-9) con valor 0 indicando que no están en uso*/
void inicializarRegistros(){ 
  for(int i = 0; i < 10; i++){
	registros[i]=0;
  }
}

/*Busca el siguiente registro disponible o devuelve error si no quedan libres*/
char *elegirRegistroDisponible(){
  for(int i = 0; i < 10; i++){
    if(registros[i]==0){
      registros[i]=1;
      char* reg;
      //printf en una posicion de memoria que yo le digo, el puntero a la cadena de caracteres que se va a montar
      asprintf(&reg,"$t%d",i); //sirve como para hacer la concatenación, guarda la cadena en la memoria apuntada por la variable
      return reg;
    }
  }
  printf("Error registros temporales agotados!\n");
  exit(1);
}


//Libera el registro que se le pasa como argumento
void liberarRegistro(char *reg){
  int idx = atoi(&(reg[2])); //posicion 3 de la cadena $=pos0 t=pos1 X=pos2
  registros[idx]=0;
}


/* FUNCIÓN COMPROBACIÓN DE ERRORES */
int analisis_ok() {
    return errores == 0;
}


/* FUNCIONES PARA GENERAR CÓDIGO INTERMEDIO */
void generarOperacionUnaria(ListaC $$, ListaC $1, char *operador) {	
	concatenaLC($$, $1);
	
	// Crea la operación unaria
    Operacion operacion;
    operacion.op = strdup(operador);               // Operador
    operacion.arg1 = recuperaResLC($$);            // Operando
    operacion.arg2 = NULL;                         // Null ya que no hay segundo operando
    operacion.res = elegirRegistroDisponible();	   // Dónde guardamos el resultado final

    guardaResLC($$, operacion.res);				   // Guarda el resultado en la lista de código $$	
    insertaLC($$, finalLC($$), operacion); 		   // Inserta la operación al final de la lista
	liberarRegistro(operacion.arg1);			   // Libera el registro 
    
}


void generarOperacionBinaria(ListaC $$, ListaC $1, ListaC $3, char *operador) {
    concatenaLC($$, $1);                        // Concatena izquierda
    concatenaLC($$, $3);                        // Concatena derecha

    Operacion operacion;
    operacion.op = strdup(operador);            // Operador
    operacion.arg1 = recuperaResLC($1);         // Operando izquierdo
    operacion.arg2 = recuperaResLC($3);         // Operando derecho
    operacion.res = elegirRegistroDisponible(); // Resultado en nuevo registro

    guardaResLC($$, operacion.res);             // Guarda el resultado en la lista
    insertaLC($$, finalLC($$), operacion);      // Inserta operación al final

    liberaLC($1);                               // Libera código izquierdo
    liberaLC($3);                               // Libera código derecho

    liberarRegistro(operacion.arg1);            // Libera registro izquierdo
    liberarRegistro(operacion.arg2);            // Libera registro derecho
}


char* concatena(char* str1, char* str2) {
    char* resultado = malloc(strlen(str1) + strlen(str2) + 1); // +1 para el '\0'
    if (resultado == NULL) {
        fprintf(stderr, "Error al reservar memoria en concatena\n");
        exit(1);
    }
    strcpy(resultado, str1);
    strcat(resultado, str2);
    return resultado;
}
