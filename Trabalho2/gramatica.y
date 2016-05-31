%{ 
#include "compilador.h"
#include <stdio.h>
#include <string.h>
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
%type <varAtr> Var




// --------------------PROGRAMA ------------------------------------
/**
Um programa é uma lista de declarações, lista de Funcões , e uma lista de Instruções 
*/

%%

Prog       :                    
            ListaDecla          {fprintf(f,"start\n");fprintf(f,"jump inicio\n");}	 	
			ListaFun 			{fprintf(f,"inicio:nop\n");}        		
			ListInst    		{fprintf(f,"stop\n");}                                                         
                   				
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
                    '(' ListaArg ')'        {decFunArgRefresh();fprintf(f,"%s:NOP\n",$3);}
                    '{' ListaDecla ListInst '}'     {fim();}
            ;            

TipoFun     : VOID      	        {$$ =_VOID;}              
            | INT                   {$$ =_INTS;}        
            ;  

IdFun 		: id 
			;

ListaArg    :   
            | ListaArg2 ;

ListaArg2   : Tipo Var                                  {decArgumentos($2.var_nome);}
            | ListaArg2  ','  Tipo Var                  {decArgumentos($4.var_nome);}
            ;

Tipo 		: INT                 {$$ =_INTS;} 
			; 


// --------------------DECLARACAO ------------------------------------

Decla       : INT id ';'                               {decVar($2,1,'S');fprintf(f,"pushi 0\n"); vars++; }   			                
            | INT id '[' num ']' ';'                   {if(testeColuna($4)==1) 
                                                                {decVar($2,$4,'A');fprintf(f,"pushn%d\n",$4);}
                                                                else {yyerror("Tamanho menor que 1");}
                                                            }
            | INT id '[' Var ']' ';'                   {Endereco a = getEndereco($4.var_nome); 
                                                        fprintf(f, "pushn %d\n", a.addr);
                                                        decVar($2,a.addr,'A');}                                     
            | INT id '[' num ']' '[' num ']' ';'       {if(testeMatriz($4,$7)==1) 
                                                                {decVar($2,$4*$7,'M');fprintf(f,"pushn %d\n",$4*$7);}
                                                                else {yyerror("Tamanho menor que 1");}        
                                                                }  

            ;


Var 		: id                                      {Endereco a=getEndereco($1); $$.var_nome=strdup($1); $$.valor=1;}
			;

// --------------------INSTRUCAO ------------------------------------

ConjInst    :                                       
            |'{' ListInst '}'                   
            ;

Inst        : If   
            | Decla                                                               
            | While                                     
            | DoWhile
            | For                                       
            | Atrib ';'                                 
            | Print';' 							                               
            | Scan ';'                                 
            | RETURN Exp ';'     {fprintf(f,"storel %d\n",decFunRetAddr());fprintf(f,"return\n");}
            | ELSE               { yyerror("'Else' sem um 'If' anteriormente");return 0;}                          
            ;

// ------------------------------------ ATRIBUIÇAO ------------------------------------

Atrib       : Var '=' Exp                       {Endereco a = getEndereco($1.var_nome); 
                                                    if(a.tipo == _INTS){ fprintf(f,"store%c %d\n",a.tipoVar, a.addr);} 
                                                        else {yyerror("Tipos incompativeis");return 0;  }  
                                                } 

            | Var '+''+'                        {Endereco a = getEndereco($1.var_nome); 
                                                    if(a.tipo ==_INTS){fprintf(f,"pushi 1\n push%c %d\n add\n store%c %d\n",a.tipoVar,a.addr, a.tipoVar, a.addr);}
                                                    else{yyerror("Tipos incompativeis"); return 0; } 
                                                }    

            | Var'[' Exp ']' '=' Exp            {Endereco a = getEndereco($1.var_nome); fprintf(f, "push%cp \n push%c %d padd\n",(a.tipoVar=='l')? 'f' : 'g', 
                                                a.tipoVar, a.addr); fprintf(f, "storen\n");}


            | Var'[' Exp ']' '[' Exp ']' '=' Exp  {Endereco a = getEndereco($1.var_nome); fprintf(f, "push%cp \n push%c %d padd\n",(a.tipoVar=='l')? 'f' : 'g', 
                                                a.tipoVar, a.addr);}
            ;

// ------------------------------------ PRINT SCAN ------------------------------------
 
Print       :  PRINT '(' Prints ')'                          
            ;

Scan        : SCAN '(' Var ')'     {Endereco a= getEndereco($3.var_nome); 
                                    fprintf(f,"read\n atoi\n store%c %d\n",a.tipoVar, a.addr);}       
            ;

Prints      : num                       {fprintf(f, "writei %d\n",$1 );}           
            | Var                       {Endereco a = getEndereco($1.var_nome); fprintf(f, "push%c %d\nwritei\n",a.tipoVar, a.addr);}   

            | Var '['Exp ']'            {Endereco a = getEndereco($1.var_nome); 
                                        fprintf(f, "push%cp\npush%c %d\npadd\n",(a.tipoVar=='l')?'f':'g', a.tipoVar, a.addr);
                                        fprintf(f, "loadn\n");}  

            | Var  '['Exp ']' '['Exp ']' {fprintf(f, "matrix\n");}                                     
            | id                         {fprintf(f, "pushs %s\nwrites", $1);}
            ;                    
// ------------------------------------ IF THEN ELSE ------------------------------------

If          :  IF                   {total++; push(s,total);}
			TestExpLog   	        {fprintf(f,"jz endCond%d\n", get(s));}
			ConjInst  		        {fprintf(f," endCond%d\n", pop(s));}	
			Else
            ;

Else        :       
            | ELSE ConjInst 
            ;

// ------------------------------------# WHILE ---------------------------------------------

While       : WHILE             {total++; push(s,total); fprintf(f, "ciclo%d: NOP\n", get(s));}
            TestExpLog          {fprintf(f, "jz endciclo%d\n", get(s)); }
            ConjInst            {fprintf(f, "jump ciclo%d\n endCiclo%d\n", get(s), get(s));  pop(s); }                                
            ;

// ------------------------------------# DO WHILE ---------------------------------------------

DoWhile     : DO                            {total++; push(s,total); fprintf(f, "ciclo%d: NOP\n", get(s));}    
            ConjInst WHILE TestExpLog ';'   {fprintf(f, "jz endciclo%d\n jump ciclo%d\n endciclo%d: NOP\n", get(s),get(s),get(s));pop(s);}      
            ;
    
// ------------------------------------# FOR ---------------------------------------------

For         : FOR ForHeader ConjInst     {fprintf(f,"jump ciclo%dA\nendciclo%d\n", get(s), get(s)); pop(s);}                  
            ;

ForHeader   :  '(' ForAtrib ';'         {total++; push(s,total); fprintf(f,"ciclo%d: nop\n", get(s));}
             ExpLog ';'                 {fprintf(f,"jz endciclo%d\njump ciclo%dB\nciclo%dA: nop\n", get(s), get(s), get(s));}
             ForAtrib ')'               {fprintf(f,"jump ciclo%d\nciclo%dB: nop\n", get(s), get(s));}
            ; 


ForAtrib    : Atrib  
            ;

// -----------------------------------------------------------------CALCULO DE EXPRESSOES -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
ExpLog 		: Exp 
			|Exp '=''=' Exp 		{fprintf(f,"equal\n");}
			|Exp '!''=' Exp         {fprintf(f,"equal\npushi 0\nequal\n");}
			|Exp '>''=' Exp 		{fprintf(f,"supeq\n");}
			|Exp '<''=' Exp 		{fprintf(f,"infeq\n");}
			|Exp '<' Exp 			{fprintf(f,"inf\n");}
			|Exp '>' Exp 			{fprintf(f,"sup\n");}
			; 


Exp 		: Termo
			|Exp '+' Termo  			{fprintf(f,"add\n");}
			|Exp  '-' Termo 			{fprintf(f,"sub\n");}
			|Exp '|''|' ExpLog          {fprintf(f, "add\n jz endCond%d:nop\n",get(s));}
            |Exp '%' Termo              {fprintf(f, "mod\n");}
			; 


Termo		: Fun
			| Termo '/' Fun 			{fprintf(f,"div\n");}
			| Termo '*' Fun 			{fprintf(f,"mul\n");}
			| Termo '&''&' ExpLog       {fprintf(f, "pushi 1\nequal\njz endCond%d: nop\n",get(s));}
			; 

Fun 	   	: num                       {fprintf(f, "pushi %d\n",$1 );}           
            | Var  	                    {Endereco a = getEndereco($1.var_nome); fprintf(f, "push%c %d\n",a.tipoVar, a.addr);} 	
            | Var '['Exp ']'            {Endereco a = getEndereco($1.var_nome); 
                                        fprintf(f, "push%cp\npush%c %d\npadd\n",(a.tipoVar=='l')?'f':'g', a.tipoVar, a.addr);
                                        fprintf(f, "loadn\n");}  

            | Var  '['Exp ']' '['Exp ']'                                      
            | IdFun                     {funcaoExiste($1); fprintf(f, "pushi 0\n");}
            '(' FunArgs')'              {fprintf(f, "call %s\n",$1); fprintf(f, "pop%d\n",numeroArgumentos());}

            | '(' Exp ')'                  
            ;                                  

FunArgs     :    
            | FunArgs2 
            ;

FunArgs2    : Exp                   {proximoArgumento(_INTS);}                            
            | FunArgs2 ',' Exp      {proximoArgumento(_INTS);}             
            ;

TestExpLog  : '(' ExpLog ')'                                        
            ;


%%

int testeMatriz(int linha, int coluna) {

    if(linha<=0) {
        
        return -1;
    }

    else {
                if(coluna<=0) {

                        
                            return -1;

                }

                else return 1;


    }
}

int testeColuna(int linha) {

    if(linha<=0) {
        
        return -1;
    }

    else return 1;
}



#include "lex.yy.c"



/*
int yyerror(char* s) {
    printf("\n\x1b[10;01m%s (line %d) \x1b[0m\n", s, yylineno);
    return 0;
}
*/


int yyerror(char *s) {
	
    fprintf(stderr,"ERRO: Syntax LINHA: %d MSG: %s\n",ccLine,s);
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
	total=0; 
	lvars=0;
    vars=0;
    initVGlobalMap(); 
  s=initStack();

	f=fopen("assembly.txt","w+");
		yyparse();
		fclose(f); 
        free(s);
		return 0; 
	}