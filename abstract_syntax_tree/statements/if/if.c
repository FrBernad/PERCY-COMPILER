#include "if.h"

#include <stdlib.h>
#include <stdio.h>

#include "abstract_syntax_tree/statements/values/values.h"

typedef struct ast_if_node {
    int type;
    ast_node_t* (*process)(ast_node_t* node);
    void (*destroy)();

    ast_node_t* if_condition;
    ast_node_t* if_statements;
    ast_node_t* else_statements;

} ast_if_node_t;

static ast_node_t* ast_if_process(ast_node_t* node) {
    ast_if_node_t* if_node = (ast_if_node_t*)node;
    if (ast_int_value_get(execute_node(if_node->if_condition))) {
        if(if_node->if_statements!=NULL){
            execute_node(if_node->if_statements);
        }
    }else if(if_node->else_statements!=NULL){
        execute_node(if_node->else_statements);
    }
    return NULL;
}

static void ast_if_destroy() {
}

ast_node_t* create_ast_if_node(ast_node_t* condition, ast_node_t* if_statements, ast_node_t* else_statements) {
    ast_if_node_t* if_node = malloc(sizeof(*if_node));

    if_node->type = IF;
    if_node->process = ast_if_process;
    if_node->destroy = ast_if_destroy;

    if_node->if_condition = condition;
    if_node->if_statements = if_statements;
    if_node->else_statements = else_statements;

    return (ast_node_t*)if_node;
}
