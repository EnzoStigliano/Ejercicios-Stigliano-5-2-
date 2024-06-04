#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función que determina si un número está o no dentro de un array
bool enArray(int array[8], int num) {
    for (int i = 0; i < 8; i++) {
        if (array[i] == num) {
            return true;
        }
    }
    return false;
}

int main() {
    int tablero[3][3];
    int fProhibida[8];
    int cProhibida[8];
    
    srand(time(NULL));

    // Rellenar tablero de 0
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = 0;
        }
    }

    // Bucle principal
    for (int i = 0; i < 3; i++) {
        // Rellenar columnas prohibidas de 10
        for (int j = 0; j < 8; j++) {
            cProhibida[j] = 10;
        }

        for (int j = 0; j < 3; j++) {
            int columna;
            bool flag;
            do {
                columna = rand() % 3; // Generar número aleatorio entre 0 y 2

                // El número es válido si no hay otro en el tablero en la misma posición y si no está en cProhibida
                if (enArray(cProhibida, columna) || tablero[j][columna] != 0) {
                    flag = true;
                } else {
                    flag = false;
                }
            } while (flag);

            // Poner número en posición correspondiente, anotar número de columna
            tablero[j][columna] = i + 1;
            cProhibida[j] = columna;

            // Evitar que el primer número se coloque en alguna diagonal
            if (i == 0 && j == 0 && (columna == 0 || columna == 2)) {
                cProhibida[1] = 1;
            }

            // Asegurarse que algún número se repita en alguna diagonal
            if (i == 1 && j == 0) {
                // Si la diagonal principal está disponible y el número se coloca en la esquina correcta, rellena con el número
                // Si no, no permite que el número obstruya la diagonal
                if (tablero[2][2] == 0) {
                    if (columna == 0) {
                        tablero[1][1] = 2;
                        tablero[2][2] = 2;
                        j = 3;
                    } else {
                        cProhibida[1] = 1;
                    }
                }

                // Si la diagonal secundaria está disponible y el número se coloca en la esquina correcta, rellena con el número
                // Si no, no permite que el número obstruya la diagonal
                if (tablero[2][0] == 0) {
                    if (columna == 2) {
                        tablero[1][1] = i + 1;
                        tablero[2][0] = i + 1;
                        j = 3;
                    } else {
                        cProhibida[1] = 1;
                    }
                }
            }
        }
    }

    // Imprimir tablero
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}