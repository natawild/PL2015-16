%{
#include<string.h>
char  nomes[1000];
int i=0;
char *tmp;
FILE *fp;


void inser(char *texto) {
   nomes[i]=*texto;
    i++;
}

void trata() {
   nomes[i]='\0';
  if(tmp) {
   i=0;
 
    int n =strlen(tmp);
    tmp[n++]='-';
    tmp[n++]='-';
    tmp[n]='\0';
    strcat(tmp,nomes); 
   }
  
 else {
    tmp=(char *) malloc(1000);
    strcat(tmp,nomes);
    i=0; 
   
   }

}

void print() {
 i=0;
   fprintf(fp,"%s",tmp);
   fprintf(fp,"\n");

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

"author ="[ ]+"\""  {BEGIN (AUT);} 
"author ="[ ]+"\{"  {BEGIN (AUT);} 
<AUT>"\}"             {;}
<AUT>"\,"[ ]+         {trata();}
<AUT>[ ]+"and"[ ]+    {trata();}
<AUT>[ ]+"and"(\n)    {trata();}
<AUT>"\"""\,"         {trata();print();tmp=NULL;BEGIN INITIAL;}
<AUT>"\}""\,"         {trata();print();tmp=NULL;BEGIN INITIAL;}
<AUT>[A-Za-z]           {inser(yytext);}



%%


int yywrap() {return 1;}
int main(){
      abrir();	
    yylex();
        fechar();
  free(tmp);    
	return 0;
}
