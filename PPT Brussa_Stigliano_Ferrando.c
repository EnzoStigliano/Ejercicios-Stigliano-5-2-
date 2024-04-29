#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	//Declaraci�n de variables
	int 
		jugada,
		maquina,
		acumJugador,
		acumMaquina,
		acumPuntosJ = 0,
		acumPuntosM = 0,
		i,
		j;
	
	//For para las rondas
	for(i=0;i<5;i++){
		printf("Ronda %d\n\n", i+1);
		acumJugador = 0;
		acumMaquina = 0;

		//For para las vueltas
		for(j=0;j<3;j++){
			printf("Ingrese pieda (1), papel (2) o tijera (3): ");
			scanf("%d", &jugada);
	
			//Establecer rangos para los n�meros aleatorios
			srand(time(NULL));
			maquina = 1 + rand()%(4 - 1);

			//Indicar victoria, derrota o empate dependiendo del caso
			if(jugada == 1 && maquina == 1){
				printf("Piedra - Pieda: Empate");
			}
			else if(jugada == 1 && maquina == 2){
				printf("Piedra - Papel: Perdiste");
				acumMaquina++;
			}
			else if(jugada == 1 && maquina == 3){
				printf("Piedra - Tijera: Ganaste");
				acumJugador++;
			}
			else if(jugada == 2 && maquina == 1){
				printf("Papel - Piedra: Ganaste");
				acumJugador++;
			}
			else if(jugada == 2 && maquina == 2){
				printf("Papel - Papel: Empate");
			}
			else if(jugada == 2 && maquina == 3){
				printf("Papel - Tijera: Perdiste");
				acumMaquina++;
			}
			else if(jugada == 3 && maquina == 1){
				printf("Tijera - Piedra: Perdiste");
				acumMaquina++;
			}
			else if(jugada == 3 && maquina == 2){
				printf("Tijera - Papel: Ganaste");
				acumJugador++;
			}
			else if(jugada == 3 && maquina == 3){
				printf("Tijera - Tijeraa: Empate");
			}
			else printf("Dato incorrecto");
			
			printf("\n\n");
		}

		
		//Acumulador de puntos
		if(acumJugador > acumMaquina){
			acumPuntosJ++;
		}
		else acumPuntosM++;
	}
	
	//Resultado
	printf("%d - %d", acumPuntosJ, acumPuntosM);
	if(acumPuntosJ > acumPuntosM){
		printf("\nGanaste!");
	}
	else if(acumPuntosJ < acumPuntosM){
		printf("\nPerdiste :(");
	}
	else if(acumPuntosJ == acumPuntosM){
		printf("Empate!");
	}
}
