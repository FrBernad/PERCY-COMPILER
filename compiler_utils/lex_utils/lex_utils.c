#include "lex_utils.h"

#include <string.h>

#include "error_handler/error_handler.h"
#include "libs/khash/khash.h"

KHASH_MAP_INIT_STR(strings_hash_map, char*)

static khash_t(strings_hash_map) * strings_hm;

void init_lex(void) {
    strings_hm = kh_init(strings_hash_map);
}

void free_lex_resources(void){
    char* str;
    kh_foreach_value(strings_hm, str, free(str));
    kh_destroy(strings_hash_map, strings_hm);
}

char* new_lex_string(char* yytext, unsigned yyleng){
    khiter_t k = kh_get(strings_hash_map, strings_hm, yytext);

    if (k != kh_end(strings_hm)) {
        return kh_val(strings_hm, k);
    }

    char * new_string = malloc((yyleng+1)*sizeof(*new_string));
    if (new_string == NULL) {
        handle_os_error("malloc failed");
    }
    
    new_string[yyleng] = 0;
    memcpy(new_string,yytext,yyleng);

    int ret;
    k = kh_put(strings_hash_map, strings_hm, new_string, &ret);

    if (ret == -1) {
        printf("se rompio algo\n\n");
    }

    return kh_val(strings_hm, k) = new_string;
}
