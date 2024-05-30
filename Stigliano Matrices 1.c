#include <stdio.h>

int main() {
    int opcion;
    int i;
    int nums[5];
    float sum;
    float media;
    int diasPorMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int mes;
    int dia;
    int numDia;
    int diasRestantes;

    do {
        printf("\nSeleccione una opcion:\n");
        printf("1. Media aritmetica de 4 numeros\n");
        printf("2. Mostrar 5 numeros en orden inverso\n");
        printf("3. Dias de un mes\n");
        printf("4. Numero de dia en el ano\n");
        printf("5. Dias hasta fin de ano\n");
        printf("6. Salir\n\n");
        scanf("%d", &opcion);

		printf("\n");
        switch (option) {
            case 1:
                sum = 0.0;
                printf("Ingrese 4 numeros:\n");
                for (i = 0; i < 4; i++) {
                	printf("Ingrese el numero n%d: ", i+1);
                    scanf("%d", &nums[i]);
                    sum += nums[i];
                }
                media = sum / 4;

                printf("Los numeros ingresados son: ");
                for (i = 0; i < 4; i++) {
                    printf("%d ", nums[i]);
                }
                printf("\nLa media aritmetica es: %.2f\n", media);
                break;

            case 2:
                printf("Ingrese 5 numeros:\n");
                for (i = 0; i < 5; i++) {
                    scanf("%d", &nums[i]);
                }

                printf("Los numeros en orden inverso son: ");
                for (i = 4; i >= 0; i--) {
                    printf("%d ", nums[i]);
                }
                printf("\n");
                break;

            case 3:
                printf("Ingrese un mes (1=enero, 12=diciembre): ");
                scanf("%d", &mes);

                if (mes >= 1 && mes <= 12) {
                    printf("El mes %d tiene %d dias.\n", mes, diasPorMes[mes-1]);
                } else {
                    printf("Mes invalido.\n");
                }
                break;

            case 4:
                numDia = 0;
                printf("Ingrese un mes (1=enero, 12=diciembre): ");
                scanf("%d", &mes);
                printf("Ingrese un dia: ");
                scanf("%d", &dia);

                if (mes >= 1 && mes <= 12 && dia >= 1 && dia <= diasPorMes[mes-1]) {
                    for (i = 0; i < mes - 1; i++) {
                        numDia += diasPorMes[i];
                    }
                    numDia += dia;

                    printf("El dia %d del mes %d es el dia numero %d del ano.\n", dia, mes, numDia);
                } else {
                    printf("Fecha invalida.\n");
                }
                break;

            case 5:
                diasRestantes = 0;
                printf("Ingrese el mes (1=enero, 12=diciembre): ");
                scanf("%d", &mes);
                printf("Ingrese el dia: ");
                scanf("%d", &dia);

                if (mes >= 1 && mes <= 12 && dia >= 1 && dia <= diasPorMes[mes - 1]) {
                    for (i = mes; i < 12; i++) {
                        diasRestantes += diasPorMes[i];
                    }
                    diasRestantes += (diasPorMes[mes - 1] - dia);

                    printf("Quedan %d dias hasta el fin del ano.\n", diasRestantes);
                } else {
                    printf("Fecha invalida.\n");
                }
                break;

            case 6:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion no valida.\n");
                break;
        }
    } while (opcion != 6);

    return 0;
}
