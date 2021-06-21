#include "utils/yacc_utils/yacc_utils.h"

#include <stdio.h>

void yyerror(char const *s){
    printf("Error! %s\n\n",s);
}
