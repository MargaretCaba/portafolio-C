#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_PHONE_LENGTH 12

bool contiene_numeros(const char *str) {
    for (int i = 0; str[i]; i++) {
        if (isdigit(str[i])) {
            return true;
        }
    }
    return false;
}

int main() {
    char nombre[MAX_NAME_LENGTH];
    char sexo;
    int edad, num_hijos;
    char telefono[MAX_PHONE_LENGTH];
    char direccion[MAX_ADDRESS_LENGTH];
    double sueldo_inicial = 10000.0;
    double sueldo_final;
    bool registro_valido;

    printf("Registro de Trabajador de Supermercado\n");

    while (1) { // Inicia el bucle infinito
        registro_valido = true;

        printf("Ingrese el nombre completo: ");
        fgets(nombre, sizeof(nombre), stdin);
        nombre[strlen(nombre) - 1] = '\0';

        do {
            printf("Ingrese el sexo (M/F): ");
            scanf(" %c", &sexo);

            if (sexo != 'M' && sexo != 'F') {
                printf("Error: Sexo no valido. Use 'M' o 'F'.\n");
                registro_valido = false;
            }
        } while (sexo != 'M' && sexo != 'F');

        printf("Ingrese la edad (2 digitos): ");
        scanf("%d", &edad);

        if (edad < 0 || edad >= 100) {
            printf("Error: Edad no valida.\n");
            registro_valido = false;
        }

        printf("Tiene hijos? (S/N): ");
        char tiene_hijos;
        scanf(" %c", &tiene_hijos);

        if (tiene_hijos == 'S' || tiene_hijos == 's') {
            printf("Ingrese el numero de hijos: ");
            scanf("%d", &num_hijos);

            if (num_hijos < 0) {
                printf("Error: Numero de hijos no valido.\n");
                registro_valido = false;
            }
        } else if (tiene_hijos == 'N' || tiene_hijos == 'n') {
            num_hijos = 0;
        } else {
            printf("Error: Respuesta no valida para la pregunta de hijos.\n");
            registro_valido = false;
        }

        do {
            printf("Ingrese el numero de teléfono (hasta 11 digitos): ");
            scanf("%s", telefono);

            if (strlen(telefono) = 11) {
                printf("Error: El número de telefono no puede tener más de 11 digitos.\n");
                registro_valido = false;
            }
            getchar(); // Consumir el carácter de nueva línea pendiente
        } while (!registro_valido);

        do {
            printf("Ingrese la dirección (sin numeros): ");
            getchar();
            fgets(direccion, sizeof(direccion), stdin);
            direccion[strlen(direccion) - 1] = '\0';

            if (contiene_numeros(direccion)) {
                printf("Error: La direccion no debe contener numeros.\n");
                registro_valido = false;
            }
        } while (!registro_valido);

        if (registro_valido) {
            sueldo_final = sueldo_inicial + (sueldo_inicial * 0.05 * num_hijos);
            printf("Registro exitoso!!!!.\n");
            printf("Nombre: %s\n", nombre);
            printf("Sexo: %c\n", sexo);
            printf("Edad: %d\n", edad);
            printf("Numero de hijos: %d\n", num_hijos);
            printf("Telefono: %s\n", telefono);
            printf("Direccion: %s\n", direccion);
            printf("Sueldo inicial: %.2f DOP\n", sueldo_inicial);
            printf("Sueldo final con aumento: %.2f DOP\n", sueldo_final);

            // Confirmación para reiniciar el programa
            char reiniciar;
            printf("Desea registrar otro trabajador? (S/N): ");
            scanf(" %c", &reiniciar);

            if (reiniciar == 'N' || reiniciar == 'n') {
                break; // Salir del bucle infinito si no se desea registrar otro trabajador
            }
        } else {
            printf("Error en el registro. Por favor, intentelo de nuevo.\n");
            printf("Presione Enter para reiniciar el registro.\n");
            getchar(); // Esperar a que el usuario presione Enter para reiniciar
        }
    }

    return 0;
}
