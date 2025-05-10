%{
    #include "y.tab.h"
    #include <string.h>
%}

%%

"app_name"      return APP_NAME;
"users"         return USERS;

"="             return EQUALS;
"{"             return OPEN_BRACE;
"}"             return CLOSED_BRACE;
"["             return LIST_START;
"]"             return LIST_END;
","             return COMMA;
";"             return SEMICOLON;

\"[^\"]*\"      {
                    yylval.str = strdup(yytext + 1);
                    yylval.str[strlen(yylval.str) - 1] = '\0';
                    return STRING;
                }

[0-9]+          {
                    yylval.number = atoi(yytext);
                    return NUMBER;
                }

"name"          return NAME;
"age"           return AGE;


[ \t\n\r]+      ;
.               ;

%%