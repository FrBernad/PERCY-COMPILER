#ifndef _IF_H
#define _IF_H

#include "abstract_syntax_tree/ast_functions/ast_functions.h"
#include "abstract_syntax_tree/ast/ast.h"


ast_functions_t ast_if_provider();
ast_node_t* create_ast_if_node();

#endif