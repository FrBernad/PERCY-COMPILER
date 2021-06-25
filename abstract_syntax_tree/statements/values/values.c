#include "values.h"

#include <stdio.h>
#include <stdlib.h>

#include "abstract_syntax_tree/statements/tags/tags.h"
#include "compiler_utils/lex_utils/lex_utils.h"
#include "abstract_syntax_tree/statements/expressions/expressions.h"
#include "hash_maps/variables_hash_map/variables_hash_map.h"

// STRING VALUE
ast_node_t *ast_value_process(ast_node_t *node) {
    return node;
}

char *ast_string_value_get(ast_node_t *node) {
    ast_value_node_t *value_node = (ast_value_node_t *) node;

    if (node->type == ID) {
        var_t *var = variables_hash_map_get(value_node->value.reference);
        if (var == NULL) {
            printf("error la variable no es de tipo string!\n");
        }

        if(var->type==STRING_TYPE){
            return var->value.str;
        }

        if (var->type == INT_TYPE) {
            char aux[20] = {0};
            return new_lex_string(aux, sprintf(aux,"%d", var->value.num));
        }
        printf("error la variable no es de tipo stringgg!\n");

        return NULL;
    }

    if (node->type == STRING_VALUE) {
        return value_node->value.str;
    }

    if (node->type == INT_VALUE) {
        char aux[20] = {0};
        return new_lex_string(aux, sprintf(aux,"%d", value_node->value.num));
    }

    printf("ERRORR STRING VLUE!!!!!!\n\n");

    return NULL;
}

static void ast_string_value_destroy(ast_node_t *node) {
    ast_value_node_t *value_node = (ast_value_node_t *) node;
    free(value_node);
}

// INT VALUE
static void ast_int_value_destroy(ast_node_t *node) {
    ast_value_node_t *value_node = (ast_value_node_t *) node;
    free(value_node);
}

int ast_int_value_get(ast_node_t *node) {
    ast_value_node_t *value_node = (ast_value_node_t *) node;

    if (node->type == ID) {
        var_t *var = variables_hash_map_get(value_node->value.reference);
        if (var == NULL || var->type != INT_TYPE) {
            printf("error la variable no es de tipo int!\n");
        }
        return var->value.num;
    }

    if (node->type == EXP_TK) {
        int val;
        ast_node_t *int_node = execute_node(value_node->value.exp);
        val = ast_int_value_get(int_node);
        if (value_node->value.exp->type != INT_VALUE && value_node->value.exp->type != ID) {
            free_node(int_node);
        }
        return val;
    }

    if (node->type == INT_VALUE) {
        return value_node->value.num;
    }

    printf("ERRORR INT VLUE!!!!!!\n\n");

    return 0;
}

//TAG VALUE
element_t *ast_tag_value_get(ast_node_t *node) {
    ast_value_node_t *value_node = (ast_value_node_t *) node;

    ast_tag_node_t *tag = (ast_tag_node_t *) value_node->value.tag;

    element_t *element = create_element(tag);
    printf("new element: tag: %s\n\n", element->name);
    return element;
}

static void ast_tag_value_destroy(ast_node_t *node) {
    ast_value_node_t *value_node = (ast_value_node_t *) node;
    free_node(value_node->value.tag);
    free(value_node);
}

// REFERENCE VALUE
char *ast_reference_value_get(ast_node_t *node) {
    ast_value_node_t *value_node = (ast_value_node_t *) node;
    return value_node->value.reference;
}

static void ast_reference_value_destroy(ast_node_t *node) {
    ast_value_node_t *value_node = (ast_value_node_t *) node;
    free(value_node);
}

// EXPRESSION VALUE
static void ast_exp_value_destroy(ast_node_t *node) {
    ast_value_node_t *value_node = (ast_value_node_t *) node;
    free_node(value_node->value.exp);
    free(value_node);
}

// STRING VALUE
ast_node_t *create_ast_string_node(char *s) {
    ast_value_node_t *string_node = malloc(sizeof(*string_node));
    string_node->type = STRING_VALUE;
    string_node->process = ast_value_process;
    string_node->destroy = ast_string_value_destroy;

    string_node->value.str = s;

    return (ast_node_t *) string_node;
}

// INT VALUE
ast_node_t *create_ast_int_node(int value) {
    ast_value_node_t *int_node = malloc(sizeof(*int_node));
    int_node->type = INT_VALUE;
    int_node->process = ast_value_process;
    int_node->destroy = ast_int_value_destroy;

    int_node->value.num = value;

    return (ast_node_t *) int_node;
}

// TAG VALUE
ast_node_t *create_ast_tag_node(ast_node_t *tag) {
    ast_value_node_t *tag_node = malloc(sizeof(*tag_node));
    tag_node->type = TAG_TK;
    tag_node->process = ast_value_process;
    tag_node->destroy = ast_tag_value_destroy;

    tag_node->value.tag = tag;

    return (ast_node_t *) tag_node;
}

// REFERENCE VALUE
ast_node_t *create_ast_reference_node(char *s) {
    ast_value_node_t *reference_node = malloc(sizeof(*reference_node));
    reference_node->type = ID;
    reference_node->process = ast_value_process;
    reference_node->destroy = ast_reference_value_destroy;

    reference_node->value.reference = s;

    return (ast_node_t *) reference_node;
}

// EXPRESSION VALUE
ast_node_t *create_ast_exp_node(ast_node_t *exp) {
    ast_value_node_t *exp_node = malloc(sizeof(*exp_node));
    exp_node->type = EXP_TK;
    exp_node->process = ast_value_process;
    exp_node->destroy = ast_exp_value_destroy;
    exp_node->value.exp = exp;

    return (ast_node_t *) exp_node;
}