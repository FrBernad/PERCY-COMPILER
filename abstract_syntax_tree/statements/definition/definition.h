#ifndef _DEFINITION_H_
#define _DEFINITION_H_

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"

ast_node_t* create_ast_definition_node(int type, char* name, ast_node_t* value);

#endif