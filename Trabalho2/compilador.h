#ifndef __COMPILADOR_H__
#define __COMPILADOR_H__

typedef struct variavel *Variavel;

typedef struct funcao *Funcao;

typedef enum eTipo{_VOID,_INTS,_INTA,_INTM}Tipo;

typedef struct sEndereco{
    int addr;
    char scope;
    Tipo tipo;
} Endereco;

int initVGlobalMap();
Funcao existeFuncao(char * func);
int inserFuncao(Tipo tipo,char * name);
int decVar(char* varName, int linha,int coluna);



#endif