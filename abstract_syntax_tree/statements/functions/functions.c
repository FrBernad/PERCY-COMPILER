#include "functions.h"

#include <stdlib.h>

#include "error_handler/error_handler.h"

static ast_node_t* ast_function_process(ast_node_t* node) {
    return NULL;
}

static void ast_function_destroy(ast_node_t* node) {
    ast_function_node_t* function_node = (ast_function_node_t*) node;

    free_node(function_node->statements);
    free(function_node);
}

ast_node_t* create_ast_function_node(char* function_name, ast_node_t* statements, char* render_var, int line_no) {
    ast_function_node_t* function_node = malloc(sizeof(*function_node));
    if (function_node == NULL) {
        handle_os_error("malloc failed");
    }

    function_node->type = FUNCTION_TK;
    function_node->line_no = line_no;
    function_node->process = ast_function_process;
    function_node->destroy = ast_function_destroy;
    
    function_node->name = function_name;
    function_node->statements = statements;
    function_node->render_var = render_var;

    return (ast_node_t*)function_node;
}
