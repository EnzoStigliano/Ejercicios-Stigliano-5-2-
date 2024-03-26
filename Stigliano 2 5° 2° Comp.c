#include <stdio.h>

int main(void) {
  /*int alumnos;
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
  } else printf("Numero invalido");*/
  
	/*double sueldo;
	double ventas[3];
	double acumComision = 0;
	int i;
	
	printf("Ingrese el sueldo base: ");
	scanf("%lf", &sueldo);
	for(i=0;i<3;i++){
		printf("Ingrese la venta n%d: ", i+1);
		scanf("%lf", &ventas[i]);
		acumComision += ventas[i] * 0.1;
	}
	printf("El total de plata por comision es de %.2lf, mas el sueldo el total sera de %.2lf", acumComision, acumComision + sueldo);
	*/
	
	/*double promedio;
	double parciales[3];
	double acumP = 0;
	double ef;
	double tf;
	double nf;
	int i;
	
	for(i=0; i<3; i++){
		printf("Ingrese la nota del parcial %d: ", i+1);
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
	*/
	
	int n1;
	int n2;
	int aux;
	int i;
	int n;
	
	printf("Ingrese el primer numero natural: ");
	scanf("%d", &n1);
	printf("Ingrese el segundo numero natural: ");
	scanf("%d", &n2);
	
	if(n1 == n2){
		printf("Ambos numeros son iguales");
	}
	else if(n1 > n2){
		n = n1-n2 + 1;
		aux = n2;
		printf("Los numeros pares entre %d y %d son: ", n1, n2);
	}
	else {
		n = n2-n1 + 1;
		aux = n1;
		printf("Los numeros pares entre %d y %d son: ", n2, n1);
	}
	
	for(i=0; i<n; i++){
		if(aux%2 == 0){
			printf("%d ", aux);
		}
		aux++;
	}
}
