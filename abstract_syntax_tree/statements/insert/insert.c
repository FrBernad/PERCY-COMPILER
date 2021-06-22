#include "insert.h"

#include <stdio.h>
#include <stdlib.h>

#include "hash_maps/variables_hash_map/variables_hash_map.h"
#include "abstract_syntax_tree/ast_functions/ast_functions.h"
#include "compiler_utils/element_list/element_list.h"

typedef struct ast_insert_node {
    int type;

    char* insert_dest;
    char* insert_src;

} ast_insert_node_t;

static ast_node_t* ast_insert_process(ast_node_t* node) {
    ast_insert_node_t* insert = (ast_insert_node_t*)node;

    var_t* insert_dest = variables_hash_map_get(insert->insert_dest);
    var_t* insert_src = variables_hash_map_get(insert->insert_src);

    if (insert_dest == NULL || insert_src == NULL || insert_dest->type != ELEMENT_TYPE || insert_src->type != ELEMENT_TYPE) {
        printf("error en insert\n\n");
        return NULL;
    }

    element_t* src_tag = insert_src->value.tag;
    element_t* dest_tag = insert_dest->value.tag;

    if(dest_tag->child_elements == NULL){
        init_elements_list(&dest_tag->child_elements);
    }

    insert_element(dest_tag,src_tag);

    return NULL;
}
static void ast_insert_destroy() {

}

ast_functions_t ast_insert_provider() {
    ast_functions_t functions = {
        .process = ast_insert_process,
        .destroy = ast_insert_destroy};

    return functions;
}

ast_node_t* create_ast_insert_node(char* insert_dest, char* insert_src) {
    ast_insert_node_t* insert_node = malloc(sizeof(*insert_node));

    insert_node->type = INSERT_MT_TK;
    insert_node->insert_dest = insert_dest;
    insert_node->insert_src = insert_src;

    return (ast_node_t*)insert_node;
}
