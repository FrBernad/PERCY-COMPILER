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
/*CONDITIONALS*/
%token <token> IF ELSE
%nonassoc IF ELSE

/*CICLE*/  
%token <token> FOR DO WHILE

%token <token> RETURN

/*Logical operators*/

%token <token> AND OR 

/*No se si faltaria el !exp o no se como ponerlo*/

/*Relational operators*/

%token <token> '-' '+' '*' '/' '<' '>' EQ LE GE NEQ

%token <token> MAIN RENDER ELEMENT_TYPE NEW INT_TYPE STRING_TYPE HTML NAVBAR FOOTER CONTAINER HEADER INSERT


%token <string_value> STRING_VALUE
%token <int_value> INT_VALUE

%token <symbol> ID PRINT

%type <node> TAG STATEMENT STATEMENTS DEFINITION DECLARATION FOR_ASSIGNMENT FOR_STATEMENT DO_WHILE WHILE_STATEMENT PRINT_STATEMENT IF_STATEMENT ASSIGNATION VALUE INSERT_MT EXP PRINTABLE_VALUE
%type <token> TYPE 
%type <symbol> RENDER_CALL 

%token DECLARATION_TK TAG_TK ASSIGNATION_TK DEFINITION_TK STATEMENTS_TK FUNCTION_TK INSERT_MT_TK EXP_TK

%right '='
%left OR AND
%left '>' '<' LE GE EQ NEQ
%left '+' '-'
%left '*' '/'
%left '!'

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

    
    STATEMENT:                  DEFINITION ';'          { $$ = $1; }
                                | DECLARATION ';'       { $$ = $1; }
                                | ASSIGNATION ';'       { $$ = $1; }
                                | INSERT_MT             { $$ = $1; }
                                | IF_STATEMENT          { $$ = $1; }
                                | DO_WHILE              { $$ = $1; }
                                | WHILE_STATEMENT       { $$ = $1; }
                                | FOR_STATEMENT         { $$ = $1; }
                                | PRINT_STATEMENT       { $$ = $1; }
                                ;
                                
    DEFINITION:                 TYPE ID '=' VALUE
                                    {
                                        $$ = create_ast_definition_node($1,$2,$4);
                                    }
                                ;

    DECLARATION:                TYPE ID
                                    {
                                        $$ = create_ast_declaration_node($1,$2);
                                    }
                                ;


    ASSIGNATION:                ID '=' VALUE
                                    {
                                        $$ = create_ast_assignation_node($1,$3);       
                                    }
                                ;

    INSERT_MT:                  ID '.' INSERT '(' ID ')' ';'
                                    {
                                        $$ = create_ast_insert_node($1,$5);       
                                    }
                                ;

    PRINT_STATEMENT:            PRINT '(' PRINTABLE_VALUE ')' ';'
                                    {
                                        $$ = create_ast_print_node($3);       
                                    }
                                ;
    
    PRINTABLE_VALUE:            INT_VALUE
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

    IF_STATEMENT:               IF '(' EXP ')' '{' STATEMENTS '}' ELSE '{' STATEMENTS '}'
                                    {
                                        $$ = create_ast_if_node($3,$6,$10);
                                    }
                                | IF '(' EXP ')' '{' STATEMENTS '}'
                                    {
                                        $$ = create_ast_if_node($3,$6,NULL);
                                    }
                                ;

    FOR_STATEMENT:              FOR '(' FOR_ASSIGNMENT ';' EXP ';' FOR_ASSIGNMENT ')' '{' STATEMENTS '}'
                                    {
                                        $$ = create_ast_for_node($3,$5,$10,$7);
                                    }
                                ;  
    
    FOR_ASSIGNMENT:             ASSIGNATION     { $$ = $1; }
                                | DECLARATION   { $$ = $1; }
                                | DEFINITION    { $$ = $1; }
                                |               { $$ = NULL;}
                                ;  
    

    DO_WHILE:                   DO '{' STATEMENTS '}' WHILE '(' EXP ')' ';'
                                    {
                                            $$ = create_ast_do_while_node($7,$3);
                                    }
                                ;

    WHILE_STATEMENT:            WHILE '(' EXP ')' '{' STATEMENTS '}'
                                    {
                                            $$ = create_ast_while_node($3,$6);
                                    }
                                ;
    
    EXP:                        EXP '+' EXP 
                                    {
                                        $$ = create_ast_expression_node('+',$1,$3);
                                    }
                                | EXP '-' EXP
                                    {
                                        $$ = create_ast_expression_node('-',$1,$3);
                                    }
                                | EXP '*' EXP
                                    {
                                        $$ = create_ast_expression_node('*',$1,$3);
                                    }
                                | EXP '/' EXP
                                    {
                                        $$ = create_ast_expression_node('/',$1,$3);
                                    }
                                | EXP '<' EXP
                                    {
                                        $$ = create_ast_expression_node('<',$1,$3);
                                    }
                                | EXP '>' EXP
                                    {
                                        $$ = create_ast_expression_node('>',$1,$3);
                                    }
                                | EXP LE EXP
                                    {
                                        $$ = create_ast_expression_node($2,$1,$3);
                                    }
                                | EXP GE EXP
                                    {
                                        $$ = create_ast_expression_node($2,$1,$3);
                                    }
                                | EXP EQ EXP
                                    {
                                        $$ = create_ast_expression_node($2,$1,$3);
                                    }
                                | EXP NEQ EXP
                                    {
                                        $$ = create_ast_expression_node($2,$1,$3);
                                    }
                                | EXP OR EXP
                                    {
                                        $$ = create_ast_expression_node($2,$1,$3);
                                    }
                                | EXP AND EXP
                                    {
                                        $$ = create_ast_expression_node($2,$1,$3);
                                    }
                                | ID  
                                    {
                                        $$ = create_ast_reference_node($1);
                                    }
                                | INT_VALUE
                                    {
                                        $$ = create_ast_int_node($1);
                                    }
                                ; 

    VALUE:                      NEW TAG 
                                    {
                                        $$ = create_ast_tag_node($2);
                                    }
                                | STRING_VALUE
                                    {
                                        $$ = create_ast_string_node($1);
                                    }
                                | EXP 
                                    {
                                        $$ = create_ast_exp_node($1);
                                    }
                                ;

    TAG:                        HTML
                                    {
                                        $$ = create_ast_html_tag_node();
                                    }
                                | NAVBAR '(' STRING_VALUE ')'
                                    {
                                        $$ = create_ast_navbar_tag_node($3);
                                    }
                                | FOOTER '(' STRING_VALUE ')'
                                    {
                                        $$ = create_ast_footer_tag_node($3);
                                    }
                                | CONTAINER '(' STRING_VALUE ')'
                                    {
                                        $$ = create_ast_container_tag_node($3);
                                    }
                                | HEADER '(' STRING_VALUE ')'
                                    {
                                        $$ = create_ast_header_tag_node($3);
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

    init_compiler();

    parse_input_file();

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
