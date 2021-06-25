#include "yacc_utils.h"

#include <stdio.h>

#include "compiler_utils/element_list/element_list.h"
#include "compiler_utils/lex_utils/lex_utils.h"
#include "hash_maps/functions_hash_map/functions_hash_map.h"
#include "hash_maps/variables_hash_map/variables_hash_map.h"
#include "libs/khash/khash.h"

extern int yylineno;
extern FILE *yyin;
static FILE *output;

static struct percy_args percy_args;

static void render_element(element_t *element, int depth);
static void indent(int depth);
static void body(char *body, int depth);
static void style(char *style);

void yyerror(char const *s) {
    printf("Error! %s, line:%d\n\n", s, yylineno);
    exit(0);
}

void init_compiler(struct percy_args args) {
    percy_args = args;
    init_lex();
    init_functions_hash_map();
    init_variables_hash_map();

    output = fopen(percy_args.file_out, "w");
    if (output == NULL) {
        perror("Error at opening file\n");
        fprintf(stderr, "Excecution cannot continue\n");
        exit(0);
    }
}

void parse_input_file() {
    FILE *input_file = fopen(percy_args.file_in, "r");
    if (input_file == NULL) {
        printf("error!!\n");
        exit(0);
    }
    
    // set lex to read from it instead of defaulting to STDIN:
    yyin = input_file;
    yyparse();
}

void free_resources(){
    ast_function_node_t *main_function = functions_hash_map_get("main");

    if (main_function == NULL) {
        printf("NO HAY MAIN!!!!\n\n");
    }

    free_ast((ast_node_t *)main_function);

    free_elements();
    free_lex_resources();
    free_functions_hash_map();
    free_variables_hash_map();
}

void save_function(ast_node_t *function) {
    ast_function_node_t *function_node = (ast_function_node_t *)function;

    functions_hash_map_put(function_node->name, function_node);
}

void execute_main_function() {
    ast_function_node_t *main_function = functions_hash_map_get("main");

    if (main_function == NULL) {
        printf("NO HAY MAIN!!!!\n\n");
    }

    execute_ast(main_function->statements);

    var_t *to_render = variables_hash_map_get(main_function->render_var);

    if (to_render == NULL || to_render->type != ELEMENT_TYPE) {
        printf("invalid render element\n");
        return;
    }

    render_element(to_render->value.tag, 0);
    printf("going to render var: %s\n", main_function->render_var);
}

static void render_element(element_t *element, int depth) {
    indent(depth);
    fprintf(output, "<%s", element->name);
    style(element->style);
    fprintf(output, ">\n");

    body(element->body, depth + 1);

    element_list_t *child_elements = element->child_elements;

    if (child_elements != NULL) {
        element_node_t *iter = child_elements->first;

        while (iter != NULL) {
            render_element(iter->element, depth + 1);
            iter = iter->next;
        }
    }

    indent(depth);
    fprintf(output, "</%s>\n", element->name);
}

static void indent(int depth) {
    for (int i = 0; i < depth; i++) {
        fprintf(output, "\t");
    }
}

static void body(char *body, int depth) {
    if (body != NULL) {
        indent(depth);
        fprintf(output, "%s\n", body);
    }
}

static void style(char *style) {
    if (style != NULL) {
        fprintf(output, " style=\"%s\"", style);
    }
}
