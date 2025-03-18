accessModifier      (public|private|protected|package)
type                (byte|short|int|long|float|double|char|bool|string|void)
operator            ("+"|"-"|"*"|"/"|"%"|"|"|"&")

Character           [a-zA-Z]
Alphanumeric        [a-zA-Z0-9]
Digit               [0-9]

    int tabs;

%%

{accessModifier}                        printf("ACCESS_MODIFIER ");

[{]                                     {printf("BLOCK_START "); tabs++;}
[}]                                     {printf("BLOCK_END "); tabs--;}

{type}                                  printf("TYPE ");

{Character}{Alphanumeric}*[ \t]*[(]     {printf("FUNCTION_NAME FN_PARAMS_START ");}

[(]                                     printf("FN_PARAMS_START ");
[)]                                     printf("FN_PARAMS_END ");

return                                  printf("RETURN ");

{Character}+{Alphanumeric}*             printf("VARIABLE_NAME ");

[=]                                     printf("ASSIGN ");

{operator}                              printf("OPERATOR ");

[ \t]+                                  ;

[\n][}]                                   {
                                            printf("\n");
                                            for(int i = 0; i < tabs - 1; i++) {
                                                printf("\t");
                                            }
                                            printf("BLOCK_END \n");
                                        }

[\n]                                    {
                                            printf("\n");
                                            for(int i = 0; i < tabs; i++) {
                                                printf("\t");
                                            }
                                        }
%%