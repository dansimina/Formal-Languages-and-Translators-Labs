%{
    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>

    char* app_name;

    #define MAX_USERS_CONFIG 500
    typedef struct {
        char* name;
        int age;
    } User;
    User users[MAX_USERS_CONFIG];
    int user_count = 0;

    typedef struct {

    } Setting;


    typedef struct {
        char* user;
        char* rights[3];
        int no_of_rights;
    } Permission;
    Permission permissions[MAX_USERS_CONFIG];
    int permission_count = 0;



    char* mode = "default";
    bool logging = 0;
    int max_users = MAX_USERS_CONFIG;


    int yylex(void);
    void yyerror(const char* str);

    void addUser(char* name, int age);
    void updateMaxUsers(int number);
    void addPermission(char* user);
    void addRight(char* right);
%}

%union {
    char* str;
    int number;
}

%token APP_NAME USERS SETTINGS PERMISSIONS
%token EQUALS OPEN_BRACE CLOSED_BRACE LIST_START LIST_END COMMA SEMICOLON
%token <str> STRING
%token TRUE FALSE
%token <number> NUMBER
%token NAME AGE
%token MODE LOGGING MAX_USERS
%token USER RIGHTS

%%

program:    app_name_line users_section settings_section permissions_section
            ;

app_name_line: APP_NAME EQUALS STRING SEMICOLON                     { app_name = strdup($3); }
              ;

users_section: USERS EQUALS LIST_START users_list LIST_END SEMICOLON
              ;

users_list: user
           | users_list COMMA user
           ;

user: OPEN_BRACE NAME EQUALS STRING COMMA AGE EQUALS NUMBER CLOSED_BRACE          { addUser($4, $8); }
     ;

settings_section: SETTINGS EQUALS OPEN_BRACE settings_list CLOSED_BRACE SEMICOLON
                 ;

settings_list: setting
              | settings_list COMMA setting
              ;

setting: MODE EQUALS STRING         { mode = strdup($3); }
        | LOGGING EQUALS bool_val
        | MAX_USERS EQUALS NUMBER   { updateMaxUsers($3); }
        |
        ;

bool_val: TRUE  { logging = true; }
         | FALSE { logging = false; }
         ;

permissions_section: PERMISSIONS EQUALS LIST_START permissions_list LIST_END SEMICOLON
                    |
                    ;
                
permissions_list: permission
                 | permissions_list COMMA permission
                 ;

permission: OPEN_BRACE USER EQUALS STRING COMMA RIGHTS EQUALS LIST_START rights LIST_END CLOSED_BRACE { addPermission($4); }
            ;

rights: right
        | rights COMMA right
        ;

right: STRING   { addRight($1); }
      ;

%%

int main() {
    yyparse();

    printf("App Name: %s\n", app_name);

    printf("Number of users: %d\n", user_count);
    for(int i = 0; i < user_count; i++) {
        printf("User: %s %d\n", users[i].name, users[i].age);
    }

    printf("Mode: %s\n", mode);
    printf("Logging: %s\n", logging ? "true" : "false");
    printf("Max users: %d\n", max_users);

    for(int i = 0; i < permission_count; i++) {
        printf("User: %s\n", permissions[i].user);
        for(int j = 0; j < permissions[i].no_of_rights; j++) {
            printf("  Right: %s\n", permissions[i].rights[j]);
        }
    }

    return 0;
}

void yyerror(const char* str) {
    fprintf(stderr, "Syntax error: %s\n", str);
}

void addUser(char* name, int age) {
    if (user_count < max_users) {
        users[user_count].name = strdup(name);
        users[user_count].age = age;
        user_count++;
    } else {
        yyerror("Max user limit reached\n");
    }
}

void updateMaxUsers(int number) {
    if(number <= MAX_USERS_CONFIG) {
        max_users = number;
    }
    else {
        yyerror("Max user limit reached\n");
    }
}

// de verificat daca exista user si alte permisiuni pt el
// de pus erori


void addPermission(char* user) {
    permissions[permission_count].user = strdup(user);
    permission_count++;
}

void addRight(char* right) {
    int idx = permission_count;
    if (idx >= 0 && permissions[idx].no_of_rights < 3) {
        permissions[idx].rights[permissions[idx].no_of_rights++] = strdup(right);
    } else {
        yyerror("Cannot add right: invalid permission index or max rights reached\n");
    }
}