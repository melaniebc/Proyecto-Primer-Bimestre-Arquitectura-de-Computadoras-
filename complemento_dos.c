#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "complemento_dos.h"

// Funcion auxiliar para verificar el overflow (desbordamiento)
int verificar_overflow(int decimal, int num_bits) {
	// Calculamos los limites con operadores de bits (1 << N es como 2 elevado a N)
	int max_val = (1 << (num_bits - 1)) - 1;
	int min_val = -(1 << (num_bits - 1));
	
	if (decimal >= min_val && decimal <= max_val) {
		return 1; // Valido
	}
	return 0; // Hay Overflow
}

// PASO A: Representacion en Complemento a Dos
void decimal_a_complemento_dos(int decimal, int num_bits, char *resultado) {
	if (!verificar_overflow(decimal, num_bits)) {
		strcpy(resultado, "ERROR_OVERFLOW");
		return;
	}
	
	// 1. Convertir valor absoluto a binario
	int abs_val = abs(decimal);
	int indice = 0;
	
	if (abs_val == 0) {
		resultado[indice++] = '0';
	} else {
		while (abs_val > 0) {
			resultado[indice++] = (abs_val % 2) + '0';
			abs_val /= 2;
		}
	}
	resultado[indice] = '\0';
	
	// Invertir la cadena (porque las divisiones salen al reves)
	for (int i = 0; i < indice / 2; i++) {
		char temp = resultado[i];
		resultado[i] = resultado[indice - 1 - i];
		resultado[indice - 1 - i] = temp;
	}
	
	// 2. Rellenar con ceros a la izquierda hasta tener N bits
	int longitud_actual = strlen(resultado);
	int ceros_faltantes = num_bits - longitud_actual;
	if (ceros_faltantes > 0) {
		char temp[100] = "";
		for (int i = 0; i < ceros_faltantes; i++) {
			strcat(temp, "0");
		}
		strcat(temp, resultado);
		strcpy(resultado, temp);
	}
	
	// 3. Si es negativo, aplicar C1 y Ca2
	if (decimal < 0) {
		// Complemento a Uno (C1): Invertir bits
		for (int i = 0; i < num_bits; i++) {
			resultado[i] = (resultado[i] == '0') ? '1' : '0';
		}
		
		// Complemento a Dos (Ca2): Sumar 1
		int acarreo = 1;
		for (int i = num_bits - 1; i >= 0; i--) {
			if (resultado[i] == '1' && acarreo == 1) {
				resultado[i] = '0'; // 1 + 1 = 0 y llevo 1
			} else if (resultado[i] == '0' && acarreo == 1) {
				resultado[i] = '1'; // 0 + 1 = 1 y ya no llevo nada
				acarreo = 0;
			}
		}
	}
}


// PASO B: Verificacion (Revertir de Ca2 a Decimal)

int complemento_dos_a_decimal(char *ca2) {
	int num_bits = strlen(ca2);
	int decimal = 0;
	
	// En C2, el bit mas significativo (el de la izquierda) tiene peso negativo
	if (ca2[0] == '1') {
		decimal -= (1 << (num_bits - 1));
	}
	
	// Los demas bits tienen peso positivo normal
	for (int i = 1; i < num_bits; i++) {
		if (ca2[i] == '1') {
			decimal += (1 << (num_bits - 1 - i));
		}
	}
	
	return decimal;
}
