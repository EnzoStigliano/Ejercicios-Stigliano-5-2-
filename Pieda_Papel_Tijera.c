#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int jugada;
	int maquina;
	
	printf("Ingrese pieda (1), papel (2) o tijera (3): ");
	scanf("%d", &jugada);
	
	srand(time(NULL));
	maquina = 1 + rand()%(4 - 1);
	
	if(jugada == 1 && maquina == 1){
		printf("Piedra - Pieda: Empate");
	}
	else if(jugada == 1 && maquina == 2){
		printf("Piedra - Papel: Perdiste");
	}
	else if(jugada == 1 && maquina == 3){
		printf("Piedra - Tijera: Ganaste");
	}
	else if(jugada == 2 && maquina == 1){
		printf("Papel - Piedra: Ganaste");
	}
	else if(jugada == 2 && maquina == 2){
		printf("Papel - Papel: Empate");
	}
	else if(jugada == 2 && maquina == 3){
		printf("Papel - Tijera: Perdiste");
	}
	else if(jugada == 3 && maquina == 1){
		printf("Tijera - Piedra: Perdiste");
	}
	else if(jugada == 3 && maquina == 2){
		printf("Tijera - Papel: Ganaste");
	}
	else if(jugada == 3 && maquina == 3){
		printf("Tijera - Tijeraa: Empate");
	}
	else printf("Dato incorrecto");
	
}
