#include "yacc_utils.h"

#include <stdio.h>

#include "compiler_utils/element_list/element_list.h"
#include "hash_maps/functions_hash_map/functions_hash_map.h"
#include "hash_maps/variables_hash_map/variables_hash_map.h"
#include "libs/khash/khash.h"

// extern FILE *yyin;
// static FILE *output;

void yyerror(char const *s) {
    printf("Error! %s\n\n", s);
}

void init_compiler() {

    init_functions_hash_map();
    init_variables_hash_map();

    // output = fopen("percy_output.html","w");

    // if(output == NULL){
    //     perror("Error at opening file\n");
    //     fprintf(stderr,"Excecution cannot continue\n");
    //     exit(0);
    // }
}

void add_new_variable(char *name, var_t *value) {
}

void save_function(ast_node_t *function) {
    ast_function_node_t *function_node = (ast_function_node_t *)function;

    functions_hash_map_put(function_node->name, function_node);
}

void execute_main_function() {
    ast_function_node_t * main_function = functions_hash_map_get("main");

    if (main_function == NULL){
        printf("NO HAY MAIN!!!!\n\n");
    }

    execute_ast(main_function->statements);
}
