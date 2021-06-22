#include "lex_utils.h"

#include <stdio.h>
#include <string.h>

char* new_lex_string(char* yytext, unsigned yyleng){
    char * new_string = malloc((yyleng+1)*sizeof(*new_string));

    if (new_string == NULL) {
        fprintf(stderr,"MALLOC FAILED\n\n");
        return new_string;
    }

    new_string[yyleng] = 0;
    
    return memcpy(new_string,yytext,yyleng);
}
