#ifndef _ASSIGNATION_H_523d13776f1dd05aef9d14fb4830e7cbb9d4cd46
#define _ASSIGNATION_H_523d13776f1dd05aef9d14fb4830e7cbb9d4cd46

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"

ast_node_t* create_ast_assignation_node(char* var_name, ast_node_t* value, int line_no);

#endif