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
#line 1 "yacc_source.y"

    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>

    char* app_name;

    #define MAX_USERS_CONFIG 500
    typedef struct {
        char* name;
        int age;
    } User;
    User users[MAX_USERS_CONFIG];
    int user_count = 0;

    typedef struct {
        char* mode;
        bool logging;
        int max_users; 
    } Settings;
    Settings settings;

    typedef struct {
        char* user;
        char* rights[3];
        int no_of_rights;
    } Permission;
    Permission permissions[MAX_USERS_CONFIG];
    int permission_count = 0;

    void init();

    int yylex(void);
    void yyerror(const char* str);

    void addUser(char* name, int age);
    void updateMaxUsers(int number);
    void addPermission(char* user);
    void addRight(char* right);

#line 112 "y.tab.c"

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
#line 42 "yacc_source.y"

    char* str;
    int number;

#line 218 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_APP_NAME = 3,                   /* APP_NAME  */
  YYSYMBOL_USERS = 4,                      /* USERS  */
  YYSYMBOL_SETTINGS = 5,                   /* SETTINGS  */
  YYSYMBOL_PERMISSIONS = 6,                /* PERMISSIONS  */
  YYSYMBOL_EQUALS = 7,                     /* EQUALS  */
  YYSYMBOL_OPEN_BRACE = 8,                 /* OPEN_BRACE  */
  YYSYMBOL_CLOSED_BRACE = 9,               /* CLOSED_BRACE  */
  YYSYMBOL_LIST_START = 10,                /* LIST_START  */
  YYSYMBOL_LIST_END = 11,                  /* LIST_END  */
  YYSYMBOL_COMMA = 12,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 13,                 /* SEMICOLON  */
  YYSYMBOL_STRING = 14,                    /* STRING  */
  YYSYMBOL_TRUE = 15,                      /* TRUE  */
  YYSYMBOL_FALSE = 16,                     /* FALSE  */
  YYSYMBOL_NUMBER = 17,                    /* NUMBER  */
  YYSYMBOL_NAME = 18,                      /* NAME  */
  YYSYMBOL_AGE = 19,                       /* AGE  */
  YYSYMBOL_MODE = 20,                      /* MODE  */
  YYSYMBOL_LOGGING = 21,                   /* LOGGING  */
  YYSYMBOL_MAX_USERS = 22,                 /* MAX_USERS  */
  YYSYMBOL_USER = 23,                      /* USER  */
  YYSYMBOL_RIGHTS = 24,                    /* RIGHTS  */
  YYSYMBOL_YYACCEPT = 25,                  /* $accept  */
  YYSYMBOL_program = 26,                   /* program  */
  YYSYMBOL_app_name_line = 27,             /* app_name_line  */
  YYSYMBOL_users_section = 28,             /* users_section  */
  YYSYMBOL_users_list = 29,                /* users_list  */
  YYSYMBOL_user = 30,                      /* user  */
  YYSYMBOL_settings_section = 31,          /* settings_section  */
  YYSYMBOL_settings_list = 32,             /* settings_list  */
  YYSYMBOL_setting = 33,                   /* setting  */
  YYSYMBOL_bool_val = 34,                  /* bool_val  */
  YYSYMBOL_permissions_section = 35,       /* permissions_section  */
  YYSYMBOL_permissions_list = 36,          /* permissions_list  */
  YYSYMBOL_permission = 37,                /* permission  */
  YYSYMBOL_rights = 38,                    /* rights  */
  YYSYMBOL_right = 39                      /* right  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   172

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  25
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  52
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   279


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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    58,    58,    59,    62,    63,    66,    67,    68,    69,
      72,    73,    74,    75,    78,    79,    80,    81,    84,    85,
      86,    87,    90,    91,    92,    93,    96,    97,    98,    99,
     100,   101,   104,   105,   108,   109,   110,   111,   112,   115,
     116,   117,   118,   121,   122,   123,   124,   125,   126,   129,
     130,   131,   134
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
  "\"end of file\"", "error", "\"invalid token\"", "APP_NAME", "USERS",
  "SETTINGS", "PERMISSIONS", "EQUALS", "OPEN_BRACE", "CLOSED_BRACE",
  "LIST_START", "LIST_END", "COMMA", "SEMICOLON", "STRING", "TRUE",
  "FALSE", "NUMBER", "NAME", "AGE", "MODE", "LOGGING", "MAX_USERS", "USER",
  "RIGHTS", "$accept", "program", "app_name_line", "users_section",
  "users_list", "user", "settings_section", "settings_list", "setting",
  "bool_val", "permissions_section", "permissions_list", "permission",
  "rights", "right", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-76)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-43)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      99,   -76,    68,    29,    82,    20,   -76,    85,    92,    11,
      49,    98,   100,   -76,   -76,     3,     3,    31,   101,   -76,
      89,     0,    32,   -76,    35,    69,    69,    72,   102,   103,
     104,    86,    97,    86,    13,    12,   106,   107,   108,    36,
     -76,    48,    30,    30,   105,   -76,   109,    89,   -76,   -76,
     -76,   -76,   -76,   -76,     6,     1,     2,    69,   111,    69,
      59,    14,    93,    -1,    50,   -76,    52,   110,   113,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   114,   117,   120,    87,   115,    87,    22,
      27,   112,   116,   118,   -76,   119,   -76,   -76,   -76,   -76,
     -76,   -76,   122,   123,   124,   125,   121,   126,    94,    96,
     130,    75,   127,   133,   -76,   -76,   -76,   131,    73,   128,
     128,   128,   -76,    54,   -76,    57,    66,   128,   135,   128,
     136,    -4,    84,   -76,   -76,   -76,   -76,   -76,   -76,   -76
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     3,     0,     0,     0,     0,     1,     0,     0,     0,
       0,     0,    38,     5,     4,     0,     0,     0,     0,     2,
      12,     0,     0,    10,     0,    22,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,     0,     0,     0,     0,    15,     0,     0,    13,     8,
      11,     9,     7,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,     0,     0,     0,    27,
      26,    29,    32,    33,    28,    31,    30,    25,    20,    24,
      21,    19,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,     0,    41,    36,    40,    37,
      35,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,    14,     0,     0,     0,
       0,     0,    52,     0,    49,     0,     0,     0,     0,     0,
       0,     0,     0,    51,    45,    50,    47,    48,    46,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -76,   -76,   -76,   -76,   132,   -25,   -76,    91,    39,   -76,
     -76,   129,    15,   -50,   -75
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     8,    22,    23,    12,    39,    40,    74,
      19,    64,    65,   123,   124
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      84,    29,    71,    75,    20,   137,    48,    69,    50,    48,
     122,    21,    13,    52,    47,    81,    72,    73,    30,    76,
      70,    21,    85,    62,    14,    53,    51,    82,   100,     6,
      63,    62,    25,    31,     9,    99,    34,    57,    63,    26,
     101,   -42,   -42,    32,    33,    58,    35,    33,    59,    60,
      15,    86,   133,    89,   135,   127,   133,    61,   127,    16,
      59,    87,    88,    90,    88,   128,   129,   131,   130,   129,
     125,   126,    80,    42,   120,     5,   115,   132,   129,    36,
      37,    38,    43,   121,   116,   138,     7,    47,    62,    36,
      37,    38,    10,   139,    21,    63,    77,    11,    79,    77,
       1,    96,     2,    98,    96,    17,    18,    28,    27,    44,
      49,    46,    45,    54,    55,    56,    83,    41,   112,    67,
     113,    93,    91,    68,    78,    92,    94,    95,    97,   106,
     107,   102,   104,   105,   117,   103,   108,   109,   110,   114,
     118,   119,   122,   111,   134,   136,     0,     0,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    66
};

static const yytype_int16 yycheck[] =
{
       1,     1,     1,     1,     1,     9,    31,     1,    33,    34,
      14,     8,     1,     1,     1,     1,    15,    16,    18,    17,
      14,     8,    23,     1,    13,    13,    13,    13,     1,     0,
       8,     1,     1,     1,    14,    13,     1,     1,     8,     8,
      13,    11,    12,    11,    12,     9,    11,    12,    12,     1,
       1,     1,   127,     1,   129,     1,   131,     9,     1,    10,
      12,    11,    12,    11,    12,    11,    12,     1,    11,    12,
     120,   121,    13,     1,     1,     7,     1,    11,    12,    20,
      21,    22,    10,    10,     9,     1,     4,     1,     1,    20,
      21,    22,     7,     9,     8,     8,    57,     5,    59,    60,
       1,    86,     3,    88,    89,     7,     6,    18,     7,     7,
      13,     7,     9,     7,     7,     7,    23,    26,    24,    14,
      24,     7,    12,    14,    13,    12,     9,     7,    13,     7,
       7,    19,    14,    14,     7,    19,    12,    12,    17,     9,
       7,    10,    14,    17,     9,     9,    -1,    -1,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    26,    27,     7,     0,     4,    28,    14,
       7,     5,    31,     1,    13,     1,    10,     7,     6,    35,
       1,     8,    29,    30,    29,     1,     8,     7,    18,     1,
      18,     1,    11,    12,     1,    11,    20,    21,    22,    32,
      33,    32,     1,    10,     7,     9,     7,     1,    30,    13,
      30,    13,     1,    13,     7,     7,     7,     1,     9,    12,
       1,     9,     1,     8,    36,    37,    36,    14,    14,     1,
      14,     1,    15,    16,    34,     1,    17,    33,    13,    33,
      13,     1,    13,    23,     1,    23,     1,    11,    12,     1,
      11,    12,    12,     7,     9,     7,    37,    13,    37,    13,
       1,    13,    19,    19,    14,    14,     7,     7,    12,    12,
      17,    17,    24,    24,     9,     1,     9,     7,     7,    10,
       1,    10,    14,    38,    39,    38,    38,     1,    11,    12,
      11,     1,    11,    39,     9,    39,     9,     9,     1,     9
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    25,    26,    26,    27,    27,    28,    28,    28,    28,
      29,    29,    29,    29,    30,    30,    30,    30,    31,    31,
      31,    31,    32,    32,    32,    32,    33,    33,    33,    33,
      33,    33,    34,    34,    35,    35,    35,    35,    35,    36,
      36,    36,    36,    37,    37,    37,    37,    37,    37,    38,
      38,    38,    39
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     1,     4,     4,     6,     6,     6,     6,
       1,     3,     1,     3,     9,     3,     9,     9,     6,     6,
       6,     6,     0,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     6,     6,     6,     6,     0,     1,
       3,     3,     0,    11,     3,    11,    11,    11,    11,     1,
       3,     3,     1
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
  case 3: /* program: error  */
