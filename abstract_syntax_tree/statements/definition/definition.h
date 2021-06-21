#ifndef _DEFINITION_H_
#define _DEFINITION_H_

#include "abstract_syntax_tree/ast_functions/ast_functions.h"
#include "abstract_syntax_tree/ast/ast.h"

typedef struct ast_definition_node {
  int type;

  struct ast_node * symbol;
  struct ast_node * value;

} ast_definition_node_t;

ast_functions_t ast_definition_provider();

ast_node_t* create_ast_definition_node(int type, char * symbol, ast_node_t * tag);

#endif