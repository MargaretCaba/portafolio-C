#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 8

int main() {
    char operator;
    int num1, num2, result;
    char another;

    printf("Calculadora simple de 8 digitos\n");

    do {
        printf("Ingrese el primer numero (hasta 8 digitos): ");
        scanf("%d", &num1);

        printf("Ingrese el operador (+, -, *, /): ");
        scanf(" %c", &operator);

        printf("Ingrese el segundo numero (hasta 8 digitos): ");
        scanf("%d", &num2);

        switch (operator) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    printf("Error: Division por cero no permitida.\n");
                    return 1; // Salir con un c�digo de error
                }
                break;
            default:
                printf("Operador no valido.\n");
                return 1; // Salir con un c�digo de error
        }

        // Verificar si el resultado excede el l�mite de 8 d�gitos
        if (result >= 100000000 || result <= -100000000) {
            printf("El resultado excede el l�mite de 8 d�gitos.\n");
        } else {
            printf("Resultado: %d\n", result);
        }

        printf("Desea realizar otra operaci�n? (s/n): ");
        scanf(" %c", &another);
    } while (another == 's' || another == 'S');

    printf("Gracias por usar la calculadora. Hasta luego!\n");

    return 0;
}
