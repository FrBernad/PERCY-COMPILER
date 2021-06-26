#include "functions_hash_map.h"

#include "libs/khash/khash.h"

KHASH_MAP_INIT_STR(functions_hash_map, ast_function_node_t*)

static khash_t(functions_hash_map) * functions_hm;

void init_functions_hash_map(void) {
    functions_hm = kh_init(functions_hash_map);
}

void free_functions_hash_map(void) {
    kh_destroy(functions_hash_map, functions_hm);
}

bool functions_hash_map_put(char* function_name, ast_function_node_t* function) {
    if (!functions_hash_map_exists(function_name)) {
        int ret;
        khiter_t k = kh_put(functions_hash_map, functions_hm, function_name, &ret);

        if (ret == -1) {
            return false;
        }
        kh_val(functions_hm, k) = function;
        return true;
    }
    return false;
}

ast_function_node_t* functions_hash_map_get(char* function_name){
    khiter_t k = kh_get(functions_hash_map, functions_hm, function_name);

    if (k != kh_end(functions_hm)){
        return kh_val(functions_hm, k);
    }

    return NULL;
}


bool functions_hash_map_exists(char* function_name) {
    khiter_t k = kh_get(functions_hash_map, functions_hm, function_name);

    return k != kh_end(functions_hm);
}
