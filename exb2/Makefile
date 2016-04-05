all: exb2

lex.yy.c: exb2.l
	lex exb2.l

comp: main.c
	gcc lex.yy.c -o exb2

main.c: lex.yy.c
