    int lung[99];
%%
[a-zA-Z]+  lung[yyleng]++;
[ \r\n]    ;
.          { 
              printf("Caracter ilegal: %c\n", yytext[0]); 
              exit(1); 
           }
%%

yywrap() {
    printf("Histograma cuvinte:\n");
    int i;
    for (i = 0; i < 99; i++) {
        if (lung[i] > 0) {
            printf(" %1d %7d\n", i, lung[i]);
        }
    }
    return(1);
}