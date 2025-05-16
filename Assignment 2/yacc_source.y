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
        char* mode;
        bool logging;
        int max_users; 
    } Settings;
    Settings settings;

    typedef struct {
        char* user;
        char* rights[3];
        int no_of_rights;
    } Permission;
    Permission permissions[MAX_USERS_CONFIG];
    int permission_count = 0;

    void init();

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
            | error     { yyerror("Syntax error in program structure"); YYABORT; }
            ;

app_name_line: APP_NAME EQUALS STRING SEMICOLON                     { app_name = strdup($3); }
              | APP_NAME EQUALS STRING error                        { yyerror("Missing semicolon after APP_NAME declaration"); YYABORT; }
              ;

users_section: USERS EQUALS LIST_START users_list LIST_END SEMICOLON
              | USERS EQUALS LIST_START users_list LIST_END error       { yyerror("Missing semicolon after USERS section"); YYABORT; }
              | USERS EQUALS error users_list LIST_END SEMICOLON        { yyerror("Missing '[' after USERS = "); YYABORT; }
              | USERS EQUALS LIST_START users_list error SEMICOLON      { yyerror("Missing ']' before semicolon in USERS section"); YYABORT; }
              ;

users_list: user
           | users_list COMMA user
           | error { yyerror("Invalid user in list"); YYABORT; }
           | users_list error user { yyerror("Missing comma between users"); YYABORT; }
           ;

user: OPEN_BRACE NAME EQUALS STRING COMMA AGE EQUALS NUMBER CLOSED_BRACE          { addUser($4, $8); }
     | OPEN_BRACE error CLOSED_BRACE                                              { yyerror("Invalid user format - expected: {name=\"...\", age=...}"); YYABORT; }
     | error NAME EQUALS STRING COMMA AGE EQUALS NUMBER CLOSED_BRACE              { yyerror("Missing '{' at start of user"); YYABORT; }
     | OPEN_BRACE NAME EQUALS STRING COMMA AGE EQUALS NUMBER error                { yyerror("Missing '}' at end of user"); YYABORT; }
     ;

settings_section: SETTINGS EQUALS OPEN_BRACE settings_list CLOSED_BRACE SEMICOLON
                 | SETTINGS EQUALS OPEN_BRACE settings_list CLOSED_BRACE error      { yyerror("Missing semicolon after SETTINGS section"); YYABORT; }
                 | SETTINGS EQUALS error settings_list CLOSED_BRACE SEMICOLON       { yyerror("Missing '{' after SETTINGS = "); YYABORT; }
                 | SETTINGS EQUALS OPEN_BRACE settings_list error SEMICOLON         { yyerror("Missing '}' before semicolon in SETTINGS section"); YYABORT; }
                 ;

settings_list: setting
              | settings_list COMMA setting
              | settings_list error setting     { yyerror("Missing comma between settings"); YYABORT; }
              | /* empty */
              ;

setting: MODE EQUALS STRING         { settings.mode = strdup($3); }
        | MODE EQUALS error         { yyerror("Invalid value for mode!"); YYABORT;}
        | LOGGING EQUALS bool_val 
        | LOGGING EQUALS error      { yyerror("Invalid value for logging!"); YYABORT;}
        | MAX_USERS EQUALS NUMBER   { updateMaxUsers($3); }
        | MAX_USERS EQUALS error    { yyerror("Invalid value for max_users!"); YYABORT; }
        ;

bool_val: TRUE  { settings.logging = true; }
         | FALSE { settings.logging = false; }
         ;

permissions_section: PERMISSIONS EQUALS LIST_START permissions_list LIST_END SEMICOLON
                    | PERMISSIONS EQUALS LIST_START permissions_list LIST_END error     { yyerror("Missing semicolon after PERMISSIONS section"); YYABORT; }
                    | PERMISSIONS EQUALS error permissions_list LIST_END SEMICOLON      { yyerror("Missing '[' after PERMISSIONS = "); YYABORT; }
                    | PERMISSIONS EQUALS LIST_START permissions_list error SEMICOLON    { yyerror("Missing ']' before semicolon in PERMISSIONS section"); YYABORT; }
                    | /* empty */
                    ;
                
permissions_list: permission
                 | permissions_list COMMA permission
                 | permissions_list error permission    { yyerror("Missing comma between permissions"); YYABORT; }
                 | /* empty */
                 ;

