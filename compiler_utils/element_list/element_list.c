#include "element_list.h"

#include <stdio.h>
#include <stdlib.h>

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/statements/values/values.h"
#include "y.tab.h"

static element_list_t elements_list;

static void add_to_elements_list(element_t* element);
static void free_element_list_nodes(element_list_t* list);

static element_node_t* new_element_node(element_t* element) {
    element_node_t* new_node = calloc(1, sizeof(*new_node));
    new_node->element = element;
    return new_node;
}

void insert_element(element_t* parent_element, element_t* child_element) {
    element_list_t* child_elements = parent_element->child_elements;
    element_node_t* new_node = new_element_node(child_element);

    if (child_elements->first == NULL && child_elements->last == NULL) {
        child_elements->first = new_node;
        child_elements->last = child_elements->first;
        return;
    }

    child_elements->last->next = new_node;
    child_elements->last = new_node;
}

void init_elements_list(element_list_t** element_list) {
    *element_list = malloc(sizeof(element_list_t));
    (*element_list)->last = NULL;
    (*element_list)->first = (*element_list)->last;
}

element_t* create_element(ast_tag_node_t* tag_node) {
    element_t* element = calloc(1, sizeof(*element));

    if (element == NULL) {
        return NULL;
    }

    switch (tag_node->type) {
        case HTML:
            element->name = "html";
            element->body = NULL;
            element->style = NULL;
            break;

        case NAVBAR:
            element->name = "div";
            element->body = ast_string_value_get(tag_node->body);
            element->style = "height:60px;width:100%;background-color:#333;font-size:20px;font-weight:bold;text-align:left;padding: 0 10px;display:flex;justify-items:start;align-content:center;";
                break;

        case FOOTER:
            element->name = "footer";
            element->body = ast_string_value_get(tag_node->body);
            element->style = "";
            break;

        case CONTAINER:
            element->name = "div";
            element->body = ast_string_value_get(tag_node->body);
            element->style = "";
            break;

        case HEADER:
            element->name = "header";
            element->body = ast_string_value_get(tag_node->body);
            element->style = "";
            break;

        default:
            free(element);
            element = NULL;
            printf("TAG INVALIDO\n");
            break;
    }

    add_to_elements_list(element);

    return element;
}

static void free_element_list_nodes(element_list_t* list) {
    element_node_t* iter = list->first;
    while (iter != NULL) {
        if (iter->element->child_elements != NULL) {
            free_element_list_nodes(iter->element->child_elements);
        }
        element_node_t* aux;
        aux = iter;
        iter = iter->next;
        free(aux);
    }
}

void free_elements() {
    element_node_t* iter = elements_list.first;
    while (iter != NULL) {
        if (iter->element->child_elements != NULL) {
            free_element_list_nodes(iter->element->child_elements);
            free(iter->element->child_elements);
        }
        free(iter->element);
        element_node_t* aux;
        aux = iter;
        iter = iter->next;
        free(aux);
    }
}

static void add_to_elements_list(element_t* element) {
    element_node_t* new_node = new_element_node(element);

    if (elements_list.first == NULL && elements_list.last == NULL) {
        elements_list.first = new_node;
        elements_list.last = elements_list.first;
        return;
    }

    elements_list.last->next = new_node;
    elements_list.last = new_node;
}
