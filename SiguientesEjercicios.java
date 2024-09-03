import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {
	    int num1=30;
		int num2=20;
		String nombre;
		double radio;
		double area;
		String texto;
		Scanner input = new Scanner(System.in);
 
		System.out.println("El resultado de la suma es " + (num1+num2));
		System.out.println("El resultado de la resta es " + (num1-num2));
		System.out.println("El resultado de la multiplicación es " + (num1*num2));
		System.out.println("El resultado de la división es " + (num1/num2));
		
		if(num1 < num2) System.out.println(num2 + " es mayor que " + num1 + "\n");
		else if(num1 > num2) System.out.println(num1 + " es mayor que " + num2 + "\n");
		else System.out.println(num2 + " y " + num1 + " son iguales\n");
		
		System.out.println("Introduce tu nombre: ");
		nombre = input.nextLine();
		System.out.println("¡Bienvenido " + nombre + "!\n");
		
		System.out.println("Ingrese el radio del circulo: ");
		radio = input.nextDouble();
		area = Math.pow(radio, 2)*Math.PI;
		System.out.println("El area del circulo es " + area);
		
		System.out.println("Ingrese un numero: ");
		texto = input.nextLine();
		num1 = Integer.parseInt(texto);
		if(num1%2 == 0) System.out.println("El numero es par\n");
		else System.out.println("El numero es impar\n");
		
		System.out.println("Ingrese un codigo de la table ASCII:");
	}
}
