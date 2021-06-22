#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"

typedef struct ast_function_node {
    
    int type;

    char* name;
    ast_node_t* statements;

} ast_function_node_t;

ast_functions_t ast_function_provider();
ast_node_t* create_ast_function_node(char* function_name, ast_node_t* statements);

#endif