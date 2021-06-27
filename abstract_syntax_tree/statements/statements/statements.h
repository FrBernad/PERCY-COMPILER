#ifndef _STATEMENTS_H_f7c3722066b6b485f0fe1c898da025ad26be3cfa
#define _STATEMENTS_H_f7c3722066b6b485f0fe1c898da025ad26be3cfa

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"

ast_node_t* create_ast_statements_node(ast_node_t* left, ast_node_t* right, int line_no);

#endif