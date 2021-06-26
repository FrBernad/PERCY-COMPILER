#include "assignation.h"

#include <stdio.h>
#include <stdlib.h>

#include "error_handler/error_handler.h"
#include "abstract_syntax_tree/statements/values/values.h"
#include "hash_maps/variables_hash_map/variables_hash_map.h"

typedef struct ast_assignation_node {
    int type;
    int line_no;

    ast_node_t* (*process)(ast_node_t* node);
    void (*destroy)(ast_node_t* node);

    char* var_name;
    ast_node_t* value;

} ast_assignation_node_t;

static ast_node_t* ast_assignation_process(ast_node_t* node) {
    ast_assignation_node_t* assignation = (ast_assignation_node_t*)node;
    
    var_t* var = variables_hash_map_get(assignation->var_name);

    if (var == NULL) {
        handle_error("variable not declared prior to assignation",node->line_no);
    }

    switch (var->type) {
        case INT_TYPE:
            var->value.num = ast_int_value_get(assignation->value);
            break;
        case STRING_TYPE:
            var->value.str = ast_string_value_get(assignation->value);
            break;
        case ELEMENT_TYPE:
            var->value.tag = ast_tag_value_get(assignation->value);
            break;
        default:
            break;
    }

    return NULL;
}

static void ast_assignation_destroy(ast_node_t* node){
    ast_assignation_node_t* assignation_node = (ast_assignation_node_t*)node;
    free_node(assignation_node->value);
    free(assignation_node);
}

ast_node_t* create_ast_assignation_node(char* var_name, ast_node_t* value, int line_no) {
    ast_assignation_node_t* assignation_node = malloc(sizeof(*assignation_node));
    if(assignation_node==NULL){
        handle_os_error("malloc failed");
    }

    assignation_node->type = ASSIGNATION_TK;
    assignation_node->line_no = line_no;
    assignation_node->process = ast_assignation_process;
    assignation_node->destroy = ast_assignation_destroy;

    assignation_node->var_name = var_name;
    assignation_node->value = value;

    return (ast_node_t*)assignation_node;
    return NULL;
}
