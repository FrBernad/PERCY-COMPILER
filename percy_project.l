/*Declarations section start here*/

/* Auxiliary declarations start here*/
%{
#include "compiler_utils/lex_utils/lex_utils.h"
#include "compiler_utils/yacc_utils/yacc_utils.h"

#include "y.tab.h"

#define TOKEN(t) (yylval.token = t)
#define SAVE_INT yylval.int_value = atoi(yytext);
#define SAVE_SYMBOL yylval.symbol = new_lex_string(yytext,yyleng);

int yydebug=1;
%}

/*Auxiliary declarations end & Regular definitions start here*/

%option nounput noinput yylineno
%option warn nodefault

digit   [0-9] 
alpha   [a-zA-Z_] 
       
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

"return"                        {return TOKEN(RETURN);}

 /*Logical operators*/
"&&"                            {return TOKEN(OP_AND);}
"||"                            {return TOKEN(OP_OR);}
 /*No se si faltaria el !exp o no se como ponerlo*/

 /*Elements*/
"main"                          {return TOKEN(MAIN);}
"element"                       {return TOKEN(ELEMENT);}
"new"                           {return TOKEN(NEW);}
"html"                          {return TOKEN(HTML);}
"navbar"                        {return TOKEN(NAVBAR);}
"footer"                        {return TOKEN(FOOTER);}
"container"                     {return TOKEN(CONTAINER);}
"header"                        {return TOKEN(HEADER);}
"insert"                        {return TOKEN(INSERT);}


 /*Relational operators*/

">"                             {return TOKEN(OP_GREATER);}
">="		                    {return TOKEN(OP_GREATER_OR_EQ);}
"<"                             {return TOKEN(OP_LESS); }
"<="		                    {return TOKEN(OP_LESS_OR_EQ);}
"=="		                    {return TOKEN(OP_EQ);}
"!="                            {return TOKEN(OP_NEQ);}

 /*valor*/
[0|1-9]{digit}+                 {SAVE_INT;return NUM;}
{alpha}({alpha}|{digit})*       {SAVE_SYMBOL;return ID;}


[ \t\n]     {}

.           {return yytext[0];}

%%
 /*--------------- Auxiliary functions ---------------------*/

int yywrap(void){
    return 1;
}