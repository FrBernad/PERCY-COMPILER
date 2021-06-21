/*Declarations section start here*/

/* Auxiliary declarations start here*/
%{
#include <stdlib.h>

#include "y.tab.h"

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
"if"        {yylval = IF; return IF;}
"else"      {yylval = ELSE;return ELSE;}

    /*Cicle*/
"for"       {yylval = FOR; return FOR;}
"do"        {yylval = DO; return DO;}
"while"     {yylval = WHILE; return WHILE;}

"return"    {yylval = RETURN; return RETURN;}

    /*Logical operators*/;
"&&"        {yylval = OP_AND; return OP_AND;}
"||"        {yylval = OP_OR; return OP_OR;}
    /*No se si faltaria el !exp o no se como ponerlo*/

    /*Elements*/
"main"      {yylval = MAIN; return MAIN;}
"element"   {yylval = ELEMENT; return ELEMENT;}
"new"       {yylval = NEW; return NEW;}
"html"      {yylval = HTML; return HTML;}
"navbar"    {yylval = NAVBAR; return NAVBAR;}
"footer"    {yylval = FOOTER; return FOOTER;}
"container" {yylval = CONTAINER; return CONTAINER;}
"header"    {yylval = HEADER; return HEADER;}
"insert"     {yylval = INSERT; return INSERT;}


    /*Relational operators*/

">"         {yylval = OP_GREATER;return OP_GREATER;}
">="		{yylval = OP_GREATER_OR_EQ; return OP_GREATER_OR_EQ;}
"<"         {yylval = OP_LESS; return OP_LESS;}
"<="		{yylval = OP_LESS_OR_EQ; return OP_LESS_OR_EQ;}
"=="		{yylval = OP_EQ; return OP_EQ;}
"!="        {yylval = OP_NEQ; return OP_NEQ;}

    /*valor*/
[0|1-9]{digit}+  {yylval = atoi(yytext);return NUMBER;}
{alpha}({alpha}|{digit})* {return ID;}


[ \t\n]     {}

.           {return yytext[0];}

%%
    /*--------------- Auxiliary functions ---------------------*/

int yywrap(void){
    return 1;
}