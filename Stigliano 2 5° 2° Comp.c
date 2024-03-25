#include <stdio.h>

int main(void) {
  int alumnos;
  printf("Ingrese la cantidad de alumnos: ");
  scanf("%d", & alumnos);
  if (alumnos > 0) {
    if (alumnos >= 100) {
      printf("Cada alumno debera pagar 500, en total se pagara %d", 500 * alumnos);
    } else if (alumnos >= 50 && alumnos <= 99) {
      printf("Cada alumno debera pagar 400, en total se pagara %d", 400 * alumnos);
    } else if (alumnos >= 30 && alumnos <= 49) {
      printf("Cada alumno debera pagar 300, en total se pagara %d", 300 * alumnos);
    } else printf("Cada alumno debera pagar 50, en total se pagara %d", 50 * alumnos);
  } else printf("Numero invalido");
}