#line 59 "yacc_source.y"
                        { yyerror("Syntax error in program structure"); YYABORT; }
#line 1320 "y.tab.c"
    break;

  case 4: /* app_name_line: APP_NAME EQUALS STRING SEMICOLON  */
#line 62 "yacc_source.y"
                                                                    { app_name = strdup((yyvsp[-1].str)); }
#line 1326 "y.tab.c"
    break;

  case 5: /* app_name_line: APP_NAME EQUALS STRING error  */
#line 63 "yacc_source.y"
                                                                    { yyerror("Missing semicolon after APP_NAME declaration"); YYABORT; }
#line 1332 "y.tab.c"
    break;

  case 7: /* users_section: USERS EQUALS LIST_START users_list LIST_END error  */
#line 67 "yacc_source.y"
                                                                        { yyerror("Missing semicolon after USERS section"); YYABORT; }
#line 1338 "y.tab.c"
    break;

  case 8: /* users_section: USERS EQUALS error users_list LIST_END SEMICOLON  */
#line 68 "yacc_source.y"
                                                                        { yyerror("Missing '[' after USERS = "); YYABORT; }
#line 1344 "y.tab.c"
    break;

  case 9: /* users_section: USERS EQUALS LIST_START users_list error SEMICOLON  */
#line 69 "yacc_source.y"
                                                                        { yyerror("Missing ']' before semicolon in USERS section"); YYABORT; }
