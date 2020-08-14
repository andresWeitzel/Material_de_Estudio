//12. Serie Fibonacci

// 1 1 2 3 5 8 13...

#include<stdio.h>

int main(){
	int numero, i, x=0, y=1,z=1;
	
	printf("Digite el numero de elementos: ");
	scanf("%i",&numero);
	
	printf("1 , ");
	
	for(i=1;i<numero;i++){
		z = x + y;
		x = y;
		y = z;
		
		printf("%i , ",z);				
	}
	
	
	return 0;
}
