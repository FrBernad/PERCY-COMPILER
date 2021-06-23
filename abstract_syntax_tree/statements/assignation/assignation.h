#ifndef _ASSIGNATION_H_
#define _ASSIGNATION_H_

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"

ast_node_t* create_ast_assignation_node(char* var_name, ast_node_t* value);

#endif