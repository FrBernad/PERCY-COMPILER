#ifndef _FOR_H
#define _FOR_H

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"

ast_node_t* create_ast_for_node(ast_node_t* first_assignment, ast_node_t* condition, ast_node_t* statements, ast_node_t* for_assignment);

#endif