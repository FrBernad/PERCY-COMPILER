%{

/* All the headers that you put here will be added to the output C file on top.*/
#include <stdio.h>
#include <string.h>

int yylex();
void yyerror(char const *s);

%}

// The next Section is the Token definitions.  All of them will be DEFINE in y.tab.h
%token NUMBER

/*CONDITIONALS*/
%token IF ELSE

/*CICLE*/  
%token FOR DO WHILE

%token RETURN

/*Logical operators*/

%token OP_AND OP_OR

/*No se si faltaria el !exp o no se como ponerlo*/

/*Relational operators*/

%token OP_GREATER OP_GREATER_OR_EQ OP_LESS OP_LESS_OR_EQ OP_EQ OP_NEQ

%token ELEMENT NEW HTML NAVBAR FOOTER CONTAINER HEADER

%token MAIN ID

%right '='
%left OR AND
%left '>' '<' LE GE EQ NE
%left '+' '-'
%left '*' '/'
%right UMINUS
%left '!'

%start main

%%
    main:                       MAIN '(' ')' '{' body '}'
                                ;

    body:                       body statement
                                | statement ';'
                                ;

    statement:                  definition 
                                | declaration 
                                | assignation
                                ;

    definition:                 declaration '=' tag
                                ;

    declaration:                ELEMENT ID
                                ;


    assignation:                ID '=' tag
                                ;

    tag:                         HTML
                                | NAVBAR
                                | FOOTER
                                | CONTAINER
                                | HEADER
                                ;



%%

void yyerror(char const *s){
    return;
}


/*
element html = new html();
element html;
html  =
element navbar = new navbar("brand", linkToLogo);
element footer = new navbar("footer text");
element container = new container();
element header = new header("this is my new webpage");
container.insert(header);

html.insert(navbar);
html.insert(container);
html.insert(footer);
*/
