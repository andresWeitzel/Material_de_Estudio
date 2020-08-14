#include<stdio.h>

int main(){
	
	//Aqui usaremos 3 variables en un print
	//int a=10;
	//float b=15.5;
	//char c='e';
	
	//printf("%i%.1f%c",a,b,c);
	
	//Pedir valor
	/*
	int d;
	float e;
	char f;
	
	printf("Digite el valor de la variable d:");
	scanf("%i",&d);
	printf("Digito:%i",d);
	*/
	//pedir nombres,etc
	char x[20];
	printf("Digite su nombre:");
	gets(x);//Toma tambien con los espacios
	scanf("%s",x);//%s es de string
	printf("Su nombre es %s ",x);
	
}

