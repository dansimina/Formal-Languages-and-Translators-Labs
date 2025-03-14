D   java
    int noJava, noJavaScript;
%%
{D}script     { noJavaScript++; REJECT; }
{D}           noJava++;
\n            |
.             ;
%%
yywrap() {
    printf("Java: %d, JavaScript: %d\n", noJava, noJavaScript);
    return 1;
}