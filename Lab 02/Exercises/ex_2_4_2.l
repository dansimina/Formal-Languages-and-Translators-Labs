%{
    #include <stdio.h>
    int c = 0;
%}

%%
. {c++;}
%%

int yywrap(void) {}

int main() {
    yylex();
    printf("count %d\n", c);
    return 0;
}