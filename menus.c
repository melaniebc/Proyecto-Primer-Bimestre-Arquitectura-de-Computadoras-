#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menus.h"
#include "interfaz.h"
#include "conversiones.h"
#include "complemento_dos.h"
#include "avanzado.h"
#include "validaciones.h"

// Funcion auxiliar para esperar al usuario y limpiar pantalla (Centrada)
void pausa() {
    printf(AMARILLO "\n\t\t [!]" RESET " Presione ENTER para volver...");
    fflush(stdin);
    getchar();
    getchar(); // Doble getchar para asegurar la captura
}

void iniciar_programa() {
    int opcion, sub_opcion;
    int numero, bits;
    char resultado[100];
    char entrada_texto[50]; 
    char entrada_bits[50];  

    system("cls");
    mostrar_barra_carga(); 

    do {
        system("cls");
        
         
        mostrar_titulo("     CONVERSOR DE BASES Y ARITMETICA    ");
        
        printf("\t\t" AZUL "  1." RESET " Decimal a Otras Bases " CIAN "(Fase 1)" RESET "\n");
        printf("\t\t" AZUL "  2." RESET " Otras Bases a Decimal " CIAN "(Fase 2)" RESET "\n");
        printf("\t\t" AZUL "  3." RESET " Complemento a Dos " CIAN "(Fase 3)" RESET "\n");
        printf("\t\t" AZUL "  4." RESET " Coma Flotante IEEE-754 " CIAN "(Fase 4)" RESET "\n");
        printf("\t\t" ROJO "  0. Salir del programa\n" RESET);
        printf("\t\t" AZUL "  +===================================================+\n" RESET);
        printf("\t\t" NEGRITA "  Seleccione una opcion: " RESET);
        
        if (scanf("%d", &opcion) != 1) {
            printf(ROJO "\n\t\t  [!] Error: Ingrese un numero valido.\n" RESET);
            fflush(stdin);
            pausa();
            continue;
        }

        switch(opcion) {
            case 1:
                // --- SUBMENU FASE 1 ---
                do {
                    system("cls");
                    
                    mostrar_titulo("  SUBMENU: DECIMAL -> OTRAS BASES  ");
                    printf("\t\t" AZUL "  1." RESET " Convertir a Binario\n");
                    printf("\t\t" AZUL "  2." RESET " Convertir a Octal\n");
                    printf("\t\t" AZUL "  3." RESET " Convertir a Hexadecimal\n");
                    printf("\t\t" AZUL "  4." RESET " Mostrar TODAS las conversiones\n");
                    printf("\t\t" ROJO "  0. Volver al Menu Principal\n" RESET);
                    printf("\t\t" AZUL "  +===================================================+\n" RESET);
                    printf("\t\t" NEGRITA "  Seleccione una opcion: " RESET);

                    if (scanf("%d", &sub_opcion) != 1) {
                        printf(ROJO "\n\t\t  [!] Error: Ingrese un numero valido.\n" RESET);
                        fflush(stdin);
                        pausa();
                        continue;
                    }

                    // Si elige una opcion valida de conversion (1 al 4)
                    if (sub_opcion >= 1 && sub_opcion <= 4) {
                        // Pedimos y validamos el numero una sola vez
                        do {
                            printf(NEGRITA "\n\t\t  Ingrese el numero decimal positivo: " RESET);
                            scanf("%s", entrada_texto);
                            if (!es_decimal_positivo_valido(entrada_texto)) {
                                printf(ROJO "\t\t  [!] Error: Ingrese UNICAMENTE numeros positivos enteros.\n" RESET);
                            }
                        } while (!es_decimal_positivo_valido(entrada_texto));

                        numero = atoi(entrada_texto);
                        printf("\n\t\t  Resultados:\n");

                        if (sub_opcion == 1 || sub_opcion == 4) {
                            decimal_a_binario(numero, resultado);
                            printf("\t\t" VERDE "  > Binario:     " RESET "%s\n", resultado);
                        }
                        if (sub_opcion == 2 || sub_opcion == 4) {
                            decimal_a_octal(numero, resultado);
                            printf("\t\t" VERDE "  > Octal:       " RESET "%s\n", resultado);
                        }
                        if (sub_opcion == 3 || sub_opcion == 4) {
                            decimal_a_hexadecimal(numero, resultado);
                            printf("\t\t" VERDE "  > Hexadecimal: " RESET "%s\n", resultado);
                        }
                        pausa();
                    } else if (sub_opcion != 0) {
                        printf(ROJO "\n\t\t  [!] Opcion no valida.\n" RESET);
                        pausa();
                    }
                } while (sub_opcion != 0);
                break;

            case 2:
                // --- SUBMENU FASE 2 ---
                do {
                    system("cls");
                    
                    mostrar_titulo("  SUBMENU: OTRAS BASES -> DECIMAL  ");
                    printf("\t\t" AZUL "  1." RESET " Binario a Decimal\n");
                    printf("\t\t" AZUL "  2." RESET " Octal a Decimal\n");
                    printf("\t\t" AZUL "  3." RESET " Hexadecimal a Decimal\n");
                    printf("\t\t" ROJO "  0. Volver al Menu Principal\n" RESET);
                    printf("\t\t" AZUL "  +===================================================+\n" RESET);
                    printf("\t\t" NEGRITA "  Seleccione una opcion: " RESET);

                    if (scanf("%d", &sub_opcion) != 1) {
                        printf(ROJO "\n\t\t  [!] Error: Ingrese un numero valido.\n" RESET);
                        fflush(stdin);
                        pausa();
                        continue;
                    }

                    switch(sub_opcion) {
                        case 1:
                            do {
                                printf(NEGRITA "\n\t\t  Ingrese un numero binario (solo 0 y 1): " RESET);
                                scanf("%s", resultado);
                                if (!es_binario_valido(resultado)) {
                                    printf(ROJO "\t\t  [!] Error: El numero contiene caracteres no validos.\n" RESET);
                                }
                            } while (!es_binario_valido(resultado));
                            printf("\t\t" VERDE "  > De Binario a Decimal: " RESET "%d\n", binario_a_decimal(resultado));
                            pausa();
                            break;

                        case 2:
                            do {
                                printf(NEGRITA "\n\t\t  Ingrese un numero octal (solo 0 al 7): " RESET);
                                scanf("%s", resultado);
                                if (!es_octal_valido(resultado)) {
                                    printf(ROJO "\t\t  [!] Error: El numero no es un octal valido.\n" RESET);
                                }
                            } while (!es_octal_valido(resultado));
                            printf("\t\t" VERDE "  > De Octal a Decimal: " RESET "%d\n", octal_a_decimal(resultado));
                            pausa();
                            break;

                        case 3:
                            do {
                                printf(NEGRITA "\n\t\t  Ingrese un numero hexadecimal (0-9, A-F): " RESET);
                                scanf("%s", resultado);
                                if (!es_hexadecimal_valido(resultado)) {
                                    printf(ROJO "\t\t  [!] Error: El numero no es un hexadecimal valido.\n" RESET);
                                }
                            } while (!es_hexadecimal_valido(resultado));
                            printf("\t\t" VERDE "  > De Hexadecimal a Decimal: " RESET "%d\n", hexadecimal_a_decimal(resultado));
                            pausa();
                            break;

                        case 0:
                            // Sale silenciosamente al menu principal
                            break;

                        default:
                            printf(ROJO "\n\t\t  [!] Opcion no valida.\n" RESET);
                            pausa();
                            break;
                    }
                } while (sub_opcion != 0);
                break;

            case 3:
                system("cls");
                
                mostrar_titulo("  FASE 3: COMPLEMENTO A DOS (Ca2)  ");
                
                // 1. Validar el número decimal (puede ser negativo)
                do {
                    printf(NEGRITA "\n\t\t  Ingrese el numero decimal (positivo o negativo): " RESET);
                    scanf("%s", entrada_texto);
                    if (!es_entero_valido(entrada_texto)) {
                        printf(ROJO "\t\t  [!] Error: Entrada invalida. Ingrese solo numeros enteros.\n" RESET);
                    }
                } while (!es_entero_valido(entrada_texto));
                
                // 2. Validar la cantidad de bits
                do {
                    printf(NEGRITA "\t\t  Ingrese la cantidad de bits (N): " RESET);
                    scanf("%s", entrada_bits);
                    if (!es_decimal_positivo_valido(entrada_bits)) {
                        printf(ROJO "\t\t  [!] Error: La cantidad de bits debe ser un numero positivo.\n" RESET);
                    }
                } while (!es_decimal_positivo_valido(entrada_bits));

                numero = atoi(entrada_texto);
                bits = atoi(entrada_bits);

                decimal_a_complemento_dos(numero, bits, resultado);
                
                if (strcmp(resultado, "ERROR_OVERFLOW") == 0) {
                    printf(ROJO "\n\t\t  [!] Error: El numero no cabe en %d bits (Overflow).\n" RESET, bits);
                } else {
                    printf(VERDE "\n\t\t  > Representacion en Ca2: " RESET "%s\n", resultado);
                    printf(VERDE "\t\t  > Verificacion Decimal:  " RESET "%d\n", complemento_dos_a_decimal(resultado));
                }
                pausa();
                break;

            case 4:
                system("cls");
                ejecutar_coma_flotante();
                pausa();
                break;

            case 0:
                printf(MAGENTA "\n\t\t  Saliendo... Gracias por usar el sistema.\n\n" RESET);
                break;

            default:
                printf(ROJO "\n\t\t  [!] Opcion no valida.\n" RESET);
                pausa();
                break;
        }
    } while(opcion != 0);
}