#line 1350 "y.tab.c"
    break;

  case 12: /* users_list: error  */
#line 74 "yacc_source.y"
                   { yyerror("Invalid user in list"); YYABORT; }
#line 1356 "y.tab.c"
    break;

  case 13: /* users_list: users_list error user  */
#line 75 "yacc_source.y"
                                   { yyerror("Missing comma between users"); YYABORT; }
#line 1362 "y.tab.c"
    break;

  case 14: /* user: OPEN_BRACE NAME EQUALS STRING COMMA AGE EQUALS NUMBER CLOSED_BRACE  */
#line 78 "yacc_source.y"
                                                                                  { addUser((yyvsp[-5].str), (yyvsp[-1].number)); }
#line 1368 "y.tab.c"
    break;

  case 15: /* user: OPEN_BRACE error CLOSED_BRACE  */
#line 79 "yacc_source.y"
                                                                                  { yyerror("Invalid user format - expected: {name=\"...\", age=...}"); YYABORT; }
#line 1374 "y.tab.c"
    break;

  case 16: /* user: error NAME EQUALS STRING COMMA AGE EQUALS NUMBER CLOSED_BRACE  */
#line 80 "yacc_source.y"
                                                                                  { yyerror("Missing '{' at start of user"); YYABORT; }
#line 1380 "y.tab.c"
    break;

  case 17: /* user: OPEN_BRACE NAME EQUALS STRING COMMA AGE EQUALS NUMBER error  */
