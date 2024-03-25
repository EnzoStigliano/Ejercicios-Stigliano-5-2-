#include <stdio.h>

int main(void) {
  int choice;
  int num;
  int num2;
  int num3;

  while (1 == 1) {
    printf("\nIngrese una opcion:\n\n1.Saber si un numero es par o impar\n2.Saber si un numero es positivo o negativo\n3.Saber si un numero es multiplo de 2 o de 3\n4.Saber cual de 3 numeros es el mayor\n\n");
    scanf("%d", & choice);
    switch (choice) {
    case 1:
      printf("Ingrese un numero: ");
      scanf("%d", & num);
      if (num % 2 == 1) {
        printf("El numero es impar");
      } else printf("El numero es par");
      printf("\n");
      break;

    case 2:
      printf("Ingrese un numero: ");
      scanf("%d", & num);
      if (num == 0) {
        printf("El numero es 0");
      } else if (num > 0) {
        printf("El numero es positivo");
      } else printf("El numero es negativo");
      printf("\n");
      break;

    case 3:
      printf("Ingrese un numero: ");
      scanf("%d", & num);
      if (num % 2 == 0) {
        if (num % 3 == 0) {
          printf("El numero es multiplo de 2 y de 3");
        } else printf("El numero es multiplo de 2");
      } else if (num % 3 == 0) {
        printf("El numero es multiplo de 3");
      } else printf("El numero no es multiplo ni de 2 ni de 3");
      printf("\n");
      break;

    case 4:
      printf("Ingrese el primer numero: ");
      scanf("%d", & num);
      printf("Ingrese el segundo numero: ");
      scanf("%d", & num2);
      printf("Ingrese el tercer numero: ");
      scanf("%d", & num3);
      if (num == num2 && num2 == num3) {
        printf("Los 3 numeros son iguales");
      } else {
        if (num > num2 && num > num3) {
          printf("%d es el mayor numero", num);
        } else if (num2 > num && num2 > num3) {
          printf("%d es el mayor numero", num2);
        } else printf("%d es el mayor numero", num3);
      }
      printf("\n");
      break;

    default:
      printf("Opcion invalida");
      printf("\n");
      break;
    }
  }
}
