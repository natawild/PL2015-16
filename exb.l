%{


char* autor(char* aut){
	char* tok, tok2;
	char* novo = (char*) malloc(sizeof(char)*80);
	strcat(novo,"author = {");
	int i;
	tok = strtok(aut, "\"");
	while(tok != NULL){
		i = 0;
		printf("%s", tok);
		tok2 = strtok(tok, " ");
		while(tok2 != NULL){
		
		tok2 = strtok(NULL, " ");
		}
	tok = strtok(NULL, "\"");
	}
	strcat(novo, "}");
	return novo;
}
%}

%%
"author = ".*	{printf("%s", autor(yytext));}
\"[a-zA-Z] 	{printf("{%c", yytext[1]);}
[a-zA-Z]\" 	{printf("%c}", yytext[0]);}

.|\n	{printf("%s", yytext);}

%%

int yywrap() {return 1;}
int main(){
	yylex();
	return 0;
}
