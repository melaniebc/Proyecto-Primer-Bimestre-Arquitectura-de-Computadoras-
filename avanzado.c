#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "avanzado.h"
#include "validaciones.h"
#include "interfaz.h" 

typedef union {
	float flotante;
	uint32_t entero;
} IEEE754;

void imprimir_bits(uint32_t numero, int inicio, int fin) {
	for (int i = inicio; i >= fin; i--) {
		printf("%d", (numero >> i) & 1);
	}
}

void ejecutar_coma_flotante() {
	IEEE754 convertidor;
	char entrada_flotante[50]; 
	
	mostrar_titulo("  FASE 4: COMA FLOTANTE (IEEE 754 - 32 bits)  ");
	
	// Bucle de validacion estricta
	do {
		printf(NEGRITA "\n\t\t  Ingrese un numero con decimales (ej. -13.625): " RESET);
		scanf("%s", entrada_flotante);
		
		if (!es_flotante_valido(entrada_flotante)) {
			printf(ROJO "\t\t  [!] Error: Entrada invalida. Ingrese solo numeros decimales validos.\n" RESET);
		}
	} while (!es_flotante_valido(entrada_flotante));
	
	convertidor.flotante = atof(entrada_flotante);
	
	uint32_t signo = (convertidor.entero >> 31) & 1;
	uint32_t exponente = (convertidor.entero >> 23) & 0xFF;
	uint32_t mantisa = convertidor.entero & 0x7FFFFF;
	
	printf(CIAN "\n\t\t  > Numero original: " RESET "%f\n", convertidor.flotante);
	printf(CIAN "\t\t  > Representacion hexadecimal en memoria: " RESET "0x%08X\n\n", convertidor.entero);
	
	printf(AZUL "\t\t  --- Desglose IEEE 754 ---\n" RESET);
	
	printf(NEGRITA "\t\t  1. Signo (1 bit): " RESET);
	printf(ROJO "%d" RESET, signo);
	if (signo == 1) printf(" (Negativo)\n");
	else printf(" (Positivo)\n");
	
	printf(NEGRITA "\t\t  2. Exponente (8 bits): " VERDE);
	imprimir_bits(exponente, 7, 0);
	printf(RESET " (Decimal: %d, Sesgo real: %d)\n", exponente, exponente - 127);
	
	printf(NEGRITA "\t\t  3. Mantisa (23 bits): " AMARILLO);
	imprimir_bits(mantisa, 22, 0);
	printf(RESET "\n\n");
	
	printf(AZUL "\t\t  Estructura completa de 32 bits en memoria:\n" RESET);
	printf("\t\t  [");
	printf(ROJO "%d" RESET, signo);
	printf("] [");
	
	printf(VERDE);
	imprimir_bits(exponente, 7, 0);
	printf(RESET);
	
	printf("] [");
	
	printf(AMARILLO);
	imprimir_bits(mantisa, 22, 0);
	printf(RESET);
	
	printf("]\n");
}
