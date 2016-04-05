%{ 
#include<string.h>

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



%%

int yywrap() {return 1;}
int main(){
	yylex(); 
	return 0;
}
