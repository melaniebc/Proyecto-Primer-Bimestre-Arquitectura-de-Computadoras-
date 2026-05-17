#ifndef VALIDACIONES_H
#define VALIDACIONES_H

// Verifica si una cadena contiene solo '0's y '1's
int es_binario_valido(char *cadena);

// Verifica si una cadena contiene solo numeros (0-7)
int es_octal_valido(char *cadena);

// Verifica si una cadena contiene solo caracteres hexadecimales validos (0-9, A-F, a-f)
int es_hexadecimal_valido(char *cadena);

// Verifica si la cadena contiene SOLO numeros positivos
int es_decimal_positivo_valido(char *cadena);

// NUEVO: Verifica si la cadena es un numero entero valido (permite el signo '-' al inicio)
int es_entero_valido(char *cadena);

// Verifica si la cadena es un numero decimal flotante (permite un '-' y un solo '.')
int es_flotante_valido(char *cadena);

#endif
