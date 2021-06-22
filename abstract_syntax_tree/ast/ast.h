#ifndef _AST_H_70c26aab8c288ac95faf1cb588871a176a4913e6
#define _AST_H_70c26aab8c288ac95faf1cb588871a176a4913e6
typedef struct ast_node {
  int type;
  struct ast_node * left;
  struct ast_node * right;
} ast_node_t;

ast_node_t* create_ast_node(ast_node_t* left, ast_node_t * right);

#endif