#line 81 "yacc_source.y"
                                                                                  { yyerror("Missing '}' at end of user"); YYABORT; }
#line 1386 "y.tab.c"
    break;

  case 19: /* settings_section: SETTINGS EQUALS OPEN_BRACE settings_list CLOSED_BRACE error  */
#line 85 "yacc_source.y"
                                                                                    { yyerror("Missing semicolon after SETTINGS section"); YYABORT; }
#line 1392 "y.tab.c"
    break;

  case 20: /* settings_section: SETTINGS EQUALS error settings_list CLOSED_BRACE SEMICOLON  */
#line 86 "yacc_source.y"
                                                                                    { yyerror("Missing '{' after SETTINGS = "); YYABORT; }
#line 1398 "y.tab.c"
    break;

  case 21: /* settings_section: SETTINGS EQUALS OPEN_BRACE settings_list error SEMICOLON  */
#line 87 "yacc_source.y"
                                                                                    { yyerror("Missing '}' before semicolon in SETTINGS section"); YYABORT; }
#line 1404 "y.tab.c"
    break;

  case 25: /* settings_list: settings_list error setting  */
#line 93 "yacc_source.y"
                                                { yyerror("Missing comma between settings"); YYABORT; }
#line 1410 "y.tab.c"
    break;

  case 26: /* setting: MODE EQUALS STRING  */
#line 96 "yacc_source.y"
                                    { settings.mode = strdup((yyvsp[0].str)); }
#line 1416 "y.tab.c"
    break;

  case 27: /* setting: MODE EQUALS error  */
#line 97 "yacc_source.y"
                                    { yyerror("Invalid value for mode!"); YYABORT;}
#line 1422 "y.tab.c"
    break;

  case 29: /* setting: LOGGING EQUALS error  */
#line 99 "yacc_source.y"
                                    { yyerror("Invalid value for logging!"); YYABORT;}
#line 1428 "y.tab.c"
    break;

  case 30: /* setting: MAX_USERS EQUALS NUMBER  */
#line 100 "yacc_source.y"
                                    { updateMaxUsers((yyvsp[0].number)); }
#line 1434 "y.tab.c"
    break;

  case 31: /* setting: MAX_USERS EQUALS error  */
#line 101 "yacc_source.y"
                                    { yyerror("Invalid value for max_users!"); YYABORT; }
#line 1440 "y.tab.c"
    break;

  case 32: /* bool_val: TRUE  */
#line 104 "yacc_source.y"
                { settings.logging = true; }
#line 1446 "y.tab.c"
    break;

  case 33: /* bool_val: FALSE  */
#line 105 "yacc_source.y"
                 { settings.logging = false; }
#line 1452 "y.tab.c"
    break;

  case 35: /* permissions_section: PERMISSIONS EQUALS LIST_START permissions_list LIST_END error  */
#line 109 "yacc_source.y"
                                                                                        { yyerror("Missing semicolon after PERMISSIONS section"); YYABORT; }
#line 1458 "y.tab.c"
    break;

  case 36: /* permissions_section: PERMISSIONS EQUALS error permissions_list LIST_END SEMICOLON  */
#line 110 "yacc_source.y"
                                                                                        { yyerror("Missing '[' after PERMISSIONS = "); YYABORT; }
#line 1464 "y.tab.c"
    break;

  case 37: /* permissions_section: PERMISSIONS EQUALS LIST_START permissions_list error SEMICOLON  */
#line 111 "yacc_source.y"
                                                                                        { yyerror("Missing ']' before semicolon in PERMISSIONS section"); YYABORT; }
#line 1470 "y.tab.c"
    break;

  case 41: /* permissions_list: permissions_list error permission  */
#line 117 "yacc_source.y"
                                                        { yyerror("Missing comma between permissions"); YYABORT; }
#line 1476 "y.tab.c"
    break;

  case 43: /* permission: OPEN_BRACE USER EQUALS STRING COMMA RIGHTS EQUALS LIST_START rights LIST_END CLOSED_BRACE  */
#line 121 "yacc_source.y"
                                                                                                        { addPermission((yyvsp[-7].str)); }
#line 1482 "y.tab.c"
    break;

  case 44: /* permission: OPEN_BRACE error CLOSED_BRACE  */
#line 122 "yacc_source.y"
                                                                                                        { yyerror("Invalid permission format - expected: {user=\"...\", rights=[...]}"); YYABORT; }
#line 1488 "y.tab.c"
    break;

  case 45: /* permission: error USER EQUALS STRING COMMA RIGHTS EQUALS LIST_START rights LIST_END CLOSED_BRACE  */
