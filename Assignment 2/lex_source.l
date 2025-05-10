%{
    #include "y.tab.h"
    #include <string.h>
%}

%%

"app_name"      return APP_NAME;
"users"         return USERS;
"settings"      return SETTINGS;
"permissions"   return PERMISSIONS;

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

"mode"          return MODE;
"logging"       return LOGGING;
"max users"     return MAX_USERS;
"true"          return TRUE;
"false"         return FALSE;

"user"          return USER;
"rights"        return RIGHTS;


[ \t\n\r]+      ;

#.*\n           ;

.               ;

%%