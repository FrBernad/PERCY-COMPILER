#include "while.h"

static ast_node_t* ast_while_process(ast_node_t* node) {
    return NULL;
}

static void ast_while_destroy() {
}

ast_functions_t ast_while_provider() {
    ast_functions_t functions = {
        .process = ast_while_process,
        .destroy = ast_while_destroy};
    return functions;
}

ast_node_t* create_ast_while_node(){
    return NULL;
}
