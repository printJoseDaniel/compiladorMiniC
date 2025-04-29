%{
#include "listaCodigo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listaSimbolos.h"
Lista tablaSimb;
int contCadenas = 0;
void imprimirTablaS();
void yyerror();
int analisis_ok();
int errores;
int erroresLexicos = 0; /* Si luego no nos va probar con extern */
int erroresSemanticos = 0;
int erroresSintacticos = 0;
Tipo tipo;
extern int yylex();
extern int yylineno;
void insertaTablaString(char* id, int tipo);
int esConstante(char* id);
void insertaTablaIdentificador(char* nombre, int tipo);
int perteneceTabla(char* id);

/*MANEJO DE REGISTROS*/
char registros[10]; // 10 registros temporales
void inicializarRegistros();
char *elegirRegistroDisponible();
void liberarRegistro(char *reg);
char* concatena(char* str1, char* str2);


/*GENERACIÓN DE CÓDIGO*/
char* concatena(char* str1, char* str2);
void generarOperacionUnaria(ListaC $$, ListaC $1, char *operador);
void generarOperacionBinaria(ListaC $$, ListaC $1, ListaC $3, char *operador);


void imprimirLC(ListaC codigo);
%}


%union{
	char *cad;
	ListaC codigo; /*Porque vamos a tener atributos de este tipo*/
}


%token VAR CONST INT IF ELSE WHILE PRINT READ LPAREN RPAREN SEMICOLON COMA IGUAL INTERROGACION DOSPUNTOS LKEY RKEY 

%token <cad> ID
%token <cad> INTLITERAL  /*PARA OPERACIONES CON expresion que deriva en ID o NUM directamente*/
%token <cad> STRING


%left PLUSOP MINUSOP
%left ASTERISCO BARRA
%left UMENOS 

/* Tipo de dato de los no terminales */
%type <codigo> programa declaraciones lista_instrucciones expresion lista_variables lista_ctes instruccion /*Los atributos correspondientes al no terminal expression van a ser de tipo codigo*/

%expect 1 /*Para que no muestre el warning de la precedencia del if-else*/

// Ese conflicto desplazamiento reducción es porque una sentencia if-else tiene 2 árboles distintos cuando tengo 2 ifs y 1 else debe asociarse con el if más proximo 
// COMO HAY QUE HACER DESPLAZAMIENTO Y BISON LO HACE AUTOMÁTICAMENTE NO HACE FALTA HACERLO

