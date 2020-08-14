/*13. Hacer un programa que imprima la suma de todos los números pares que hay desde 1 
hasta n, y diga cuantos números hay.*/

#include<stdio.h>

int main(){
	int cont=0,i,suma=0,n;
	
	printf("Digite la cantidad de elementos: ");
	scanf("%i",&n);
	
	for(i=1;i<=n;i++){
		if(i%2==0){
			suma += i;
			cont++;
		}
	}
	
	printf("\n La suma es: %i",suma);
	printf("\n La cantidad de numeros es: %i",cont);
	
	
	
	return 0;
}
