#ifndef _DO_WHILE_H
#define _DO_WHILE_H

#include "abstract_syntax_tree/ast_functions/ast_functions.h"
#include "abstract_syntax_tree/ast/ast.h"

ast_functions_t ast_do_while_provider();
ast_node_t* create_ast_do_while_node();
#endif