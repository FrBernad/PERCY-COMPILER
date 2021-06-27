#ifndef _DEFINITION_H_6f13a91313e05e8c47d49eed0b3457fe6d56446d
#define _DEFINITION_H_6f13a91313e05e8c47d49eed0b3457fe6d56446d

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"

ast_node_t* create_ast_definition_node(int type, char* name, ast_node_t* value, int line_no);

#endif