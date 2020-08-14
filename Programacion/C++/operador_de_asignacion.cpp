#include <stdio.h>

int main(){
/*	
	int a,b,c;
	a=b=c=10;
	
	printf("El valor de a,b,c es:%i %i %i\n",a,b,c);
	
	b=c+a+100;
	
	printf("El valor de a,b,c es:%i %i %i\n",a,b,c);
*/

//OPERACIONES CON OPERADORES
//Pedir 2 numeros al usuario,sumarlos,restaros y dividirlos entre 20
/*
	int e,r;
	printf("Digite 1er num entero\n");
	scanf("%i",&e);
	e+=20;
	e-=20;
	e/=20;
	printf("El resultado es:%i\n",e);
	
	printf("Digite 2do num entero\n");
	scanf("%i",&r);
	r+=20;
	r-=20;
	r/=20;
	printf("El resultado es:%i\n",r);
*/
//Mismo ejercicio pero ahora todo lo pedido hcerlo entre ellos

	int a,b,mult=0,div=0,sum=0,rest=0;
	printf("Digite dos numeros enteros..");
	printf("El 1er num es:");
	scanf("%i",&a);
	printf("El segundo num es:");
	scanf("%i",&b);
	
	
	mult=a*b;
	div=a/b;
	sum=a+b;
	rest=a-b;
	
	printf("La multiplicacion de los dos numeros es%i",mult);
	printf("La Division de los dos numeros es%i",div);
	printf("La suma de los dos numeros es%i",sum);
	printf("La resta de los dos numeros es%i",rest);


}
