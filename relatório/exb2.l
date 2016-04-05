%{ 
#include<string.h>
char nomes[1000];
int i=0;
char *tmp;
char *titulo;


char * inser(char *texto) {
nomes[i]=*texto;
i++;
return nomes;
}

void trata() {
  nomes[i]='\0';
 
 if(tmp) {
         strcat(tmp," and");
      int n=strlen(tmp);
          tmp[n++]=' ';
          tmp[n]='1';
          
          strcat(tmp,nomes);
             i=0; 
}  
  
  else { 

      tmp=(char *)malloc(1000);
      strcat(tmp,nomes);
          i=0;
        }

}
void final (char * fin) {
int n=strlen(tmp);

  tmp[n++]=*fin;
  tmp[n]='\0';
   

}

void trataResto() {
  
   nomes[i]='\0';
  
   if(tmp) {
          
          int n=strlen(tmp);
          tmp[n++]=' ';
          strcat(tmp,nomes);
          i=0;

     }
  
  else {

          tmp=(char *) malloc(1000);
          strcat(tmp,nomes);
          i=0;
      }

 }
  
void printFinal() {
i=0;

    printf("%s",tmp);

}

void printResto() {
i=0;   
   int n=strlen(tmp);
         tmp[n++]=',';
       tmp[n]='\0';

      printf("%s",tmp);
}

void printExcep() {
i=0;
printf("%s",tmp);

}


void print(){
i=0;
  char *token;
  int n =strlen(tmp);
 
    tmp[n++]=',';
   tmp[n]='\0';
  token=strtok(tmp,"1"); 
 
   while(token!=NULL){
 
    printf("%s\n",token);

    token =strtok(NULL,"1");
  
}
}
void imprime(char *c){  

i=0;
int t=0;

while(c[t]==' ') {
t++;
 }
  while(c[t]!='\0') {
   nomes[i]=c[t];
   i++;
  t++; 
  
 }  
  nomes[i]='\0';
  i=0;
  printf("%s",nomes);


}

void autor(char* aut){	
	char* nomes;	
	nomes = strtok(aut, "{\n\"");
	nomes = strtok(NULL, "}\n\"");
	char *nome = strstr(nomes, " and ");

	if(nome!=NULL){		
		while(nome != NULL){
			strncpy(nome, "\n", 1);		
			nome = strstr(nomes, " and ");	
		}
		printf("%s", nomes);
	}		
	printf("%s", nomes);
}

%}

auto [Aa][Uu][Tt][Hh][Oo][Rr]
titu [Tt][Ii][Tt][lL][Ee]

%x INICIO

%%

.+	{BEGIN INICIO;}

<INICIO>.*[^@]@.*			{;}
<INICIO>"  "+				{;}
<INICIO>[  ]+"\}"			{;}
<INICIO>{auto}[ ]+"\=".*		{autor(yytext);}





%%

int yywrap() {return 1;}
int main(){
	yylex(); 
	return 0;
}
