#include "while.h"

static void ast_while_process() {
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
