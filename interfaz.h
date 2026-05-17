#ifndef INTERFAZ_H
#define INTERFAZ_H

// Definicion de colores ANSI
#define RESET       "\033[0m"
#define NEGRITA     "\033[1m"
#define ROJO        "\033[31m"
#define VERDE       "\033[32m"
#define AMARILLO    "\033[33m"
#define AZUL        "\033[34m"
#define MAGENTA     "\033[35m"
#define CIAN        "\033[36m"
#define FONDO_AZUL  "\033[44m"

// Funciones de dise�o
void mostrar_barra_carga();
void dibujar_marco();
void mostrar_titulo(char *titulo);

#endif
