#ifndef _ELEMENT_LIST_H_12c0a04c2e6fb38f3ca7aded1503229cf32d3c3c
#define _ELEMENT_LIST_H_12c0a04c2e6fb38f3ca7aded1503229cf32d3c3c

struct element_list;

typedef struct element {
    char* name;
    struct element_list* child_elements;
} element_t;

typedef struct element_node {
    element_t element;
    struct element_node* next;
} element_node_t;

typedef struct element_list {
    struct element_node* first;
    struct element_node* last;
    int size;
} element_list_t;

void insert_element(element_node_t* parent_element, element_node_t* child_element);

#endif