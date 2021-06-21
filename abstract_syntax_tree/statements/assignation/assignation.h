#ifndef _ASSIGNATION_H_
#define _ASSIGNATION_H_

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"

ast_functions_t ast_assignation_provider();

ast_node_t* create_ast_assignation_node(char* symbol, ast_node_t * tag);

#endif