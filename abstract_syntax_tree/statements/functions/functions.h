#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"

typedef struct ast_function_node {
    int type;
    int line_no;

    ast_node_t* (*process)(ast_node_t* node);
    void (*destroy)(ast_node_t* node);

    char* name;
    ast_node_t* statements;
    char* render_var;
} ast_function_node_t;

ast_node_t* create_ast_function_node(char* function_name, ast_node_t* statements, char* render_var, int line_no);

#endif