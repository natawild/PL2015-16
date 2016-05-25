%{ 

#include <stdio.h>
#include "stack.h"

extern ccLine;
static int total;
FILE *f;
static Stack s;


%}


%union{
    char* var_nome;
    int valor;
 
    struct sVarAtr
    {
        char* var_nome;
        int valor;
        int size;
    } varAtr;   
}


%token INT WHILE FOR IF ELSE RETURN VOID PRINT SCAN DO 
%token <valor>num 
%token <var_nome>id 

/*
%type <varAtr> Var
%type <varAtr> Atrib
*/

// --------------------PROGRAMA ------------------------------------
/**
Um programa é uma lista de declarações, lista de Funcões , e uma lista de Instruções 
*/

%%

Prog        : 					{fprintf(f,"START\n");}
			ListaDecla  	 	{fprintf(f,"JUMP inicio\n");}
			ListaFun 			{fprintf(f,"inicio:NOP\n");}
			ListInst    		{fprintf(f,"STOP\n");}                                                                    
            ;

ListaDecla  :                            
            | ListaDecla Decla 
            ;

ListaFun    :   
            | ListaFun Funcao 
            ;

ListInst    : Inst                               
            | ListInst Inst                                    
            ;

// --------------------  FUNCAO ------------------------------------
/** A declaração de funções é precedida pelo símbolo terminal '\#'. 
 */

Funcao      : '#' TipoFun IdFun '(' ListaArg ')' '{' ListaDecla ListInst '}'              
            ;

TipoFun     : VOID                             
            | INT                           
            ;  

IdFun 		: id 
			;

ListaArg    :   
            | ListaArg2 ;

ListaArg2   : Tipo Var                            
            | ListaArg2  ','  Tipo Var         
            ;

Tipo 		: INT
			; 


// --------------------DECLARACAO ------------------------------------

Decla       : INT Var ';'                      
            | INT Var '[' num ']' ';'
            | INT Var '[' num ']' '[' num ']' ';'         
            ;
Var : id  ;

             

// --------------------INSTRUCAO ------------------------------------

ConjInst    :   
            |'{' ListInst '}'
            ;

Inst        : If                                          
            | While                                     
            | DoWhile
            | For                                       
            | Atrib ';'                                 
            | Print';' 							                               
            | Scan ';'                                 
            | RETURN Exp ';'                               
            ;

// ------------------------------------ ATRIBUIÇAO ------------------------------------

Atrib       : Var '=' Exp                                                                                      
            | Var '+''+'                                                                                       
            | Var'[' Exp ']' '=' Exp  
            | Var'[' Exp ']' '[' Exp ']' '=' Exp  
            ;

// ------------------------------------ PRINT SCAN ------------------------------------

Print:     PRINT '(' Exp ')'  		{fprintf(f,"WRITEI\n");}                        
            ;

Scan:      SCAN '(' Var')'                        
            ;
// ------------------------------------ IF THEN ELSE ------------------------------------

If          :  IF TestExpLog ConjInst  Else
            ;

Else        :       
            | ELSE ConjInst 
            ;

// ------------------------------------# WHILE ---------------------------------------------

While       : WHILE TestExpLog ConjInst                                    
            ;

// ------------------------------------# DO WHILE ---------------------------------------------

DoWhile     : DO ConjInst WHILE TestExpLog ';'              
            ;
    
// ------------------------------------# FOR ---------------------------------------------

For         : FOR ForHeader ConjInst                      
            ;

ForHeader   :  '(' ForAtrib ';' ExpLog ';' ForAtrib ')' 
            ;  

ForAtrib    : Atrib  
            ;

// -----------------------------------------------------------------CALCULO DE EXPRESSOES -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
ExpLog 		: Exp 
			|Exp '=''=' Exp
			|Exp '!''=' Exp
			|Exp '>''=' Exp
			|Exp '<''=' Exp
			|Exp '<' Exp
			|Exp '>' Exp
			; 


Exp 		: Termo
			|Exp '+' Termo 
			|Exp  '-' Termo 
			|Exp '|''|' ExpLog 
			; 


Termo		: Fun
			| Termo '/' Fun
			| Termo '*' Fun
			| Termo '&''&' ExpLog
			; 

Fun 	   	: num                       
            | Var                              
            | Var '['Exp ']'                                           
            | Var  '['Exp ']' '['Exp ']'                                      
            | IdFun '(' FunArgs')' 
            | '(' Exp ')'                  
            ;                                  

FunArgs     :    
            | FunArgs2 
            ;

FunArgs2    : Exp                                
            | FunArgs2 ',' Exp                 
            ;

TestExpLog  : '(' ExpLog ')'                                        
            ;


%%

#include "lex.yy.c"

/*
int yyerror(char* s) {
    printf("\n\x1b[10;01m%s (line %d) \x1b[0m\n", s, yylineno);
    return 0;
}
*/

/*

int yyerror(char *s) {
	fprintf(stderr, "Erro na linha ( %d! ) %s\n", yylineno, s);
	return 0;
}
*/

int  yyerror(char *s){
    fprintf(stderr,"ERRO: Syntax LINHA: %d MSG: %s\n",ccLine,s);
    exit(0);
    return 0; 
}

void inicio()
{
    s = initStack();
    total = 0;
    f = fopen("assembly.out", "w");
}

int main(){
	
	yyparse();
	return 0; 
}

