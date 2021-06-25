#include "for.h"

#include <stdio.h>
#include <stdlib.h>

#include "abstract_syntax_tree/statements/values/values.h"

typedef struct ast_for_node {
    int type;
    ast_node_t* (*process)(ast_node_t* node);
    void (*destroy)(ast_node_t* node);

    ast_node_t* first_assignment;
    ast_node_t* condition;
    ast_node_t* statements;
    ast_node_t* for_assignment;

} ast_for_node_t;

static ast_node_t* ast_for_process(ast_node_t* node) {
    ast_for_node_t* for_node = (ast_for_node_t*)node;

    if (for_node->first_assignment != NULL) {
        execute_node(for_node->first_assignment);
    }

    int val;

    ast_node_t* int_node = execute_node(for_node->condition);
    val = ast_int_value_get(int_node);
    if (for_node->condition->type != INT_VALUE && for_node->condition->type != ID) {
        free_node(int_node);
    }

    while (val) {
        if (for_node->statements != NULL) {
            execute_node(for_node->statements);
        }
        if (for_node->for_assignment != NULL) {
            execute_node(for_node->for_assignment);
        }

        int_node = execute_node(for_node->condition);
        val = ast_int_value_get(int_node);
        if (for_node->condition->type != INT_VALUE && for_node->condition->type != ID) {
            free_node(int_node);
        }

    }

    return NULL;
}

static void ast_for_destroy(ast_node_t* node) {
    ast_for_node_t* for_node = (ast_for_node_t*)node;

    free_node(for_node->first_assignment);
    free_node(for_node->condition);
    free_node(for_node->statements);
    free_node(for_node->for_assignment);

    free(for_node);
}

ast_node_t* create_ast_for_node(ast_node_t* first_assignment, ast_node_t* condition, ast_node_t* statements, ast_node_t* for_assignment) {
    ast_for_node_t* for_node = malloc(sizeof(*for_node));

    for_node->type = FOR;
    for_node->process = ast_for_process;
    for_node->destroy = ast_for_destroy;

    for_node->first_assignment = first_assignment;
    for_node->statements = statements;
    for_node->condition = condition;
    for_node->for_assignment = for_assignment;

    return (ast_node_t*)for_node;
}