%% 
	programa: {
		tablaSimb=creaLS(); 
		inicializarRegistros();
	} 
	ID LPAREN RPAREN LKEY declaraciones lista_instrucciones RKEY {
		imprimirTablaS(); 									// Imprime la tabla de símbolos
		concatenaLC($6, $7);  								// Concatena declaraciones e instrucciones
		//imprimirLC($6), 									// Imprime el código intermedio resultante
		liberarRegistro(recuperaResLC($6)),  				// Libera registro de la última expresión evaluada 
		liberarRegistro(recuperaResLC($7)),  				// Libera registro de la última expresión evaluada
		liberaLC($6);										// Libera la lista de código intermedio
		liberaLC($7);										// Libera la lista de código intermedio
		liberaLS(tablaSimb); 								// Limpia la tabla de símbolos
		printf("Fin del programa");
		;
	}
	;


	declaraciones: 
		declaraciones VAR tipo lista_variables SEMICOLON {
			if(analisis_ok()) {
				$$ = $1;
				concatenaLC($$, $4); // Concatena la lista de instrucciones
				liberaLC($4);
			}
		}
		| declaraciones CONST tipo lista_ctes SEMICOLON { /*const int x,y,z*/ 
			if (analisis_ok()) {
            	$$ = $1;
         	    concatenaLC($$, $4);
            	liberaLC($4);
        }
		}
		| { $$ = creaLC(); } /*λ*/ 
		;

		
	tipo:
		INT
		;


	lista_variables:
		ID {
			if (!perteneceTabla($1)) { 
				insertaTablaIdentificador($1, VARIABLE);
			} else {
				printf ("Variable %s ya declarada \n", $1);
			}
		$$ = creaLC();  // No hay inicialización, lista vacía
		}
		| lista_variables COMA ID {
			if (!perteneceTabla($3)) {
				insertaTablaIdentificador($3, VARIABLE); 
			} else { 
				printf ("Variable %s ya declarada \n", $3); /*a,b*/
			}
		$$ = $1; // Reutiliza la lista de la izquierda, aunque esté vacía
		}
		;
		
		
	lista_ctes:
		ID IGUAL expresion {
			if (!perteneceTabla($1)) { 
				insertaTablaIdentificador($1, CONSTANTE);
			} else {
				printf ("Constante %s ya declarada \n", $1);	
			}  
		} /*a = b+c*/
		| lista_ctes COMA ID IGUAL expresion {if (!perteneceTabla($3)) insertaTablaIdentificador($3, CONSTANTE);
							                  else printf ("Constante %s ya declarada \n", $3);} /*x = 5, y = 10*/
		;
		

	lista_instrucciones:
		lista_instrucciones instruccion
		| { $$ = creaLC(); } /*λ*/
		;

		
	instruccion:
		ID IGUAL expresion SEMICOLON {
			if (!perteneceTabla($1)) {
				printf("Variable %s no declarada \n",$1);
				$$ = creaLC();
				liberaLC($3);			
			} else if  (esConstante($1)) {
				printf("Asignacióin a constante %s no permitida\n", $1);
				$$ = creaLC();
				liberaLC($3);			
			 	/* {printf($1)...} Impirmir todos los ID para ver los lexemas y depurar */
			} else {
				$$ = $3;
				Operacion operacion;
				operacion.op = "sw";
				operacion.res = recuperaResLC($3);
				operacion.arg1 = concatena("_", $1);
				operacion.arg2 = NULL;

				insertaLC($$, finalLC($$), operacion);
				liberarRegistro(operacion.res);
			}
		}
		| LKEY lista_instrucciones RKEY {
			
		}
		| IF LPAREN expresion RPAREN instruccion ELSE instruccion {
			if (analisis_ok()) {
				$$ = $3; // Lo primero que se hace es evaluar si es correcta o no 
			}
		}
		| IF LPAREN expresion RPAREN instruccion {

		}
		| WHILE LPAREN expresion RPAREN instruccion  {

		}
		| PRINT LPAREN lista_impresion RPAREN SEMICOLON {

		}
		| READ  LPAREN lista_lectura RPAREN SEMICOLON {

		}
		| error SEMICOLON 
		;
		

	lista_impresion: 
		item_impreso
		| lista_impresion COMA item_impreso
		;
		
	item_impreso: 
		expresion
		| STRING {insertaTablaString($1, CADENA);}
		;
		

	lista_lectura: 
		ID {if (!perteneceTabla($1)) printf ("Variable %s no declarada \n", $1);
			else if (esConstante($1)) printf ("Asignación a constante \n");}
		| lista_lectura COMA ID {if (!perteneceTabla($3)) printf ("Variable %s no declarada \n", $3);
	                             else if (esConstante($3)) printf ("Asignación a constante \n");}
		;
		
		
	expresion: 
		expresion PLUSOP expresion {
		    if (analisis_ok()) {
        		$$ = creaLC(); // No sé si hay que crear una nueva lista o reutilizar la de la izquierda 
        		generarOperacionBinaria($$, $1, $3, "add");
    		}
		}
		| expresion MINUSOP expresion {
		    if (analisis_ok()) {
        		$$ = creaLC();
        		generarOperacionBinaria($$, $1, $3, "sub");
    		}
		}
		| expresion ASTERISCO expresion {
		    if (analisis_ok()) {
        		$$ = creaLC();
        		generarOperacionBinaria($$, $1, $3, "mul");
    		}
		}
		| expresion BARRA expresion {
		    if (analisis_ok()) {
        		$$ = creaLC();
        		generarOperacionBinaria($$, $1, $3, "div");
    		}
		}
		| LPAREN expresion INTERROGACION expresion DOSPUNTOS expresion RPAREN {
			/* TERNARIA MÁS ADELANTE */
		}
		| UMENOS expresion {
	    	if (analisis_ok()) {
        		$$ = creaLC();                  		// Crea una nueva lista
        		generarOperacionUnaria($$, $2, "neg");  // Genera la operación unaria (-x)
        		liberaLC($2);                  			// Libera la lista de $2
    		}
		}
		| LPAREN expresion RPAREN { 
			$$ = $2; 
		}
		| ID {
    		if (analisis_ok() && perteneceTabla($1)) {
				$$ = creaLC();

				Operacion operacion;
				operacion.op = strdup("lw");
				char *varName;
		        asprintf(&varName, "_%s", $1);
        		operacion.arg1 = varName;
				operacion.arg2 = NULL;
				operacion.res = elegirRegistroDisponible();

				insertaLC($$, finalLC($$), operacion);
				guardaResLC($$, operacion.res);
			} else {
				printf("Variable %s no declarada \n", $1);
			}
		}
		| INTLITERAL {    
			if (analisis_ok()) {
				$$ = creaLC();

				Operacion operacion;
				operacion.op = "li";
				operacion.arg1 = strdup($1);
				operacion.arg2 = NULL;
				operacion.res = elegirRegistroDisponible();

				insertaLC($$, finalLC($$), operacion);
				guardaResLC($$, operacion.res);
    		}
		}
		;
	
