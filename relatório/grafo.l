%{
#include<string.h>
typedef struct listaLigada{

   char *tmp;
   struct listaLigada *next;

}*Lista;

Lista guarda;

char  nomes[1000];
int i=0;
char *autor;
FILE *fp;
char *inserir;


Lista init () {

  guarda =(Lista) malloc(sizeof(struct listaLigada));
  guarda->next=NULL;
  guarda->tmp=NULL;
  return guarda;
}

void trata () {
   nomes[i]='\0'; 

    if(guarda) {
   
  Lista aux =(Lista) malloc(sizeof(struct listaLigada));
  aux->tmp=strdup(nomes);
  aux->next=guarda;
      guarda=aux;
      
i=0;
}
    
   else {
      guarda=init();
      guarda->tmp=strdup(nomes);
i=0;
   }   

  i=0;

}






void inser(char *texto) {
   nomes[i]=*texto;
    i++;
}


void print() {
int n;

int flag=0;
Lista aux=guarda;     

 while(aux!=NULL && !flag) {

    if((n=strcmp(aux->tmp,autor))==0) {
     flag =1;

      }
    aux=aux->next;

}

   if(flag) {
      
      while(guarda->next!=NULL){
       fprintf(fp,"\"");

       fprintf(fp,"%s",guarda->tmp);

       fprintf(fp,"\"");

       fprintf(fp,"%s","--");

      guarda=guarda->next;  

    }    fprintf(fp,"\"");
         fprintf(fp,"%s",guarda->tmp);
         fprintf(fp,"\"");
         fprintf(fp,"\n");
             }    
  
  
    guarda=NULL;   
}



void abrir(){

        fp = fopen("ficheiro.dot", "w");
        fprintf(fp, "graph {");
}

void fechar() {


 fprintf(fp, "}");
        fclose(fp);

}





%}

%x AUT



%%
"author ="[ ]*"\""  {BEGIN (AUT);} 
"author ="[ ]*"\{"  {BEGIN (AUT);}
<AUT>"\."         {inser(yytext);}
<AUT>[ ]+            {;}
<AUT>"\}"             {;}
<AUT>"\,"[ ]+         {trata();}
<AUT>[ ]+"and"[ ]+    {trata();}
<AUT>[ ]+"and"(\n)    {trata();}
<AUT>"\"""\,"         {trata();print();guarda=NULL;BEGIN INITIAL;}
<AUT>"\}""\,"         {trata();print();guarda=NULL;BEGIN INITIAL;}
<AUT>[A-Za-z]         {inser(yytext);}


%%


int yywrap() {return 1;}
int main(int argc, char* argv[]){
    if (argc ==2) {

    abrir();
   
   autor=strdup(argv[1]);	
   guarda=NULL;
    yylex();

    fechar(); 
}

 else {printf("Indtroduza o nome\n");}
 return 0;


}
