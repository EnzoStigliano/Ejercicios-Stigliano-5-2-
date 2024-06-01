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
        tablero[3][3],
        i,
        j,
        k,
        fila,
        columna,
        flag,
        fProhibida[8],
        cProhibida[8];

    srand(time(NULL));

    //Rellenar tablero de 0
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            tablero[i][j] = 0;
        }
    }

    //Bucle principal
    for (i = 0; i < 3; i++) {
        //Rellenar columnas prohibidas de 10
        for (j = 0; j < 8; j++) {
            cProhibida[j] = 10;
        }

        for (j = 0; j < 3; j++) {
            do {
                columna = rand() % 3; //Generar número aleatorio entre 0 y 2

                //El número es válido si no hay otro en el tablero en la misma posición y si no está en cProhibida
                if (enArray(cProhibida, columna) || tablero[j][columna] != 0) {
                    flag = 1;
                } else flag = 0;
            } while (flag == 1);

            //Poner número en posición correspondiente, anotar número de columna
            tablero[j][columna] = i + 1;
            cProhibida[j] = columna;
            //Evitar que el primer número se coloque en alguna diagonal
            if (i == 0 && j == 0 && (columna == 0 || columna == 2)) {
                cProhibida[1] = 1;
            }

            //Asegurarse que algún número se repita en alguna diagonal
            if (i == 1 && j == 0) {
                //Si la diagonal principal está disponible y el número se coloca en la esquina correcta, rellena con el número
                //Si no, no permite que el número obstruya la diagonal
                if (tablero[2][2] == 0) {
                    if (columna == 0) {
                        tablero[1][1] = 2;
                        tablero[2][2] = 2;
                        j = 3;
                    } else cProhibida[1] = 1;
                }

                //Si la diagonal secundaria está disponible y el número se coloca en la esquina correcta, rellena con el número
                //Si no, no permite que el número obstruya la diagonal
                if (tablero[2][0] == 0) {
                    if (columna == 2) {
                        tablero[1][1] = i + 1;
                        tablero[2][0] = i + 1;
                        j = 3;
                    } else cProhibida[1] = 1;
                }
            }
        }
    }

    //Imprimir tablero
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", tablero[i][j]);
        }
        printf("\n");
    }
}