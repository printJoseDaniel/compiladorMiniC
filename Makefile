a_lex: main_proyecto.c a_lex.tab.c lex.yy.c a_lex.tab.h listaSimbolos.h listaSimbolos.c listaCodigo.h listaCodigo.c
	gcc lex.yy.c main_proyecto.c a_lex.tab.c listaSimbolos.c listaCodigo.c -lfl -o a_lex 

a_lex.tab.c a_lex.tab.h: a_lex.y
	bison -d -v a_lex.y 
	
lex.yy.c: analizadorLexicoMiniC.l
	flex analizadorLexicoMiniC.l

limpia:
	rm lex.yy.c a_lex.tab.c a_lex.tab.h a_lex

run:
	./a_lex entrada
