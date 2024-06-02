#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Función que determina si un número está o no dentro de un array
int enArray(int array[8], int num) {
    for (int i = 0; i < 8; i++) {
        if (array[i] == num) {
            return 1;
        }
    }

    return 0;
}

int main(void) {
    int 
        tablero[6][6],
        i,
        j,
        fila,
        columna,
        flag,
        fProhibida[8],
        cProhibida[8];

    srand(time(NULL));

    //Rellenar tablero de 0
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            tablero[i][j] = 0;
        }
    }

    //Bucle principal
    for (i = 0; i < 6; i++) {
        //Rellenar columnas prohibidas de 10
        for (j = 0; j < 8; j++) {
            cProhibida[j] = 10;
            fProhibida[j] = 10;
        }

        for (j = 0; j < 6; j++) {
            do {
                switch (j){
                case 0:
                    fila = rand() % 2;
                    columna = rand() % 3;
                    break;
                case 1:
                    fila = rand() % 2;
                    columna = (rand() % (5 - 3 + 1)) + 3;
                    break;
                case 2:
                    fila = (rand() % (3 - 2 + 1)) + 2;
                    columna = rand() % 3;
                    break;
                case 3:
                    fila = (rand() % (3 - 2 + 1)) + 2;
                    columna = (rand() % (5 - 3 + 1)) + 3;
                    break;
                case 4:
                    fila = (rand() % (5 - 4 + 1)) + 4;
                    columna = rand() % 3;
                    break;
                case 5:
                    fila = (rand() % (5 - 4 + 1)) + 4;
                    columna = (rand() % (5 - 3 + 1)) + 3;
                    break;
                }
                //El número es válido si no hay otro en el tablero en la misma posición y si no está en cProhibida
                if (enArray(cProhibida, columna)|| tablero[fila][columna] != 0) {
                    flag = 1;
                } else flag = 0;
            } while (flag == 1);

            //Poner número en posición correspondiente, anotar número de columna
            tablero[fila][columna] = i + 1;
            fProhibida[j] = fila;
            cProhibida[j] = columna;
        }
    }

    //Imprimir tablero
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            printf("%d ", tablero[i][j]);
        }
        printf("\n");
    }
}