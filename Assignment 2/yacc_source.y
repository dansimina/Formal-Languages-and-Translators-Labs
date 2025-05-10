%{
    #include <stdio.h>
    #include <string.h>

    char* app_name;

    #define MAX_USERS_CONFIG 100
    typedef struct {
        char* name;
        int age;
    }User;
    User users[MAX_USERS_CONFIG];
    int user_count = 0;

    int yylex(void);
    void yyerror(const char* str);

    void add_user(char* name, int age);

%}

%union {
    char* str;
    int number;
}

%token APP_NAME USERS SETTINGS PERMISSIONS
%token EQUALS OPEN_BRACE CLOSED_BRACE LIST_START LIST_END COMMA SEMICOLON
%token <str> STRING
%token <bool> BOOL
%token <number> NUMBER
%token NAME AGE
%token MODE LOGGING MAX_USERS
%token USER RIGHTS

%%

program:    app_name_line users_section settings_section
            ;

app_name_line: APP_NAME EQUALS STRING SEMICOLON                     { app_name = strdup($3); }
              ;

users_section: USERS EQUALS LIST_START users_list LIST_END SEMICOLON
              ;

users_list: user
           | users_list COMMA user
           ;

user: OPEN_BRACE NAME EQUALS STRING COMMA AGE EQUALS NUMBER CLOSED_BRACE          { add_user($4, $8); }
     ;

settings_section: SETTINGS EQUALS OPEN_BRACE settings_list CLOSED_BRACE SEMICOLON
                 ;

settings_list: setting
              | settings_list COMMA setting
              ;

setting: MODE EQUALS STRING
        | LOGGING EQUALS BOOL
        | MAX_USERS EQUALS NUMBER
        |
        ;


%%

int main() {
    yyparse();

    printf("App Name: %s\n", app_name);

    printf("Number of users: %d\n", user_count);
    for(int i = 0; i < user_count; i++) {
        printf("User: %s %d\n", users[i].name, users[i].age);
    }

    return 0;
}

void yyerror(const char* str) {
    fprintf(stderr, "Syntax error: %s\n", str);
}

void add_user(char* name, int age) {
        if (user_count < MAX_USERS_CONFIG) {
            users[user_count].name = strdup(name);
            users[user_count].age = age;
            user_count++;
        } else {
            fprintf(stderr, "Max user limit reached\n");
        }
    }