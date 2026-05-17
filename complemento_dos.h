#ifndef COMPLEMENTO_DOS_H
#define COMPLEMENTO_DOS_H

// Verifica si el numero cabe en N bits
int verificar_overflow(int decimal, int num_bits);

// Paso A: Convierte a Ca2
void decimal_a_complemento_dos(int decimal, int num_bits, char *resultado);

// Paso B: Revierte de Ca2 al decimal original
int complemento_dos_a_decimal(char *ca2);

#endif
