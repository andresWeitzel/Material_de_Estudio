#include <stdio.h>

int main(){
	/*Mostrar los diez primeros num
	int i;
	for(i=0;i<=10;i++){
		printf("\n%i",i);	
	}
	*/
	
	//suma de los 10 primeros numeros pares
	
	int suma_pares=0,i;
	
	for(i=1;i<=10;i++){
		if(i%2==0){
			suma_pares+=i;
		}
	}
	printf("\nLa suma de los 10 primeros numeros es:%i",suma_pares);

	
	
	
}
