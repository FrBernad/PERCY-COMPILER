#include "values.h"

#include <stdio.h>
#include <stdlib.h>

#include "abstract_syntax_tree/statements/tags/tags.h"

// STRING VALUE
char* ast_string_value_process(ast_node_t* node) {
    ast_value_node_t* value_node = (ast_value_node_t*)node;
    return value_node->value.str;
}

static void ast_string_value_destroy() {
}

// INT VALUE
int ast_int_value_process(ast_node_t* node) {
    ast_value_node_t* value_node = (ast_value_node_t*)node;
    return value_node->value.num;
}

static void ast_int_value_destroy() {
}

//TAG VALUE
element_t* ast_tag_value_process(ast_node_t* node) {
    ast_value_node_t* value_node = (ast_value_node_t*)node;

    ast_tag_node_t* tag = (ast_tag_node_t*)value_node->value.tag;

    element_t* element = create_element(tag);
    printf("new element: tag: %s\n\n", element->name);
    return element;
}

static void ast_tag_value_destroy() {
}

// REFERENCE VALUE
char* ast_reference_value_process(ast_node_t* node) {
    ast_value_node_t* value_node = (ast_value_node_t*)node;

    return value_node->value.reference;
}

static void ast_reference_value_destroy() {
}

// STRING VALUE
ast_node_t* create_ast_string_node(char* s) {
    ast_value_node_t* string_node = malloc(sizeof(*string_node));
    string_node->type = STRING_VALUE;
    string_node->process = NULL;
    string_node->destroy = ast_string_value_destroy;

    string_node->value.str = s;

    return (ast_node_t*)string_node;
}

// INT VALUE
ast_node_t* create_ast_int_node(int value) {
    ast_value_node_t* int_node = malloc(sizeof(*int_node));
    int_node->type = INT_VALUE;
    int_node->process = NULL;
    int_node->destroy = ast_int_value_destroy;

    int_node->value.num = value;

    return (ast_node_t*)int_node;
}

// TAG VALUE
ast_node_t* create_ast_tag_node(ast_node_t* tag) {
    ast_value_node_t* tag_node = malloc(sizeof(*tag_node));
    tag_node->type = TAG_TK;
    tag_node->process = NULL;
    tag_node->destroy = ast_tag_value_destroy;

    tag_node->value.tag = tag;

    return (ast_node_t*)tag_node;
}

// REFERENCE VALUE
ast_node_t* create_ast_reference_node(char* s) {
    ast_value_node_t* reference_node = malloc(sizeof(*reference_node));
    reference_node->type = ID;
    reference_node->process = NULL;
    reference_node->destroy = ast_reference_value_destroy;

    reference_node->value.reference = s;

    return (ast_node_t*)reference_node;
}