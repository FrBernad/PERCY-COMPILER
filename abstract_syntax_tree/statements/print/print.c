#include "print.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "abstract_syntax_tree/statements/values/values.h"
#include "hash_maps/variables_hash_map/variables_hash_map.h"

typedef struct ast_print_node {
    int type;
    ast_node_t* (*process)(ast_node_t* node);
    void (*destroy)();

    ast_node_t* value;

} ast_print_node_t;

static void print_reference_value(ast_value_node_t* value);

static ast_node_t* ast_print_process(ast_node_t* node) {
    ast_print_node_t* print_node = (ast_print_node_t*)node;

    ast_value_node_t* value = (ast_value_node_t*)print_node->value;

    switch (value->type) {
        case INT_VALUE:
            printf("%d", value->value.num);
            break;
        case STRING_VALUE:
            if (strcmp(value->value.str, "\\n") == 0) {
                putchar('\n');
            } else {
                printf("%s", value->value.str);
            }
            break;
        case ID:
            print_reference_value(value);
            break;
        default:
            break;
    }

    return NULL;
}

static void print_reference_value(ast_value_node_t* value) {
    var_t* var = variables_hash_map_get(value->value.reference);
    if (var == NULL) {
        printf("error la variable no existe!\n");
        return;
    }

    switch (var->type) {
        case INT_TYPE:
            printf("%d", var->value.num);
            break;
        case STRING_TYPE:
            printf("%s", var->value.str);
            break;
        case ELEMENT_TYPE:
            printf("%s", var->value.tag->name);
            break;
        default:
            printf("unknown type\n");
            break;
    }
}

static void ast_print_destroy() {
}

ast_node_t* create_ast_print_node(ast_node_t* value) {
    ast_print_node_t* print_node = malloc(sizeof(*print_node));

    print_node->type = PRINT;
    print_node->process = ast_print_process;
    print_node->destroy = ast_print_destroy;

    print_node->value = value;

    return (ast_node_t*)print_node;
}