%% 
/*Después de este %% es la sección de código*/

void imprimirTablaS() {
    printf("\t.data\n\n");  

    // Primero imprime las cadenas
    printf("# Cadenas del programa\n");
    PosicionLista p = inicioLS(tablaSimb);
    while (p != finalLS(tablaSimb)) {
        Simbolo aux = recuperaLS(tablaSimb, p);
        if (aux.tipo == CADENA) {
            printf("$str%d:\n", aux.valor);
            printf("\t.asciiz \"%s\"\n", aux.nombre);
        }
        p = siguienteLS(tablaSimb, p);
    }

    // Luego las variables y constantes
    printf("\n# Variables y constantes\n");
    p = inicioLS(tablaSimb);
    while (p != finalLS(tablaSimb)) {
        Simbolo aux = recuperaLS(tablaSimb, p);
        if (aux.tipo != CADENA) {
            printf("_%s:\n", aux.nombre);
            printf("\t.word %d\n", aux.valor);
        }
        p = siguienteLS(tablaSimb, p);
    }
}


/*COMPRUEBA SI YA ESTÁ EN LA TABLA*/
int perteneceTabla(char* id) {
	int pertenece = 0;
	
	PosicionLista posicion = buscaLS(tablaSimb, id);
	if(posicion != finalLS(tablaSimb)) {
		pertenece = 1;	
		errores++;
	}
	return pertenece;	
}


/* INSERTA CUANDO SE HA COMPROBADO PREVIAMENTE CON perteneceTabla que no está definida */
void insertaTablaIdentificador(char* nombre, int tipo) {
	if (tipo != CADENA) {
		Simbolo simbolo;
		simbolo.nombre = nombre;
		simbolo.tipo = tipo;
		
		insertaLS(tablaSimb, finalLS(tablaSimb), simbolo);
	}
}


int esConstante(char* id) {
	// llamar a buscaLS que lo recupera y entonces ver el tipo 
	PosicionLista p = buscaLS(tablaSimb, id);
	Simbolo aux;
	if (p != finalLS(tablaSimb)) {
		Simbolo aux = recuperaLS(tablaSimb, p);
		errores++;
	}	
	return (aux.tipo==CONSTANTE);
}


