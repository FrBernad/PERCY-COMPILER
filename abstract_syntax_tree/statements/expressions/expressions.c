#include "expressions.h"

#include <stdio.h>
#include <stdlib.h>

#include "abstract_syntax_tree/statements/values/values.h"
#include "error_handler/error_handler.h"

static int process_expression_value(int left, int right, int type, int line_no);

// ---

static ast_node_t* ast_exp_process(ast_node_t* node) {
    ast_node_t* int_node = execute_node(node->left);
    int left = ast_int_value_get(int_node);
    if (node->left->type != INT_VALUE && node->left->type != ID) {
        free_node(int_node);
    }

    int_node = execute_node(node->right);
    int right = ast_int_value_get(int_node);
    if (node->right->type != INT_VALUE && node->right->type != ID) {
        free_node(int_node);
    }

    return create_ast_int_node(process_expression_value(left, right, node->type, node->line_no), node->line_no);
}

static void ast_exp_destroy(ast_node_t* node) {
    ast_expression_node_t* exp_node = (ast_expression_node_t*)node;
    free_node(exp_node->left);
    free_node(exp_node->right);

    free(exp_node);
}

// ---

ast_node_t* create_ast_expression_node(int type, ast_node_t* left, ast_node_t* right, int line_no) {
    ast_expression_node_t* exp_node = malloc(sizeof(*exp_node));
    if (exp_node == NULL) {
        handle_os_error("malloc failed");
    }

    exp_node->type = type;
    exp_node->line_no = line_no;
    exp_node->process = ast_exp_process;
    exp_node->destroy = ast_exp_destroy;

    exp_node->left = left;
    exp_node->right = right;

    return (ast_node_t*)exp_node;
}

static int process_expression_value(int left, int right, int type, int line_no) {
    int ret_val = 0;
    switch (type) {
        case '+':
            ret_val = left + right;
            break;
        case '-':
            ret_val = left - right;
            break;
        case '*':
            ret_val = left * right;
            break;
        case '/':
            ret_val = left / right;
            break;
        case '<':
            ret_val = left < right;
            break;
        case '>':
            ret_val = left > right;
            break;
        case '%':
            ret_val = left % right;
            break;
        case LE:
            ret_val = left <= right;
            break;
        case GE:
            ret_val = left >= right;
            break;
        case EQ:
            ret_val = left == right;
            break;
        case NEQ:
            ret_val = left != right;
            break;
        case OR:
            ret_val = left || right;
            break;
        case AND:
            ret_val = left && right;
            break;
        default:
            handle_error("expression not recognized",line_no);
            break;
    }

    return ret_val;
}
