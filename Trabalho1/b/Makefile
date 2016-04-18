all: exb

lex.yy.c: exb.l
	lex exb.l

comp: main.c
	gcc lex.yy.c -o exb

main.c: lex.yy.c
