#define led 3
#define pote A0


void setup() {
pinMode(led,OUTPUT);
pinMode(pote,INPUT);
}

void loop() {
//Analogica=0 a 1023
//PWM=0 a 255
/*Aca convertimos el valor analogico maximo 
del pote(1023) al valor maximo digital(255) para que ambas lecturas sean iguales */

//analogWrite(led,analogRead(pot)/4);



/*Haremos lo mismo pero con la funcion MAP, este precisa de 5 parametros
 * Sintasis--> 
 *  map(lectura, valorMINIMOdeENTRADA, valorMAXIMOdeENTRADA, valorMINIMOdeSALIDA, valorMAXIMOdeSALIDA);
*/
analogWrite(led,map(analogRead(pote),0,1023,0,255));


}
