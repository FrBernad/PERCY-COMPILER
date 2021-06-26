#ifndef _DECLARATION_H_b783d967b70dcb43bb61225c2dedbe0b7a1d630e
#define _DECLARATION_H_b783d967b70dcb43bb61225c2dedbe0b7a1d630e

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"

typedef struct ast_declaration_node {
    int type;
    int line_no;

    ast_node_t* (*process)(ast_node_t* node);
    void (*destroy)(ast_node_t* node);

    int value_type;
    char* var_name;
} ast_declaration_node_t;

ast_node_t* create_ast_declaration_node(int type, char* var_name, int line_no);

#endif