#line 123 "yacc_source.y"
                                                                                                        { yyerror("Missing '{' at start of permission"); YYABORT; }
#line 1494 "y.tab.c"
    break;

  case 46: /* permission: OPEN_BRACE USER EQUALS STRING COMMA RIGHTS EQUALS LIST_START rights LIST_END error  */
#line 124 "yacc_source.y"
                                                                                                        { yyerror("Missing '}' at end of permission"); YYABORT; }
#line 1500 "y.tab.c"
    break;

  case 47: /* permission: OPEN_BRACE USER EQUALS STRING COMMA RIGHTS EQUALS error rights LIST_END CLOSED_BRACE  */
#line 125 "yacc_source.y"
                                                                                                        { yyerror("Missing '[' after rights = "); YYABORT; }
#line 1506 "y.tab.c"
    break;

  case 48: /* permission: OPEN_BRACE USER EQUALS STRING COMMA RIGHTS EQUALS LIST_START rights error CLOSED_BRACE  */
#line 126 "yacc_source.y"
                                                                                                        { yyerror("Missing ']' before '}' in permission"); YYABORT; }
#line 1512 "y.tab.c"
    break;

  case 51: /* rights: rights error right  */
#line 131 "yacc_source.y"
                                { yyerror("Missing comma between rights"); YYABORT; }
#line 1518 "y.tab.c"
    break;

  case 52: /* right: STRING  */
#line 134 "yacc_source.y"
                { addRight((yyvsp[0].str)); }
#line 1524 "y.tab.c"
    break;


#line 1528 "y.tab.c"

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

#line 137 "yacc_source.y"


int main() {
    init();

    int result = yyparse();
    
    if (result == 0) {
        printf("Parsing successful!\n\n");
        
        printf("App Name: %s\n", app_name);

        printf("Number of users: %d\n", user_count);
        for(int i = 0; i < user_count; i++) {
            printf("User: %s %d\n", users[i].name, users[i].age);
        }

        printf("Mode: %s\n", settings.mode);
        printf("Logging: %s\n", settings.logging ? "true" : "false");
        printf("Max users: %d\n", settings.max_users);

        for(int i = 0; i < permission_count; i++) {
            printf("User: %s\n", permissions[i].user);
            for(int j = 0; j < permissions[i].no_of_rights; j++) {
                printf("  Right: %s\n", permissions[i].rights[j]);
            }
        }
    } else {
        printf("Parsing failed!\n");
    }

    return result;
}

void init() {
    //init settings
    settings.mode = "default";
    settings.logging = false;
    settings.max_users = MAX_USERS_CONFIG;

    //init permissions
    for(int i = 0; i < MAX_USERS_CONFIG; i++) {
        permissions[i].no_of_rights = 0;
    }
}

void yyerror(const char* str) {
    fprintf(stderr, "Syntax error: %s\n", str);
}

void addUser(char* name, int age) {
    if (user_count < settings.max_users) {
        users[user_count].name = strdup(name);
        users[user_count].age = age;
        user_count++;
    } else {
        yyerror("Max user limit reached");
    }
}

void updateMaxUsers(int number) {
    if(number <= MAX_USERS_CONFIG) {
        settings.max_users = number;
    }
    else {
        yyerror("Max user limit exceeded");
    }
}

bool isUser(char* user) {
    for(int i = 0; i < user_count; i++) {
        if(strcmp(user, users[i].name) == 0) {
            return true;
        }
    }
    return false;
}

void addPermission(char* user) {
    if(!isUser(user)) {
        char buffer[100];
        sprintf(buffer, "User '%s' doesn't exist!", user);
        yyerror(buffer);
        return;
    }

    for(int i = 0; i < permission_count; i++) {
        if(strcmp(user, permissions[i].user) == 0) {
            char buffer[100];
            sprintf(buffer, "There are duplicate permissions for the user: %s.", user);
            yyerror(buffer);
            return;
        }
    }

    permissions[permission_count].user = strdup(user);
    permission_count++;
}

void addRight(char* right) {
    if(strcmp(right, "read") != 0 && strcmp(right, "write") != 0 && strcmp(right, "execute") != 0) {
        char buffer[100];
        sprintf(buffer, "Invalid right '%s'! Must be one of: read, write, execute", right);
        yyerror(buffer);
        return;
    }
    
    for(int i = 0; i < permissions[permission_count].no_of_rights; i++) {
        if(strcmp(right, permissions[permission_count].rights[i]) == 0) {
            return;
        }
    }

    permissions[permission_count].rights[permissions[permission_count].no_of_rights++] = strdup(right);
}
