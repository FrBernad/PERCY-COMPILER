#ifndef _WHILE_H_cd5bb2e5e71eb062547a4f1ba1ff5244493d0e79
#define _WHILE_H_cd5bb2e5e71eb062547a4f1ba1ff5244493d0e79

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"

ast_node_t* create_ast_while_node(ast_node_t* condition, ast_node_t* statements, int line_no);

#endif