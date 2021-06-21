%{

#include "compiler_utils/yacc_utils/yacc_utils.h"
/* All the headers that you put here will be added to the output C file on top.*/
%}

%union {
    ast_node_t *node;

    char * symbol;

    int int_value;

    int token;
}

// The next Section is the Token definitions.  All of them will be DEFINE in y.tab.h
%token NUM INSERT

/*CONDITIONALS*/
%token IF ELSE
%nonassoc IF ELSE

/*CICLE*/  
%token FOR DO WHILE

%token RETURN

/*Logical operators*/

%token OP_AND OP_OR

/*No se si faltaria el !exp o no se como ponerlo*/

/*Relational operators*/

%token OP_GREATER OP_GREATER_OR_EQ OP_LESS OP_LESS_OR_EQ OP_EQ OP_NEQ

%token <token> ELEMENT NEW
%token <node> HTML NAVBAR FOOTER CONTAINER HEADER

%token MAIN

%token <symbol> ID

%type <node> STATEMENT STATEMENTS DEFINITION DECLARATION ASSIGNATION IF_STATEMENT ITERATION_STATEMENT
%type <token> TYPE

%type <node> TAG

%right '='
%left OR AND
%left '>' '<' LE GE EQ NE
%left '+' '-'
%left '*' '/'
%left '!'

%start PROGRAM
/*
main(){
    element html = new html();
}

                      PROGRAM
                /                 \
             MAIN                 STATEMENTS
                                /            \                 
                          STATEMENTS        STATEMENT
                            /                       \
                         lambda                  DEFINITION 
                                                 /          \
                                                ID           TAG
                                                               \
                                                                html
                                            
                                               
                            
*/
%%
    PROGRAM:                    MAIN '(' ')' '{' STATEMENTS '}' {/*crear programa*/;}
                                ;

    STATEMENTS:                 STATEMENTS STATEMENT    
                                |                       { $$ = NULL; }
                                ;

    STATEMENT:                  DEFINITION              { $$ = $1; }
                                | DECLARATION           { $$ = $1; }
                                | ASSIGNATION           { $$ = $1; }
                                ;
                                
    DEFINITION:                 TYPE ID '=' NEW TAG ';'
                                    {
                                        $$ = create_ast_definition_node($1,$2,$5);
                                    }
                                ;

    DECLARATION:                TYPE ID ';'
                                    {
                                        $$ = create_ast_declaration_node($1,$2);
                                    }
                                ;


    ASSIGNATION:                ID '=' TAG ';'
                                    {
                                        $$ = create_ast_assignation_node($1,$3);       
                                    }
                                ;

    TAG:                        HTML
                                | NAVBAR
                                | FOOTER
                                | CONTAINER
                                | HEADER
                                ;

    TYPE:                        ELEMENT
                                ;

                        



%%

int main(int argc, char const *argv[]){
    

    //1° PARSEAR argumentos
    /*2° INISIALIZAR TREE, TABLE, ETC*/ init_compiler();
    //3° 
    // PARSEAR INPUT PERCY
    //4° 
    //5° RENDER (a partir de root)
    //6° LIBERAR RECURSOS, CERRAR COSAS*/


    return 0;
}

/*

main(){


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

}

*/
