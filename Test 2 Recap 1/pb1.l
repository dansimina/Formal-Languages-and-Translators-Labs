    // parseaza input-ul, identifica niste tokeni si ii trimite catre yacc

%{
    #include <stdio.h>
    #include "y.tab.h"
    extern int yylval; // reprez o val care se trimite din lex catre yacc odata cu token-ul
%}
%%

[0-9]+      {   //identificam numerele
                yylval = atoi(yytext); //aici returnam valoarea pt un numar
                return INTEGER; // INTEGER e un token
            }

[-+*/\n]    return *yytext;
[ \t]       ; //ignoram spatiile si tab-urile

%%