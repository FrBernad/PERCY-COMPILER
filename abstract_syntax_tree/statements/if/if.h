#ifndef _IF_H_c095ee96856e07ef9c132102d79f45bc35df0af9
#define _IF_H_c095ee96856e07ef9c132102d79f45bc35df0af9

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"

ast_node_t* create_ast_if_node(ast_node_t* condition, ast_node_t* if_statements, ast_node_t* else_statements, int line_no);

#endif