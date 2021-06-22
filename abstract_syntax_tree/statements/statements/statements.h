#ifndef _STATEMENTS_H_
#define _STATEMENTS_H_

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"

ast_functions_t ast_statements_provider();

ast_node_t* create_ast_statements_node(ast_node_t* left, ast_node_t* right);

#endif