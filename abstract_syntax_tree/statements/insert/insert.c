#include "insert.h"

#include <stdio.h>
#include <stdlib.h>

#include "abstract_syntax_tree/ast_functions/ast_functions.h"
#include "compiler_utils/element_list/element_list.h"
#include "error_handler/error_handler.h"
#include "hash_maps/variables_hash_map/variables_hash_map.h"

typedef struct ast_insert_node {
    int type;
    int line_no;

    ast_node_t* (*process)(ast_node_t* node);
    void (*destroy)(ast_node_t* node);

    char* insert_dest;
    char* insert_src;

} ast_insert_node_t;

static ast_node_t* ast_insert_process(ast_node_t* node) {
    ast_insert_node_t* insert_node = (ast_insert_node_t*)node;

    var_t* insert_dest = variables_hash_map_get(insert_node->insert_dest);
    var_t* insert_src = variables_hash_map_get(insert_node->insert_src);

    if (insert_dest == NULL) {
        handle_error("insert operation destination is not defined",node->line_no);
    }

    if (insert_src == NULL) {
        handle_error("insert operation source is not defined", node->line_no);
    }

    if (insert_dest->type != ELEMENT_TYPE) {
        handle_error("insert operation destination is not of element type", node->line_no);
    }

    if (insert_src->type != ELEMENT_TYPE) {
        handle_error("insert operation source is not of element type", node->line_no);
    }

    element_t* src_tag = insert_src->value.tag;
    element_t* dest_tag = insert_dest->value.tag;

    if(dest_tag->child_elements == NULL){
        init_elements_list(&dest_tag->child_elements);
    }

    insert_element(dest_tag, src_tag);

    return NULL;
}
static void ast_insert_destroy(ast_node_t * node) {
    ast_insert_node_t* insert_node = (ast_insert_node_t*)node;
    free(insert_node);
}

ast_node_t* create_ast_insert_node(char* insert_dest, char* insert_src, int line_no) {
    ast_insert_node_t* insert_node = malloc(sizeof(*insert_node));
    if (insert_node == NULL) {
        handle_os_error("malloc failed");
    }

    insert_node->type = INSERT_MT_TK;
    insert_node->line_no = line_no;
    insert_node->process = ast_insert_process;
    insert_node->destroy = ast_insert_destroy;

    insert_node->insert_dest = insert_dest;
    insert_node->insert_src = insert_src;

    return (ast_node_t*)insert_node;
}
