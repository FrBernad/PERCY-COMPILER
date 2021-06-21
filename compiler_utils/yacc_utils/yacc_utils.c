#include "yacc_utils.h"

#include <stdio.h>

#include "libs/khash/khash.h"
#include "compiler_utils/element_list/element_list.h"

enum hash_tables {
    SYMBOLS_MAP
};

typedef enum var_type {
    element,
    numeric,
    string,
} var_type_t;

typedef struct var {
    
    var_type_t type;
    union {
        char * str;
        int num;
        element_node_t node;
    }value;

} var_t;

KHASH_MAP_INIT_STR(SYMBOLS_MAP, var_t)

static khash_t(SYMBOLS_MAP) * symbols_map;

extern FILE *yyin;
static FILE *output;

void yyerror(char const *s) {
    printf("Error! %s\n\n", s);
}

void init_compiler() {

    // output = fopen("percy_output.html","w");

    // if(output == NULL){
    //     perror("Error at opening file\n");
    //     fprintf(stderr,"Excecution cannot continue\n");
    //     exit(0);
    // }

    symbols_map = kh_init(SYMBOLS_MAP);

}

void add_new_variable(char * name,var_t * value){


}

