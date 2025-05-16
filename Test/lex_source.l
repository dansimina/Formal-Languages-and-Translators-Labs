%{
    #include "y.tab.h"
    #include <string.h>
%}

%%

"int"                   return INT;
"bool"                  return BOOL;
"true"                  { yylval.boolean = 1; return TRUE; }
"false"                 { yylval.boolean = 0; return FALSE; }
"&&"                    return AND;
"||"                    return OR;
"=="                    return EQ;
"!="                    return NE;
"<="                    return LE;
">="                    return GE;
"<"                     return LT;
">"                     return GT;
"+"                     return PLUS;
"-"                     return MINUS;
"*"                     return MULT;
"/"                     return DIV;
"("                     return OPEN_PARENTHESIS;
")"                     return CLOSE_PARENTHESIS;
"="                     return EQUALS;
";"                     return SEMICOLON;

[a-zA-Z][a-zA-Z0-9_]*   { 
                          yylval.string = strdup(yytext);
                          return ID; 
                        }

[0-9]+                  {
                            yylval.number = atoi(yytext);
                            return NUMBER;
                        }

[ \t\n\r]+              ;

.                       ;

%%

