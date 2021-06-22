#include "tags.h"

#include <stdlib.h>

static ast_node_t* ast_tags_process(ast_node_t* node) {
    return NULL;
}

static void ast_tags_destroy() {
}

ast_functions_t ast_tags_provider() {
    ast_functions_t functions = {
        .process = ast_tags_process,
        .destroy = ast_tags_destroy};
    return functions;
}

ast_node_t* create_ast_html_tag_node() {
    ast_tag_node_t* tag_node = malloc(sizeof(*tag_node));
    tag_node->type = HTML;

    return (ast_node_t*)tag_node;
}

ast_node_t* create_ast_navbar_tag_node() {
    ast_tag_node_t* tag_node = malloc(sizeof(*tag_node));
    tag_node->type = NAVBAR;

    return (ast_node_t*)tag_node;
}

ast_node_t* create_ast_footer_tag_node() {
    ast_tag_node_t* tag_node = malloc(sizeof(*tag_node));
    tag_node->type = FOOTER;

    return (ast_node_t*)tag_node;
}

ast_node_t* create_ast_container_tag_node() {
    ast_tag_node_t* tag_node = malloc(sizeof(*tag_node));
    tag_node->type = CONTAINER;

    return (ast_node_t*)tag_node;
}

ast_node_t* create_ast_header_tag_node() {
    ast_tag_node_t* tag_node = malloc(sizeof(*tag_node));
    tag_node->type = HEADER;

    return (ast_node_t*)tag_node;
}
