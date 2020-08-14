#include <stdio.h>

#define num 5
double x=6;
int y=7;
int z1;
double z2;
double zt; 




int main(){
	
	printf("El valor de num es:%i\n",num);
	
	/*AL SER UNA DEFINIDA NO SE PUEDE ALTERAR SU VALOR
	num=8;
	printf("El nuevo valor de num es:%i\n",num);
	*/
	
	z1=x+y;//YA DECLARADAS LAS Z1 Y Z2 DAREMOS UN VALOR
	printf("El valor de z1 es :%i\n",z1);
	
	z1=++z1;//sumamos 1 al valor z1, con lo cual alteramos el valor final
	printf("El nuevo valor de z1 es:%i\n",z1);
	
	z2=3.16;
	printf("El valor de z2 es :%d\n",z2);
	
	zt=z1+z2;
	printf("El valor de zt es ;%d\n",zt);
	
	
	
	
	
	
	return 0;
}
