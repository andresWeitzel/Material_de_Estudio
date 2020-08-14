#include<stdio.h>//entrada salida
#define PI 3.1416//definimos algo fijo
int x=11;//Variable global, fuera del main

int main(){
	//EJEMPLO CON ENTERO
	int x=10;//variable local xq esta dentro del main
	int suma=0;
	suma=PI+ x;
	
	printf("La suma es:%i\n",suma);//el %i indica que es un tipo de dato entero
	
	//EJEMPLO CON DECIMAL
	int j=10;//variable local xq esta dentro del main
	float suma2=0;
	suma2=PI+ j;
	
	printf("La suma es:%f\n",suma2);//el %f indica que es un tipo de dato decimal
	printf("La suma es:%.2f\n",suma2);//el %.2f acotamos los decimales

	
	
	return 0;
}
