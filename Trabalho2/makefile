

gramatica: y.tab.c 	 lex.yy.c 
		gcc -o gramatica y.tab.c

lex.yy.c: gramatica.l 
			flex gramatica.l

y.tab.c: gramatica.y
			yacc -d gramatica.y

clean: 
	rm  lex.yy.c y.tab.c y.tab.h gramatica

