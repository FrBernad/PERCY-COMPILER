#ifndef _WHILE_H
#define _WHILE_H

#include "abstract_syntax_tree/ast_functions/ast_functions.h"
#include "abstract_syntax_tree/ast/ast.h"

ast_functions_t ast_while_provider();
ast_node_t* create_ast_while_node();

#endif