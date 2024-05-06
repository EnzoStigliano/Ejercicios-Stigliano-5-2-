#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Limpiar la consola
void limpiarConsola() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

//Función para inicializar un tablero con las medidas que determinó el usuario
//Pirata y tesoro random
int inicializarTablero(int **tablero, int f, int c, int posicionPirata[2])
{
    srand(time(NULL));
    int i;
    int j;
    int fr = 0;
    int cr = 0;

    //Rellenar el tablero de 0
    for (i = 0; i < f; i++)
    {
        for (j = 0; j < c; j++)
        {
            tablero[i][j] = 0;
        }
    }

    //Generar valores aleatorios entre 1 y las filas/columnas - 2
    fr = rand() % (f - 2) + 1;
    cr = rand() % (c - 2) + 1;

    //Colocar el pirata y guardar su posición
    tablero[fr][cr] = 1;
    posicionPirata[0] = fr;
    posicionPirata[1] = cr;

    //Generar valores aleatorios para el tesoro
    do
    {
        fr = rand() % (f - 2) + 1;
        cr = rand() % (c - 2) + 1;
    } while (tablero[fr][cr] == 1); //Asegurarme que la posición no sea la misma que la del pirata

    tablero[fr][cr] = 2; //Colocar el tesoro
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
                printf("P "); //Los puentes de las esquinas
            }
            else if (j == 0 && i == f - 1)
            {
                printf("P "); //Puentes
            }
            else if (i == 0 || i == f - 1 || j == 0 || j == c - 1)
            {
                printf("A "); //Colocar agua en los bordes
            }
            else if(tablero[i][j] == 1){
                printf("1 "); //Colocar al pirata
            }
            else
                printf("0 "); //Poner "arena" en el resto de lugares
        }
        printf("\n");
    }
}

int moverPirata(int posicionPirata[2], char mov, int **tablero, int f, int c, int *encontrado)
{
    int posicionAntigua[2]; //Array para guardar la posición antigua del pirata, se usa para la actualización

    //Asignar valores de la posición actual
    posicionAntigua[0] = posicionPirata[0];
    posicionAntigua[1] = posicionPirata[1];

    switch (mov)
    {
    case 'n':
        if (posicionPirata[0] - 1 != 0)
        {
            posicionPirata[0]--; //Mover hacia arriba
        }
        break;

    case 's':
        if (posicionPirata[0] + 1 != f - 1)
        {
            posicionPirata[0]++; //Mover hacia abajo
        }
        break;

    case 'e':
        if (posicionPirata[1] + 1 != c - 1)
        {
            posicionPirata[1]++; //Mover hacia la derecha
        }
        break;

    case 'o':
        if (posicionPirata[1] - 1 != 0)
        {
            posicionPirata[1]--; //Mover hacia la izquierda
        }
        break;

    default:
        printf("Posicion invalida\n");
        break;
    }
    if (tablero[posicionPirata[0]][posicionPirata[1]] == 2) //Verificar si en la posición a la que se moverá el pirata está el tesoro
    {
        *encontrado = 1; //Tesoro encontrado
    }
    //Actualizar el tablero con la nueva posiciónd el pirata
    tablero[posicionAntigua[0]][posicionAntigua[1]] = 0;
    tablero[posicionPirata[0]][posicionPirata[1]] = 1;
}

int main(void)
{
    int filas;
    int columnas; 
    int encontrado = 0; // Variable para verificar si se encontró el tesoro
    int posicionPirata[2]; // Coordenadas del pirata en el tablero
    char mov; // Dirección de movimiento ingresada por el usuario
    int turnos = 50; // Número máximo de turnos
    int salir = 0; // Variable para controlar si el usuario quiere salir del juego
    int i; 

    printf("Busqueda del tesoro! Intente encontrar el tesoro en menos de 50 turnos\n\n");

    do
    {
        do
        {
            //Ingreso de cantidad de filas y columnas
            printf("Ingrese la cantidad de filas del tablero (minimo 4): ");
            scanf("%d", &filas);
            printf("Ingrese la cantidad de columnas del tablero (minimo 4): ");
            scanf("%d", &columnas);

            //Verificar si las filas y columnas cumplen con el mínimo
            if (filas < 4)
            {
                printf("\nLa cantidad de filas no cumple con el minimo requerido\n");
            }
            if (columnas < 4)
            {
                printf("\nLa cantidad de columnas no cumple con el minimo requerido\n");
            }
        } while (filas < 4 || columnas < 4); //Seguir preguntando si las filas o las columnas no cumplen con el mínimo

        // Reservación de memoria para el puntero del tablero
        int **tablero = (int **)malloc(filas * sizeof(int *));
        for (i = 0; i < filas; i++)
        {
            tablero[i] = (int *)malloc(columnas * sizeof(int));
        }

        inicializarTablero(tablero, filas, columnas, posicionPirata); // Inicializar el tablero
        dibujarTablero(tablero, filas, columnas); // Dibujar el tablero

        // Bucle de turnos del juego
        while (encontrado != 1 && turnos > 0)
        {
            printf("Turnos restantes: %d\n", turnos); 
            printf("Ingrese la direccion a la que se quiere mover (n = arriba, s = abajo, e = derecha, o = izquierda): ");
            scanf(" %c", &mov); 
            limpiarConsola(); // Limpiar la consola 
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
        for (i = 0; i < filas; i++)
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