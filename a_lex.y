%{
#include <stdio.h>
void yyerror();
extern int yylex();
extern int yylineno;
%}
%union{
	char *cad;
}

%token VAR CONST INT IF ELSE WHILE PRINT READ LPAREN RPAREN SEMICOLON COMA IGUAL INTERROGACION DOSPUNTOS LKEY RKEY 

%token <cad> ID  
%token <cad> INTLITERAL  /*PARA OPERACIONES CON expresion que deriva en ID o NUM directamente*/
%token <cad> CADENA
%left PLUSOP MINUSOP
%left ASTERISCO BARRA
%left UMENOS /*PREGUNTAR PROFESORA SI HACE FALTA añadirlo al .h --> NO SABEMOS SI EL lexico1.h sirve o ya no hace falta con el tab.h*/

%expect 1 /*Para que no muestre el warning de la precedencia del if-else*/

/*PREGUNTAR PROFESORA %type <char> expresion*/
/*PRETUNAR PROFESORA SI HACE FALTA ESTO {$$ = $1 + $3; }*/
/*PREGUNTAR PROFESORA SI ESTO DEL OUTPUT Estado 72 conflictos: 1 desplazamiento/reducción ESTÁ BIEN*/ 
%% 
	programa: 
		ID LPAREN RPAREN LKEY declaraciones lista_instrucciones RKEY {printf("Fin del programa");} 
		;


	declaraciones:
		declaraciones VAR tipo lista_variables SEMICOLON   
		| declaraciones CONST tipo lista_ctes SEMICOLON /*const int x,y,z*/ 
		| 
		;

		
	tipo:
		INT
		;


	lista_variables:
		ID
		| lista_variables COMA ID /*a,b*/
		;
		
		
	lista_ctes:
		ID IGUAL expresion /*a = b+c*/
		| lista_ctes COMA ID IGUAL expresion /*x = 5, y = 10*/
		;
		

	lista_instrucciones:
		lista_instrucciones instruccion
		| /*λ*/
		;

		
	instruccion:
		ID IGUAL expresion SEMICOLON
		| LKEY lista_instrucciones RKEY
		| IF LPAREN expresion RPAREN instruccion ELSE instruccion
		| IF LPAREN expresion RPAREN instruccion
		| WHILE LPAREN expresion RPAREN instruccion 
		| PRINT LPAREN lista_impresion RPAREN SEMICOLON
		| READ  LPAREN lista_lectura RPAREN SEMICOLON
		| error SEMICOLON {}
		;
		
			
	lista_impresion: 
		item_impreso
		| lista_impresion COMA item_impreso
		;
		
	item_impreso: 
		expresion
		| CADENA
		;
		

	lista_lectura: 
		ID
		| lista_lectura COMA ID 
		;
		
		
	expresion: 
		expresion PLUSOP expresion 
		| expresion MINUSOP expresion 
		| expresion ASTERISCO expresion
		| expresion BARRA expresion 
		| LPAREN expresion INTERROGACION expresion DOSPUNTOS expresion RPAREN 
		| UMENOS expresion
		| LPAREN expresion RPAREN 
		| ID 
		| INTLITERAL
		;
	
%% 

void yyerror(const char *s) {
    extern char *yytext;
    fprintf(stderr, "Error sintáctico en '%s' en línea %d: %s\n", yytext, yylineno, s);
}

