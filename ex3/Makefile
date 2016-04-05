all: grafo

lex.yy.c: grafo.l
	lex grafo.l

comp: main.c
	gcc lex.yy.c -o grafo

main.c: lex.yy.c
