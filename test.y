%{
#include <ctype.h>
#include <stdio.h>
int yylex();
void yyerror(const char *s);
int yydebug=1; // útil para debugging..
%}

%token CHAR
%start linea

%%
linea:      expr '\n' {printf("%s",$1);}
            ;
expr:       expr letra    
            |    letra
            ;
letra:      CHAR
            ;
%%
int yylex() {
    int c;
    c = getchar();
        if (isalpha(c)) {
        yylval =  isupper(c) ? c-'A'+'a' : c;
        return CHAR;
        }
    return c;
}