#include "ast_functions.h"

#include <stdio.h>

void execute_ast(ast_node_t* ast) {
    execute_node(ast);
}

ast_node_t* execute_node(ast_node_t* node){
    if(node==NULL){
        return NULL;
    }

    return node->process(node);
}

void free_ast(ast_node_t* node) {
    free_node(node);
}

void free_node(ast_node_t* node) {
    if (node == NULL) {
        return;
    }
    node->destroy(node);
}
