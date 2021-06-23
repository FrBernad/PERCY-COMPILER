#include "declaration.h"

#include <stdio.h>
#include <stdlib.h>

#include "abstract_syntax_tree/statements/values/values.h"
#include "hash_maps/variables_hash_map/variables_hash_map.h"
#include "y.tab.h"

static ast_node_t* ast_declaration_process(ast_node_t* node) {
    ast_declaration_node_t* declaration = (ast_declaration_node_t*)node;

    var_t* var = variables_hash_map_put(declaration->var_name, declaration->value_type);

    if (var == NULL) {
        printf("Redeclaration of variable\n");
    }
    
    printf("Var declaration: name: %s\ttype: %d\n", declaration->var_name, declaration->value_type);

    return NULL;
}

static void ast_declaration_destroy() {
}

ast_node_t* create_ast_declaration_node(int type, char* var_name) {
    ast_declaration_node_t * declaration_node = malloc(sizeof(*declaration_node));

    declaration_node->type = DECLARATION_TK;
    declaration_node->process = ast_declaration_process;
    declaration_node->destroy = ast_declaration_destroy;

    declaration_node->value_type = type;
    declaration_node->var_name = var_name;

    return (ast_node_t*)declaration_node;
}
