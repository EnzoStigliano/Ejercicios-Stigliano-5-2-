import java.util.Scanner;

/*
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;

public class Main {
    public static void main(String[] args) {
        DateTimeFormatter formatoHora = DateTimeFormatter.ofPattern("HH:mm:ss");
        LocalTime horaActual;
        
        while (true) {
            horaActual = LocalTime.now();
            System.out.print("\r" + horaActual.format(formatoHora));
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
*/

/*
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int numero = 0;
        int mayorNumero = Integer.MIN_VALUE;
        int menorNumero = Integer.MAX_VALUE;
        int sumaTotal = 0;
        int sumaPositivos = 0;
        int sumaNegativos = 0;
        int cantidadNumeros = 0;

        while (numero != -1) {
            System.out.print("Ingrese un número (-1 para terminar): ");
            numero = input.nextInt();
            
            if (numero != -1) {
                sumaTotal += numero;
                cantidadNumeros++;
                
                if (numero > mayorNumero) {
                    mayorNumero = numero;
                }

                if (numero < menorNumero) {
                    menorNumero = numero;
                }

                if (numero > 0) {
                    sumaPositivos += numero;
                } else {
                    sumaNegativos += numero;
                }
            }
        }

        if (cantidadNumeros > 0) {
            double media = (double) sumaTotal / cantidadNumeros;
            System.out.println("Mayor número introducido: " + mayorNumero);
            System.out.println("Menor número introducido: " + menorNumero);
            System.out.println("Suma de todos los números: " + sumaTotal);
            System.out.println("Suma de los números positivos: " + sumaPositivos);
            System.out.println("Suma de los números negativos: " + sumaNegativos);
            System.out.println("Media de la suma: " + media);
        } else {
            System.out.println("No se ingresaron números.");
        }
    }
}
*/

/*
public class Main {

    enum Mes {
        ENERO(1, 31),
        FEBRERO(2, 28),
        MARZO(3, 31),
        ABRIL(4, 30),
        MAYO(5, 31),
        JUNIO(6, 30),
        JULIO(7, 31),
        AGOSTO(8, 31),
        SEPTIEMBRE(9, 30),
        OCTUBRE(10, 31),
        NOVIEMBRE(11, 30),
        DICIEMBRE(12, 31);

        private final int orden;
        private final int dias;

        Mes(int orden, int dias) {
            this.orden = orden;
            this.dias = dias;
        }

        public int getOrden() {
            return orden;
        }

        public int getDias() {
            return dias;
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int diasBuscados;

        System.out.print("Ingrese el número de días: ");
        diasBuscados = input.nextInt();

        for (Mes mes : Mes.values()) {
            if (mes.getDias() == diasBuscados) {
                System.out.println("Mes: " + mes.name() + ", Orden: " + mes.getOrden() + ", Días: " + mes.getDias());
            }
        }
    }
}
*/

/*
public class Main {
    enum DiaSemana {
        LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String diaIngresado;
        DiaSemana dia;

        System.out.print("Ingrese un día de la semana: ");
        diaIngresado = input.nextLine().toUpperCase();
        dia = DiaSemana.valueOf(diaIngresado);

        if (dia == DiaSemana.SABADO || dia == DiaSemana.DOMINGO) {
            System.out.println("El día " + diaIngresado + " no es un día laboral.");
        } 
        else {
            System.out.println("El día " + diaIngresado + " es un día laboral.");
        }
    }
}
*/

/*
public class Main {
    enum DiaSemana {
        LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String diaIngresado;
        DiaSemana dia;

        System.out.print("Ingrese un día de la semana: ");
        diaIngresado = input.nextLine().toUpperCase();
        dia = DiaSemana.valueOf(diaIngresado);

        if (dia == DiaSemana.SABADO || dia == DiaSemana.DOMINGO) {
            System.out.println("El día " + diaIngresado + " no es laboral.");
        } 
        else {
            System.out.println("El día " + diaIngresado + " es laboral.");
        }
    }
}
*/

/*
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String frase;
        String[] palabras;

        System.out.print("Ingrese una frase: ");
        frase = input.nextLine();

        palabras = frase.split(" ");

        for (int i = 0; i < palabras.length; i++) {
            System.out.println(palabras[i]);
        }
    }
}
*/

