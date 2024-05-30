#include <stdio.h>

int main() {
    // Declaracion de variables int
    int 
        opcion,
        i, 
        horas, 
        minutos, 
        segundos,
        padreEdad = 50, 
        hijoEdad = 20,
        añosDiferencia,
        totalSegundos, 
        horasConvertidas, 
        minutosConvertidos, 
        segundosConvertidos;

    // Declaracion de variables float
    float 
        sueldo, 
        impuesto, 
        capital, 
        interesMensual = 0.02, 
        ahorro;

    // Declaracion de arrays
    char periodo[3];

    do {
        printf("\n\nSeleccione una opcion:\n");
        printf("1. Calcular impuesto sobre alquiler\n");
        printf("2. Convertir hora a formato 12 horas\n");
        printf("3. Calcular ahorro mensual en el banco\n");
        printf("4. Determinar cuando la edad del padre sera el doble que la del hijo\n");
        printf("5. Convertir tiempo de segundos a horas, minutos y segundos\n");
        printf("6. Salir\n\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el sueldo de alquiler: ");
                scanf("%f", &sueldo);

                if (sueldo <= 202) {
                    impuesto = 0;
                } else if (sueldo <= 607) {
                    impuesto = sueldo * 0.05;
                } else if (sueldo <= 1013) {
                    impuesto = sueldo * 0.10;
                } else if (sueldo <= 1418) {
                    impuesto = sueldo * 0.15;
                } else {
                    impuesto = sueldo * 0.25;
                }

                printf("El impuesto sobre el alquiler es: %.2f\n", impuesto);
                break;

            case 2:
                printf("Ingrese la hora en formato 24 horas (hh mm): ");
                scanf("%d %d", &horas, &minutos);

                if (horas >= 0 && horas < 24 && minutos >= 0 && minutos < 60) {
                    if (horas == 0) {
                        horas = 12;
                        strcpy(periodo, "AM");
                    } else if (horas < 12) {
                        strcpy(periodo, "AM");
                    } else if (horas == 12) {
                        strcpy(periodo, "PM");
                    } else {
                        horas -= 12;
                        strcpy(periodo, "PM");
                    }
                    printf("La hora en formato 12 horas es: %02d:%02d %s\n", horas, minutos, periodo);
                } else {
                    printf("Hora invalida.\n");
                }
                break;

            case 3:
                printf("Ingrese el capital a invertir: ");
                scanf("%f", &capital);

                ahorro = capital * (1 + interesMensual);
                printf("El ahorro despues de un mes es: %.2f\n", ahorro);
                break;

            case 4:
                añosDiferencia = 0;
                while (padreEdad != 2 * hijoEdad) {
                    padreEdad++;
                    hijoEdad++;
                    añosDiferencia++;
                }
                printf("Dentro de %d anos la edad del padre sera el doble que la del hijo.\n", añosDiferencia);
                break;

            case 5:
                printf("Ingrese el tiempo en segundos: ");
                scanf("%d", &totalSegundos);

                horasConvertidas = totalSegundos / 3600;
                minutosConvertidos = (totalSegundos % 3600) / 60;
                segundosConvertidos = totalSegundos % 60;

                printf("El tiempo convertido es: %02d horas %02d minutos %02d segundos\n", horasConvertidas, minutosConvertidos, segundosConvertidos);
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
