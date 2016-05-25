

gramatica: y.tab.c 	 lex.yy.c 	stack.o 
		gcc -o gramatica y.tab.c stack.c

lex.yy.c: gramatica.l 
			flex gramatica.l

y.tab.c: gramatica.y
			yacc -d gramatica.y

stack.o: stack.c stack.h
			gcc -c stack.c 

clean: 
	rm  *.o lex.yy.c y.tab.c y.tab.h gramatica

