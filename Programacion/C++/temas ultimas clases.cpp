
/*clase 8/11

--->Recursividad  
      
    utlizacion de:
	
	 fibonachi
	fractales--->ej:la curva de coch,hilbert,
	mandermol
	
	
	clase 15/11/18 
	archivos-->actualizaciones del sistema,registros
	loggeo de errores, ej impresiones, registro comppleto
	
	comandos file(defino un archivo(nombre)), con este comando le puedo decir a donde puedo crear un archivo
	apunte numero 35 ue paso el por drive
	abriendo archivos--->file * nombre,    fopen("nombre",parametros);//solo lectura no puedo modificarlo
	utilizacion de captura de informacion
	fprintf(manda informacion al archivo)
	fscanf(leer lo que est escrito en el archivo lo muestra)
	ejercicios 22
	finales fecha 

*/

//crndo archivos para lectura  de temperatura
//A modo de esquema


#include <stdio.h>
#include<stdlib.h>

int main(void){
	FILE*temperatura;
	temperatura= fopen("temperatura.txt","w");
	int c,valor;
	for(c=1;c<=200;c++){
		valor=rand()%101;
		fprintf(temperatura,"%d\n",valor);
	}
	fclose(temperatura);
}//Revisar programa dentro del sensor


//Ahora para abrir el archivo y abrirlo como segundo paso
//
FILE*temp2;
temp2=fopen("temperatura.txt","r");
int cont=0,sum=0;
while(fscanf(temp2,"%d",&dato)!=eof){
	


cont++;
sum=sum+dato;
}


printf("prom=%d",sum/cont);
fclose(temp2);
file*resul;
fopen("resultado.txt","w");
fprintf("resul","prom%d",sum/cont);
fclose(resul);


 
