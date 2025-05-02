%{
    #include <stdio.h>
    #include <string.h>

    #define MAX_CONFIG_ENTRIES 100

    typedef struct {
        char* key;
        char *value;
    } ConfigEntry;

    ConfigEntry config [MAX_CONFIG_ENTRIES];
    int entry_count = 0;

    void add_entry(char* key, char* value);

    int yylex(void);
    void yyerror(const char* str);
%}

%union {
    char* str;
}

// str se aplica pt toate token-urile din linie, de aceea aici e pe 2 linii separate
%token <str> STRING
%token LEFT_BRACE RIGHT_BRACE COLON COMMA

%%

config: LEFT_BRACE entry_list RIGHT_BRACE
        ;

// ori avem entry, ori avem o lista de entry-uri virgula entry
entry_list: entry
            | entry_list COMMA entry
            ;

entry: STRING COLON STRING  {    
                                add_entry($1, $3);
                            };

%%

int main() {
    yyparse();

    printf("JSON Configuration:\n");
    for(int i = 0; i < entry_count; i++) {
        printf("    %s: %s\n", config[i].key, config[i].value);
    }

    return 0;
}

void add_entry(char* key, char* value) {
    if(entry_count < MAX_CONFIG_ENTRIES) {
        config[entry_count].key = strdup(key);
        config[entry_count].value = strdup(value);
        entry_count++; 
    }
    else {
        fprintf(stderr, "Max number of entries reached! (%d/%d)", entry_count, MAX_CONFIG_ENTRIES);
    }
}

void yyerror(const char* str) {
    fprintf(stderr, "Syntax error: %s\n", str);
}