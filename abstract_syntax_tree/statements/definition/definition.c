#include "definition.h"

static void ast_definition_process(){

}

static void ast_definition_destroy() {
}

ast_functions_t ast_definition_provider(){
    ast_functions_t functions = {
        .process = ast_definition_process,
        .destroy = ast_definition_destroy
    };

    return functions;
}

ast_node_t* create_ast_definition_node(int type, char * symbol, ast_node_t * tag) {
    return NULL;
}
