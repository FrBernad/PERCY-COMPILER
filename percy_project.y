%{
#include "compiler_utils/yacc_utils/yacc_utils.h"
%}

%union {
    ast_node_t *node;

    char * symbol;

    char * string_value;

    int int_value;

    int token;
}

// The next Section is the Token definitions.  All of them will be DEFINE in y.tab.h
/*Conditionals*/
%token <token> IF ELSE
%nonassoc IF ELSE

/*Cycle*/  
%token <token> FOR DO WHILE

/*Logical operators*/
%token <token> AND OR 

/*Relational operators*/
%token <token> '-' '+' '*' '/' '<' '>' EQ LE GE NEQ

/*Percy grammar*/
%token <token> MAIN RENDER ELEMENT_TYPE NEW INT_TYPE STRING_TYPE HTML NAVBAR FOOTER CONTAINER HEADER INSERT TEXT BODY

%token <string_value> STRING_VALUE
%token <int_value> INT_VALUE
%token <symbol> ID

%type <node> TAG_VALUE TAG STATEMENT STATEMENTS DEFINITION DECLARATION FOR_ASSIGNMENT FOR_STATEMENT DO_WHILE WHILE_STATEMENT IF_STATEMENT ASSIGNATION VALUE INSERT_MT EXP
%type <token> TYPE 
%type <symbol> RENDER_CALL 

%token DECLARATION_TK TAG_TK ASSIGNATION_TK DEFINITION_TK STATEMENTS_TK FUNCTION_TK INSERT_MT_TK EXP_TK

