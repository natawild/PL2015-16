%{ 
#include<string.h>
char nomes[1000];
int i=0;

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
	}		
	printf("author = %s", nomes);
}

%}

auto [Aa][Uu][Tt][Hh][Oo][Rr]


%x INICIO

%%

.+	{BEGIN INICIO;}

<INICIO>.*[^@]@.*			{ECHO;}
<INICIO>"  "+				{;}
<INICIO>[  ]+"\}"			{;}
<INICIO>{auto}[ ]+"\=".*		{autor(yytext);}





%%

int yywrap() {return 1;}
int main(){
	yylex(); 
	return 0;
}
