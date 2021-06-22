#ifndef _YAC_UTILS_H_5b115b0fd63d58c1cbc279469a91d3b573366a859ae838795da9e329
#define _YAC_UTILS_H_5b115b0fd63d58c1cbc279469a91d3b573366a859ae838795da9e329

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

int yylex();

void yyerror(char const *s);

void init_compiler();

void save_function(ast_node_t *function);

void execute_main_function();

#endif