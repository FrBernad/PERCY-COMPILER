#ifndef _TAGS_H_e386ae97e33f640db08e7aa30eb7447b902c69bd
#define _TAGS_H_e386ae97e33f640db08e7aa30eb7447b902c69bd

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"

typedef struct ast_tag_node {
    int type;
    int line_no;

    ast_node_t* (*process)(ast_node_t* node);
    void (*destroy)(ast_node_t* node);

    ast_node_t * body;
} ast_tag_node_t;

ast_node_t* create_ast_html_tag_node(int type, ast_node_t* body, int line_no);

#endif