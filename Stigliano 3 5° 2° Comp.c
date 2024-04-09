#include <stdio.h>

int main(void)
{
	int
		choice,
		n = 0,
		i,
		n1,
		n2,
		n3,
		num,
		nums[3];

	double
		acum = 0,
		promedio,
		pruebas[4],
		tarea,
		acumProm = 0,
		acumNota = 0,
		nota;

	while (1 == 1)
	{
		printf("\n\nIngrese una opcion:\n\n");
		printf("1.Numeros consecutivos\n2.Promedio\n3.Par o impar\n4.Aprobar o no\n5.Nota\n\n");
		scanf("%d", &choice);

		if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
		{
			printf("Opcion incorrecta\n\n");
		}
		else
		{
			switch (choice)
			{
			case 1:
				while (n == 0)
				{
					for (i = 0; i < 87; i++)
					{
						n1 = i;
						n2 = i + 1;
						n3 = i + 2;

						if (n1 + n2 + n3 == 87)
						{
							n = 1;
							printf("Los 3 numeros consecutivos que sumados dan 87 son %d, %d y %d", n1, n2, n3);
						}
					}
				}
				break;

			case 2:
				for (i = 0; i < 3; i++)
				{
					printf("Ingrese el numero n%d: ", i + 1);
					scanf("%d", &nums[i]);
					acum += nums[i];
				}

				promedio = acum / 3;

				printf("El promedio de los 3 numeros es %.2lf", promedio);
				break;

			case 3:

				printf("Ingrese un numero positivo: ");
				scanf("%d", &num);

				if (num > 0)
				{
					if (num % 2 == 0)
					{
						printf("El numero es par");
					}
					else
						printf("El numero es impar");
				}
				else
					printf("Numero invalido");
				break;

			case 4:

				for (i = 0; i < 4; i++)
				{
					printf("Ingrese la nota de la prueba %d: ", i + 1);
					scanf("%lf", &pruebas[i]);
					acumProm += pruebas[i];
				}
				promedio = acumProm / 4;
				printf("Ingrese la nota de tarea: ");
				scanf("%lf", &tarea);

				if ((promedio + tarea) / 2 >= 6)
				{
					printf("La nota final es %.2lf, el alumno aprobo", (promedio + tarea) / 2);
				}
				else
					printf("La nota final es %.2lf, el alumno desaprobo", (promedio + tarea) / 2);
				break;

			case 5:
				printf("Ingrese la nota: ");
				scanf("%lf", &nota);
				if (nota >= 6)
				{
					printf("Aprobado");
					if (nota >= 8)
					{
						printf(", Felicitaciones!");
					}
				}
				else
				{
					printf("Desaprobado");
					if (nota == 1)
					{
						printf(", debe esforzarce mas");
					}
				}
				break;
			}
		}
	}
}
