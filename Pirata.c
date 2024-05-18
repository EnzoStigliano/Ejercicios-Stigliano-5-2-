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

int inicializarTablero(int **tablero, int f, int c, int posicionPirata[2]) {
  srand(time(NULL));
  int salidas[f][c]; // Matriz donde se guardarán las salidas
  int dungeons[16][4] = {
      // Lista de posibles salidas, si tiene un 1 es porque tiene salida para
      // ese lado. Orden: izquierda, derecha, arriba, abajo
      {0, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {0, 0, 1, 1},
      {0, 1, 0, 0}, {0, 1, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1},
      {1, 0, 0, 0}, {1, 0, 0, 1}, {1, 0, 1, 0}, {1, 0, 1, 1},
      {1, 1, 0, 0}, {1, 1, 0, 1}, {1, 1, 1, 0}, {1, 1, 1, 1}};
  int i;                // Variable para for 1
  int j;                // Variable para for 2
  int fr = 0;           // Fila random
  int cr = 0;           // Columna random
  int onoff = 1;        // iniciar o detener la generación de tierra
  int flag = 0;         // verificar si se genero un bloque de tierra
  int salida;           // numero asignado
  int cantDungeons = 0; // cantidad de tierra generada proceduralmente
  int grwt;             // ground water
  int tesoro;           // Número random para poner el tesoro
  int aux = 0;

  // Rellenar todo de 16 (número que no esté en el rango 0-15 inclusive)
  for (i = 0; i < f; i++) {
    for (j = 0; j < c; j++) {
      salidas[i][j] = 16;
    }
  }

  // Generar coordenadas para el pirata
  fr = rand() % f;
  cr = rand() % c;
  posicionPirata[0] = fr;
  posicionPirata[1] = cr;

  // N de casilla random
  salida = (rand() % 15) + 1;

  // Colocar el primer bloque de tierra
  salidas[fr][cr] = salida;

  // Generación procedural de tierra
  while (onoff == 1) {
    flag = 0;
    for (i = 0; i < f; i++) {
      for (j = 0; j < c; j++) {
        if (salidas[i][j] == 16) {
          // Cada vez que se genere un bloque de tierra se contará la cantidad
          // de éstos generados y si efectivamente se ha generado alguno Generar
          // un bloque de tierra si hay otro a la izquierda y si además éste
          // tiene salida hacia la derecha
          if (j - 1 >= 0 && salidas[i][j - 1] != 16) {
            if (dungeons[salidas[i][j - 1]][0] == 1) {
              salida = rand() % 15;
              salidas[i][j] = salida;
              cantDungeons++;
              flag = 1;
            }
          } else if (i - 1 >= 0 &&
                     salidas[i - 1][j] !=
                         16) { // Generar un bloque de tierra si hay otro arriba
                               // y si además éste tiene salida hacia abajo
            if (dungeons[salidas[i - 1][j]][2] == 1) {
              salida = rand() % 15;
              salidas[i][j] = salida;
              cantDungeons++;
              flag = 1;
            }
          } else if (j + 1 < c &&
                     salidas[i][j + 1] !=
                         16) { // Generar un bloque de tierra si hay otro a la
                               // derecha y si además éste tiene salida hacia la
                               // izquierda
            if (dungeons[salidas[i][j + 1]][1] == 1) {
              salida = rand() % 15;
              salidas[i][j] = salida;
              cantDungeons++;
              flag = 1;
            }
          } else if (i + 1 < f &&
                     salidas[i + 1][j] !=
                         16) { // Generar un bloque de tierra si hay otro abajo
                               // y si además éste tiene salida hacia arriba
            if (dungeons[salidas[i + 1][j]][3] == 1) {
              salida = rand() % 15;
              salidas[i][j] = salida;
              cantDungeons++;
              flag = 1;
            }
          }
        }
      }
    }
    if (flag == 0)
      onoff = 0; // Si no se generó ningún bloque de tierra se detiene el bucle
  }

  for (i = 0; i < f; i++) {
    for (j = 0; j < c; j++) {
      // Generar el tesoro en un bloque de tierra con la misma probabilidad de
      // estar en cualquiera previamente generado
      if (salidas[i][j] != 16) {
        tesoro = rand() % cantDungeons;
        if (tesoro == 0) {
          tablero[i][j] = 20; // Colocar tesoro
          break;
        } else
          aux++; // Contador de bloques de tierra donde no se generó el tesoro
      }
      // Generar el tesoro en el último bloque de tierra en caso de que no se
      // haya generado en los otros bloques
      if (aux == cantDungeons && salidas[i][j] != 16) {
        tablero[i][j] = 20;
      }
    }
  }

  tablero[posicionPirata[0]][posicionPirata[1]] = 21; // Poner al pirata

  // Poner tierra (0) en los bloques generados previamente, y aleatoriamente
  // poner agua o tierra en el resto
  for (i = 0; i < f; i++) {
    for (j = 0; j < c; j++) {
      if (salidas[i][j] != 16 && tablero[i][j] != 20 && tablero[i][j] != 21) {
        tablero[i][j] = 0;
      } else if (tablero[i][j] != 20 && tablero[i][j] != 21) {
        grwt = rand() % 2;
        tablero[i][j] = grwt;
      }
    }
  }
}

void dibujarTablero(int **tablero, int f, int c) {
  int i;
  int j;

  for (i = 0; i < f; i++) {
    for (j = 0; j < c; j++) {
      switch (tablero[i][j]) {
      case 0:
        printf("0");
        break;

      case 1:
        printf("A");
        break;

      case 20:
        printf("T");
        break;

      case 21:
        printf("1");
        break;
      }
    }
    printf("\n");
  }
}

int moverPirata(int posicionPirata[2], char mov, int **tablero, int f, int c,
                int *encontrado) {
  int posicionAntigua[2];

  posicionAntigua[0] = posicionPirata[0];
  posicionAntigua[1] = posicionPirata[1];

  switch (mov) {
  case 'n':
    if (posicionPirata[0] - 1 >= 0 &&
        tablero[posicionPirata[0] - 1][posicionPirata[1]] !=
            1) // Fijarse si arriba no hay agua
    {
      posicionPirata[0]--;
    }
    break;

  case 's':
    if (posicionPirata[0] + 1 < f &&
        tablero[posicionPirata[0] + 1][posicionPirata[1]] !=
            1) // Fijarse si abajo no hay agua
    {
      posicionPirata[0]++;
    }
    break;

  case 'e':
    if (posicionPirata[1] + 1 < c &&
        tablero[posicionPirata[0]][posicionPirata[1] + 1] !=
            1) // Fijarse si a la derecha no hay agua
    {
      posicionPirata[1]++;
    }
    break;

  case 'o':
    if (posicionPirata[1] - 1 >= 0 &&
        tablero[posicionPirata[0]][posicionPirata[1] - 1] !=
            1) // Fijarse si a la izquierda no hay agua
    {
      posicionPirata[1]--;
    }
    break;

  default:
    printf("Posicion invalida\n\n");
    break;
  }
  if (tablero[posicionPirata[0]][posicionPirata[1]] == 20) {
    *encontrado = 1;
  }
  tablero[posicionAntigua[0]][posicionAntigua[1]] = 0;
  tablero[posicionPirata[0]][posicionPirata[1]] = 21;
}

int main(void) {
  int filas;
  int columnas;
  int encontrado;        // Variable para verificar si se encontró el tesoro
  int posicionPirata[2]; // Coordenadas del pirata en el tablero
  char mov;              // Dirección de movimiento ingresada por el usuario
  int turnos;            // Número máximo de turnos
  int salir = 0; // Variable para controlar si el usuario quiere salir del juego
  int opcion = 0;
  char tecla;

  while(1){
    // Limpiar la pantalla
    system("cls");

    // Dibujar el título
    printf("\033[1;34m"); // Texto en azul
    printf("┌─────────────────────────────────┐\n");
    printf("│\033[1m ¡Bienvenido al juego del tesoro!│ \n"); // Texto mas grande
    printf("└─────────────────────────────────┘\n");
    printf("\033[0m"); // Resetear el color
    printf("\n");

    // Dibujar las opciones
    printf("\033[1;33m"); // Texto en amarillo
    printf("  Menu:\n");
    printf("  1. Jugar\n");
    printf("  2. Reglas\n");
    printf("  3. Controles\n");
    printf("  4. Salir\n");
    printf("\033[0m"); // Resetear el color

    // Esperar input del usuario
    printf("\033[1;32m"); // Texto en verde
    printf("\nIngresa el número de la opción: ");
    printf("\033[0m"); // Resetear el color
    scanf("%d", &opcion);

    // Procesar la selección
    switch (opcion) {
    case 1:
      // Mostrar juego
      system("cls");
        // Bucle principal del juego
        do {
          // Solicitar dimensiones del tablero al usuario
          do {
            printf("Ingrese la cantidad de filas del tablero (minimo 4): ");
            scanf("%d", &filas);
            printf("Ingrese la cantidad de columnas del tablero (minimo 4): ");
            scanf("%d", &columnas);
            if (filas < 4) {
              printf("La cantidad de filas no cumple con el minimo requerido\n\n");
            }
            if (columnas < 4) {
              printf("La cantidad de columnas no cumple con el minimo requerido\n\n");
            }
          } while (filas < 4 || columnas < 4); // Seguir preguntando si las filas o las
                                               // columnas no cumplen con el mínimo

          // Reservación de memoria para el puntero del tablero
          int **tablero = (int **)malloc(filas * sizeof(int *));
          for (int i = 0; i < filas; i++) {
            tablero[i] = (int *)malloc(columnas * sizeof(int));
          }

          inicializarTablero(tablero, filas, columnas,
                             posicionPirata);       // Inicializar el tablero
          dibujarTablero(tablero, filas, columnas); // Dibujar el tablero
          encontrado = 0; // Inicializar la variable de tesoro encontrado
          turnos = 5;

          // Bucle de turnos del juego
          while (encontrado != 1 && turnos > 0) {
            printf("Turnos restantes: %d\n", turnos);
            printf("Ingrese la direccion a la que se quiere mover: ");
            scanf(" %c", &mov);
            limpiarConsola(); // Limpiar la consola para mostrar el nuevo estado del
                              // tablero
            moverPirata(posicionPirata, mov, tablero, filas, columnas,
                        &encontrado); // Mover al pirata
            dibujarTablero(tablero, filas,
                           columnas); // Dibujar el tablero actualizado
            if (encontrado == 1) {
              printf("Encontraste el tesoro!\n");
            }
            turnos--;
          }

          if (turnos == 0 && encontrado == 0) {
            printf("Se te acabaron los turnos, perdiste!\n");
          }

          // Liberar la memoria utilizada
          for (int i = 0; i < filas; i++) {
            free(tablero[i]);
          }
          free(tablero);

          // Preguntar al usuario si desea jugar nuevamente
          printf("Queres jugar otra vez? (1 = si; 0 = no): ");
          scanf("%d", &salir);

        } while (salir == 1); // Repetir el juego si el usuario elige continuar
      printf("Presiona Enter para volver al menu...\n");
      getchar();

      break;
    case 2:
      // Mostrar reglas
      system("cls");
      printf("\033[1;34m"); // Texto en azul
      printf("┌────────────────────────────────┐\n");
      printf("│    Reglas del juego:           │\n");
      printf("├────────────────────────────────┤\n");
      printf("│- Tienes 5 intentos para        │\n");
      printf("│  intentar encontrar el tesoro  │\n");
      printf("│- Evita caer al agua.           │\n");
      printf("└────────────────────────────────┘\n");
      printf("\033[0m"); // Resetear el color
      printf("Presiona Enter para salir.\n");
      getchar();
      break;
    case 3:
      // Mostrar controles
      system("cls");
      printf("\033[1;34m"); // Texto en azul
      printf("┌────────────────────────────────┐\n");
      printf("│       Controles del juego:     │\n");
      printf("├────────────────────────────────┤\n");
      printf("│- Tecla n (Norte↑):             │\n");
      printf("│  Desplazamiento hacia arriba.  │\n");
      printf("│- Tecla s (Sur↓):               │\n");
      printf("│  Desplazamiento hacia abajo.   │\n");
      printf("│- Tecla o (Oeste←):             │\n");
      printf("│  Desplazamiento hacia la       │\n");
      printf("│  izquierda.                    │\n");
      printf("│- Tecla e (Este→):              │\n");
      printf("│  Desplazamiento hacia la       │\n");
      printf("│  derecha.                      │\n");
      printf("└────────────────────────────────┘\n");
      printf("\033[0m"); // Resetear el color
      printf("Presiona Enter para salir.\n");
      getchar();
      break;
    case 4:
      //salir
      return 0;
    default:
      printf("\033[1;31m"); // Texto en rojo
      printf("Opción inválida. Intenta de nuevo.\n");
      printf("\033[0m"); // Resetear el color
      getchar();
      break;
    }

    // Limpiar el buffer de entrada
    while (getchar() != '\n')
      ;
  }
  }

