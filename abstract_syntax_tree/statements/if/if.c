#include "if.h"

static ast_node_t* ast_if_process(ast_node_t* node) {
    return NULL;
}

static void ast_if_destroy() {
}

ast_functions_t ast_if_provider() {
    ast_functions_t functions = {
        .process = ast_if_process,
        .destroy = ast_if_destroy
    };
    return functions;
}

ast_node_t* create_ast_if_node(){

    return NULL;
}
