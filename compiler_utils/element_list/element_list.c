#include "element_list.h"

#include <stdio.h>
#include <stdlib.h>

#include "abstract_syntax_tree/statements/values/values.h"
#include "error_handler/error_handler.h"
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
    if (*element_list == NULL) {
        handle_os_error("malloc failed");
    }

    (*element_list)->last = NULL;
    (*element_list)->first = (*element_list)->last;
}

element_t* create_element(ast_tag_node_t* tag_node) {
    element_t* element = calloc(1, sizeof(*element));
    if(element==NULL){
        handle_os_error("calloc failed");
    }

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
            element->body = NULL;
            element->style = "box-sizing: border-box;height:60px;width:100%;background-color:#333;font-size:20px;font-weight:bold;text-align:left;padding: 0 10px;display:flex;justify-content:start;align-content:center;color:#e8e8e8;";
            init_elements_list(&element->child_elements);

            ast_tag_node_t nav_text_tag = {
                .body = tag_node->body,
                .type = TEXT
            };
            element_t* nav_text = create_element(&nav_text_tag);
            insert_element(element, nav_text);
            break;

        case FOOTER:
            element->name = "footer";
            element->body = NULL;
            element->style = "box-sizing: border-box;position:absolute;bottom:0;height:100px;width:100%;background-color:#333;font-size:20px;font-weight:bold;text-align:center;padding: 0 10px;display:flex;justify-content:center;align-content:center;color:#e8e8e8;";
            init_elements_list(&element->child_elements);

            ast_tag_node_t footer_text_tag = {
                .body = tag_node->body,
                .type = TEXT};
            element_t* footer_text = create_element(&footer_text_tag);
            insert_element(element, footer_text);
            break;

        case CONTAINER:
            element->name = "div";
            element->body = NULL;
            element->style = "box-sizing: border-box;width:100%;font-size:20px;font-weight:bold;text-align:center;padding:20px;display:flex;justify-content:center;align-content:center";
            break;

        case HEADER:
            element->name = "h1";
            element->body = ast_string_value_get(tag_node->body);
            element->style = "text-align: center;";
            break;

        case TEXT:
            element->name = "p";
            element->body = ast_string_value_get(tag_node->body);
            element->style = "text-align: center;";
            break;

        case BODY:
            element->name = "body";
            element->body = NULL;
            element->style = "margin:0;";
            break;

        default:
            free(element);
            element = NULL;
            handle_error("invalid tag", tag_node->line_no);
            break;
    }

    add_to_elements_list(element);

    return element;
}
// H N T
// H: N
// N: T
static void free_element_list_nodes(element_list_t* list) {
    element_node_t* iter = list->first;
    while (iter != NULL) {
        element_node_t* aux;
        aux = iter;
        iter = iter->next;
        free(aux);
    }
}

void free_elements(void) {
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
    if (new_node == NULL) {
        handle_os_error("malloc failed");
    }

    if (elements_list.first == NULL && elements_list.last == NULL) {
        elements_list.first = new_node;
        elements_list.last = elements_list.first;
        return;
    }

    elements_list.last->next = new_node;
    elements_list.last = new_node;
}
