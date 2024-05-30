#include <stdio.h>

int main() {
    int option;
    int i, j;
    int nums[10];
    float numsReales[10];
    float sum, media;
    int maxNum;
    int vec1[2], vec2[2];
    int vec1_3d[3], vec2_3d[3];
    int diferencia[2];
    float productoEscalar;
    int productoVectorial[3];
    int dependencia;

    do {
        printf("Seleccione una opcion:\n");
        printf("1. Mostrar 10 numeros enteros en orden inverso\n");
        printf("2. Mostrar numeros reales por encima de la media\n");
        printf("3. Calcular el mayor de 10 numeros enteros\n");
        printf("4. Calcular la diferencia entre dos vectores en el plano\n");
        printf("5. Calcular el producto escalar de dos vectores en el espacio\n");
        printf("6. Calcular el producto vectorial de dos vectores en el espacio\n");
        printf("7. Determinar si dos vectores en el plano son linealmente dependientes\n");
        printf("8. Salir\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Ingrese 10 numeros enteros:\n");
                for (i = 0; i < 10; i++) {
                    scanf("%d", &nums[i]);
                }

                printf("Los numeros en orden inverso son: ");
                for (i = 9; i >= 0; i--) {
                    printf("%d ", nums[i]);
                }
                printf("\n");
                break;

            case 2:
                sum = 0.0;
                printf("Ingrese 10 numeros reales:\n");
                for (i = 0; i < 10; i++) {
                    scanf("%f", &numsReales[i]);
                    sum += numsReales[i];
                }
                media = sum / 10;

                printf("La media es: %.2f\n", media);
                printf("Los numeros por encima de la media son: ");
                for (i = 0; i < 10; i++) {
                    if (numsReales[i] > media) {
                        printf("%.2f ", numsReales[i]);
                    }
                }
                printf("\n");
                break;

            case 3:
                printf("Ingrese 10 numeros enteros:\n");
                for (i = 0; i < 10; i++) {
                    scanf("%d", &nums[i]);
                }
                maxNum = nums[0];
                for (i = 1; i < 10; i++) {
                    if (nums[i] > maxNum) {
                        maxNum = nums[i];
                    }
                }
                printf("El mayor de los numeros ingresados es: %d\n", maxNum);
                break;

            case 4:
                printf("Ingrese las coordenadas del primer vector (x1 y1): ");
                for (i = 0; i < 2; i++) {
                    scanf("%d", &vec1[i]);
                }
                printf("Ingrese las coordenadas del segundo vector (x2 y2): ");
                for (i = 0; i < 2; i++) {
                    scanf("%d", &vec2[i]);
                }
                for (i = 0; i < 2; i++) {
                    diferencia[i] = vec1[i] - vec2[i];
                }
                printf("La diferencia de los vectores es: (%d, %d)\n", diferencia[0], diferencia[1]);
                break;

            case 5:
                printf("Ingrese las coordenadas del primer vector en el espacio (x1 y1 z1): ");
                for (i = 0; i < 3; i++) {
                    scanf("%d", &vec1_3d[i]);
                }
                printf("Ingrese las coordenadas del segundo vector en el espacio (x2 y2 z2): ");
                for (i = 0; i < 3; i++) {
                    scanf("%d", &vec2_3d[i]);
                }
                productoEscalar = 0;
                for (i = 0; i < 3; i++) {
                    productoEscalar += vec1_3d[i] * vec2_3d[i];
                }
                printf("El producto escalar de los vectores es: %.2f\n", productoEscalar);
                break;

            case 6:
                printf("Ingrese las coordenadas del primer vector en el espacio (x1 y1 z1): ");
                for (i = 0; i < 3; i++) {
                    scanf("%d", &vec1_3d[i]);
                }
                printf("Ingrese las coordenadas del segundo vector en el espacio (x2 y2 z2): ");
                for (i = 0; i < 3; i++) {
                    scanf("%d", &vec2_3d[i]);
                }
                productoVectorial[0] = vec1_3d[1] * vec2_3d[2] - vec1_3d[2] * vec2_3d[1];
                productoVectorial[1] = vec1_3d[2] * vec2_3d[0] - vec1_3d[0] * vec2_3d[2];
                productoVectorial[2] = vec1_3d[0] * vec2_3d[1] - vec1_3d[1] * vec2_3d[0];

                printf("El producto vectorial de los vectores es: (%d, %d, %d)\n", productoVectorial[0], productoVectorial[1], productoVectorial[2]);
                break;

            case 7:
                printf("Ingrese las coordenadas del primer vector (x1 y1): ");
                for (i = 0; i < 2; i++) {
                    scanf("%d", &vec1[i]);
                }
                printf("Ingrese las coordenadas del segundo vector (x2 y2): ");
                for (i = 0; i < 2; i++) {
                    scanf("%d", &vec2[i]);
                }
                if (vec1[0] * vec2[1] == vec1[1] * vec2[0]) {
                    dependencia = 1;
                } else {
                    dependencia = 0;
                }

                if (dependencia) {
                    printf("Los vectores son linealmente dependientes\n");
                } else {
                    printf("Los vectores no son linealmente dependientes\n");
                }
                break;

            case 8:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion no valida.\n");
                break;
        }
    } while (option != 8);

    return 0;
}
