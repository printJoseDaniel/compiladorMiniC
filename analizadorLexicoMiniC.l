%{
#include "listaCodigo.h"
#include "a_lex.tab.h"
%}
%option yylineno
digito              [0-9]
letra               [a-zA-Z]
entero              {digito}+
simbolo             [$_]
escape		    \\.
	// ni comilla ni \n ni 
	// Comentarios tienen que ser tabulados y como en c 

%x    														COM
%%

"/*"														BEGIN COM;
<COM>[^*]*													;
<COM>[*]+[^/*]*												;
<COM>[*]+[/] 													BEGIN(0);

[ \n\t\r]+                                                      ;
	/* Comentario de una linea:*/
"//"(.*)\n                                                    ;
var                                                            	return VAR;
const                                                           return CONST;
int                                                            	return INT;
if                                                            	return IF;
else                                                            return ELSE;
while                                                           return WHILE;
print                                                           return PRINT;
read                                                          	return READ;
\"([^"\n\\]|{escape})*\"					return STRING;

	/* Despues de reconocer usar yylength*/
({letra}|{simbolo})({letra}|{digito}|{simbolo})*        { 
								if (yyleng >32){ 
									printf("Error léxico: Cadena demasiado larga -->");
								}
								yylval.cad=strdup(yytext);
								return ID;
							}
	/* Despues de reconocer mirar q valor abs menor o igual a 2147483648*/
{entero}                                                {  
								if (atoll(yytext) > 2147483648){
									printf("Error léxico: Número demasiado grande -->");
								}
								yylval.cad=strdup(yytext);
								return INTLITERAL;
							}

"/"								return BARRA;
"*"								return ASTERISCO;
"("                                                             return LPAREN;		
")"                                                             return RPAREN;
";"                                                             return SEMICOLON;
","                                                             return COMA;
"="                                                             return IGUAL;
"+"                                                             return PLUSOP;
"-"                                                             return MINUSOP;
"?"								return INTERROGACION;
":"								return DOSPUNTOS;
"{"                                                             return LKEY;		
"}"                                                             return RKEY;
	/* Modo Pánico*/
([^a-zA-Z0-9$_();:,=+\-{}\n\t\s/*?"])+ 		printf("Error léxico en caracteres %s no reconocidos en linea %d\n",yytext, yylineno);
%%
