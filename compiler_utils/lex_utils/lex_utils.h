#ifndef _LEX_UTILS_433771a42a12f16a123d4cda8ee9704846d094db
#define _LEX_UTILS_433771a42a12f16a123d4cda8ee9704846d094db

#include <stdio.h>
#include <stdlib.h>

#include "abstract_syntax_tree/ast/ast.h"
#include "y.tab.h"

#define TOKEN(t) (yylval.token = t)
#define SAVE_SYMBOL yylval.symbol = new_lex_string(yytext, yyleng);
#define SAVE_STRING_LITERAL(t, l) yylval.string_value = new_lex_string(t + 1, yyleng - 2);
#define SAVE_INT yylval.int_value = atoi(yytext);

char* new_lex_string(char* yytext, unsigned yyleng);
void init_lex();
void free_lex_resources();

#endif