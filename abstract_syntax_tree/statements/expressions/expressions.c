#include "expressions.h"

#include <stdio.h>
#include <stdlib.h>

#include "abstract_syntax_tree/statements/values/values.h"

static int process_expression_value(int left, int right, int type);

// ---

static ast_node_t* ast_exp_process(ast_node_t* node) {
    int left = ast_int_value_get(execute_node(node->left));
    int right = ast_int_value_get(execute_node(node->right));

    return create_ast_int_node(process_expression_value(left, right, node->type));
}

static void ast_exp_destroy() {
}

// ---

ast_node_t* create_ast_expression_node(int type, ast_node_t* left, ast_node_t* right) {
    ast_expression_node_t* exp_node = malloc(sizeof(*exp_node));

    exp_node->type = type;
    exp_node->process = ast_exp_process;
    exp_node->destroy = ast_exp_destroy;

    exp_node->left = left;
    exp_node->right = right;

    return (ast_node_t*)exp_node;
}


static int process_expression_value(int left, int right, int type) {
    printf("type %d\n",type);
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
            printf("Expression not recognized\n");
            break;
    }

    return ret_val;
}