%right '='
%left OR AND
%left '>' '<' LE GE EQ NEQ
%left '+' '-'
%left '*' '/' '%'
%left ')'
%right '('

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
                                        ast_node_t * main_function = create_ast_function_node("main",$5,$6,yylineno);
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
                                        $$ = create_ast_statements_node($1,$2,yylineno); 
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
                                ;
                                
    DEFINITION:                 TYPE ID '=' VALUE
                                    {
                                        $$ = create_ast_definition_node($1,$2,$4,yylineno);
                                    }
                                ;

    DECLARATION:                TYPE ID
                                    {
                                        $$ = create_ast_declaration_node($1,$2,yylineno);
                                    }
                                ;


    ASSIGNATION:                ID '=' VALUE
                                    {
                                        $$ = create_ast_assignation_node($1,$3,yylineno);       
                                    }
                                ;

    INSERT_MT:                  ID '.' INSERT '(' ID ')' ';'
                                    {
                                        $$ = create_ast_insert_node($1,$5,yylineno);       
                                    }
                                ;

    IF_STATEMENT:               IF '(' EXP ')' '{' STATEMENTS '}' ELSE '{' STATEMENTS '}'
                                    {
                                        $$ = create_ast_if_node($3,$6,$10,yylineno);
                                    }
                                | IF '(' EXP ')' '{' STATEMENTS '}'
                                    {
                                        $$ = create_ast_if_node($3,$6,NULL,yylineno);
                                    }
                                ;

    FOR_STATEMENT:              FOR '(' FOR_ASSIGNMENT ';' EXP ';' FOR_ASSIGNMENT ')' '{' STATEMENTS '}'
                                    {
                                        $$ = create_ast_for_node($3,$5,$10,$7,yylineno);
                                    }
                                ;  
    
    FOR_ASSIGNMENT:             ASSIGNATION     { $$ = $1; }
                                | DECLARATION   { $$ = $1; }
                                | DEFINITION    { $$ = $1; }
                                |               { $$ = NULL;}
                                ;  
    

    DO_WHILE:                   DO '{' STATEMENTS '}' WHILE '(' EXP ')' ';'
                                    {
                                            $$ = create_ast_do_while_node($7,$3,yylineno);
                                    }
                                ;

    WHILE_STATEMENT:            WHILE '(' EXP ')' '{' STATEMENTS '}'
                                    {
                                            $$ = create_ast_while_node($3,$6,yylineno);
                                    }
                                ;
    
    EXP:                        EXP '+' EXP 
                                    {
                                        $$ = create_ast_expression_node('+',$1,$3,yylineno);
                                    }
                                | EXP '-' EXP
                                    {
                                        $$ = create_ast_expression_node('-',$1,$3,yylineno);
                                    }
                                | EXP '*' EXP
                                    {
                                        $$ = create_ast_expression_node('*',$1,$3,yylineno);
                                    }
                                | EXP '/' EXP
                                    {
                                        $$ = create_ast_expression_node('/',$1,$3,yylineno);
                                    }
                                | EXP '<' EXP
                                    {
                                        $$ = create_ast_expression_node('<',$1,$3,yylineno);
                                    }
                                | EXP '>' EXP
                                    {
                                        $$ = create_ast_expression_node('>',$1,$3,yylineno);
                                    }
                                | EXP '%' EXP
                                    {
                                        $$ = create_ast_expression_node('%',$1,$3,yylineno);
                                    }
                                | EXP LE EXP
                                    {
                                        $$ = create_ast_expression_node($2,$1,$3,yylineno);
                                    }
                                | EXP GE EXP
                                    {
                                        $$ = create_ast_expression_node($2,$1,$3,yylineno);
                                    }
                                | EXP EQ EXP
                                    {
                                        $$ = create_ast_expression_node($2,$1,$3,yylineno);
                                    }
                                | EXP NEQ EXP
                                    {
                                        $$ = create_ast_expression_node($2,$1,$3,yylineno);
                                    }
                                | EXP OR EXP
                                    {
                                        $$ = create_ast_expression_node($2,$1,$3,yylineno);
                                    }
                                | EXP AND EXP
                                    {
                                        $$ = create_ast_expression_node($2,$1,$3,yylineno);
                                    }
                                | '(' EXP ')'
                                    {
                                        $$ = $2;
                                    }
                                | ID  
                                    {
                                        $$ = create_ast_reference_node($1,yylineno);
                                    }
                                | INT_VALUE
                                    {
                                        $$ = create_ast_int_node($1,yylineno);
                                    }
                                ; 

    VALUE:                      NEW TAG 
                                    {
                                        $$ = create_ast_tag_node($2,yylineno);
                                    }
                                | STRING_VALUE
                                    {
                                        $$ = create_ast_string_node($1,yylineno);
                                    }
                                | EXP 
                                    {
                                        $$ = create_ast_exp_node($1,yylineno);
                                    }
                                ;

    TAG:                        HTML '(' ')'
                                    {
                                        $$ = create_ast_html_tag_node(HTML,NULL,yylineno);
                                    }
                                | NAVBAR '(' TAG_VALUE ')'
                                    {
                                        $$ = create_ast_html_tag_node(NAVBAR,$3,yylineno);
                                    }
                                | FOOTER '(' TAG_VALUE ')'
                                    {
                                        $$ = create_ast_html_tag_node(FOOTER,$3,yylineno);
                                    }
                                | CONTAINER '(' ')'
                                    {
                                        $$ = create_ast_html_tag_node(CONTAINER,NULL,yylineno);
                                    }
                                | HEADER '(' TAG_VALUE ')'
                                    {
                                        $$ = create_ast_html_tag_node(HEADER,$3,yylineno);
                                    }
                                | TEXT '(' TAG_VALUE ')'
                                    {
                                        $$ = create_ast_html_tag_node(TEXT,$3,yylineno);
                                    }
                                | BODY '(' ')'
                                    {
                                        $$ = create_ast_html_tag_node(BODY,NULL,yylineno);
                                    }
                                ;
    TAG_VALUE:                  STRING_VALUE
                                    {
                                        $$ = create_ast_string_node($1,yylineno);
                                    }
                                | ID  
                                    {
                                        $$ = create_ast_reference_node($1,yylineno);
                                    }
                                | INT_VALUE
                                    {
                                        $$ = create_ast_int_node($1,yylineno);
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

int main(int argc, char *argv[]){
void parse_args(int argc, char** argv, struct percy_args* args);
    struct percy_args args;

    parse_args(argc,argv,&args);

    init_compiler(args);

    parse_input_file();

    execute_main_function();

    free_resources(0);

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
