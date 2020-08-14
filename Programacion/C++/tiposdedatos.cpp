#include<stdio.h>

int main(){
	
	char a='e';//char es de tipo caracter tamaño=1byte va de 0 a 255
	printf("El elemento es :%c\n",a);//%c tipo caracter
	
	short b=-15;//short es corto tamaño=2bytes va de -128 a 127
	printf("El elemento es :%i\n",b);//Lo tomamos como entero
	
	int c=1024;//int es entero tamaño=2 bytes va desde -32768 hasta 32767
	printf("El elemento es:%i\n",c);
	
	unsigned int d=128;//solamente positivo,2 bytes, va desde 0 hasta 65535
	printf("El elemento es:%i\n",d);
	
	long e=123456;//4 bytes
	printf("El elemento es:%li\n",e);
	
	float f=15.678;//4 bytes
	printf("El elemento es:%f\n",f);
	printf("El elemento es:%.2f\n",f);//reduzco la cantidad de num despues de la coma;
	
	double g=1211.1212;//8 bytes
	printf("El elemento es:%lf\n",g);
	printf("El elemento es:%.2lf\n",g);//Reduzco cantidad de numeros
	
	
	
	
	
	return 0;
}
