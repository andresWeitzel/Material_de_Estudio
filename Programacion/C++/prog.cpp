//Una vez ingresado los tres valores, ordenarlos de menor a mayor.
#include<stdio.h>

int main(){
	int a,b,c;
	
	printf("\nIngrese el 1er digito:");
	scanf("%i",&a);
	printf("\nIngrese el 2do digito:");
	scanf("%i",&b);
	printf("\nIngrese el 3er digito:");
	scanf("%i",&c);
	
	if(a<b && a<c){
		if(b<c){printf("\nEl orden de los numeros es:%i%i%i",a,b,c);}
		else{printf("\nEl orden de los numeros es:%i%i%i",a,c,b);}
	}
			
	if(a>b && a>c){
		if(b<c){printf("\nEl orden de los numeros es:%i%i%i",b,c,a);}
		else{printf("\nEl orden de los numeros es:%i%i%i",c,b,a);}
		
	}
	if(c<a && c<b){
		if(a<b){printf("\nEl orden de los numeros es:%i%i%i",c,a,b);}
		else{printf("\nEl orden de los numeros es:%i%i%i",c,b,a);}
		
	}		

		
			
			
		
	

	
	
}
