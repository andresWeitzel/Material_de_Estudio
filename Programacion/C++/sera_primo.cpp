//¿Es o no un numero primo?

#include<stdio.h>

int main(){
	//HICIMOS CUALQUIERA
	/*int numero,primo,no_primo,w;
	printf("\nDigite un numero entero:");
	scanf("%i",&numero);
	
	w=0;
	
	while(w<=1){
		if(numero%numero && numero%1){
			printf("Es un numero primo");
		}else{
			printf("No es un numero primo");
		}
	}
	w ++;
	*/
	int i,num,cont=0;//Se inicializa con cero, sino le asigna un valor x
	printf("\nDigite un numero:");
	scanf("%i",&num);
	
	for(i=1;i<=num;i++){
		if(num%i==0){//El numero que el usuario coloque se dividira por la cantidad total
			cont++;
		
		}
		
	}
	
	if(cont>2){//si cont>2, significa que el numero se puede dividir mas veces y no es primo
		printf("El numero no es primo,sino compuesto ");
	}else{
		printf("El numero es primo");
	}
	
	
	
}
