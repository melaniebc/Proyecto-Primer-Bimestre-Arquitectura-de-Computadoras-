#include <stdio.h>
#include <windows.h> 
#include "interfaz.h"

void mostrar_barra_carga() {
	printf(AMARILLO "\n\t\t Cargando sistema... " RESET);
	printf("[");
	for (int i = 0; i <= 20; i++) {
		printf(VERDE "#" RESET);
		fflush(stdout);
		Sleep(50); 
	}
	printf("] 100%%\n");
}

void dibujar_marco() {
	printf("\t\t" AZUL "+===================================================+\n" RESET);
}

void mostrar_titulo(char *titulo) {
	dibujar_marco();
	printf("\t\t" AZUL "|" RESET NEGRITA CIAN " %-49s " RESET AZUL "|\n", titulo);
	printf("\t\t" AZUL "+===================================================+\n" RESET);
}
