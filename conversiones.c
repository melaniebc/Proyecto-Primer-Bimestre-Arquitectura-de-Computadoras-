#include <stdio.h>
#include <string.h>
#include "conversiones.h"

// Funcion auxiliar para invertir la cadena de texto
void invertir_cadena(char *cadena) {
	int longitud = strlen(cadena);
	for (int i = 0; i < longitud / 2; i++) {
		char temp = cadena[i];
		cadena[i] = cadena[longitud - 1 - i];
		cadena[longitud - 1 - i] = temp;
	}
}

// 1. Conversion de Decimal a Binario (Base 2)
void decimal_a_binario(int decimal, char *resultado) {
	if (decimal == 0) {
		strcpy(resultado, "0");
		return;
	}
	
	int indice = 0;
	while (decimal > 0) {
		resultado[indice] = (decimal % 2) + '0'; // Obtener el residuo y convertirlo a caracter
		decimal = decimal / 2;
		indice++;
	}
	resultado[indice] = '\0'; // Finalizar la cadena de texto
	invertir_cadena(resultado); // Acomodar los bits en el orden correcto
}

// 2. Conversion de Decimal a Octal (Base 8)
void decimal_a_octal(int decimal, char *resultado) {
	if (decimal == 0) {
		strcpy(resultado, "0");
		return;
	}
	
	int indice = 0;
	while (decimal > 0) {
		resultado[indice] = (decimal % 8) + '0';
		decimal = decimal / 8;
		indice++;
	}
	resultado[indice] = '\0';
	invertir_cadena(resultado);
}

// 3. Conversion de Decimal a Hexadecimal (Base 16)
void decimal_a_hexadecimal(int decimal, char *resultado) {
	if (decimal == 0) {
		strcpy(resultado, "0");
		return;
	}
	
	// Arreglo con los caracteres validos en hexadecimal
	char digitos_hex[] = "0123456789ABCDEF";
	int indice = 0;
	
	while (decimal > 0) {
		resultado[indice] = digitos_hex[decimal % 16]; // Mapear el residuo a su respectiva letra/n�mero
		decimal = decimal / 16;
		indice++;
	}
	resultado[indice] = '\0';
	invertir_cadena(resultado);
}



// FASE 2: Conversion de Otras Bases a Decimal

// Funcion auxiliar matematica para evitar usar <math.h> ni la función pow()
int calcular_potencia(int base, int exponente) {
	int resultado = 1;
	for (int i = 0; i < exponente; i++) {
		resultado *= base;
	}
	return resultado;
}

// Funcion auxiliar para obtener el valor numerico de un caracter hexadecimal
int valor_hexadecimal(char c) {
	if (c >= '0' && c <= '9') return c - '0';
	if (c >= 'A' && c <= 'F') return c - 'A' + 10;
	if (c >= 'a' && c <= 'f') return c - 'a' + 10;
	return 0;
}

// 1. Conversion de Binario a Decimal
int binario_a_decimal(char *binario) {
	int decimal = 0;
	int longitud = strlen(binario);
	
	for (int i = 0; i < longitud; i++) {
		int digito = binario[i] - '0'; // Convertir caracter a entero
		int posicion = longitud - 1 - i;
		decimal += digito * calcular_potencia(2, posicion);
	}
	return decimal;
}

// 2. Conversion de Octal a Decimal
int octal_a_decimal(char *octal) {
	int decimal = 0;
	int longitud = strlen(octal);
	
	for (int i = 0; i < longitud; i++) {
		int digito = octal[i] - '0';
		int posicion = longitud - 1 - i;
		decimal += digito * calcular_potencia(8, posicion);
	}
	return decimal;
}

// 3. Conversion de Hexadecimal a Decimal
int hexadecimal_a_decimal(char *hexadecimal) {
	int decimal = 0;
	int longitud = strlen(hexadecimal);
	
	for (int i = 0; i < longitud; i++) {
		int digito = valor_hexadecimal(hexadecimal[i]);
		int posicion = longitud - 1 - i;
		decimal += digito * calcular_potencia(16, posicion);
	}
	return decimal;
}
