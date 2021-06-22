#include "element_list.h"

#include <stdio.h>
#include <stdlib.h>

#include "abstract_syntax_tree/ast/ast.h"
#include "y.tab.h"

static element_node_t * new_element_node(element_t* element) {
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

element_t* create_element(int type) {
    element_t* element = calloc(1,sizeof(*element));
    
    if(element == NULL){
        return NULL;
    }

    switch (type) {
        case HTML:
            element->name = "html";
            break;

        case NAVBAR:
            element->name = "navbar";
            break;

        case FOOTER:
            element->name = "footer";
            break;

        case CONTAINER:
            element->name = "container";
            break;

        case HEADER:
            element->name = "header";
            break;

        default:
            free(element);
            element = NULL;
            printf("TAG INVALIDO\n");
            break;
    }

    return element;
}
