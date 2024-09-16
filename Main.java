import java.util.Scanner;

public class Main {
    public static void(String[] args) {
        
    }
}

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