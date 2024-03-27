#include <stdio.h>

int main(void) {
  int alumnos, n1, n2, aux, i, n = 0, choice;

  double sueldo, ventas[3], acumComision = 0, promedio, parciales[3], acumP, ef, tf, nf;

  while (1 == 1) {
    printf("\nIngrese una opcion\n\n1.Viaje de egresados\n2.Comisiones y sueldo\n3.Nota algoritmos\n4.Numeros pares\n5.Autos en la ruta\n");
    scanf("%d", &choice);
    printf("\n");
    if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5) {
      printf("Opcion invalida\n");
    } else {
      switch (choice) {
        case 1:
          printf("Ingrese la cantidad de alumnos: ");
          scanf("%d", &alumnos);
          if (alumnos > 0) {
            if (alumnos >= 100) {
              printf("Cada alumno debera pagar 500, en total se pagara %d",
                     500 * alumnos);
            } else if (alumnos >= 50 && alumnos <= 99) {
              printf("Cada alumno debera pagar 400, en total se pagara %d",
                     400 * alumnos);
            } else if (alumnos >= 30 && alumnos <= 49) {
              printf("Cada alumno debera pagar 300, en total se pagara %d",
                     300 * alumnos);
            } else
              printf(
                  "El total a pagar sera 6000, cada alumno debera pagar %.2f",
                  6000 / alumnos);
          } else
            printf("Numero invalido");
          break;

        case 2:
          printf("Ingrese el sueldo base: ");
          scanf("%lf", &sueldo);
          for (i = 0; i < 3; i++) {
            printf("Ingrese la venta n%d: ", i + 1);
            scanf("%lf", &ventas[i]);
            acumComision += ventas[i] * 0.1;
          }
          printf(
              "El total de plata por comision es de %.2lf, mas el sueldo el "
              "total "
              "sera de %.2lf",
              acumComision, acumComision + sueldo);
          break;

        case 3:
          for (i = 0; i < 3; i++) {
            printf("Ingrese la nota del parcial %d: ", i + 1);
            scanf("%lf", &parciales[i]);
            acumP += parciales[i];
          }
          printf("Ingrese la nota del examen final: ");
          scanf("%lf", &ef);
          printf("Ingrese la nota del trabajo final: ");
          scanf("%lf", &tf);
          promedio = acumP / 3;
          nf = 0.55 * promedio + 0.30 * ef + 0.15 * tf;
          printf("La nota final de algoritmos es de %.2lf", nf);
          break;

        case 4:
          printf("Ingrese el primer numero natural: ");
          scanf("%d", &n1);
          printf("Ingrese el segundo numero natural: ");
          scanf("%d", &n2);

          if (n1 == n2) {
            printf("Ambos numeros son iguales");
          } else if (n1 > n2) {
            n = n1 - n2 + 1;
            aux = n2;
            printf("Los numeros pares entre %d y %d son: ", n1, n2);
          } else {
            n = n2 - n1 + 1;
            aux = n1;
            printf("Los numeros pares entre %d y %d son: ", n2, n1);
          }

          for (i = 0; i < n; i++) {
            if (aux % 2 == 0) {
              printf("%d ", aux);
            }
            aux++;
          }
          break;

        case 5:
          // Si una auto esta en el kilometro 70 y otro en el 150, si ambos van
          // en sentido opuesto (acercandose) a la misma velocidad, siempre se
          // encontraran en el mismo lugar, en el km 70 mas la mitad de la
          // diferencia entre 70 y 150, es decir 80. Por lo tanto, 80/2 = 40, 70
          // + 40 = 110 No vale la pena poner ningun tipo de entrada, pues no
          // importa la velocidad siempre se encontraran en el mismo lugar, lo
          // que variaría sería el tiempo, pero eso ya no lo pide el ejercicio
          // Me ahorro el hacer la cuenta pudiendo simplemente explicarlo, para
          // ahorrar procesamiento
          printf(
              "Si los dos autos van en sentido opuesto y van a la misma "
              "velocidad, "
              "se encontraran en el kilometro 110");
          break;
      }
    }
  }
}
