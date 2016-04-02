%{
#include<string.h>
char  nomes[1000];
int i=0;
char *tmp;
char *f;

char * inser(char *texto) {
nomes[i]=*texto;
i++;
return nomes;
}

char* trata() {
      nomes[i]='\0';
 
   int variavel =1;

  if(nomes[variavel]==' ') {
   char kill[1000]; int o=0;
   while(nomes[variavel]==' ') {variavel++;}
   while(nomes[variavel]!='\0') {
       kill[o]=nomes[variavel];
       o++;
      variavel++;
}    kill[o]='\0';
   o=0;
   while(kill[o]!='\0') {
       nomes[o]=kill[o];
    o++;
  }
   
 nomes[o]='\0';

}

  int n= strlen(nomes);
int j=n-1;


while(nomes[j]==' '){j--;}

while(nomes[j]!=' ' && j!=0){
j--;
}  
int k=1;
nomes[k]='.';
k++;

if(j!=0) {
while(nomes[j]!='\0') {

      nomes[k]=nomes[j];
     j++;
     k++;
}

nomes[k]='\0';
i=0;
return nomes;
}
else { 
nomes[k]='\0';i=0;
return nomes; }


}

char* funcao(char *c) {

if (tmp) { 
 
i=0;
  strcat(tmp," and ");
int n=strlen(tmp);
int j=0;
tmp[n]=' ';
n++;

for (j=0;c[j]!='\0';j++) {

   tmp[n]=c[j];
   n++;

}
tmp[n]='\0';

}

else {
i=0; 
int j=0;
tmp=(char *)malloc(1000);
  
   for(j=0;c[j]!='\0';j++) {
             tmp[j]=c[j]; 
 
  }
         tmp[j]='\0';

}

return tmp;

}



void print() {

char h[1000]="author = {";

strcat(h,tmp);
int n=strlen(h);
h[n]='}';
n++;
h[n++]=',';

h[n]='\0';
printf("%s",h);

}






%}


%x AUT

%%


"author = \""  {BEGIN (AUT);} 
"author = \{"  {BEGIN (AUT);} 

<AUT>"\}"  {inser(yytext); }
<AUT>"\""  {inser(yytext); }
<AUT>"\,"[ ]+  {f=trata();f=funcao(f);} 
<AUT>[ ]+"and"[ ]+  {f=trata();f=funcao(f);}
<AUT>[ ]+"and"(\n)  {f=trata();f=funcao(f);}
<AUT>"\"""\,"     {f=trata();f=funcao(f);print();tmp=NULL;BEGIN INITIAL;}
<AUT>"\}""\,"     {f=trata();f=funcao(f);print();tmp=NULL;BEGIN INITIAL;}
<AUT>[ '-}] {inser(yytext); }  

\"[a-zA-Z] 	{printf("{%c", yytext[1]);}
[a-zA-Z]\" 	{printf("%c}", yytext[0]);}


%%

int yywrap() {return 1;}
int main(){
	yylex();
        
  free(tmp);    
	return 0;
}
