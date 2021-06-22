#include "functions.h"

#include <stdlib.h>

static ast_node_t* ast_function_process(ast_node_t* node) {
    return NULL;
}

static void ast_function_destroy() {
}

ast_functions_t ast_function_provider() {
    ast_functions_t functions = {
        .process = ast_function_process,
        .destroy = ast_function_destroy};

    return functions;
}

ast_node_t* create_ast_function_node(char* function_name, ast_node_t* statements, char* render_var) {
    ast_function_node_t* function_node = malloc(sizeof(*function_node));

    function_node->type = FUNCTION_TK;

    function_node->name = function_name;
    function_node->statements = statements;
    function_node->render_var = render_var;

    return (ast_node_t*)function_node;
}
