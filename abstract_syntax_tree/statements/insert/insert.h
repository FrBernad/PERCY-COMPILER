#ifndef _INSERT_H_79020ceb9d9889cabea4fdb4c88bbe15a3a24eeb
#define _INSERT_H_79020ceb9d9889cabea4fdb4c88bbe15a3a24eeb

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"

ast_node_t* create_ast_insert_node(char* insert_dest, char* insert_src, int line_no);

#endif