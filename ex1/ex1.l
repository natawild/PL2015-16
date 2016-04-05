%{

typedef struct Est{
	char* cat;
	int i;
	struct est *next;
}Est;

Est* est;

void* novo(){
	est =(Est*) malloc(sizeof(Est));
	est->next = NULL;
	est->cat = NULL;
	est->i = 0;	
}

char* minusculas(char* d){
	char* novo = strdup(d);
	int j=0;
	while(novo[j] != '\0'){
		novo[j]= tolower(novo[j]);
		j++;
	}
	return novo;
}

void* procura(char* c){
	int flag = 1;

		Est* aux;
		aux = est;
		while(aux!=NULL && flag && aux->cat != NULL){
			if(!strcmp(minusculas(aux->cat), minusculas(c+1))){				
				aux->i++;
				flag=0;
			}
			aux=aux->next;
		}				

	if(flag){
		Est* novo = (Est*) malloc(sizeof(Est));
		novo->cat = strdup(c+1);
		novo->i = 1;
		novo->next = est;
		est = novo;
	}
}

%}

%%
@[^{]*	{procura(yytext);}
.|\n	{;}

%%

void print(){
	FILE* fp;
	fp = fopen("ficheiro.html", "w");
	fprintf(fp, "<html>");
	while(est->next!=NULL){
		fprintf(fp, "%s -> %d<br>", est->cat, est->i);
		est = est->next;
	}	
	fprintf(fp, "<\html>");
	fclose(fp);
}

int yywrap() {return 1;}
int main(){
	est = novo();
	yylex();
	print();
	return 0;
}
