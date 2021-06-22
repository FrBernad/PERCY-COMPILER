#include "values.h"

#include <stdlib.h>

// STRING VALUE
typedef struct ast_string_value_node {
    int type;
    char* value;
} ast_string_value_node_t;

// INT VALUE
typedef struct ast_int_value_node {
    int type;
    int value;
} ast_int_value_node_t;

//TAG VALUE
typedef struct ast_tag_value_node {
    int type;
    ast_node_t* value;
} ast_tag_value_node_t;

// REFERENCE VALUE
typedef struct ast_symbol_reference_node {
    int type;
    char* value;
} ast_symbol_reference_node_t;


// STRING VALUE
static ast_node_t *
ast_string_value_process() {
    return NULL;
}

static void ast_string_value_destroy() {
}

ast_functions_t ast_string_value_provider() {
    ast_functions_t functions = {
        .process = ast_string_value_process,
        .destroy = ast_string_value_destroy};
    return functions;
}

// INT VALUE
static ast_node_t *
ast_int_value_process() {
    return NULL;
}

static void ast_int_value_destroy() {
}

ast_functions_t ast_int_value_provider() {
    ast_functions_t functions = {
        .process = ast_int_value_process,
        .destroy = ast_int_value_destroy};
    return functions;
}

//TAG VALUE
static ast_node_t *
ast_tag_value_process() {
    return NULL;
}

static void ast_tag_value_destroy() {
}

ast_functions_t ast_tag_value_provider() {
    ast_functions_t functions = {
        .process = ast_tag_value_process,
        .destroy = ast_tag_value_destroy};
    return functions;
}

// REFERENCE VALUE
static ast_node_t *
ast_reference_value_process() {
    return NULL;
}

static void ast_reference_value_destroy() {
}

ast_functions_t ast_reference_value_provider() {
    ast_functions_t functions = {
        .process = ast_reference_value_process,
        .destroy = ast_reference_value_destroy};
    return functions;
}

// STRING VALUE
ast_node_t* create_ast_string_node(char* s) {
    ast_string_value_node_t* string_node = malloc(sizeof(*string_node));
    string_node->type = STRING_VALUE;
    string_node->value = s;

    return (ast_node_t*)string_node;
}

// INT VALUE
ast_node_t* create_ast_int_node(int value) {
    ast_int_value_node_t* int_node = malloc(sizeof(*int_node));
    int_node->type = INT_VALUE;
    int_node->value = value;

    return (ast_node_t*)int_node;
}

// TAG VALUE
ast_node_t* create_ast_tag_node(ast_node_t* tag) {
    ast_tag_value_node_t* tag_node = malloc(sizeof(*tag_node));
    tag_node->type = TAG_TK;
    tag_node->value = tag;

    return (ast_node_t*)tag_node;
}


// REFERENCE VALUE
ast_node_t* create_ast_symbol_reference_node(char* s) {
    ast_symbol_reference_node_t* symbol_reference = malloc(sizeof(*symbol_reference));
    symbol_reference->type = ID;
    symbol_reference->value = s;

    return (ast_node_t*)symbol_reference;
}