/*
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String cadena;
        String subcadena;

        System.out.print("Ingrese una cadena: ");
        cadena = input.nextLine();

        if (cadena.length() >= 5) {
            subcadena = cadena.substring(3, 5);
            System.out.println("La cuarta y quinta letra son: " + subcadena);
        }
        else {
            System.out.println("La cadena es demasiado corta.");
        }
    }
}

*/

/*
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String palabra1;
        String palabra2;

        System.out.print("Ingrese la primera palabra: ");
        palabra1 = input.nextLine();

        System.out.print("Ingrese la segunda palabra: ");
        palabra2 = input.nextLine();

        if (palabra1.equals(palabra2)) {
            System.out.println("Las palabras son iguales.");
        }
        else {
            System.out.println("Las palabras son diferentes.");
        }
    }
}

*/

/*
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String frase;
        int longitud;

        System.out.print("Ingrese una frase: ");
        frase = input.nextLine();

        longitud = frase.length();

        System.out.println("La longitud de la cadena es: " + longitud);
    }
}
*/

/*
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String frase;
        int opcion;
        String resultado = "";

        System.out.print("Ingrese una frase: ");
        frase = input.nextLine();

        System.out.print("B?Desea convertir la frase a mayC:sculas (1) o minC:sculas (2)? ");
        opcion = input.nextInt();

        if (opcion == 1) {
            resultado = frase.toUpperCase();
        }
        else if (opcion == 2) {
            resultado = frase.toLowerCase();
        }

        System.out.println("Resultado: " + resultado);
    }
}
*/

/*
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String frase;
        String resultado = "";

        do {
            System.out.print("Escriba una frase (escriba una cadena vacC-a para terminar): ");
            frase = input.nextLine();
            if (!frase.isEmpty()) {
                resultado += frase + " ";
            }
        } while (!frase.isEmpty());

        System.out.println("La cadena resultante es: " + resultado.trim());
    }
}
*/

/*
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String frase;
        String fraseSinEspacios;

        System.out.print("Ingrese una frase: ");
        frase = input.nextLine();
        fraseSinEspacios = frase.replace(" ", "");

        System.out.println("Frase sin espacios: " + fraseSinEspacios);
    }
}
*/

/*
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int numero;
        int suma = 0;
        int i;

        do {
            System.out.print("Ingrese un nC:mero mayor que 1: ");
            numero = input.nextInt();
        } while (numero <= 1);

        for (i = 1; i <= numero; i++) {
            suma += i;
        }

        System.out.println("La suma de los nC:meros del 1 al " + numero + " es: " + suma);
    }
}
*/

/*
public class CalculadoraPolacaInversaApp {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int operando1;
        int operando2;
        String operacion;
        double resultad;

        System.out.print("Ingrese el primer operando: ");
        operando1 = input.nextInt();
        System.out.print("Ingrese el segundo operando: ");
        operando2 = input.nextInt();
        System.out.print("Ingrese el signo de la operaciC3n (+, -, *, /, ^, %): ");
        operacion = input.next();

        switch (operacion) {
            case "+":
                resultado = operando1 + operando2;
                break;
            case "-":
                resultado = operando1 - operando2;
                break;
            case "*":
                resultado = operando1 * operando2;
                break;
            case "/":
                resultado = (double) operando1 / operando2;
                break;
            case "^":
                resultado = Math.pow(operando1, operando2);
                break;
            case "%":
                resultado = operando1 % operando2;
                break;
            default:
                System.out.println("OperaciC3n no vC!lida.");
                return;
        }

        System.out.println("El resultado es: " + resultado);
    }
}
*/

/*
public class Main {
    public static void main(String[] args) {
        String frase = "La lluvia en Sevilla es una maravilla";

        for (int i = 0; i < frase.length(); i++) {
            int codigoAscii = (int) frase.charAt(i);
            System.out.print(codigoAscii + " ");
        }
    }
}
*/

/*
public class Main {
    public static void main(String[] args) {
        String frase = "La lluvia en Sevilla es una maravilla";
        String nuevaFrase = frase.replace('a', 'e');

        System.out.println(nuevaFrase);
    }
}
*/

/*
public class Main {
    public static void main(String[] args) {
        String frase = "La lluvia en Sevilla es una maravilla";
        int vocales = 0;

        for (int i = 0; i < frase.length(); i++) {
            char letra = frase.charAt(i);
            if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' ||
                letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U') {
                vocales++;
            }
        }

        System.out.println("El nC:mero total de vocales es: " + vocales);
    }
}
*/

