
/*
public class Main 
{
    public static void main(String[] args) {
        int input;
        int i;
        int j;
        boolean flag;
        boolean flag2 = false;
        
        do {
            System.out.printf("Ingrese un numero mayor a 100: ");
            System.in.scanf("%d", &input);
            if(input <= 100) System.out.printf("El numero debe ser mayor a 100, vuelva a intentar\n");
            else {
                flag = true;
		        flag2 = true;
		        for(j=2;j<input-1;j++){
		                if(input % j == 0) {
		                System.out.printf("%d ", j);
		                flag2 = false;
		            }
		        }
		        if(flag2) System.out.printf(" es primo");
		        System.out.printf("\n");
            }
        } while(!flag2);
    }    
}
*/


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


/*
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