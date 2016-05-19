%{ 

#include <stdio.h>

int ccLine =0; 

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


%token INT WHILE FOR IF ELSE RETURN VOID PRINTI SCANI TRUE FALSE DO END
%token var num

%type <var_nome> var
%type <valor> num
%type <varAtr> VarAtr
%type <varAtr> Atrib
%type <type> Tipo


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

Funcao      : '#' Tipo var '(' ListaArg ')' '{' ListaDecla ListInst '}'              
            ;


ListaArg    :   
            | ListaArg2 ;

ListaArg2   : Tipo var                            
            | ListaArg2  ','  Tipo var         
            ;


// --------------------DECLARACAO ------------------------------------

Decla       : INT var ';'                      
            | INT var '[' num ']' ';'        
            ;

Tipo        : VOID                             
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
            | Printi';'                                 
            | Scani ';'                                 
            | RETURN Exp ';'                               
            ;


VarAtr      : var                                    
            ;


// ------------------------------------ ATRIBUIÇAO ------------------------------------

Atrib       : VarAtr '=' Exp                                                                                      
            | VarAtr '+''+'                                                                                       
            | VarAtr '[' Exp ']' '=' Exp                        
            ;

// ------------------------------------ PRINT SCAN ------------------------------------

Printi:     PRINTI '(' Exp ')'                          
            ;

Scani:      SCANI '(' VarAtr ')'                        
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


ForAtrib    :   
            |Atrib  
            ;

// -----------------------------------------------------------------CALCULO DE EXPRESSOES -------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Exp         : Exp '+' Exp                        
            | Exp '-' Exp                      
            | Exp '%' Exp                       
            | Exp '*' Exp                       
            | Exp '/' Exp                       
            | '(' Exp ')'                       
            | num                               
            | VarAtr                                                 
            | VarAtr                                       
            | var '(' FunArgs')'                  
            ;


FunArgs     :    
            | FunArgs2 
            ;

FunArgs2    : Exp                                
            | FunArgs2 ',' Exp                 
            ;

TestExpL    : '(' ExpL ')'                                        
            ;

ExpL        : Exp '=''=' Exp                       
            | Exp '!''=' Exp                       
            | Exp '>''=' Exp                      
            | Exp '<''=' Exp                       
            | Exp '<' Exp                          
            | Exp '>' Exp                          
            | '(' ExpL ')' '&' '&' '(' ExpL ')'                    
            | '(' ExpL ')' '|''|' '(' ExpL ')'   
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