void insertaTablaString(char* id, int tipo) {
	if (tipo == CADENA) {
		Simbolo simbolo;
		simbolo.nombre = id;
		simbolo.tipo = tipo;
		simbolo.valor = ++contCadenas;
		insertaLS(tablaSimb, finalLS(tablaSimb), simbolo);
	}
}


void yyerror(const char *msg) {
    extern char *yytext;
    fprintf(stderr, "Error sintáctico en '%s' en línea %d: %s\n", yytext, yylineno, msg);
}


/*FUNCIONES PARA MANEJAR LOS REGISTROS*/
/*Inicializa el array con los 10 registros (0-9) con valor 0 indicando que no están en uso*/
void inicializarRegistros(){ 
  for(int i = 0; i < 10; i++){
	registros[i]=0;
  }
}

/*Busca el siguiente registro disponible o devuelve error si no quedan libres*/
char *elegirRegistroDisponible(){
  for(int i = 0; i < 10; i++){
    if(registros[i]==0){
      registros[i]=1;
      char* reg;
      //printf en una posicion de memoria que yo le digo, el puntero a la cadena de caracteres que se va a montar
      asprintf(&reg,"$t%d",i); //sirve como para hacer la concatenación, guarda la cadena en la memoria apuntada por la variable
      return reg;
    }
  }
  printf("Error registros temporales agotados!\n");
  exit(1);
}


//Libera el registro que se le pasa como argumento
void liberarRegistro(char *reg){
  int idx = atoi(&(reg[2])); //posicion 3 de la cadena $=pos0 t=pos1 X=pos2
  registros[idx]=0;
}


/* FUNCIÓN COMPROBACIÓN DE ERRORES */
int analisis_ok() {
    return errores == 0;
}


/* FUNCIONES PARA GENERAR CÓDIGO INTERMEDIO */
void generarOperacionUnaria(ListaC $$, ListaC $1, char *operador) {	
	concatenaLC($$, $1);
	
	// Crea la operación unaria
    Operacion operacion;
    operacion.op = strdup(operador);               // Operador
    operacion.arg1 = recuperaResLC($$);            // Operando
    operacion.arg2 = NULL;                         // Null ya que no hay segundo operando
    operacion.res = elegirRegistroDisponible();	   // Dónde guardamos el resultado final

    guardaResLC($$, operacion.res);				   // Guarda el resultado en la lista de código $$	
    insertaLC($$, finalLC($$), operacion); 		   // Inserta la operación al final de la lista
	liberarRegistro(operacion.arg1);			   // Libera el registro 
    
}


void generarOperacionBinaria(ListaC $$, ListaC $1, ListaC $3, char *operador) {
    concatenaLC($$, $1);                        // Concatena izquierda
    concatenaLC($$, $3);                        // Concatena derecha

    Operacion operacion;
    operacion.op = strdup(operador);            // Operador
    operacion.arg1 = recuperaResLC($1);         // Operando izquierdo
    operacion.arg2 = recuperaResLC($3);         // Operando derecho
    operacion.res = elegirRegistroDisponible(); // Resultado en nuevo registro

    guardaResLC($$, operacion.res);             // Guarda el resultado en la lista
    insertaLC($$, finalLC($$), operacion);      // Inserta operación al final

    liberaLC($1);                               // Libera código izquierdo
    liberaLC($3);                               // Libera código derecho

    liberarRegistro(operacion.arg1);            // Libera registro izquierdo
    liberarRegistro(operacion.arg2);            // Libera registro derecho
}


char* concatena(char* str1, char* str2) {
    char* resultado = malloc(strlen(str1) + strlen(str2) + 1); // +1 para el '\0'
    if (resultado == NULL) {
        fprintf(stderr, "Error al reservar memoria en concatena\n");
        exit(1);
    }
    strcpy(resultado, str1);
    strcat(resultado, str2);
    return resultado;
}
