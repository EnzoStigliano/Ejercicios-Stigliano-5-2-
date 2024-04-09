#include<stdio.h>

int main(void){
	int num;
	
	printf("Ingrese un numero: ");
	scanf("%d", &num);
	
	if(num == 1){
		printf("El numero es 1");
	}
	else {
		printf("%d ", num);
		while(num != 1){
			if((num % 2) == 0){
				num = num / 2;
			}
			else num = (num * 3) + 1;
			
			printf("%d ", num);
		}
	}
}
