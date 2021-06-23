#ifndef _INSERT_H_
#define _INSERT_H_

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"

ast_node_t* create_ast_insert_node(char* insert_dest, char* insert_src);

#endif