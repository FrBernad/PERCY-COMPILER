#include "declaration.h"

static ast_node_t* ast_declaration_process(ast_node_t* node) {
    // ast_declaration_node_t* declaration = (ast_declaration_node_t*)node;

    return NULL;
}

static void ast_declaration_destroy() {
}

ast_functions_t ast_declaration_provider() {
    ast_functions_t functions = {
        .process = ast_declaration_process,
        .destroy = ast_declaration_destroy};

    return functions;
}

ast_node_t* create_ast_declaration_node(int type, char* symbol) {
    //fijarse que no este declarada y si no lo esta crearla
    return NULL;
}
