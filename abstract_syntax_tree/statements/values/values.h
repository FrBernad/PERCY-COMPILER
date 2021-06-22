#ifndef _VALUES_H
#define _VALUES_H

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"

ast_functions_t ast_string_value_provider();
ast_functions_t ast_int_value_provider();
ast_functions_t ast_tag_value_provider();
ast_functions_t ast_reference_value_provider();

ast_node_t* create_ast_tag_node(ast_node_t* tag);
ast_node_t* create_ast_int_node(int value);
ast_node_t* create_ast_string_node(char* s);
ast_node_t* create_ast_symbol_reference_node(char* symbol);

#endif