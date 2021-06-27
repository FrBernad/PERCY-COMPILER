#ifndef _DO_WHILE_H_a98ed4066043a5e559a47c2080f1132cf0f2a335
#define _DO_WHILE_H_a98ed4066043a5e559a47c2080f1132cf0f2a335

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"

ast_node_t* create_ast_do_while_node(ast_node_t* condition, ast_node_t* statements, int line_no);

#endif