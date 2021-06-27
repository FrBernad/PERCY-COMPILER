#ifndef _EXPRESSIONS_H_61877220cee3e6da5fbc4a54084c0e3fcad64a20
#define _EXPRESSIONS_H_61877220cee3e6da5fbc4a54084c0e3fcad64a20

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"

typedef struct ast_expression_node {
    int type;
    int line_no;

    ast_node_t* (*process)(ast_node_t* node);
    void (*destroy)(ast_node_t* node);

    ast_node_t* left;
    ast_node_t* right;
} ast_expression_node_t;

ast_node_t* create_ast_expression_node(int type, ast_node_t* left, ast_node_t* right, int line_no);

#endif