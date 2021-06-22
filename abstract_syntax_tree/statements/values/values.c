#include "values.h"

#include <stdlib.h>
#include <stdio.h>

#include "abstract_syntax_tree/statements/tags/tags.h"

// STRING VALUE
typedef struct ast_value_node {
    int type;
    union {
        char* str;
        int num;
        ast_node_t* tag;
        char* reference;
    } value;
} ast_value_node_t;

// STRING VALUE
char* ast_string_value_process(ast_node_t* node) {
    ast_value_node_t* value_node = (ast_value_node_t*)node;
    return value_node->value.str;
}

// INT VALUE
int ast_int_value_process(ast_node_t* node) {
    ast_value_node_t* value_node = (ast_value_node_t*)node;
    return value_node->value.num;
}

//TAG VALUE
element_t* ast_tag_value_process(ast_node_t* node) {
    ast_value_node_t* value_node = (ast_value_node_t*)node;

    ast_tag_node_t* tag = (ast_tag_node_t*)value_node->value.tag;

    element_t * element = create_element(tag->type);
    printf("new element: tag: %s\n", element->name);
    return element;
}

// REFERENCE VALUE
char* ast_reference_value_process(ast_node_t* node) {
    ast_value_node_t* value_node = (ast_value_node_t*)node;
    return value_node->value.reference;
}

// STRING VALUE
ast_node_t* create_ast_string_node(char* s) {
    ast_value_node_t* string_node = malloc(sizeof(*string_node));
    string_node->type = STRING_VALUE;
    string_node->value.str = s;

    return (ast_node_t*)string_node;
}

// INT VALUE
ast_node_t* create_ast_int_node(int value) {
    ast_value_node_t* int_node = malloc(sizeof(*int_node));
    int_node->type = INT_VALUE;
    int_node->value.num = value;

    return (ast_node_t*)int_node;
}

// TAG VALUE
ast_node_t* create_ast_tag_node(ast_node_t* tag) {
    ast_value_node_t* tag_node = malloc(sizeof(*tag_node));
    tag_node->type = TAG_TK;
    tag_node->value.tag = tag;

    return (ast_node_t*)tag_node;
}

// REFERENCE VALUE
ast_node_t* create_ast_symbol_reference_node(char* s) {
    ast_value_node_t* symbol_reference = malloc(sizeof(*symbol_reference));
    symbol_reference->type = ID;
    symbol_reference->value.reference = s;

    return (ast_node_t*)symbol_reference;
}