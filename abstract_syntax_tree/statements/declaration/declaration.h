#ifndef _DECLARATION_H_b783d967b70dcb43bb61225c2dedbe0b7a1d630e
#define _DECLARATION_H_b783d967b70dcb43bb61225c2dedbe0b7a1d630e

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"

typedef struct ast_declaration_node {
    int type;

    struct ast_node* symbol;
    struct ast_node* value;

} ast_declaration_node_t;

ast_functions_t ast_declaration_provider();

ast_node_t* create_ast_declaration_node(int type, char* symbol);

#endif