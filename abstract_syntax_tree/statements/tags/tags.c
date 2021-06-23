#include "tags.h"

#include <stdlib.h>

static ast_node_t* ast_tags_process(ast_node_t* node) {
    return NULL;
}

static void ast_tags_destroy() {
}

ast_node_t* create_ast_html_tag_node() {
    ast_tag_node_t* tag_node = malloc(sizeof(*tag_node));
    tag_node->type = HTML;
    tag_node->process = ast_tags_process;
    tag_node->destroy = ast_tags_destroy;

    tag_node->body = NULL;

    return (ast_node_t*)tag_node;
}

ast_node_t* create_ast_navbar_tag_node(char * body) {
    ast_tag_node_t* tag_node = malloc(sizeof(*tag_node));
    tag_node->type = NAVBAR;
    tag_node->process = ast_tags_process;
    tag_node->destroy = ast_tags_destroy;

    tag_node->body = body;

    return (ast_node_t*)tag_node;
}

ast_node_t* create_ast_footer_tag_node(char * body) {
    ast_tag_node_t* tag_node = malloc(sizeof(*tag_node));
    tag_node->type = FOOTER;
    tag_node->process = ast_tags_process;
    tag_node->destroy = ast_tags_destroy;

    tag_node->body = body;

    return (ast_node_t*)tag_node;
}

ast_node_t* create_ast_container_tag_node(char * body) {
    ast_tag_node_t* tag_node = malloc(sizeof(*tag_node));
    tag_node->type = CONTAINER;
    tag_node->process = ast_tags_process;
    tag_node->destroy = ast_tags_destroy;

    tag_node->body = body;

    return (ast_node_t*)tag_node;
}

ast_node_t* create_ast_header_tag_node(char * body) {
    ast_tag_node_t* tag_node = malloc(sizeof(*tag_node));
    tag_node->type = HEADER;
    tag_node->process = ast_tags_process;
    tag_node->destroy = ast_tags_destroy;

    tag_node->body = body;

    return (ast_node_t*)tag_node;
}
