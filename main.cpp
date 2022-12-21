#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Numeros Romanos
int romanToInt(char *s) {
    int result = 0;
    int i;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] == 'I') {
            if (s[i + 1] == 'V' || s[i + 1] == 'X') {
                result -= 1;
            } else {
                result += 1;
            }
        } else if (s[i] == 'V') {
            result += 5;
        } else if (s[i] == 'X') {
            if (s[i + 1] == 'L' || s[i + 1] == 'C') {
                result -= 10;
            } else {
                result += 10;
            }
        } else if (s[i] == 'L') {
            result += 50;
        } else if (s[i] == 'C') {
            if (s[i + 1] == 'D' || s[i + 1] == 'M') {
                result -= 100;
            } else {
                result += 100;
            }
        } else if (s[i] == 'D') {
            result += 500;
        } else if (s[i] == 'M') {
            result += 1000;
        } else {
            return -1;  // dato invalido
        }
    }
    return result;
}

void aux_romanToInt() {
    char roman[16];
    printf("Ingrese el numero romano que desee convertir... : ");
    scanf("%s", roman); //se captura el dato ingresado
    int result = romanToInt(roman); //se envia el resultado al metodo de conversion
    if (result == -1) {
        printf("Null\n");
    } else {
        printf("%d\n", result);
    }
}

//Factores Primos
void factoresPrimos(int numero) {
    int i;
    int potencia;
    int factores[100];  // Array para almacenar los factores primos
    int exponentes[100];  // Array para almacenar los exponentes de los factores primos
    int num_factors = 0;  // Número de factores primos encontrados hasta ahora

    // For para buscar el numero de factores primos del numero ingresado
    for (i = 2; i <= sqrt(numero); i++) {
        potencia = 0;
        while (numero % i == 0) {
            potencia++;
            numero /= i;
        }
        if (potencia > 0) {
            factores[num_factors] = i;
            exponentes[num_factors] = potencia;
            num_factors++;
        }
    }

    // If n is a prime number greater than 2
    if (numero > 2) {
        factores[num_factors] = numero;
        exponentes[num_factors] = 1;
        num_factors++;
    }

    // Ordena los factores primos de mayor a menor
    for (i = 0; i < num_factors - 1; i++) {
        for (int j = i + 1; j < num_factors; j++) {
            if (factores[i] < factores[j]) {
                int temp = factores[i];
                factores[i] = factores[j];
                factores[j] = temp;
                temp = exponentes[i];
                exponentes[i] = exponentes[j];
                exponentes[j] = temp;
            }
        }
    }

    // Imprime la factorización de primos en formato potencia
    for (i = 0; i < num_factors; i++) {
        printf("%d^%d ", factores[i], exponentes[i]);
    }
    printf("\n");
}

int aux_factoresPrimos() {

    int n;
    //Le pedimos al usuario que ingrese un numero
    printf("Ingrese un numero... : ");
    //capturamos el numero ingresado
    scanf("%d", &n);
    printf("la descomposicion del numero en potencias de sus factores primos %d es: ", n);
    factoresPrimos(n);

    return 0;

}

//Borrar Espacios
void borrarEspacios(char *cadenaTexto) {
    int i = 0, j = 0;
    int len = strlen(cadenaTexto);

    // eliminar espacios del inicio
    while (isspace(cadenaTexto[i]) && i < len) i++;

    // eliminar espacios del final
    while (isspace(cadenaTexto[len - 1]) && len > 0) len--;

    // eliminar espacios entre palabras
    while (i < len) {
        if (!isspace(cadenaTexto[i]) || (isspace(cadenaTexto[i]) && !isspace(cadenaTexto[j - 1]))) {
            cadenaTexto[j++] = cadenaTexto[i];
        }
        i++;
    }

    cadenaTexto[j] = '\0';
}

char aux_borrarEspacios() {
#define MAX_LEN 100
    char cadenaTexto[MAX_LEN];

    printf("Ingresar un texto: ");
    fflush(stdin);
    fgets(cadenaTexto, MAX_LEN, stdin);

    borrarEspacios(cadenaTexto);
    printf("Texto ingresado con los espacios extra borrados: %s", cadenaTexto);
    printf("\n");

    return 0;
}



int menuOption;
char *menu = "\t---MENU DE OPCIONES--- \n\n"
             "1. Numeros Romanos\n"
             "2. Factores Primos\n"
             "3. Borrar Espacios\n"
             "4. \n"
             "5. \n"
             "6. \n"
             "7. Producto Punto\n"
             "8. Multiplicacion de Matrices\n"
             "9. Matriz Magica\n"
             "0. Salir\n\n"
             "Dijite una opcion del menu\n";

int main() {

    do {

        printf(menu);
        scanf("%i", &menuOption);
        fflush(stdin);
        switch (menuOption) {

            case 0:
                printf("Saliendo...\n");

                break;
            case 1:
                printf("--Numeros Romanos--\n");
                aux_romanToInt();
                break;
            case 2:
                printf("--Factores Primos--\n");
                aux_factoresPrimos();
                break;
            case 3:
                printf("--Borrar Espacios Extra--\n");
                aux_borrarEspacios();
                break;
            case 4:

                break;
            case 5:

                break;

            case 6:

                break;
            case 7:
                printf("--Producto Punto--");

                break;
            case 8:

                break;
            case 9:

                break;

            default:
                printf("\n\n Por favor seleccione una opcion valida\n\n\n");


        }
    } while (menuOption != 0);


    return 0;
}
