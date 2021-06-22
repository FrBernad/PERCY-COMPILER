#include "definition.h"

#include <stdio.h>
#include <stdlib.h>

#include "abstract_syntax_tree/statements/values/values.h"
#include "hash_maps/variables_hash_map/variables_hash_map.h"
#include "y.tab.h"

typedef struct ast_definition_node {
    int type;

    int value_type;

    char* var_name;
    ast_node_t* value;

} ast_definition_node_t;

static ast_node_t* ast_definition_process(ast_node_t* node) {
    ast_definition_node_t* definition = (ast_definition_node_t*)node;

    var_t* var = variables_hash_map_put(definition->var_name, definition->value_type);

    if (var == NULL) {
        printf("Redefinition of variable");
    }
    printf("Var definition: name: %s\ttype: %d\n", definition->var_name, definition->value_type);

    switch (definition->value_type) {
        case INT_VALUE:
            var->value.num = ast_int_value_process(definition->value);
            break;
        case STRING_VALUE:
            var->value.str = ast_string_value_process(definition->value);
            break;
        case ELEMENT_TYPE:
            var->value.tag = ast_tag_value_process(definition->value);
            break;
        case ID:
            var->value.reference = ast_reference_value_process(definition->value);
            break;
        default:
            printf("Invalid type");
            break;
    }

    return NULL;
}

static void ast_definition_destroy() {
}

ast_functions_t ast_definition_provider() {
    ast_functions_t functions = {
        .process = ast_definition_process,
        .destroy = ast_definition_destroy};

    return functions;
}

ast_node_t* create_ast_definition_node(int type, char* name, ast_node_t* value) {

    ast_definition_node_t* definition_node = malloc(sizeof(*definition_node));

    definition_node->type = DEFINITION_TK;

    definition_node->value_type = type;
    definition_node->var_name = name;
    definition_node->value = value;

    return (ast_node_t*)definition_node;
}
