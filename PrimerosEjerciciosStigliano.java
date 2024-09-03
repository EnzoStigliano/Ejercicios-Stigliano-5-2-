import java.util.Scanner;
import java.util.ArrayList;

/*
//Ejercicio 5
public class Main
{
    public static void main(String[] args) {
        // Declaración de variables 
        ArrayList<String> tareas;
        Scanner input;
        String tarea;
        int opcion;
        int numeroTarea;
        int i;

        // Inicialización de variables
        tareas = new ArrayList<>();
        input = new Scanner(System.in);

        do {
            //Pedido de datos
            System.out.println("\n--- Lista de Tareas ---");
            System.out.println("1. Añadir tarea");
            System.out.println("2. Ver lista de tareas");
            System.out.println("3. Eliminar tarea");
            System.out.println("4. Salir");
            System.out.print("Seleccione una opción (1-4): ");
            opcion = input.nextInt();
            input.nextLine();  // Consumir el salto de línea
            
            switch (opcion) {
                case 1:
                    // Añadir tarea
                    System.out.print("Ingrese la tarea: ");
                    tarea = input.nextLine();
                    tareas.add(tarea);
                    System.out.println("Tarea añadida.");
                    break;
                    
                case 2:
                    // Ver lista de tareas usando for-each
                    System.out.println("\n--- Lista de Tareas ---");
                    if (tareas.isEmpty()) {
                        System.out.println("La lista de tareas está vacía.");
                    } else {
                        i = 1;
                        for (String t : tareas) {
                            System.out.printf("%d. %s\n", i++, t);
                        }
                    }
                    break;
                    
                case 3:
                    // Eliminar tarea
                    System.out.println("\n--- Eliminar Tarea ---");
                    if (tareas.isEmpty()) {
                        System.out.println("La lista de tareas está vacía.");
                    } else {
                        i = 1;
                        for (String t : tareas) {
                            System.out.printf("%d. %s\n", i++, t);
                        }
                        System.out.print("Seleccione el número de la tarea a eliminar: ");
                        numeroTarea = input.nextInt();
                        if (numeroTarea > 0 && numeroTarea <= tareas.size()) {
                            tareas.remove(numeroTarea - 1);
                            System.out.println("Tarea eliminada.");
                        } else {
                            System.out.println("Número de tarea inválido.");
                        }
                    }
                    break;
                    
                case 4:
                    // Salir
                    System.out.println("Saliendo del programa...");
                    break;
                    
                default:
                    System.out.println("Opción no válida. Intente de nuevo.");
            }
        } while (opcion != 4);
    }
}
*/

/*
//Ejercicio 4
public class Main 
{
    public static void main(String[] args) {
        int num1;
        int num2;
        int resultado;
        int option;
        int continuar;
        Scanner input = new Scanner(System.in);
        
        do {
            System.out.printf("Ingrese el primer número: ");
            num1 = input.nextInt();
            
            System.out.printf("Ingrese el segundo número: ");
            num2 = input.nextInt();
            
            System.out.printf("Elija la operación:\n");
            System.out.printf("1. Sumar\n");
            System.out.printf("2. Restar\n");
            System.out.printf("3. Multiplicar\n");
            System.out.printf("4. Dividir\n");
            System.out.printf("Ingrese su opción (1-4): ");
            option = input.nextInt();
            
            switch (option) {
                case 1:
                    resultado = num1 + num2;
                    System.out.printf("Resultado: %d + %d = %d\n", num1, num2, resultado);
                    break;
                case 2:
                    resultado = num1 - num2;
                    System.out.printf("Resultado: %d - %d = %d\n", num1, num2, resultado);
                    break;
                case 3:
                    resultado = num1 * num2;
                    System.out.printf("Resultado: %d * %d = %d\n", num1, num2, resultado);
                    break;
                case 4:
                    if (num2 != 0) {
                        resultado = num1 / num2;
                        System.out.printf("Resultado: %d / %d = %d\n", num1, num2, resultado);
                    } else {
                        System.out.printf("Error: No se puede dividir por cero\n");
                    }
                    break;
                default:
                    System.out.printf("Opción no válida\n");
            }
            
            System.out.printf("¿Desea realizar otra operación? (1: Sí, 0: No): ");
            continuar = input.nextInt();
            
        } while (continuar == 1);
    }
}
*/

/*
//Ejercicio 3
public class Main 
{
    public static void main(String[] args) {
        int i;
        int j;
        int input;
        boolean flag = false;
        Scanner scanner = new Scanner(System.in);
        
        do {
            System.out.printf("Ingrese un numero mayor a 100: ");
            input = scanner.nextInt();
            if(input <= 100) System.out.printf("El numero debe ser mayor a 100, vuelva a intentar\n\n");
            else {
		        flag = true;
		        for(j=2;j<input-1;j++){
		                if(input % j == 0) {
		                System.out.printf("%d ", j);
		                flag = false;
		            }
		        }
		        if(flag) System.out.printf(" es primo");
		        System.out.printf("\n");
            }
        } while(!flag);
    }    
}
*/

/*
//Ejercicio 2
public class Main
{
    public static void main(String[] args) {
        int i;
        int j;
        boolean flag;
        boolean flag2;
        
        for(i=50;i<101;i++){
            flag = true;
		    flag2 = true;
		    System.out.printf("%d", i);
		    for(j=2;j<i-1;j++){
		        if(i % j == 0) {
		            if(flag) {
		                System.out.printf(" sus divisores son: "); 
		                flag = false;
		            }
		            System.out.printf("%d ", j);
		            flag2 = false;
		        }
		    }
		    if(flag2) System.out.printf(" es primo");
		    System.out.printf("\n");
		}
    }
}
*/

/*
//Ejercicio 1
public class Main
{
	public static void main(void) {
		int i;
		
		for(i=0;i<100;i++){
		    System.out.printf("%d", i+1);
		    if((i+1) % 2 == 0) System.out.printf(" es par");
		    System.out.printf("\n");
		}
	}
}
*/