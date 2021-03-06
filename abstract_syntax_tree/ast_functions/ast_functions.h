#ifndef _AST_FUNCTIONS_H_63002a2ff45778afe3c25bdb1f33dae9e5c080ee
#define _AST_FUNCTIONS_H_63002a2ff45778afe3c25bdb1f33dae9e5c080ee

#include <stddef.h>

#include "abstract_syntax_tree/ast/ast.h"
#include "y.tab.h"

void execute_ast(ast_node_t* ast);
ast_node_t* execute_node(ast_node_t* node);
void free_ast(ast_node_t* node);
void free_node(ast_node_t* node);

#endif