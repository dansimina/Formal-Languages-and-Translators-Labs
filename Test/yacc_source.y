%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VAR_NAME 100
#define MAX_NUM_OF_VARS 100
#define MAX_NUM_OF_EXPR 100

typedef struct {
    char name[MAX_VAR_NAME];
    int value;
} Variable;

Variable variables[MAX_NUM_OF_VARS];
int var_count = 0;

int results[MAX_NUM_OF_EXPR];
bool bool_results[MAX_NUM_OF_EXPR];
int expr_count = 0;

bool bool_result = false;

void add_variable(const char* name, int value);
int find_variable(const char* name);
int yylex(void);
void yyerror(const char* str);
%}

%union {
    char* string;
    int number;
    int boolean;
}

%token INT BOOL
%token <number> NUMBER
%token <boolean> TRUE FALSE
%token <string> ID
%token PLUS MINUS MULT DIV
%token AND OR EQ NE LT GT LE GE
%token OPEN_PARENTHESIS CLOSE_PARENTHESIS EQUALS SEMICOLON

%type <number> expression

%left OR
%left AND
%left EQ NE
%left LT GT LE GE
%left PLUS MINUS
%left MULT DIV

%%
program: list_of_variables list_of_expressions
        ;

list_of_variables: list_of_variables variable_declaration
                  | variable_declaration
             ;

variable_declaration: INT ID EQUALS NUMBER SEMICOLON    {
                                                            //printf("Variable %s declared with value %d\n", $2, $4); 
                                                            add_variable($2, $4);
                                                        }
                    | BOOL ID EQUALS TRUE SEMICOLON     {
                                                            //printf("Variable %s declared with value true\n", $2); 
                                                            add_variable($2, 1);
                                                        }
                    | BOOL ID EQUALS FALSE SEMICOLON    {
                                                            //printf("Variable %s declared with value false\n", $2); 
                                                            add_variable($2, 0);
                                                        }
                    ;

list_of_expressions: list_of_expressions expression     {
                                                            if(expr_count == MAX_NUM_OF_EXPR) {
                                                                yyerror("Maximum number of expressions reached");
                                                                YYABORT;
                                                            }
                                                            bool_results[expr_count] = bool_result;
                                                            results[expr_count++] = $2;
                                                            //printf("Final result: %d\n", $2);
                                                        }
                    | expression                        {     
                                                            if(expr_count == MAX_NUM_OF_EXPR) {
                                                                yyerror("Maximum number of expressions reached");
                                                                YYABORT;
                                                            }           
                                                            bool_results[expr_count] = bool_result;
                                                            results[expr_count++] = $1;
                                                            //printf("Final result: %d\n", $1);
                                                        }
                    ;

expression: expression PLUS expression      { 
                                                $$ = $1 + $3; 
                                                bool_result = false;
                                                //printf("Result of addition: %d\n", $$); 
                                            }
            | expression MINUS expression   { 
                                                $$ = $1 - $3;
                                                bool_result = false; 
                                                //printf("Result of subtraction: %d\n", $$); 
                                            }
            | expression MULT expression    { 
                                                $$ = $1 * $3; 
                                                bool_result = false;
                                                //printf("Result of multiplication: %d\n", $$); 
                                            }
            | expression DIV expression     { 
                                                if ($3 != 0) { 
                                                    $$ = $1 / $3; 
                                                    bool_result = false;
                                                    //printf("Result of division: %d\n", $$); 
                                                } else { 
                                                    yyerror("Division by zero"); 
                                                    YYABORT; 
                                                } 
                                            }
            | expression AND expression     {
                                                $$ = $1 && $3;
                                                bool_result = true;
                                                //printf("Result of AND: %d\n", $$);
                                            }
            | expression OR expression      { 
                                                $$ = $1 || $3;
                                                bool_result = true;
                                                //printf("Result of OR: %d\n", $$);
                                            }
            | expression EQ expression      {
                                                $$ = ($1 == $3);
                                                bool_result = true;
                                                //printf("Result of equality check: %d\n", $$);
                                            }
            | expression NE expression      {
                                                $$ = ($1 != $3);
                                                bool_result = true;
                                                //printf("Result of inequality check: %d\n", $$);
                                            }
            | expression LT expression      {
                                                $$ = ($1 < $3);
                                                bool_result = true;
                                                //printf("Result of less than: %d\n", $$);
                                            }
            | expression GT expression      {
                                                $$ = ($1 > $3);
                                                bool_result = true;
                                                //rintf("Result of greater than: %d\n", $$);
                                            }
            | expression LE expression      {
                                                $$ = ($1 <= $3);
                                                bool_result = true;
                                                //printf("Result of less than or equal: %d\n", $$);
                                            }
            | expression GE expression      {
                                                $$ = ($1 >= $3);
                                                bool_result = true;
                                                //printf("Result of greater than or equal: %d\n", $$);
                                            }
            | OPEN_PARENTHESIS expression CLOSE_PARENTHESIS { $$ = $2; }
            | ID    { 
                        int index = find_variable($1); 
                        if (index != -1) { 
                            $$ = variables[index].value; 
                        } else { 
                            yyerror("Variable not found: %s", $1); 
                            YYABORT; 
                        } 
                    }
            | NUMBER    { 
                            $$ = $1; 
                            bool_result = false;
                            //printf("Number: %d\n", $$); 
                        }
            | TRUE  { 
                        $$ = 1; 
                        bool_result = true;
                        //printf("Boolean true: %d\n", $$); 
                    }
            | FALSE { 
                        $$ = 0;    
                        bool_result = true;
                        //printf("Boolean false: %d\n", $$); 
                    }
            ;

%%

int main() {
    int result = yyparse();

    for (int i = 0; i < expr_count; i++) {
        if(bool_results[i]) {
            printf("Expression %d: %s\n", i + 1, results[i] ? "true" : "false");
        } else {
            printf("Expression %d: %d\n", i + 1, results[i]);
        }    
    }

    return result;
}

void yyerror(const char* str) {
    fprintf(stderr, "Error: %s\n", str);
}

void add_variable(const char* name, int value) {
    if (find_variable(name) != -1) {
        fprintf(stderr, "Error: Variable %s already declared\n", name);
        return;
    }
    
    if (var_count < MAX_NUM_OF_VARS) {
        strncpy(variables[var_count].name, name, MAX_VAR_NAME - 1);
        variables[var_count].name[MAX_VAR_NAME - 1] = '\0';
        variables[var_count].value = value;
        var_count++;
    } else {
        fprintf(stderr, "Error: Maximum number of variables reached.\n");
    }
}

int find_variable(const char* name) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}