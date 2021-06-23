#include "ast_functions.h"

#include <stdio.h>

void execute_ast(ast_node_t* ast) {
    execute_node(ast);
}

ast_node_t* execute_node(ast_node_t* node){
    if(node==NULL){
        return NULL;
    }
    printf("node type:%d\n",node->type);
    return node->process(node);
}
