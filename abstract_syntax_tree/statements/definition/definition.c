#include "definition.h"

#include <stdio.h>
#include <stdlib.h>

#include "abstract_syntax_tree/statements/values/values.h"
#include "error_handler/error_handler.h"
#include "hash_maps/variables_hash_map/variables_hash_map.h"
#include "y.tab.h"

typedef struct ast_definition_node {
    int type;
    int line_no;

    ast_node_t* (*process)(ast_node_t* node);
    void (*destroy)(ast_node_t* node);

    int value_type;

    char* var_name;
    ast_node_t* value;

} ast_definition_node_t;

static ast_node_t* ast_definition_process(ast_node_t* node) {
    ast_definition_node_t* definition = (ast_definition_node_t*)node;

    var_t* var = variables_hash_map_put(definition->var_name, definition->value_type);

    if (var == NULL) {
        handle_error("redefinition of variable", node->line_no);
    }

    switch (definition->value_type) {
        case INT_TYPE:
            var->value.num = ast_int_value_get(definition->value);
            break;
        case STRING_TYPE:
            var->value.str = ast_string_value_get(definition->value);
            break;
        case ELEMENT_TYPE:
            var->value.tag = ast_tag_value_get(definition->value);
            break;
        default:
            handle_error("invalid variable type", node->line_no);
            break;
    }

    return NULL;
}

static void ast_definition_destroy(ast_node_t* node) {
    ast_definition_node_t* definition = (ast_definition_node_t*)node;
    free_node(definition->value);
    free(definition);
}

ast_node_t* create_ast_definition_node(int type, char* name, ast_node_t* value, int line_no) {
    ast_definition_node_t* definition_node = malloc(sizeof(*definition_node));
    if (definition_node == NULL) {
        handle_os_error("malloc failed");
    }

    definition_node->type = DEFINITION_TK;
    definition_node->line_no = line_no;
    definition_node->process = ast_definition_process;
    definition_node->destroy = ast_definition_destroy;

    definition_node->value_type = type;
    definition_node->var_name = name;
    definition_node->value = value;

    return (ast_node_t*)definition_node;
}
