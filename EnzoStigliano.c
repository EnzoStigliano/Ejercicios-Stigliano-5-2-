#include <stdio.h>

int main(void){
	//Declaración de variables
	int 
		choice,
		tipo,
		tamanio,
		genero,
		edad,
		anios,
		hijos,
		plata,
		i;
	
	float 
		kilos,
		ganancia,
		base,
		potencia,
		exponente,
		radio,
		longitud,
		area,
		volumen;
	
	//Lo pongo dentro de un while para que se siga repitiendo constantesmente hasta que el usuario desee
	while(choice != 6){
		//Pedido de opcion
		printf("\n\nIngrese una opcion:\n\n1.Productor de uva\n2.Base y potencia\n3.Circunferencia\n4.Jubilacion\n5.Subsidio familiar\n6.Salir\n\n");
		scanf("%d", &choice);
		
		//Uso un switch para mayor comodidad
		switch(choice) {
			case 1:
				//Pedido de datos
				printf("Ingrese el tipo de uva (Si es tipo A, ingrese 1; si es tipo B, ingrese 0): ");
				scanf("%d", &tipo);
				printf("Ingrese el tamanio de la uva (1 o 2): ");
				scanf("%d", &tamanio);
				printf("Ingrese la cantidad de kilos: ");
				scanf("%f", &kilos);
				
				//Me aseguro que los datos sean validos	
				if((tipo != 1 && tipo != 0) || (tamanio != 1 && tamanio != 2) || kilos < 0){
					printf("Datos invalidos");
				}	
				else { //Dependiendo del tipo y del tamaño, multiplico los kilos por el precio, y así me da la ganancia
					if(tipo == 1){
						if(tamanio == 1){
							ganancia = kilos * 200;	
						}
						else ganancia = kilos * 300;
					}
					else {
						if(tamanio == 1){
							ganancia = kilos * 300;
						}
						else ganancia = kilos * 500;
					}
					printf("\nLa ganancia del productor sera de $%.2f", ganancia);
				}
			break;
				
			case 2:
				//Pedido de datos
				printf("Ingrese la base: ");
				scanf("%f", &base);
				printf("Ingrese la exponente: ");
				scanf("%f", &exponente);
	
				//Me aseguro que los datos sean enteros y que sean positivos
				if(base == (int)base && exponente == (int)exponente && base >= 0 && exponente >= 0){
					if(exponente != 0){
						potencia = base;
						for(i = 0; i < exponente - 1; i++){ //Hago exponente - 1 porque la primera vez ya hay 2 veces que se multiplica el número
							//Acumulo potenciaciones
							potencia = potencia * base;
						}
						printf("\nLa potencia es %.2f", potencia);
					}
					else printf("El la potencia es 1");
				}
				else printf("Datos invalidos");
			break;
				
			case 3:
				//Pedido de datos
				printf("Ingrese el radio de la circunferencia: ");
				scanf("%f", &radio);
	
				//Fórmulas correspondientes
				longitud = 2*3.14*radio;
				area = 3.14*radio*radio;
				volumen = (4/3)*3.14*radio*radio*radio;
	
				printf("\nLa longitud de la circunferencia es %.2f, el area es %.2f, y el volumen es %.2f", longitud, area, volumen);
			break;
			
			case 4:
				//Ingreso de datos
				printf("Ingrese el genero (1 para hombre, 0 para mujer): ");
				scanf("%d", &genero);
				printf("Ingrese la edad: ");
				scanf("%d", &edad);
				printf("Ingrese los anios de aporte: ");
				scanf("%d", &anios);
	
				printf("\n"); //Estética
				if(genero == 1 || genero == 0){
					if(anios > 20){ //Filtro
						//Dependiendo de la edad y el genero determino si se puede jubilar o no
						if(genero == 1){
							if(edad > 65){
								printf("Se puede jubilar");
							}
							else printf("No se puede jubilar");
						}
						else {
							if(edad > 60){
								printf("Se puede jubilar");
							}
							else printf("No se puede jubilar");
						}
					}
					else printf("No se puede jubilar");
				}
				else printf("Genero invalido");
			break;
			
			case 5:
				//Pedido de datos
				printf("Ingrese la cantidad de hijos: ");
				scanf("%d", &hijos);
	
				if(hijos > 0){ //Me aseguro que la familia tenga hijos
					//Multiplico la cantidad de hijos por el numero correspondiente
					if(hijos <= 2){
						plata = 700 * hijos;
					}
					else if(hijos <= 5){
						plata = 800 * hijos;
					}
					else plata = 1200 * hijos;
		
					//Hago un for para poner la edad de los hijos. No uso arrays por comodidad
					for(i=0; i<hijos; i++){
						printf("Ingrese la edad del hijo %d: ", i+1);
						scanf("%d", &edad);
						if(edad >= 6 && edad <= 18){
							plata += 1000;
						}
					}
		
					printf("\nLa cantidad de plata que se recibira sera $%d", plata);
				}
				else printf("Datos invalidos");
			break;
		}
	} //Si el usuario ingresa 6, el programa termina
	
	return 0;
}
