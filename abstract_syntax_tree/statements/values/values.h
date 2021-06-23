#ifndef _VALUES_H
#define _VALUES_H

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"
#include "compiler_utils/element_list/element_list.h"

typedef struct ast_value_node {
    int type;
    union {
        char* str;
        int num;
        ast_node_t* tag;
        char* reference;
    } value;
} ast_value_node_t;

char* ast_string_value_process(ast_node_t* node);
int ast_int_value_process(ast_node_t* node);
element_t* ast_tag_value_process(ast_node_t* node);
char* ast_reference_value_process(ast_node_t* node);

ast_node_t* create_ast_tag_node(ast_node_t* tag);
ast_node_t* create_ast_int_node(int value);
ast_node_t* create_ast_string_node(char* s);
ast_node_t* create_ast_reference_node(char* symbol);

#endif