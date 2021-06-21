#include "for.h"

static void ast_for_process() {
}

static void ast_for_destroy() {
}

ast_functions_t ast_for_provider() {
    ast_functions_t functions = {
        .process = ast_for_process,
        .destroy = ast_for_destroy};
    return functions;
}

ast_node_t* create_ast_for_node(){
    return NULL;
}
