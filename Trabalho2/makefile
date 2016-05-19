

gramatica: y.tab.c 	 lex.yy.c 
		gcc -o gramatica y.tab.c

lex.yy.c: parser.l 
			flex parser.l

y.tab.c: gramatica.y
			yacc -d gramatica.y


clean: 
	rm *.o lex.yy.c y.tab.c y.tab.h y

