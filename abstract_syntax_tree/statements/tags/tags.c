#include "tags.h"

#include <stdlib.h>

#include "abstract_syntax_tree/statements/values/values.h"
#include "error_handler/error_handler.h"

static ast_node_t* ast_tags_process(ast_node_t* node) {
    return NULL;
}

static void ast_tags_destroy(ast_node_t* node) {
    ast_tag_node_t* tag_node = (ast_tag_node_t*)node;
    if (tag_node->body != NULL) {
        free_node(tag_node->body);
    }
    free(tag_node);
}

ast_node_t* create_ast_html_tag_node(int type, ast_node_t* body, int line_no) {
    ast_tag_node_t* tag_node = malloc(sizeof(*tag_node));
    if (tag_node == NULL) {
        handle_os_error("malloc failed");
    }
    
    tag_node->type = type;
    tag_node->line_no = line_no;

    tag_node->process = ast_tags_process;
    tag_node->destroy = ast_tags_destroy;

    tag_node->body = body;

    return (ast_node_t*)tag_node;
}
