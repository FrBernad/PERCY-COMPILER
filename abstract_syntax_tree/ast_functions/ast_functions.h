#ifndef _AST_FUNCTIONS_H_63002a2ff45778afe3c25bdb1f33dae9e5c080ee
#define _AST_FUNCTIONS_H_63002a2ff45778afe3c25bdb1f33dae9e5c080ee

#include <stddef.h>

typedef struct ast_functions {
    void (*process)();
    void (*destroy)();
} ast_functions_t;

void init_ast_functions();

#endif