%{
    #include <stdio.h>

    extern int yylex(void); //yacc tb sa apeleze lex pentru parsarea lexicala    

    void yyerror(char const *s) {
        fprintf(stderr, "%s\n", s); //pentru erori
    }
%}

// tb sa definim tokenii pe care ii folosim in
%token INTEGER

// spunem cum vrem sa parseze gramatica, in cazul acesta se parseaza prima data ce e in stanga
%left '+' '-' 
// specificam tokenii pe linii diferite astfel cei mai prioritari apar mai jos
%left '*' '/'

// prima data calculeaza inmultirea si impartirea si dupa adunarea si scaderea

%%

//gramaticile de forma " nume : termenii 

//gramatica principala pt a trata mai multe expresii
expression_list : expression_list expression '\n' { printf("Resul: %d\n", $2); } //ne asteptam ca pe fiecare linie sa avem o expresie
                | //expresia poate sa fie si empty
                ; //terminare gramatica

// expresia pe care vrem sa o calculam, care poate sa fie fie un numar(INTEGER e token-ul din lex), sau alta expresie
// daca vrem ca gramatica sa returneze ceva folosim $$, practic $$ tine loc de return
expression : INTEGER
            //ca sa ne folosim la termenii din gramatica folosim $1 - primul termen, $2 - caracterul + si $3 al treilea termen
            //ne folosim de recurenta pentru a putea avea operatii repetate
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