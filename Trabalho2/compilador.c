#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"
#include "compilador.h"

#define OK 0
#define ERRO_A_VAR_JA_EXISTE -1
#define ERRO_A_VAR_NAP_EXISTE -2
#define ERRO_TIPO_INVALIDO -3
#define ERRO_FUNCAO_NAO_EXISTE -4
#define ERRO_A_FUNCAO_JA_EXISTE -5
#define ERRO -5


//void yyerror(char *s);

struct variavel{
    Tipo tipo;
    char *nome;
    int memAdr;
};


typedef struct funcaoArg
{
    struct Variavel* v; 
    struct funcaoArg *next;
}* FuncaoArg;



struct funcao{
    Tipo tipo;
    char *nome;
    FuncaoArg args;
    FuncaoArg argsEnd;
    int numeroArg;
};

typedef struct sScope{
    map_t vars;
    int addrCount;
}*Scope;



static Funcao emUsoFun;
static Funcao funcaoAux;
static Scope vGlobal;
static Scope vInterna;

static map_t mFuncMap;


int initVGlobalMap()
{
    vGlobal = (Scope) malloc(sizeof(struct sScope));
    vGlobal->vars = hashmap_new();
    vGlobal->addrCount = 0;
	mFuncMap = hashmap_new();
    return 0;
}


Funcao existeFuncao(char * func) {

			Funcao tmp;

			if(!(hashmap_get(mFuncMap,func,(any_t*)&tmp)==MAP_OK)) {

				tmp=NULL;
			}		

				return tmp;
}


Variavel static existeVar(Scope fun, char* varName)
{
	Variavel tmp;
    if (fun==NULL)
        fun = vGlobal;
	
	if(!(hashmap_get(fun->vars, varName, (any_t*) &tmp) == MAP_OK))
		tmp = NULL;
	return tmp;	
}

/* insere uma funcao, retorna ok se estiver todo bem*/
int inserFuncao(Tipo tipo,char * name) {

		int ret=0;
        /* se a funcao não existir retorna nulo, logo eu posso declarala*/
        
		if(!(existeFuncao(name))) {
				
				Funcao nova=(Funcao) malloc(sizeof(struct funcao));
				nova->nome=strdup(name);
				nova->tipo=tipo;
				nova->args=NULL;
				nova->argsEnd=NULL;
				nova->numeroArg=0;

				hashmap_put(mFuncMap,name,(any_t)nova);
				funcaoAux=nova;

				vInterna=(Scope)malloc(sizeof(struct sScope));
				vInterna->vars=hashmap_new();
				vInterna->addrCount=0;
				ret=OK;
 		}

 		else {
 				
 				//yyerror("Funcão já declarada");
 				ret=ERRO_A_FUNCAO_JA_EXISTE;


 		}
 return ret;

}


int  decVar(char* varName, int linha,int coluna) {

	Scope context; 
    int erro = 0;

    /* se não houver declarações locais irá ver existe variaveis globais com o mesmo nome*/

     if (vInterna== NULL) { 
        context = vGlobal;
        erro += (existeVar(vGlobal, varName) != NULL);
    } else {
        context = vInterna;         /* se for NULL dá como resultado zero, senão dá um*/
        erro += (existeVar(vInterna, varName) != NULL);
        erro += (existeVar(vGlobal, varName) != NULL);
    }

    	/*se der dirente de zero*/

    if(!erro) {

    		Variavel variavel=(Variavel)malloc(sizeof(struct variavel));



    		if(linha>1 && coluna>1) {

    					variavel->tipo= _INTM;
					}

    		else {
    				/*-10 porque o array não tem colunas*/		
    				if(linha>1 && coluna==-10) {

    				(variavel->tipo)= _INTA;
 					
 					}

 					else {

 							variavel->tipo= _INTS;

 					}
			}

			variavel->nome=strdup(varName);
			variavel->memAdr=context->addrCount;
			context->addrCount=context->addrCount+linha+coluna;

			hashmap_put(context->vars, varName, (any_t)variavel);







    	erro=OK;

    }


    else {
    	printf("dsa\n");
    	//yyerror("Variável já declarada anteriormente");
    	erro=ERRO_A_VAR_JA_EXISTE;
    }





return erro;


}









int main(int argc, char const *argv[])
{
	initVGlobalMap();
	//inserFuncao(_VOID,"ola");
	//inserFuncao(_INTS,"ola");
	//decVar("ola",1,10);
	//decVar("ola",1,0);




	return 0;
}





