#include "statements.h"

#include <stdio.h>
#include <stdlib.h>

#include "abstract_syntax_tree/ast_functions/ast_functions.h"

static ast_node_t* ast_statements_process(ast_node_t* node) {
    printf("ejecturo left\n\n");
    ast_node_t* left_statements = execute_node(node->left);
    printf("ejecturo right\n\n");
    return execute_node(node->right);
}

static void ast_statements_destroy() {
}

ast_functions_t ast_statements_provider() {
    ast_functions_t functions = {
        .process = ast_statements_process,
        .destroy = ast_statements_destroy};

    return functions;
}

ast_node_t* create_ast_statements_node(ast_node_t* left, ast_node_t* right) {
    ast_node_t* ast_node = malloc(sizeof(*ast_node));

    ast_node->type = STATEMENTS_TK;
    ast_node->left = left;
    ast_node->right = right;

    return ast_node;
}
