import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String texto;
        char caracter;
        
        System.out.println("Ingrese un carácter:");
        texto = input.nextLine();
        caracter = texto.charAt(0);
        codigo = (int) caracter;
        System.out.println("El código ASCII del carácter '" + caracter + "' es: " + codigo);
    }   
}

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