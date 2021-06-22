#include "assignation.h"

static ast_node_t * ast_assignation_process() {
    return NULL;
}

static void ast_assignation_destroy() {
}

ast_functions_t ast_assignation_provider(){
    ast_functions_t functions = {
        .process = ast_assignation_process,
        .destroy = ast_assignation_destroy
    };

    return functions;
}

ast_node_t* create_ast_assignation_node(char* symbol, ast_node_t* tag) {
    //chequear que este declarada 
    //asignarle un valor

    return NULL;
}