permission: OPEN_BRACE USER EQUALS STRING COMMA RIGHTS EQUALS LIST_START rights LIST_END CLOSED_BRACE   { addPermission($4); }
            | OPEN_BRACE error CLOSED_BRACE                                                             { yyerror("Invalid permission format - expected: {user=\"...\", rights=[...]}"); YYABORT; }
            | error USER EQUALS STRING COMMA RIGHTS EQUALS LIST_START rights LIST_END CLOSED_BRACE      { yyerror("Missing '{' at start of permission"); YYABORT; }
            | OPEN_BRACE USER EQUALS STRING COMMA RIGHTS EQUALS LIST_START rights LIST_END error        { yyerror("Missing '}' at end of permission"); YYABORT; }
            | OPEN_BRACE USER EQUALS STRING COMMA RIGHTS EQUALS error rights LIST_END CLOSED_BRACE      { yyerror("Missing '[' after rights = "); YYABORT; }
            | OPEN_BRACE USER EQUALS STRING COMMA RIGHTS EQUALS LIST_START rights error CLOSED_BRACE    { yyerror("Missing ']' before '}' in permission"); YYABORT; }
            ;

rights: right
        | rights COMMA right
        | rights error right    { yyerror("Missing comma between rights"); YYABORT; }
        ;

right: STRING   { addRight($1); }
      ;

%%

int main() {
    init();

    int result = yyparse();
    
    if (result == 0) {
        printf("Parsing successful!\n\n");
        
        printf("App Name: %s\n", app_name);

        printf("Number of users: %d\n", user_count);
        for(int i = 0; i < user_count; i++) {
            printf("User: %s %d\n", users[i].name, users[i].age);
        }

        printf("Mode: %s\n", settings.mode);
        printf("Logging: %s\n", settings.logging ? "true" : "false");
        printf("Max users: %d\n", settings.max_users);

        for(int i = 0; i < permission_count; i++) {
            printf("User: %s\n", permissions[i].user);
            for(int j = 0; j < permissions[i].no_of_rights; j++) {
                printf("  Right: %s\n", permissions[i].rights[j]);
            }
        }
    } else {
        printf("Parsing failed!\n");
    }

    return result;
}

void init() {
    //init settings
    settings.mode = "default";
    settings.logging = false;
    settings.max_users = MAX_USERS_CONFIG;

    //init permissions
    for(int i = 0; i < MAX_USERS_CONFIG; i++) {
        permissions[i].no_of_rights = 0;
    }
}

void yyerror(const char* str) {
    fprintf(stderr, "Syntax error: %s\n", str);
}

void addUser(char* name, int age) {
    if (user_count < settings.max_users) {
        users[user_count].name = strdup(name);
        users[user_count].age = age;
        user_count++;
    } else {
        yyerror("Max user limit reached");
    }
}

void updateMaxUsers(int number) {
    if(number <= MAX_USERS_CONFIG) {
        settings.max_users = number;
    }
    else {
        yyerror("Max user limit exceeded");
    }
}

bool isUser(char* user) {
    for(int i = 0; i < user_count; i++) {
        if(strcmp(user, users[i].name) == 0) {
            return true;
        }
    }
    return false;
}

void addPermission(char* user) {
    if(!isUser(user)) {
        char buffer[100];
        sprintf(buffer, "User '%s' doesn't exist!", user);
        yyerror(buffer);
        return;
    }

    for(int i = 0; i < permission_count; i++) {
        if(strcmp(user, permissions[i].user) == 0) {
            char buffer[100];
            sprintf(buffer, "There are duplicate permissions for the user: %s.", user);
            yyerror(buffer);
            return;
        }
    }

    permissions[permission_count].user = strdup(user);
    permission_count++;
}

void addRight(char* right) {
    if(strcmp(right, "read") != 0 && strcmp(right, "write") != 0 && strcmp(right, "execute") != 0) {
        char buffer[100];
        sprintf(buffer, "Invalid right '%s'! Must be one of: read, write, execute", right);
        yyerror(buffer);
        return;
    }
    
    for(int i = 0; i < permissions[permission_count].no_of_rights; i++) {
        if(strcmp(right, permissions[permission_count].rights[i]) == 0) {
            return;
        }
    }

    permissions[permission_count].rights[permissions[permission_count].no_of_rights++] = strdup(right);
}