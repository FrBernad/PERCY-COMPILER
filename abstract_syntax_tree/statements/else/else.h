#ifndef _ELSE_H
#define _ELSE_H

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"

ast_functions_t ast_else_provider();
ast_node_t* create_ast_else_node();

#endif