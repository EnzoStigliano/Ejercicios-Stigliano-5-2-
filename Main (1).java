import java.util.Scanner;

/*
public class Main {
    public static void main(String[] args) {
        java.util.Scanner input = new java.util.Scanner(System.in);
        int num1, num2, random;

        System.out.print("Ingrese el primer número: ");
        num1 = input.nextInt();

        System.out.print("Ingrese el segundo número: ");
        num2 = input.nextInt();

        System.out.println("Generando 10 números aleatorios entre " + num1 + " y " + num2 + ":");

        for (int i = 0; i < 10; i++) {
            random = (int)(Math.random() * (Math.abs(num2 - num1) + 1)) + Math.min(num1, num2);
            System.out.println(random);
        }
    }
}
*/

/*
public class Main {
    public static void main(String[] args) {
        java.util.Scanner input = new java.util.Scanner(System.in);
        String dia;

        System.out.print("Ingrese un día de la semana: ");
        dia = input.nextLine().toLowerCase();

        switch (dia) {
            case "lunes":
                System.out.println("Es un día laboral.");
                break;
            case "martes":
                System.out.println("Es un día laboral.");
                break;
            case "miércoles":
                System.out.println("Es un día laboral.");
                break;
            case "jueves":
                System.out.println("Es un día laboral.");
                break;
            case "viernes":
                System.out.println("Es un día laboral.");
                break;
            case "sábado":
                System.out.println("No es un día laboral.");
                break;
            case "domingo":
                System.out.println("No es un día laboral.");
                break;
            default:
                System.out.println("Día no válido.");
                break;
        }
    }
}
*/

/*
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String password = "1234";
        String intento;
        int intentos = 0;
        boolean acierto = false;

        while (intentos < 3 && !acierto) {
            System.out.print("Introduce la contraseña: ");
            intento = input.nextLine();
            intentos++;

            if (intento.equals(password)) {
                System.out.println("Enhorabuena");
                acierto = true;
            } 
            else {
                System.out.println("Contraseña incorrecta.");
            }
        }

        if (!acierto) {
            System.out.println("Has agotado los 3 intentos.");
        }
    }
}
*/

/*
public class Main {
    public static void main(String[] args) {
        java.util.Scanner input = new java.util.Scanner(System.in);
        int numero;

        do {
            System.out.println("Ingrese un número mayor o igual que cero: ");
            numero = input.nextInt();
        } while (numero < 0);

        System.out.println("El número ingresado es: " + numero);
    }
}
*/

/*
public class Main {
    public static void main(String[] args) {
        java.util.Scanner input = new java.util.Scanner(System.in);
        double a, b, c;
        double discriminante;

        System.out.println("Ingrese el coeficiente a: ");
        a = input.nextDouble();
        System.out.println("Ingrese el coeficiente b: ");
        b = input.nextDouble();
        System.out.println("Ingrese el coeficiente c: ");
        c = input.nextDouble();

        System.out.println("Calculando el discriminante...");
        discriminante = (b * b) - (4 * a * c);
        System.out.println("El discriminante es: " + discriminante);

        if (discriminante > 0) {
            System.out.println("La ecuación tiene dos raíces reales.");
            double raiz1 = (-b + Math.sqrt(discriminante)) / (2 * a);
            double raiz2 = (-b - Math.sqrt(discriminante)) / (2 * a);
            System.out.println("Las raíces son: " + raiz1 + " y " + raiz2);
        } 
        else if (discriminante == 0) {
            System.out.println("La ecuación tiene una sola raíz real.");
            double raiz = -b / (2 * a);
            System.out.println("La raíz es: " + raiz);
        } 
        else {
            System.out.println("La ecuación no tiene raíces reales.");
        }
    }
}
*/


/*
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int numVentas;
        double sumaVentas = 0;
        double venta;

        System.out.println("Ingrese el número de ventas a introducir: ");
        numVentas = input.nextInt();

        for (int i = 0; i < numVentas; i++) {
            System.out.println("Ingrese el monto de la venta " + (i+1) + ": ");
            venta = input.nextDouble();
            sumaVentas += venta;
        }

        System.out.println("La suma total de todas las ventas es: " + sumaVentas);
    }
}
*/

/*
public class Main {
    public static void main(String[] args) {
        for(int i = 1; i<101; i++){
            if((i % 2 == 0) || (i % 3 == 0)){
                System.out.println(i);
            }
        }
    }
}
*/

/*
public class Main {
    public static void main(String[] args) {
        for(int i = 1; i<101; i++) System.out.println(i);
    }
}
*/

/*
public class Main {
    public static void main(String[] args) {
        int i = 1;
        while(i < 101) {
            System.out.println(i);
            i++;
        }
    }
}
*/

/*
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double precio;
        
        System.out.println("Ingrese el precio: ");
        precio = input.nextDouble();
        
        System.out.println("El precio con el IVA es: " + (precio + (precio * 0.21)));
    }
}
*/

/*
public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String caracter;
        int codigo;
        int ascii;
        
        System.out.print("Introduce un caracter: ");
        caracter = input.nextLine();
        codigo = caracter.charAt(0);
        ascii = (int) codigo;
        System.out.println("El código ASCII es: " + ascii);
        
        input.close();
    }
}
*/

/*
public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String texto;
        int codigo;
        char caracter;
        
        System.out.print("Introduce un código de la tabla ASCII: ");
        texto = input.nextLine();
        codigo = Integer.parseInt(texto);
        caracter = (char) codigo;
        System.out.println("El carácter correspondiente es: " + caracter);
        
        input.close();
    }
}
*/


/*
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String texto;
        int num;
        
        System.out.println("Ingrese un numero: ");
		texto = input.nextLine();
		num = Integer.parseInt(texto);
		if(num%2 == 0) System.out.println("El numero es par\n");
		else System.out.println("El numero es impar\n");
    }
}
*/

/*
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double radio;
        double area;
        
        System.out.println("Ingrese el radio del circulo: ");
		radio = input.nextDouble();
		area = Math.pow(radio, 2)*Math.PI;
		System.out.println("El area del circulo es " + area);
    }
}
*/

/*
public class Main{
    public static void main(String[] args) {
		String nombre;
		Scanner input = new Scanner(System.in);
		
		System.out.println("Introduce tu nombre: ");
		nombre = input.nextLine();
		System.out.println("¡Bienvenido " + nombre + "!\n");
    }
}
*/

/*
public class Main
{
	public static void main(String[] args) {
	    int num1=30;
		int num2=20;
		
		if(num1 < num2) System.out.println(num2 + " es mayor que " + num1 + "\n");
		else if(num1 > num2) System.out.println(num1 + " es mayor que " + num2 + "\n");
		else System.out.println(num2 + " y " + num1 + " son iguales\n");
	}
}
*/