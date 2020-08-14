//Sentencia SWITCH,solamente puede ser de tipo int or char

#include <stdio.h>

int main(){
	
	int num;
	printf("Digite un numero entre 1-3\n");
	scanf("\n%i",&num);
	
	switch(num){
		case 1:printf("Numero 1");break;//tres casos diferntes por que tengo 3 num
		case 2:printf("Numero 2");break;//el break nos indica que en caso se cumpla un case termina ahi
		case 3:printf("Numero 3");break;
		default:printf("No ha digitado lo solicitado");
	}
}
