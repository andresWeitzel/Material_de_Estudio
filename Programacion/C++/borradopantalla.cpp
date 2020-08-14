//Hacer un programa que borre la pantalla al pulsar 1

#include<stdio.h>
#include<stdlib.h>

int main(){
	char tecla;//caracter
	printf("programa de borrado de pantalla");
	printf("\n---------------------------------");
	printf("\n---------------------------------");
	printf("\nPara borrado de pantalla digite 1");
	scanf("%c",&tecla);
	
	if(tecla=='1'){
		system("cls");//necesitamos incluir la libreria <stdlib.h>
		printf("transaction completed");
	}else{
		//importante..
		fflush(stdin);//Para limpiar la memoria buffer

		
		printf("\ndigite 1");
		printf("\nprograma de borrado de pantalla");
		printf("\n---------------------------------");
		printf("\n---------------------------------");
		printf("\nPara borrado de pantalla digite 1");
		scanf("%c",&tecla);
				
		if(tecla=='1'){
			system("cls");//necesitamos incluir la libreria <stdlib.h>
			printf("transaction completed");
		}else{
			printf("\ndigite 1");
			printf("\nprograma de borrado de pantalla");
			printf("\n---------------------------------");
			printf("\n---------------------------------");
			printf("\nPara borrado de pantalla digite 1");
			scanf("%c",&tecla);
	}
	}
}
