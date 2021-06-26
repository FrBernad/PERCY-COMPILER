#include "do_while.h"

#include <stdio.h>
#include <stdlib.h>

#include "abstract_syntax_tree/statements/values/values.h"
#include "error_handler/error_handler.h"

typedef struct ast_do_while_node {
    int type;
    int line_no;

    ast_node_t* (*process)(ast_node_t* node);
    void (*destroy)(ast_node_t* node);

    ast_node_t* condition;
    ast_node_t* statements;

} ast_do_while_node_t;

static ast_node_t* ast_do_while_process(ast_node_t* node) {
    ast_do_while_node_t* do_while_node = (ast_do_while_node_t*)node;
    int val;
    do {
        if (do_while_node->statements != NULL) {
            execute_node(do_while_node->statements);
        }
        ast_node_t* int_node = execute_node(do_while_node->condition);
        val = ast_int_value_get(int_node);
        if (do_while_node->condition->type != INT_VALUE && do_while_node->condition->type != ID) {
            free_node(int_node);
        }
    } while (val);
    return NULL;
}

static void ast_do_while_destroy(ast_node_t* node) {
    ast_do_while_node_t* do_while_node = (ast_do_while_node_t*)node;

    free_node(do_while_node->condition);
    free_node(do_while_node->statements);

    free(do_while_node);
}

ast_node_t* create_ast_do_while_node(ast_node_t* condition, ast_node_t* statements, int line_no) {
    ast_do_while_node_t* do_while_node = malloc(sizeof(*do_while_node));
    if (do_while_node == NULL) {
        handle_os_error("malloc failed");
    }

    do_while_node->type = DO;
    do_while_node->line_no = line_no;
    do_while_node->process = ast_do_while_process;
    do_while_node->destroy = ast_do_while_destroy;

    do_while_node->condition = condition;
    do_while_node->statements = statements;

    return (ast_node_t*)do_while_node;
}
