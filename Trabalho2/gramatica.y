%{ 
#include "compilador.h"
#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include "y.tab.h"



extern ccLine;
static int total;
FILE *f;
static Stack s;

int vars; 
int lvars; 


%}

%union{
    char* var_nome;
    int valor;
    Tipo tipo;
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

%type <tipo> TipoFun
%type <tipo> Tipo
%type <var_nome> IdFun




// --------------------PROGRAMA ------------------------------------
/**
Um programa é uma lista de declarações, lista de Funcões , e uma lista de Instruções 
*/

%%

Prog       : ListaDecla  	 	{fprintf(f,"START\n");}
			ListaFun 			{fprintf(f,"JUMP inicio\n");}		
			ListInst    		{fprintf(f,"inicio:NOP\n");}                                                               
                   				{fprintf(f,"STOP\n");}  
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

Funcao      : '#' TipoFun IdFun                 {inserFuncao($2,$3);}
                    '(' ListaArg ')' 
                    '{' ListaDecla ListInst '}'             
            ;

TipoFun     : VOID      	        {$$ =_VOID;}              
            | INT                   {$$ =_INTS;}        
            ;  

IdFun 		: id 
			;

ListaArg    :   
            | ListaArg2 ;

ListaArg2   : Tipo Var                            
            | ListaArg2  ','  Tipo Var         
            ;

Tipo 		: INT                 {$$ =_INTS;} 
			; 


// --------------------DECLARACAO ------------------------------------

Decla       : INT Var ';'   {fprintf(f,"PUSHI 0\n"); vars++; }   			                
            | INT Var '[' num ']' ';'
            | INT Var '[' num ']' '[' num ']' ';'         
            ;


Var 		: id              {fprintf(f,"%s\n",$1);} 
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

Print:     PRINT '(' Exp ')'  		//{fprintf(f,"\tpushs \" %s\" \n\twrites\n",$3);}                        
            ;

Scan:      SCAN '(' Var')'   		//{fprintf(f,"\tread %s\n\tatoi\n\tstoreg %d",$1,lvars);lvars++; }                                 
            ;
// ------------------------------------ IF THEN ELSE ------------------------------------

If          :  IF 
			TestExpLog   	{fprintf(f,"JZ endCond%d\n", get(s));}
			ConjInst  		 {fprintf(f," endCo%d\n", pop(s));}	
			Else
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
			|Exp '=''=' Exp 		{fprintf(f,"equal\n");}
			|Exp '!''=' Exp
			|Exp '>''=' Exp 		{fprintf(f,"supeq\n");}
			|Exp '<''=' Exp 		{fprintf(f,"infeq\n");}
			|Exp '<' Exp 			{fprintf(f,"inf\n");}
			|Exp '>' Exp 			{fprintf(f,"sup\n");}
			; 


Exp 		: Termo
			|Exp '+' Termo  			{fprintf(f,"add\n");}
			|Exp  '-' Termo 			{fprintf(f,"sub\n");}
			|Exp '|''|' ExpLog 
			; 


Termo		: Fun
			| Termo '/' Fun 			{fprintf(f,"div\n");}
			| Termo '*' Fun 			{fprintf(f,"mul\n");}
			| Termo '&''&' ExpLog
			; 

Fun 	   	: num                       {fprintf(f,"%d", $1);}     
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


int yyerror(char *s) {
	fprintf(stderr, "Erro na linha ( %d! ) %s\n", yylineno, s);
	return 0;
}


/*

int  yyerror(char *s){
    fprintf(stderr,"ERRO: Syntax LINHA: %d MSG: %s\n",ccLine,s);
    exit(0);
    return 0; 
}

*/

/*

void inicio()
{
    s = initStack();
    total = 0;
    f = fopen("assembly.out", "w");
}
*/


int main(int argc, char* argv[]){
	vars=0; 
	lvars=0;
    initVGlobalMap(); 
  s=initStack();

	f=fopen("assembly.txt","w+");
		yyparse();
		fclose(f); 
        free(s);
		return 0; 
	}


