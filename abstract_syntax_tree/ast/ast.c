#include "ast.h"

#include "y.tab.h"

#include <stdlib.h>

ast_node_t* create_ast_node(ast_node_t* left, ast_node_t * right){
    
    ast_node_t* ast_node = malloc(sizeof(*ast_node));

    ast_node->type = STATEMENTS_TK;
    ast_node->left = left;
    ast_node->right = right;

    return ast_node;
}
