#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // Librería para funciones de entrada de caracteres
#include <windows.h> // Librería para Sleep

int main() {
    char tecla;

    printf("Temporizador (Presiona 'w' para empezar y 's' para detener)\n");

    while (1) { // Bucle infinito
        if (_kbhit()) { // Comprueba si se ha presionado una tecla
            tecla = _getch(); // Obtiene la tecla presionada

            if (tecla == 'w') {
                printf("Temporizador iniciado...\n");

                int segundos = 0;
                int minutos = 0;

                while (1) {
                    system("cls"); // Limpia la pantalla (para actualizar el temporizador)

                    segundos++;
                    if (segundos == 60) {
                        segundos = 0;
                        minutos++;
                    }

                    printf("Tiempo transcurrido: %02d:%02d:%02d\n", minutos / 60, minutos % 60, segundos);
                    printf("Presiona 's' para detener el temporizador.\n");

                    if (_kbhit()) {
                        tecla = _getch();
                        if (tecla == 's') {
                            printf("Temporizador detenido.\n");
                            break; // Sale del bucle cuando se presiona 's'
                        }
                    }

                    // Espera un segundo (1,000 ms)
                    Sleep(1000);
                }
            }
        }
    }

    return 0;
}
