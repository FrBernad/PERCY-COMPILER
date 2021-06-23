%{

#include "compiler_utils/yacc_utils/yacc_utils.h"

/* All the headers that you put here will be added to the output C file on top.*/
%}

%union {
    ast_node_t *node;

    char * symbol;

    char * string_value;

    int int_value;

    int token;
}

// The next Section is the Token definitions.  All of them will be DEFINE in y.tab.h
%token FIRST_TK

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

%token <token> OP_GREATER OP_GREATER_OR_EQ OP_LESS OP_LESS_OR_EQ OP_EQ OP_NEQ

%token <token> MAIN RENDER ELEMENT_TYPE NEW INT_TYPE STRING_TYPE HTML NAVBAR FOOTER CONTAINER HEADER INSERT

%token <string_value> STRING_VALUE
%token <int_value> INT_VALUE

%token <symbol> ID

%type <node> TAG STATEMENT STATEMENTS DEFINITION DECLARATION ASSIGNATION VALUE INSERT_MT
%type <token> TYPE 
%type <symbol> RENDER_CALL 

%token DECLARATION_TK TAG_TK ASSIGNATION_TK DEFINITION_TK STATEMENTS_TK FUNCTION_TK INSERT_MT_TK


%right '='
%left OR AND
%left '>' '<' LE GE EQ NE
%left '+' '-'
%left '*' '/'
%left '!'

%token LAST_TK

%start PROGRAM

/*
main(){
    element html = new html();
}

                      PROGRAM
                                \
                                  STATEMENTS
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
    PROGRAM:                    MAIN '(' ')' '{' STATEMENTS RENDER_CALL '}' 
                                    {
                                        ast_node_t * main_function = create_ast_function_node("main",$5,$6);
                                        printf("created main!\n");
                                        save_function(main_function);
                                    }
                                ;

    RENDER_CALL:                RENDER '(' ID ')' ';'
                                    {
                                        $$ = $3;
                                    }
                                ;

    STATEMENTS:                 STATEMENTS STATEMENT    
                                    {
                                        $$ = create_ast_statements_node($1,$2); 
                                    }
                                |                       
                                    { 
                                        $$ = NULL; 
                                    }
                                ;

    
    STATEMENT:                  DEFINITION              { $$ = $1; }
                                | DECLARATION           { $$ = $1; }
                                | ASSIGNATION           { $$ = $1; }
                                | INSERT_MT             { $$ = $1; }
                                ;
                                
    DEFINITION:                 TYPE ID '=' VALUE ';'
                                    {
                                        $$ = create_ast_definition_node($1,$2,$4);
                                    }
                                ;

    DECLARATION:                TYPE ID ';'
                                    {
                                        $$ = create_ast_declaration_node($1,$2);
                                    }
                                ;


    ASSIGNATION:                ID '=' VALUE ';'
                                    {
                                        $$ = create_ast_assignation_node($1,$3);       
                                    }
                                ;

    INSERT_MT:                  ID '.' INSERT '(' ID ')' ';'
                                    {
                                        $$ = create_ast_insert_node($1,$5);       
                                    }
                                ;

    VALUE:                      NEW TAG 
                                    {
                                        $$ = create_ast_tag_node($2);
                                    }
                                | INT_VALUE
                                    {
                                        $$ = create_ast_int_node($1);
                                    }
                                | STRING_VALUE
                                    {
                                        $$ = create_ast_string_node($1);
                                    }
                                | ID
                                    {
                                        $$ = create_ast_reference_node($1);
                                    }
                                ;

    TAG:                        HTML
                                    {
                                        $$ = create_ast_html_tag_node();
                                    }
                                | NAVBAR
                                    {
                                        $$ = create_ast_navbar_tag_node();
                                    }
                                | FOOTER
                                    {
                                        $$ = create_ast_footer_tag_node();
                                    }
                                | CONTAINER
                                    {
                                        $$ = create_ast_container_tag_node();
                                    }
                                | HEADER
                                    {
                                        $$ = create_ast_header_tag_node();
                                    }
                                ;

    TYPE:                        ELEMENT_TYPE 
                                    {
                                        $$ = $1;
                                    }
                                |  INT_TYPE
                                    {
                                        $$ = $1;
                                    }
                                |  STRING_TYPE
                                    {
                                        $$ = $1;
                                    }
                                ;


%%

int main(int argc, char const *argv[]){
    

    //1° PARSEAR argumentos
    /*2° INISIALIZAR TREE, TABLE, ETC*/ init_compiler();
    //3° PARSEAR INPUT PERCY
    //4° ANALISIS SEMANTICO, GUARDADO DE VARIABLES
    //5° RENDER (a partir de root)
    //6° LIBERAR RECURSOS, CERRAR COSAS*/

    yyparse();

    execute_main_function();

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
