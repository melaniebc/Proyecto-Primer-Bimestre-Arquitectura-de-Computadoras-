#include <string.h>
#include <ctype.h> 
#include "validaciones.h"

int es_binario_valido(char *cadena) {
	int longitud = strlen(cadena);
	for (int i = 0; i < longitud; i++) {
		if (cadena[i] != '0' && cadena[i] != '1') {
			return 0; // Falso: encontro algo que no es 0 ni 1
		}
	}
	return 1; // Verdadero: todos son 0 o 1
}

int es_octal_valido(char *cadena) {
	int longitud = strlen(cadena);
	for (int i = 0; i < longitud; i++) {
		if (cadena[i] < '0' || cadena[i] > '7') {
			return 0; // Falso: encontro un digito mayor a 7 o una letra
		}
	}
	return 1; // Verdadero
}

int es_hexadecimal_valido(char *cadena) {
	int longitud = strlen(cadena);
	for (int i = 0; i < longitud; i++) {
		char c = cadena[i];
		// Comprobar si es un digito, o una letra de A-F, o una letra de a-f
		if (!isdigit(c) && 
			!(c >= 'A' && c <= 'F') && 
			!(c >= 'a' && c <= 'f')) {
			return 0; // Falso
		}
	}
	return 1; // Verdadero
}
int es_decimal_positivo_valido(char *cadena) {
	int longitud = strlen(cadena);
	
	// Si el usuario por alguna razon ingresa vacio
	if (longitud == 0) return 0; 
	
	for (int i = 0; i < longitud; i++) {
		// isdigit() comprueba si el caracter es un numero del 0 al 9
		if (!isdigit(cadena[i])) {
			return 0; // Falso: Encontro una letra, un espacio o un signo negativo
		}
	}
	return 1; // Verdadero: Todo esta limpio
}
int es_entero_valido(char *cadena) {
	int longitud = strlen(cadena);
	if (longitud == 0) return 0;
	
	int inicio = 0;
	
	// Si el primer caracter es un signo negativo, es valido, pero empezamos a revisar desde el segundo
	if (cadena[0] == '-' || cadena[0] == '+') {
		// Un solo guion "-" no es un numero valido
		if (longitud == 1) return 0; 
		inicio = 1;
	}
	
	// Revisar el resto de la cadena
	for (int i = inicio; i < longitud; i++) {
		if (!isdigit(cadena[i])) {
			return 0; // Encontro una letra o un simbolo invalido
		}
	}
	return 1;
}

int es_flotante_valido(char *cadena) {
	int longitud = strlen(cadena);
	if (longitud == 0) return 0;
	
	int inicio = 0;
	int puntos_decimales = 0;
	
	if (cadena[0] == '-' || cadena[0] == '+') {
		if (longitud == 1) return 0; // Un solo signo suelto no es valido
		inicio = 1;
	}
	
	// Revisar el resto de la cadena
	for (int i = inicio; i < longitud; i++) {
		if (cadena[i] == '.') {
			puntos_decimales++;
			if (puntos_decimales > 1) return 0; // M�s de un punto decimal es error
		} else if (!isdigit(cadena[i])) {
			return 0; // Encontro una letra o un simbolo invalido
		}
	}
	return 1; // Verdadero: Es un flotante limpio
}
	
