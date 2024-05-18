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
    int salidas[f][c]; //Matriz donde se guardarán las salidas
    int casillas[16][4] = { //Lista de posibles salidas, si tiene un 1 es porque tiene salida para ese lado. Orden: izquierda, derecha, arriba, abajo
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
    };
    int i; //Variable para for 1
    int j; //Variable para for 2
    int fr = 0; //Fila random
    int cr = 0; //Columna random
    int onoff = 1; //iniciar o detener la generación de tierra
    int flag = 0; //verificar si se genero un bloque de tierra
    int salida; //numero asignado
    int dungeons = 0; //cantidad de tierra generada proceduralmente
    int grwt; //ground water
    int tesoro; //Número random para poner el tesoro
    int aux = 0;

    //Rellenar todo de 16 (número que no esté en el rango 0-15 inclusive)
    for(i=0;i<f;i++){
        for(j=0;j<c;j++){
            salidas[i][j] = 16;
        }
    }

    //Generar coordenadas para el pirata
    fr = rand() % (f - 1);
    cr = rand() % (c - 1);
    posicionPirata[0] = fr;
    posicionPirata[1] = cr;

    //N de casilla random
    salida = (rand()%15) + 1;

    //Colocar el primer bloque de tierra
    salidas[fr][cr] = salida;

    //Generación procedural de tierra
    while(onoff == 1){
        flag == 0;
        for(i=0;i<f;i++){
            for(j=0;j<c;j++){
                if(salidas[i][j] == 16){
                    //Cada vez que se genere un bloque de tierra se contará la cantidad de éstos generados y si efectivamente se ha generado alguno
                    //Generar un bloque de tierra si hay otro a la izquierda y si además éste tiene salida hacia la derecha
                    if(j-1 >= 0 && salidas[i][j-1] != 16){
                        if(salidas[salidas[i][j-1]][0] == 1){
                            salida = (rand()%15) + 1;
                            salidas[i][j] = salida;
                            dungeons++;
                            flag = 1;
                        }
                    }

                    //Generar un bloque de tierra si hay otro arriba y si además éste tiene salida hacia abajo
                    if(i-1 >= 0 && salidas[i-1][j] != 16){
                        if(salidas[salidas[i-1][j]][2] == 1){
                            salida = (rand()%15) + 1;
                            salidas[i][j] = salida;
                            dungeons++;
                            flag = 1;
                        }
                    }

                    //Generar un bloque de tierra si hay otro a la derecha y si además éste tiene salida hacia la izquierda
                    if(j+1 >= 0 && salidas[i][j+1] != 16){
                        if(salidas[salidas[i][j+1]][1] == 1){
                            salida = (rand()%15) + 1;
                            salidas[i][j] = salida;
                            dungeons++;
                            flag = 1;
                        }
                    }

                    //Generar un bloque de tierra si hay otro abajo y si además éste tiene salida hacia arriba
                    if(i+1 >= 0 && salidas[i+1][j] != 16){
                        if(salidas[salidas[i+1][j]][3] == 1){
                            salida = (rand()%15) + 1;
                            salidas[i][j] = salida;
                            dungeons++;
                            flag = 1;
                        }
                    }
                }
            }
        }
        if(flag == 0) onoff == 0; //Si no se generó ningún bloque de tierra se detiene el bucle
    }

    for(i=0; i<f; i++){
            for(j=0; j<c; j++){
                //Generar el tesoro en un bloque de tierra con la misma probabilidad de estar en cualquiera previamente generado
                if(salidas[i][j] != 16){
                    tesoro = rand() % (dungeons-1);
                    if(tesoro == 1){
                        tablero[i][j] = 20; //Colocar tesoro
                        j = c; //Detener bucle columnas
                        i = f; //Detener bucle filas
                    }
                    else aux++; //Contador de bloques de tierra donde no se generó el tesoro
                }
                //Generar el tesoro en el último bloque de tierra en caso de que no se haya generado en los otros bloques
                if(aux == dungeons && salidas[i][j] != 16){
                    tablero[i][j] = 20;
                }
            }
        }

    tablero[posicionPirata[0]][posicionPirata[1]] = 21; //Poner al pirata

    //Poner tierra (0) en los bloques generados previamente, y aleatoriamente poner agua o tierra en el resto
    for(i=0;i<f;i++){
        for(j=0;j<c;j++){
            if(salidas[i][j] != 16 && tablero[i][j] != 20 && tablero[i][j] != 21){
                tablero[i][j] = 0;
            }
            else {
                grwt = rand() % 1;
                tablero[i][j] == grwt;
            }
        }
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
            switch (tablero[i][j]){
                case 0:
                    printf("0");
                    break;
            
                case 1:
                    printf("A");
                    break;

                case 20:
                    printf("0");
                    break;

                case 21:
                    printf("1");
                    break;
            }
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
        if (tablero[posicionPirata[0]-1][posicionPirata[1]] != 1) //Fijarse si arriba no hay agua
        {
            posicionPirata[0]--;
        }
        break;

    case 's':
        if (tablero[posicionPirata[0]+1][posicionPirata[1]] != 1) //Fijarse si abajo no hay agua
        {
            posicionPirata[0]++;
        }
        break;

    case 'e':
        if (tablero[posicionPirata[0]][posicionPirata[1]-1] != 1) //Fijarse si a la derecha no hay agua
        {
            posicionPirata[1]++;
        }
        break;

    case 'o':
        if (tablero[posicionPirata[0]][posicionPirata[1]-1] != 1) //Fijarse si a la izquierda no hay agua
        {
            posicionPirata[1]--;
        }
        break;

    default:
        printf("Posicion invalida\n");
        break;
    }
    if (tablero[posicionPirata[0]][posicionPirata[1]] == 20)
    {
        *encontrado = 1;
    }
    tablero[posicionAntigua[0]][posicionAntigua[1]] = 0;
    tablero[posicionPirata[0]][posicionPirata[1]] = 21;
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
        encontrado = 0; // Inicializar la variable de tesoro encontrado

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