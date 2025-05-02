%{
    #include "y.tab.h"
    #include <string.h>
%}

%%

    // string care e intre ghilimele si contine orice inafara de  ghilimele
\"[^\"]+\"  {
                yylval.str = strdup(yytext + 1); //stergem primele ghilimele
                yylval.str[strlen(yylval.str) - 1] = '\0'; //stergem ghilimelele de la final
                return STRING;
            }

"{"         return LEFT_BRACE;
"}"         return RIGHT_BRACE;
":"         return COLON;
","         return COMMA;
[ \t\n\r]   ; //ignoram spatiile albe si new line
.           ; //ignoram orice alt caracter

%%