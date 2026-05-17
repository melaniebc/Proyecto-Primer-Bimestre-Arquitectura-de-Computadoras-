Markdown
# Proyecto Primer Bimestre - Arquitectura de Computadoras

Este proyecto consiste en un sistema modular desarrollado en **C** enfocado en la manipulación de datos a nivel binario, conversiones numéricas y operaciones de arquitectura de computadoras (como el cálculo de complementos). El sistema cuenta con una interfaz basada en menús de terminal y validaciones robustas para garantizar el correcto flujo de la información.

## 🚀 Características Principales

- **Menús Interactivos:** Interfaz limpia en consola para navegar de manera intuitiva entre las diferentes opciones del programa.
- **Módulo de Conversiones:** Funcionalidades para transformar valores entre diferentes bases numéricas (Binario, Octal, Decimal, Hexadecimal).
- **Cálculo de Complementos:** Implementación de operaciones lógicas esenciales como el Complemento a 1 y Complemento a 2.
- **Validaciones Rigurosas:** Control de errores de entrada en tiempo real (verificación de cadenas binarias válidas, octales, flotantes, etc.) para evitar fallos o desbordamientos en el sistema.

## 📁 Estructura del Repositorio

El código está organizado de forma modular para facilitar su mantenimiento y escalabilidad:

- `main.c`: Punto de entrada principal que coordina la ejecución del programa.
- `menus.c` / `menus.h`: Control de la interfaz de usuario y navegación en la terminal.
- `conversiones.c` / `conversiones.h`: Lógica matemática para el cambio de bases numéricas.
- `complemento_dos.c` / `complemento_dos.h`: Algoritmos para el cálculo de complementos lógicos.
- `avanzado.c` / `avanzado.h`: Operaciones y optimizaciones avanzadas del sistema.
- `validaciones.c` / `validaciones.h`: Funciones dedicadas a comprobar la integridad de los datos ingresados por el usuario.
- `.gitignore`: Archivo de configuración para omitir archivos ejecutables (`.exe`) y temporales del control de versiones.

## 🛠️ Requisitos previos y Compilación

Para compilar y ejecutar este proyecto localmente, necesitas un compilador de C (como **GCC** a través de MinGW).

### Pasos para ejecutar desde PowerShell:

1. Asegúrate de entrar a la carpeta interna del proyecto:
   ```bash
   cd ProyectoArqui
2. Compila todos los módulos juntos si realizas cambios:
   ```bash
   gcc main.c menus.c conversiones.c complemento_dos.c avanzado.c validaciones.c -o programa
3. Ejecuta el archivo generado usando el formato de PowerShell:
   ```bash
   .\programa.exe

## 👥 Autores
Buenaño Melanie
Cabezas Stefano
Castillo Zander
Guerrón Viviana 


