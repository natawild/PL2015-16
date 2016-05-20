%{ 

#include <stdio.h>


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


%token INT WHILE FOR IF ELSE RETURN VOID PRINT SCAN TRUE FALSE DO 
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

Prog        : ListaDecla ListaFun ListInst                                                                        
            ;

ListaFun    :   
            | ListaFun Funcao 
            ;

ListaDecla  :                            
            | ListaDecla Decla 
            ;

ListInst    : Inst                               
            | ListInst Inst                                    
            ;

// --------------------  FUNCAO ------------------------------------
/** A declaração de funções é precedida pelo símbolo terminal '\#'. 
 */

Funcao      : '#' TipoFun IdFun '(' ListaArg ')' '{' ListaDecla ListInst '}'              
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

TipoFun     : VOID                             
            | INT                           
            ;               

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

Print:     PRINT '(' Exp ')'                          
            ;

Scan:      SCAN '(' Var')'                        
            ;
// ------------------------------------ IF THEN ELSE ------------------------------------

If          :  IF TestExpL ConjInst  Else
            ;

Else        :       
            | ELSE ConjInst 
            ;

// ------------------------------------# WHILE ---------------------------------------------

While       : WHILE TestExpL ConjInst                                    
            ;

// ------------------------------------# DO WHILE ---------------------------------------------

DoWhile     : DO ConjInst WHILE TestExpL ';'              
            ;
    
// ------------------------------------# FOR ---------------------------------------------

For         : FOR ForHeader ConjInst                      
            ;

ForHeader   :  '(' ForAtrib ';' ExpL ';' ForAtrib ')' 
            ;  


ForAtrib    : Atrib  
            ;

// -----------------------------------------------------------------CALCULO DE EXPRESSOES -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
ExpL 		: Exp 
			|Exp '=''=' Exp
			|Exp '!''=' Exp
			|Exp '>''=' Exp
			|Exp '<''=' Exp
			|Exp '<' Exp
			|Exp '>' Exp


Exp 		: Termo
			|Exp '+' Termo 
			|Exp  '-' Termo 
			|Exp '|''|' Termo 
			; 


Termo		: Fun
			| Termo '/' Fun
			| Termo '*' Fun
			| Termo  '&''&' Fun
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

TestExpL    : '(' ExpL ')'                                        
            ;


%%

#include "lex.yy.c"

int yyerror(char *s) {
	fprintf(stderr, "Erro na linha ( %d! ) %s\n", yylineno, s);
	return 0;
}

int main(){
	
	yyparse();
	return 0; 
}

