#include "declaration.h"

#include <stdio.h>
#include <stdlib.h>

#include "abstract_syntax_tree/statements/values/values.h"
#include "error_handler/error_handler.h"
#include "hash_maps/variables_hash_map/variables_hash_map.h"

static ast_node_t* ast_declaration_process(ast_node_t* node) {
    ast_declaration_node_t* declaration = (ast_declaration_node_t*)node;

    var_t* var = variables_hash_map_put(declaration->var_name, declaration->value_type);

    if (var == NULL) {
        handle_error("redeclaration of variable",node->line_no);
    }
    
    return NULL;
}

static void ast_declaration_destroy(ast_node_t* node) {
    ast_declaration_node_t* declaration = (ast_declaration_node_t*)node;
    free(declaration);
}

ast_node_t* create_ast_declaration_node(int type, char* var_name, int line_no) {
    ast_declaration_node_t * declaration_node = malloc(sizeof(*declaration_node));
    if (declaration_node == NULL) {
        handle_os_error("malloc failed");
    }

    declaration_node->type = DECLARATION_TK;
    declaration_node->line_no = line_no;
    declaration_node->process = ast_declaration_process;
    declaration_node->destroy = ast_declaration_destroy;

    declaration_node->value_type = type;
    declaration_node->var_name = var_name;

    return (ast_node_t*)declaration_node;
}
