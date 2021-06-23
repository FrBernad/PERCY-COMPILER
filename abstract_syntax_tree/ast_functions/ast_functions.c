#include "ast_functions.h"

#include <stdio.h>

#include "abstract_syntax_tree/statements/assignation/assignation.h"
#include "abstract_syntax_tree/statements/declaration/declaration.h"
#include "abstract_syntax_tree/statements/definition/definition.h"
#include "abstract_syntax_tree/statements/do_while/do_while.h"
#include "abstract_syntax_tree/statements/else/else.h"
#include "abstract_syntax_tree/statements/for/for.h"
#include "abstract_syntax_tree/statements/functions/functions.h"
#include "abstract_syntax_tree/statements/if/if.h"
#include "abstract_syntax_tree/statements/insert/insert.h"
#include "abstract_syntax_tree/statements/statements/statements.h"
#include "abstract_syntax_tree/statements/tags/tags.h"
#include "abstract_syntax_tree/statements/values/values.h"
#include "abstract_syntax_tree/statements/while/while.h"

#define ASCII_CHARS_COUNT 257
#define TOTAL_FUNCTIONS (ASCII_CHARS_COUNT + LAST_TK - FIRST_TK - 1)
// static ast_functions_t ast_functions[500];

static ast_functions_t ast_functions[TOTAL_FUNCTIONS];

void init_ast_functions() {
    ast_functions[STATEMENTS_TK]  = ast_statements_provider();
    ast_functions[ASSIGNATION_TK] = ast_assignation_provider();
    ast_functions[DECLARATION_TK] = ast_declaration_provider();
    ast_functions[DEFINITION_TK]  = ast_definition_provider();
    ast_functions[INSERT_MT_TK]   = ast_insert_provider();
    ast_functions[ELSE]           = ast_else_provider();
    ast_functions[FOR]            = ast_for_provider();
    ast_functions[FUNCTION_TK]    = ast_function_provider();
    ast_functions[IF]             = ast_if_provider();
}

void execute_ast(ast_node_t* ast) {
    execute_node(ast);
}

ast_node_t* execute_node(ast_node_t* node){
    if(node==NULL){
        return NULL;
    }
    printf("node type:%d\n",node->type);
    return ast_functions[node->type].process(node);
}
