//Multiplos de 3 desde 1 hasta n

#include <stdio.h>

int main(){
	/*int n,cont;
	
	printf("Total de numeros:");
	scanf("%i",&n);
	
	cont=1;
	
	while(cont<=n){
		if(cont%3==0){
			printf("%i.\n",cont);
		}
		cont++;
		
	}------------------------------------
	*/
	//sumar 1-2+3-4...n
	/*Solucion:
	
	impares(+)
	pares(-)
	
	suma_pares=-2-4-6..
	suma_impares=1+3+5..
	
	suma=suma_pares+suma_impares.
	
	1-2+3-4+5-6
	-1+3-4+5-6
	2-4+5-6
	-2+5-6
	3-6
	-3
	*/
	
	int n,cont,suma=0,suma_pares=0,suma_impares=0,negativo;
	
	printf("Digite la cantidad de numeros a sumar");
	scanf("%i",&n);
	
	cont=1;
	
	while(cont<=n){
		
		if(cont%2==0){
			negativo=cont*(-1);
			suma_pares+=negativo;
			
		}else{
			suma_impares+=cont;
			
		}
		cont++;
		
	}
	
	suma=suma_pares+suma_impares;
	printf("La suma total es:%i",suma);
	
	
	
	
	
	
	
	
	
}
