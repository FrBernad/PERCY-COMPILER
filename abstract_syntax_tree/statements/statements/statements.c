#include "statements.h"

#include <stdio.h>
#include <stdlib.h>

#include "abstract_syntax_tree/ast_functions/ast_functions.h"

static ast_node_t* ast_statements_process(ast_node_t* node) {
    execute_node(node->left);
    return execute_node(node->right);
}

static void ast_statements_destroy(ast_node_t * node) {
    free_node(node->left);
    free_node(node->right);

    free(node);
}

ast_node_t* create_ast_statements_node(ast_node_t* left, ast_node_t* right) {
    ast_node_t* statements_node = malloc(sizeof(*statements_node));

    statements_node->type = STATEMENTS_TK;
    statements_node->process = ast_statements_process;
    statements_node->destroy = ast_statements_destroy;

    statements_node->left = left;
    statements_node->right = right;

    return statements_node;
}
