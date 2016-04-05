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

%x AUT
%x TITLE
%x INICIO
%x ALL
%x IN
%%

.+	{BEGIN INICIO;}

<INICIO>.*[^@]@.*			{;}
<INICIO>"  "+				{;}
<INICIO>[  ]+"\}"			{;}
<INICIO>{auto}[ ]+"\=".*		{autor(yytext);}




%{
/*
<INICIO>"\}"				{BEGIN INITIAL;imprime(yytext);}
<INICIO>[ ]+{titu}[ ]+"\="[ ]+        {BEGIN (TITLE);imprime(yytext);}
<INICIO>[ ]+{auto}[ ]+"\="[ ]+        {BEGIN (AUT);}
<INICIO>[ ]+[A-Za-z]+[ ]+"\="[ ]+      {BEGIN (ALL);imprime(yytext);}
<INICIO>[ ]+.+[ ]+"\="[ ]+             {BEGIN (ALL);imprime(yytext);}

<AUT>"\}"           {inser(yytext);} 
<AUT>"\""           {inser(yytext); }
<AUT>"\,"[ ]+       {trata();} 
<AUT>[ ]+"and"[ ]+  {trata();}
<AUT>[ ]+"and"(\n)  {trata();}
<AUT>"\"""\,"       {trata();final(yytext);print();tmp=NULL;BEGIN INICIO;}
<AUT>"\}""\,"       {trata();final(yytext);print();tmp=NULL;BEGIN INICIO;}
<AUT>[ '-}]         {inser(yytext);} 



<TITLE>"\}"           {inser(yytext);}  
<TITLE>[ ]+           {trataResto();} 
<TITLE>"\"""\,"       {trataResto();final(yytext);printResto();tmp=NULL;BEGIN INICIO;}
<TITLE>"\}""\,"       {trataResto();final(yytext);printResto();tmp=NULL;BEGIN INICIO;}
<TITLE>['-~]         {inser(yytext);} 

<ALL>"&"            {inser(yytext);}
<ALL>"\{"           {inser(yytext);}
<ALL>"\""(\n)       {trataResto();final(yytext);printExcep();tmp=NULL;BEGIN INICIO;}
<ALL>"\,"           {trataResto();printResto();tmp=NULL;BEGIN INICIO;}
<ALL>[ ]+           {trataResto();}
<ALL>"\}"           {inser(yytext);}
<ALL>"\}"[ ]+       {trataResto();final(yytext);printResto();tmp=NULL;BEGIN INICIO;}
<ALL>"\}"(\n)       {trataResto();final(yytext);printResto();tmp=NULL;BEGIN INICIO;}
<ALL>"\"""\,"       {trataResto();final(yytext);printResto();tmp=NULL;BEGIN INICIO;}
<ALL>"\}""\,"       {trataResto();final(yytext);printResto();tmp=NULL;BEGIN INICIO;}
<ALL>"\""[ ]+       {trataResto();final(yytext);printFinal();tmp=NULL;BEGIN INICIO;}
<ALL>[ ]+[1-9]+     {inser(yytext);}
<ALL>['-~]          {inser(yytext);}
*/
%}

%%

int yywrap() {return 1;}
int main(){
	yylex(); 
	return 0;
}
