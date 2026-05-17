# Guía de Uso del Proyecto y Git

Este documento contiene los comandos esenciales para compilar, ejecutar y mantener actualizado el repositorio de **Arquitectura de Computadoras** desde la terminal de Visual Studio Code.

---

## 🛠️ 1. Compilación y Ejecución (PowerShell)

Dado que la estructura del proyecto está limpia y los archivos se encuentran dentro de la subcarpeta del proyecto, sigue estos pasos en orden:

### Paso A: Entrar a la carpeta del proyecto
```powershell
cd ProyectoArqui
Paso B: Compilar todos los módulos (.c) juntos
Si realizas cambios en el código o si el ejecutable no se encuentra, vuelve a compilar usando GCC:

PowerShell
gcc main.c menus.c conversiones.c complemento_dos.c avanzado.c validaciones.c -o programa
Paso C: Ejecutar el programa en Windows (PowerShell)
Usa la barra invertida (.\) requerida por PowerShell para lanzar el ejecutable generado:

PowerShell
.\programa.exe
🚀 2. Flujo de Trabajo con GitHub (Guardar Cambios)
A partir de ahora, cada vez que edites tus archivos .c o .h y quieras subir los nuevos avances a tu repositorio de GitHub, solo debes ejecutar estos 3 comandos en tu terminal:

Añadir las modificaciones al escenario:

Bash
git add .
Crear un punto de control con una descripción de lo que hiciste:

Bash
git commit -m "Descripción breve de los cambios realizados"
Subir los cambios a la nube:

Bash
git push
📄 3. Archivo de Configuración (.gitignore)
El archivo .gitignore creado en la raíz del proyecto asegura que Git ignore de forma automática los archivos temporales y binarios pesados. Su contenido actual es:

Plaintext
*.exe
.vscode/
Debug/
💡 Nota: Esto evita que se suba el archivo programa.exe o las configuraciones locales de tu editor a GitHub, manteniendo el repositorio limpio y profesional para el trabajo en equipo.
