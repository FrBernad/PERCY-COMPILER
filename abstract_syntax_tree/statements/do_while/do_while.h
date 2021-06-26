#ifndef _DO_WHILE_H
#define _DO_WHILE_H

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"

ast_node_t* create_ast_do_while_node(ast_node_t* condition, ast_node_t* statements, int line_no);

#endif