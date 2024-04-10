#include <stdio.h>

main ()
{
    int A [5][6];
    int 
		i,
		j,
		//Creo 2 variables con la cantidad de filas y columnas que tiene la matriz, dependiendo del número que se establezca
		//No ponía en la consigna que el usuario ingrese la dimensión de la matriz
		filas = sizeof(A)/sizeof(A[0]),
		columnas =  sizeof(A[0]) / sizeof(A[0][0]);
		
    printf ("Este programa te pide una matriz de %dx%d \n \n", filas, columnas );
    // ciclo for para pedir datos de la matriz
    //Hago que los for repitan la cantidad de veces de las filas y las columnas
	for (i=0; i<filas; i++)
	{
		for (j=0; j<columnas; j++)
		{
			printf ("Ingresa el valor A[%d][%d]: ", i+1, j+1); //Les pongo los valores más 1 para que le sea más común al usuario que no está acostumbrado a empezar a contar desde 0 
			scanf ("%d", &A[i][j]);
		}
	}
    
    // ciclo for para pedir imprimir en pantalla la matriz
	for (i=0; i<filas; i++)
	{
		for (j=0; j<columnas; j++)
		{
			/* printf ("%d ", A[i][j]);
			puedo agregar un espacio, pero lo que necesito es que baje cada vez
			que termine la fila y eso lo controla el ciclo for con variable i */
			
			// caracter de control \t tabulador horizontal
			printf ("%d\t", A[i][j]);
		}
		printf ("\n");
	}
      
}