/*
public class Main {
    public static void main(String[] args) {
        for (int numero = 2; numero <= 100; numero++) {
            boolean esPrimo = true;
            for (int i = 2; i <= Math.sqrt(numero); i++) {
                if (numero % i == 0) {
                    esPrimo = false;
                    break;
                }
            }
            if (esPrimo) {
                System.out.println(numero);
            }
        }
    }
}
*/

/*
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int numero;
        boolean esPrimo = true;

        System.out.println("Ingrese un nC:mero: ");
        numero = input.nextInt();

        if (numero <= 1) {
            esPrimo = false;
        }
        else {
            for (int i = 2; i <= Math.sqrt(numero); i++) {
                if (numero % i == 0) {
                    esPrimo = false;
                    break;
                }
            }
        }

        if (esPrimo) {
            System.out.println("El nC:mero es primo.");
        }
        else {
            System.out.println("El nC:mero no es primo.");
        }
    }
}
*/

/*
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int numero;

        do {
            System.out.println("Ingrese un nC:mero entero positivo: ");
            numero = input.nextInt();
        } while (numero <= 0);

        int cifras = Integer.toString(numero).length();

        if (cifras == 1) {
            System.out.println("\nEl nC:mero tiene " + cifras + " cifra.");
        } else {
            System.out.println("\nEl nC:mero tiene " + cifras + " cifras.");
        }
    }
}
*/

/*
public class Main {
    public static void main(String[] args) {
        java.util.Scanner input = new java.util.Scanner(System.in);
        int num1, num2, random;

        System.out.print("Ingrese el primer nC:mero: ");
        num1 = input.nextInt();

        System.out.print("Ingrese el segundo nC:mero: ");
        num2 = input.nextInt();

        System.out.println("Generando 10 nC:meros aleatorios entre " + num1 + " y " + num2 + ":");

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

        System.out.print("Ingrese un dC-a de la semana: ");
        dia = input.nextLine().toLowerCase();

        switch (dia) {
            case "lunes":
                System.out.println("Es un dC-a laboral.");
                break;
            case "martes":
                System.out.println("Es un dC-a laboral.");
                break;
            case "miC)rcoles":
                System.out.println("Es un dC-a laboral.");
                break;
            case "jueves":
                System.out.println("Es un dC-a laboral.");
                break;
            case "viernes":
                System.out.println("Es un dC-a laboral.");
                break;
            case "sC!bado":
                System.out.println("No es un dC-a laboral.");
                break;
            case "domingo":
                System.out.println("No es un dC-a laboral.");
                break;
            default:
                System.out.println("DC-a no vC!lido.");
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
            System.out.print("Introduce la contraseC1a: ");
            intento = input.nextLine();
            intentos++;

            if (intento.equals(password)) {
                System.out.println("Enhorabuena");
                acierto = true;
            }
            else {
                System.out.println("ContraseC1a incorrecta.");
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
            System.out.println("Ingrese un nC:mero mayor o igual que cero: ");
            numero = input.nextInt();
        } while (numero < 0);

        System.out.println("El nC:mero ingresado es: " + numero);
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
            System.out.println("La ecuaciC3n tiene dos raC-ces reales.");
            double raiz1 = (-b + Math.sqrt(discriminante)) / (2 * a);
            double raiz2 = (-b - Math.sqrt(discriminante)) / (2 * a);
            System.out.println("Las raC-ces son: " + raiz1 + " y " + raiz2);
        }
        else if (discriminante == 0) {
            System.out.println("La ecuaciC3n tiene una sola raC-z real.");
            double raiz = -b / (2 * a);
            System.out.println("La raC-z es: " + raiz);
        }
        else {
            System.out.println("La ecuaciC3n no tiene raC-ces reales.");
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

        System.out.println("Ingrese el nC:mero de ventas a introducir: ");
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
        System.out.println("El cC3digo ASCII es: " + ascii);

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

        System.out.print("Introduce un cC3digo de la tabla ASCII: ");
        texto = input.nextLine();
        codigo = Integer.parseInt(texto);
        caracter = (char) codigo;
        System.out.println("El carC!cter correspondiente es: " + caracter);

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
		System.out.println("B!Bienvenido " + nombre + "!\n");
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