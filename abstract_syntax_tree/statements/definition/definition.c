#include "definition.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct ast_definition_node {
    int type;

    int value_type;

    char * symbol;    
    ast_node_t* value;


} ast_definition_node_t;

static ast_node_t * ast_definition_process() {
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

ast_node_t* create_ast_definition_node(int type, char* symbol, ast_node_t* value) {
    printf("NEW DEFINITION!\nVariable named: %s\n", symbol);

    ast_definition_node_t* definition_node = malloc(sizeof(*definition_node));

    definition_node->type = DECLARATION_TK;

    definition_node->value_type = type;
    definition_node->symbol = symbol;
    definition_node->value = value;

    return (ast_node_t*)definition_node;
}
