#ifndef _VARIABLES_HASH_MAP_H
#define _VARIABLES_HASH_MAP_H

#include <stdbool.h>

#include "compiler_utils/element_list/element_list.h"

typedef struct var {
    int type;
    char* name;
    union {
        char* str;
        int num;
        element_t * tag;
        char* reference;
    } value;
} var_t;

void init_variables_hash_map();

var_t* variables_hash_map_put(char* var_name, int type);

bool variables_hash_map_exists(char* var_name);

var_t* variables_hash_map_get(char* var_name);

#endif