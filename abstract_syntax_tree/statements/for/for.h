#ifndef _FOR_H_19ea46c7ee908ad7cce52ce57ad6f7f3c7096175
#define _FOR_H_19ea46c7ee908ad7cce52ce57ad6f7f3c7096175

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"

ast_node_t* create_ast_for_node(ast_node_t* first_assignment, ast_node_t* condition, ast_node_t* statements, ast_node_t* for_assignment, int line_no);

#endif