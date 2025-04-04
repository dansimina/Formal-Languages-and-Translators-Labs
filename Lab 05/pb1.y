%{
    #include <stdio.h>

    extern int yylex(void);

    void yyerror(char const *s) {
        fprintf(stderr, "%s\n", s);
    }
%}

%token INTEGER
%left '+' '-'
%left '*' '/'

%%

expressions_list : expressions_list expression '\n' { printf("Result: %d\n", $2); }
                 | /* EMPTY */
                 ;

expression : INTEGER
           | expression '+' expression { $$ = $1 + $3; }
           | expression '-' expression { $$ = $1 - $3; }
           | expression '*' expression { $$ = $1 * $3; }
           | expression '/' expression { $$ = $1 / $3; }
           ;

%%

int main() {
    yyparse();
    return 0;
}
 