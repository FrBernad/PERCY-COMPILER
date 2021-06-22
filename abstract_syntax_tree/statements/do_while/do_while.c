#include "do_while.h"

static ast_node_t* ast_do_while_process(ast_node_t* node) {
    return NULL;
}

static void ast_do_while_destroy() {
}

ast_functions_t ast_do_while_provider() {
    ast_functions_t functions = {
        .process = ast_do_while_process,
        .destroy = ast_do_while_destroy};
    return functions;
}

ast_node_t* create_ast_do_while_node(){
    return NULL;
}
