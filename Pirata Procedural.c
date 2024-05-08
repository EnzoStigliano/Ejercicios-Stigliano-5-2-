#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void limpiarConsola() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int inicializarTablero(int **tablero, int f, int c, int posicionPirata[2])
{
    srand(time(NULL));
    int casillas = { //1 si tiene salida a la: izquierda, derecha, arriba, abajo
        {0, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 1, 1},
        {0, 1, 0, 0},
        {0, 1, 0, 1},
        {0, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 0, 0},
        {1, 0, 0, 1},
        {1, 0, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 1, 0},
        {1, 1, 1, 1}
    }
    int casillaActual[4];
    int i;
    int j;
    int fr = 0;
    int cr = 0;
    int filaPirata;
    int columnaPirata;
    int sp;
    int flag = 0;
    int random;
    int casillaSiguiente;

    //Rellenar todo de 1
    for(i=0;i<f;i<++){
        for(j=0;j<c;j++){
            tablero[i][j] = 1;
        }
    }

    //Colocar primer bloque de tierra
    fr = rand() % (f - 1) + 1;
    cr = rand() % (c - 1) + 1;
    tablero[fr][cr] = 0;

    //N de casilla random
    random = (rand()%13) + 1;

    for(i = 0; i < 4; i++){
        casillaActual[i] = casillas[random][i]; //Salidas de la casilla actual
    }

    //Repetir cantidad de salidas

    //Seleccionar salida
    do {
        aux = rand() % 3; //Posicion salida
    } while(casillaActual[aux] == 0);

    casillaSiguiente = (rand()%13) + 1; //N de casilla siguiente
    switch(aux){
        case 0: //Ver si tiene salida a la derecha
            if(casillas[casillaSiguiente][1] == 1){
                if(cr+1 != c-1){ //Fijarse si se choca o no con el borde
                    tablero[fr][cr+1] = 0; //Colocar nuevo bloque de tierra
                }
                else flag = 1; //Indicar si se choca
            }
            break;
        case 1: //Ver si tiene salida a la izquierda
            if(casillas[casillaSiguiente][0] == 1){
                if(cr-1 != c-1){ //Fijarse si se choca o no con el borde
                    tablero[fr][cr+1] = 0; //Colocar nuevo bloque de tierra
                }
                else flag = 1; //Indicar si se choca
            }
            break;
        case 2: //Ver si tiene salida abajo
            if(casillas[casillaSiguiente][3] == 1){
                if(fr+1 != f-1){ //Fijarse si se choca o no con el borde
                    tablero[fr][cr+1] = 0; //Colocar nuevo bloque de tierra
                }
                else flag = 1; //Indicar si se choca
            }
            break;
        case 3: //Ver si tiene salida arriba
            if(casillas[casillaSiguiente][2] == 1){
                if(cr+1 != c-1){ //Fijarse si se choca o no con el borde
                    tablero[fr][cr+1] = 0; //Colocar nuevo bloque de tierra
                }
                else flag = 1; //Indicar si se choca
            }
            break;
    }
}

void dibujarTablero(int **tablero, int f, int c)
{
    int i;
    int j;

    for (i = 0; i < f; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (i == 0 && j == c - 1)
            {
                printf("P ");
            }
            else if (j == 0 && i == f - 1)
            {
                printf("P ");
            }
            else if (i == 0 || i == f - 1 || j == 0 || j == c - 1)
            {
                printf("A ");
            }
            else if(tablero[i][j] == 1){
                printf("1 ");
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int moverPirata(int posicionPirata[2], char mov, int **tablero, int f, int c, int *encontrado)
{
    int posicionAntigua[2];

    posicionAntigua[0] = posicionPirata[0];
    posicionAntigua[1] = posicionPirata[1];

    switch (mov)
    {
    case 'n':
        if (posicionPirata[0] - 1 != 0)
        {
            posicionPirata[0]--;
        }
        break;

    case 's':
        if (posicionPirata[0] + 1 != f - 1)
        {
            posicionPirata[0]++;
        }
        break;

    case 'e':
        if (posicionPirata[1] + 1 != c - 1)
        {
            posicionPirata[1]++;
        }
        break;

    case 'o':
        if (posicionPirata[1] - 1 != 0)
        {
            posicionPirata[1]--;
        }
        break;

    default:
        printf("Posicion invalida\n");
        break;
    }
    if (tablero[posicionPirata[0]][posicionPirata[1]] == 2)
    {
        *encontrado = 1;
    }
    tablero[posicionAntigua[0]][posicionAntigua[1]] = 0;
    tablero[posicionPirata[0]][posicionPirata[1]] = 1;
}

int main(void)
{
    int filas;
    int columnas; 
    int encontrado; // Variable para verificar si se encontró el tesoro
    int posicionPirata[2]; // Coordenadas del pirata en el tablero
    char mov; // Dirección de movimiento ingresada por el usuario
    int turnos = 50; // Número máximo de turnos
    int salir = 0; // Variable para controlar si el usuario quiere salir del juego

    printf("Busqueda del tesoro! Intente encontrar el tesoro en menos de 50 turnos\n\n");

    // Bucle principal del juego
    do
    {
        // Solicitar dimensiones del tablero al usuario
        do
        {
            printf("Ingrese la cantidad de filas del tablero (minimo 4): ");
            scanf("%d", &filas);
            printf("Ingrese la cantidad de columnas del tablero (minimo 4): ");
            scanf("%d", &columnas);
            if (filas < 4)
            {
                printf("La cantidad de filas no cumple con el minimo requerido\n\n");
            }
            if (columnas < 4)
            {
                printf("La cantidad de columnas no cumple con el minimo requerido\n\n");
            }
        } while (filas < 4 || columnas < 4); //Seguir preguntando si las filas o las columnas no cumplen con el mínimo

        // Reservación de memoria para el puntero del tablero
        int **tablero = (int **)malloc(filas * sizeof(int *));
        for (int i = 0; i < filas; i++)
        {
            tablero[i] = (int *)malloc(columnas * sizeof(int));
        }

        inicializarTablero(tablero, filas, columnas, posicionPirata); // Inicializar el tablero
        dibujarTablero(tablero, filas, columnas); // Dibujar el tablero
        encontrado = 0; // Reiniciar la variable de tesoro encontrado

        // Bucle de turnos del juego
        while (encontrado != 1 && turnos > 0)
        {
            printf("Turnos restantes: %d\n", turnos); 
            printf("Ingrese la direccion a la que se quiere mover: ");
            scanf(" %c", &mov); 
            limpiarConsola(); // Limpiar la consola para mostrar el nuevo estado del tablero
            moverPirata(posicionPirata, mov, tablero, filas, columnas, &encontrado); // Mover al pirata
            dibujarTablero(tablero, filas, columnas); // Dibujar el tablero actualizado
            if (encontrado == 1)
            {
                printf("Encontraste el tesoro!\n"); 
            }
            turnos--; 
        }

        if (turnos == 0)
        {
            printf("Se te acabaron los turnos, perdiste!\n"); 
        }

        // Liberar la memoria utilizada
        for (int i = 0; i < filas; i++)
        {
            free(tablero[i]);
        }
        free(tablero);

        // Preguntar al usuario si desea jugar nuevamente
        printf("Queres jugar otra vez? (1 = si; 0 = no): ");
        scanf("%d", &salir);
    } while (salir == 1); // Repetir el juego si el usuario elige continuar

    return 0;
}