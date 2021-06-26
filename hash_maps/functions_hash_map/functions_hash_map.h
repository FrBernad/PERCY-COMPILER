#ifndef _FUNCTIONS_HASH_MAP_H
#define _FUNCTIONS_HASH_MAP_H

#include <stdbool.h>

#include "abstract_syntax_tree/ast/ast.h"
#include "abstract_syntax_tree/statements/functions/functions.h"

void init_functions_hash_map(void);
void free_functions_hash_map(void);
bool functions_hash_map_put(char* function_name, ast_function_node_t* function);

bool functions_hash_map_exists(char* function_name);

ast_function_node_t* functions_hash_map_get(char* function_name);

#endif