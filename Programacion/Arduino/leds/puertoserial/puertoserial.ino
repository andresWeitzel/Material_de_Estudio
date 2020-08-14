/*--Puerto Serial--
 * puerto de comunicacion com3/uart
 * UART-->PUERTO SERIAL, bits para transmitir y recibir datos
 * escribimos en el puerto serial la ventaja al enviar datos podemos ver en tiekmpo real que esta haciendo el microprocedor 
 * 
*/
int memoria1=0;

void setup() {
  
Serial.begin(9600);//el 9600 es la velocidad de transmicion(badio)
}

void loop() {

Serial.print("Hola");//enviamos algo al monitor serial
Serial.print("\n");
Serial.print(memoria1);
delay(500);
memoria1++;

}
