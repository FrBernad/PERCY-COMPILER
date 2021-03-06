#ifndef _AST_H_70c26aab8c288ac95faf1cb588871a176a4913e6
#define _AST_H_70c26aab8c288ac95faf1cb588871a176a4913e6

struct ast_node;

typedef struct ast_node {
    int type;
    int line_no;
    struct ast_node* (*process)(struct ast_node* node);
    void (*destroy)(struct ast_node* node);

    struct ast_node* left;
    struct ast_node* right;
} ast_node_t;

#endif