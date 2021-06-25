#include "while.h"

#include <stdio.h>
#include <stdlib.h>

#include "abstract_syntax_tree/statements/values/values.h"

typedef struct ast_while_node {
    int type;
    ast_node_t* (*process)(ast_node_t* node);
    void (*destroy)();

    ast_node_t* condition;
    ast_node_t* statements;

} ast_while_node_t;

static ast_node_t* ast_while_process(ast_node_t* node) {
    ast_while_node_t* while_node = (ast_while_node_t*)node;

    while (ast_int_value_get(execute_node(while_node->condition))) {
        if (while_node->statements != NULL) {
            execute_node(while_node->statements);
        }
    }
    return NULL;
}

static void ast_while_destroy() {
}

ast_node_t* create_ast_while_node(ast_node_t* condition, ast_node_t* statements) {
    ast_while_node_t* while_node = malloc(sizeof(*while_node));

    while_node->type = WHILE;
    while_node->process = ast_while_process;
    while_node->destroy = ast_while_destroy;

    while_node->condition = condition;
    while_node->statements = statements;

    return (ast_node_t*)while_node;
}
