/*Declarations section start here*/

/* Auxiliary declarations start here*/
%{
#include "compiler_utils/lex_utils/lex_utils.h"
#include "compiler_utils/yacc_utils/yacc_utils.h"

#include "y.tab.h"
#include <stdio.h>

#define TOKEN(t) (yylval.token = t)
#define SAVE_SYMBOL yylval.symbol = new_lex_string(yytext,yyleng);
#define SAVE_STRING_LITERAL(t,l) yylval.string_value = new_lex_string(t+1,yyleng-2);
#define SAVE_INT yylval.int_value = atoi(yytext);

%}

/*Auxiliary declarations end & Regular definitions start here*/

%option nounput noinput yylineno
%option warn nodefault

DIGIT   [0-9] 
ALPHA   [a-zA-Z_] 
       
/*----------------Declarations section ends here----------*/
    
    
/*--------------------- Rules ----------------------------*/
%%
 /*Conditionals*/
"if"                            {return TOKEN(IF);}
"else"                          {return TOKEN(ELSE);}

 /*Cicle*/
"for"                           {return TOKEN(FOR);}
"do"                            {return TOKEN(DO);}
"while"                         {return TOKEN(WHILE);}
"print"                         {return TOKEN(PRINT);}

"render"                        {return TOKEN(RENDER);}

 /*Logical operators*/
"&&"                            {return TOKEN(AND);}
"||"                            {return TOKEN(OR);}
 /*No se si faltaria el !exp o no se como ponerlo*/

 /*Elements*/
"main"                          {return TOKEN(MAIN);}
"element"                       {return TOKEN(ELEMENT_TYPE);}
"string"                        {return TOKEN(STRING_TYPE);}
"int"                           {return TOKEN(INT_TYPE);}
"new"                           {return TOKEN(NEW);}
"html"                          {return TOKEN(HTML);}
"navbar"                        {return TOKEN(NAVBAR);}
"footer"                        {return TOKEN(FOOTER);}
"container"                     {return TOKEN(CONTAINER);}
"header"                        {return TOKEN(HEADER);}
"insert"                        {return TOKEN(INSERT);}


 /*Relational operators*/

">"                             {return TOKEN('>');}
">="		                    {return TOKEN(GE);}
"<"                             {return TOKEN('<'); }
"<="		                    {return TOKEN(LE);}
"=="		                    {return TOKEN(EQ);}
"!="                            {return TOKEN(NEQ);}

 /*valor*/
{ALPHA}({ALPHA}|{DIGIT})*       {SAVE_SYMBOL;return ID;}

0|[1-9]{DIGIT}*                 {SAVE_INT;return INT_VALUE;}
\"([^\\"\n]|\\.)*\"				{SAVE_STRING_LITERAL(yytext,yyleng); return STRING_VALUE;}

[ \t\n]                         {}

.                               {return yytext[0];}

%%
 /*--------------- Auxiliary functions ---------------------*/

int yywrap(void){
    return 1;
}
