//Hacer un programa que simule un cajero aut. con un saldo inicial de 1000 dolares

#include<stdio.h>

int main (){
	int opcion,saldo=1000;
	
	printf("\t--Bienvenido a su cuenta--");// el barra t nos da un espacio
	printf("\nRetirar dinero(Digite:1)");
	printf("\nVer  dinero(Digite:2) ");
	printf("\nSalir(Digite:3)");
	printf("\n--Opcion:--");
	scanf("%i",&opcion);
	
	switch(opcion){
		case 1:
		printf("¿Cual es el monto que desea retirar?\n");
		scanf("%i",&saldo);
		if(saldo>1000){
			printf("Saldo no disponible, vuelva a intentarlo");
			printf("¿Cual es el monto que desea retirar?\n");
			scanf("%i",&saldo);
			if(saldo>1000){
				printf("Saldo no disponible, vuelva a intentarlo");
			
			}else{
				fflush(stdin);
				printf("Aguarde un momento..");
				printf("...........");
				printf("Extrayendo..");}
			
		}else{
			fflush(stdin);
			printf("Aguarde un momento..");
			printf("...........");
			printf("Extrayendo..");
	
		};break;
		
		case 2:printf("Saldo disponible%i:",saldo);break;
		case 3:printf("Muchas Gracias por su visita");break;
		default:("Ha digitado parametros incorrectos");
	}
}
