%{
    #include <stdio.h>
    int cnt = 0;
%}
%%
[ \t]+ ;
\/\/.*\n {cnt++;}

%%
int yywrap() {}

int main(void) {
    yylex();
    printf("count %d", cnt);
    return 0;
}