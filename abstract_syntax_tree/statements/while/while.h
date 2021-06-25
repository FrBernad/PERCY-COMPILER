#ifndef _WHILE_H
#define _WHILE_H

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"

ast_node_t* create_ast_while_node(ast_node_t* condition, ast_node_t* statements);

#endif