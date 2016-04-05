all: ex1

lex.yy.c: ex1.l
	lex ex1.l

comp: main.c
	gcc lex.yy.c -o ex1

main.c: lex.yy.c
