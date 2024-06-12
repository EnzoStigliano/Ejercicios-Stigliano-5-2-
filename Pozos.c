#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void limpiarPantalla() {
    // Limpiar la consola
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void esperar(int segundos) {
    #ifdef _WIN32
    sleep(segundos * 1000);
    #else
    sleep(segundos);
    #endif
}

void inicializarTablero(int tablero[10][10], int visible[10][10]) {
    int i;
    int j;
    int fila;
    int col;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tablero[i][j] = 1;
            visible[i][j] = 0;
        }
    }

    visible[0][0] = 1; // La posición inicial es visible

    for (i = 0; i < 3; i++) {
        fila = rand() % 10;
        col = rand() % 10;

        // Asegurarse de que la posición inicial y los alrededores de la meta no sean pozos
        if (tablero[fila][col] == 1 && (fila != 0 || col != 0) && !((fila >= 8 && col == 9) || (fila == 9 && col >= 8))) {
            tablero[fila][col] = 0;
        }
    }
}

void imprimirTablero(int tablero[10][10], int visible[10][10], int jugadorFila, int jugadorCol) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == jugadorFila && j == jugadorCol) {
                printf("\033[1;32mJ \033[0m"); // Color verde para el jugador
            } else if (visible[i][j]) {
                if (tablero[i][j] == 0) {
                    printf("\033[1;31mP \033[0m"); // Color rojo para pozos
                } else {
                    printf("\033[1;34m1 \033[0m"); // Color azul para camino seguro
                }
            } else {
                printf("\033[1;37m? \033[0m"); // Color blanco para celdas no descubiertas
            }
        }
        printf("\n");
    }
}

void iniciarJuego(int tablero[10][10], int visible[10][10], int jugadorFila, int jugadorCol, int vidas) {
    char movimiento;

    jugadorFila = 0;
    jugadorCol = 0;
    vidas = 3;

    while (1) {
        limpiarPantalla();
        imprimirTablero(tablero, visible, jugadorFila, jugadorCol);
        printf("\033[1;33mVidas: %d\n\033[0m", vidas); // Color amarillo para las vidas
        printf("\033[1;36mIngrese movimiento (w: arriba, s: abajo, a: izquierda, d: derecha): \033[0m");
        scanf(" %c", &movimiento);

        int nuevaFila = jugadorFila;
        int nuevaCol = jugadorCol;

        if (movimiento == 'w' && jugadorFila > 0) nuevaFila--;
        if (movimiento == 's' && jugadorFila < 10 - 1) nuevaFila++;
        if (movimiento == 'a' && jugadorCol > 0) nuevaCol--;
        if (movimiento == 'd' && jugadorCol < 10 - 1) nuevaCol++;

        if (nuevaFila == jugadorFila && nuevaCol == jugadorCol) {
            printf("\033[1;35m¡Movimiento inválido! Intente de nuevo.\n\033[0m"); // Color magenta para mensaje de movimiento inválido
            esperar(1);
            continue;
        }

        jugadorFila = nuevaFila;
        jugadorCol = nuevaCol;

        if (tablero[jugadorFila][jugadorCol] == 0) {
            vidas--;
            printf("\033[1;31m¡Caíste en un pozo! Vidas restantes: %d\n\033[0m", vidas); // Color rojo para caída en pozo
            visible[jugadorFila][jugadorCol] = 1;
            if (vidas == 0) {
                printf("\033[1;31m¡Juego terminado! Te has quedado sin vidas.\n\033[0m"); // Color rojo para juego terminado
                return;
            }
            jugadorFila = 0;
            jugadorCol = 0;
            esperar(2);
        }

        if (jugadorFila == 9 && jugadorCol == 9) {
            printf("\033[1;32m¡Felicidades! Llegaste a la meta.\n\033[0m"); // Color verde para victoria
            break;
        }
    }
}

void explicarJuego() {
    limpiarPantalla();
    printf("\033[1;32m┌─────────────────────────────────────────────┐\n\033[0m");
    printf("\033[1;32m|          Explicación del Juego              |\n\033[0m");
    printf("\033[1;32m├─────────────────────────────────────────────┤\n\033[0m");
    printf("\033[1;32m| Bienvenido al Juego del Pozo!               |\n\033[0m");
    printf("\033[1;32m| El objetivo es llegar desde la posición     |\n\033[0m");
    printf("\033[1;32m| inicial (0,0) hasta la posición final (9,9) |\n\033[0m");
    printf("\033[1;32m| en un tablero 10x10 sin caer en ninguno de  |\n\033[0m");
    printf("\033[1;32m| los 3 pozos generados aleatoriamente.       |\n\033[0m");
    printf("\033[1;32m| Buena suerte!                               |\n\033[0m");
    printf("\033[1;32m├─────────────────────────────────────────────┤\n\033[0m");
    printf("\033[1;32m| Presione Enter para continuar.              |\n\033[0m");
    printf("\033[1;32m└─────────────────────────────────────────────┘\n\033[0m");
    printf("\n");
    getchar();
}

int main() {
    int tablero[10][10];
    int visible[10][10];
    int jugadorFila;
    int jugadorCol;
    int vidas;
    int opcion;
    char choice;

    while (1) {
        limpiarPantalla();
        printf("\033[1;34m┌──────────────────────────────┐\n\033[0m");
        printf("\033[1;34m│      Juego del Pozo          │\n\033[0m");
        printf("\033[1;34m├──────────────────────────────┤\n\033[0m");
        printf("\033[1;34m│ 1. Explicacion del juego     │\n\033[0m");
        printf("\033[1;34m│ 2. Iniciar juego             │\n\033[0m");
        printf("\033[1;34m│ 3. Salir                     │\n\033[0m");
        printf("\033[1;34m└──────────────────────────────┘\n\033[0m");
        printf("\033[1;36mSeleccione una opcion: \033[0m");
        scanf("%d", &opcion);
        getchar();  // Para capturar el salto de línea tras el scanf

        if (opcion == 1) {
            explicarJuego();
        } else if (opcion == 2) {
            srand(time(NULL));
            inicializarTablero(tablero, visible);
            tablero[0][0] = 1;

            iniciarJuego(tablero, visible, jugadorFila, jugadorCol, vidas);

            printf("\033[1;36m¿Desea jugar de nuevo? (s/n): \033[0m");
            scanf(" %c", &choice);
            if (choice != 's') {
                exit(0);
            }
        } else {
            exit(0);
        }
    }

    return 0;
}