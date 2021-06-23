#ifndef _TAGS_H
#define _TAGS_H

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"

typedef struct ast_tag_node {
    int type;
    ast_node_t* (*process)(ast_node_t* node);
    void (*destroy)();

    char * body;
} ast_tag_node_t;

ast_node_t* create_ast_html_tag_node();
ast_node_t* create_ast_navbar_tag_node();
ast_node_t* create_ast_footer_tag_node();
ast_node_t* create_ast_container_tag_node();
ast_node_t* create_ast_header_tag_node();

#endif