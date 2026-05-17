#ifndef CONVERSIONES_H
#define CONVERSIONES_H

// Firmas de las funciones para la Fase 1
void decimal_a_binario(int decimal, char *resultado);
void decimal_a_octal(int decimal, char *resultado);
void decimal_a_hexadecimal(int decimal, char *resultado);

// Firmas de las funciones para la Fase 2
int binario_a_decimal(char *binario);
int octal_a_decimal(char *octal);
int hexadecimal_a_decimal(char *hexadecimal);

#endif
