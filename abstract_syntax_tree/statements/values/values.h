#ifndef _VALUES_H
#define _VALUES_H

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"
#include "compiler_utils/element_list/element_list.h"

typedef struct ast_value_node {
    int type;
    int line_no;

    ast_node_t* (*process)(ast_node_t* node);
    void (*destroy)(ast_node_t* node);

    union {
        char* str;
        int num;
        ast_node_t* tag;
        ast_node_t* exp;
        char* reference;
    } value;
} ast_value_node_t;

ast_node_t* ast_value_process(ast_node_t* node);

char* ast_string_value_get(ast_node_t* node);
int ast_int_value_get(ast_node_t* node);
element_t* ast_tag_value_get(ast_node_t* node);
char* ast_reference_value_get(ast_node_t* node);

ast_node_t* create_ast_tag_node(ast_node_t* tag, int line_no);
ast_node_t* create_ast_int_node(int value, int line_no);
ast_node_t* create_ast_string_node(char* s, int line_no);
ast_node_t* create_ast_reference_node(char* symbol, int line_no);
ast_node_t* create_ast_exp_node(ast_node_t* exp, int line_no);

#endif