#include <stdio.h>

int main() {
    // Declaracion de variables int
    int 
        opcion,
        hombres, 
        mujeres, 
        totalEstudiantes,
        edad,
        genero; // 0 para mujer, 1 para hombre
    
    // Declaracion de variables float
    float 
        notas[3], 
        calificacionPromedio, 
        calificacionTrabajoFinal, 
        calificacionFinal,
        sueldoBase, 
        ventas[3], 
        comision, 
        totalRecibido,
        totalCompra, 
        descuento,
        numero, 
        valorAbsoluto,
        pesosArgentinos, 
        tipoCambio, 
        dolares,
        peso,
        frecuenciaCardiacaMaxima;
    
    do {
        printf("\nSeleccione una opcion:\n");
        printf("1. Calcular calificacion final\n");
        printf("2. Calcular total mensual de un vendedor\n");
        printf("3. Calcular total a pagar con descuento\n");
        printf("4. Calcular valor absoluto de un numero\n");
        printf("5. Calcular porcentaje de hombres y mujeres en un grupo\n");
        printf("6. Convertir pesos argentinos a dolares\n");
        printf("7. Calcular frecuencia cardiaca maxima\n");
        printf("8. Salir\n\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese las calificaciones de las 3 evaluaciones parciales:\n");
                for (i = 0; i < 3; i++) {
                    printf("Calificacion %d: ", i + 1);
                    scanf("%f", &notas[i]);
                }
                printf("Ingrese la calificacion del promedio: ");
                scanf("%f", &calificacionPromedio);
                printf("Ingrese la calificacion del trabajo final: ");
                scanf("%f", &calificacionTrabajoFinal);

                calificacionFinal = (0.55 * (notas[0] + notas[1] + notas[2]) / 3) + (0.30 * calificacionPromedio) + (0.15 * calificacionTrabajoFinal);

                printf("La calificacion final es: %.2f\n", calificacionFinal);
                break;

            case 2:
                printf("Ingrese el sueldo base: ");
                scanf("%f", &sueldoBase);
                printf("Ingrese el monto de las tres ventas:\n");
                for (i = 0; i < 3; i++) {
                    printf("Venta %d: ", i + 1);
                    scanf("%f", &ventas[i]);
                }

                comision = 0.10 * (ventas[0] + ventas[1] + ventas[2]);
                totalRecibido = sueldoBase + comision;

                printf("El dinero obtenido por comisiones es: %.2f\n", comision);
                printf("El total que recibira en el mes es: %.2f\n", totalRecibido);
                break;

            case 3:
                printf("Ingrese el total de la compra: ");
                scanf("%f", &totalCompra);

                descuento = totalCompra * 0.15;
                totalCompra -= descuento;

                printf("El total a pagar con descuento es: %.2f\n", totalCompra);
                break;

            case 4:
                printf("Ingrese un numero: ");
                scanf("%f", &numero);

                valorAbsoluto = (numero < 0) ? -numero : numero;

                printf("El valor absoluto de %.2f es: %.2f\n", numero, valorAbsoluto);
                break;

            case 5:
                printf("Ingrese la cantidad de hombres en el grupo: ");
                scanf("%d", &hombres);
                printf("Ingrese la cantidad de mujeres en el grupo: ");
                scanf("%d", &mujeres);

                totalEstudiantes = hombres + mujeres;
                printf("Porcentaje de hombres: %.2f%%\n", (hombres * 100.0) / totalEstudiantes);
                printf("Porcentaje de mujeres: %.2f%%\n", (mujeres * 100.0) / totalEstudiantes);
                break;

            case 6:
                printf("Ingrese la cantidad en pesos argentinos: ");
                scanf("%f", &pesosArgentinos);
                printf("Ingrese el tipo de cambio (pesos argentinos por dolar): ");
                scanf("%f", &tipoCambio);

                dolares = pesosArgentinos / tipoCambio;

                printf("La equivalencia en dolares estadounidenses es: %.2f\n", dolares);
                break;

            case 7:
                printf("Ingrese su edad: ");
                scanf("%d", &edad);
                printf("Ingrese su peso en kg: ");
                scanf("%f", &peso);
                printf("Ingrese su genero (0 para mujer, 1 para hombre): ");
                scanf("%d", &genero);

                if (genero == 1) {
                    frecuenciaCardiacaMaxima = ((210 - (0.5 * edad)) - (0.01 * peso)) + 4;
                } else {
                    frecuenciaCardiacaMaxima = (210 - (0.5 * edad)) - (0.01 * peso);
                }

                printf("La frecuencia cardiaca maxima es: %.2f\n", frecuenciaCardiacaMaxima);
                break;

            case 8:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion no valida.\n");
                break;
        }
    } while (opcion != 8);

    return 0;
}
