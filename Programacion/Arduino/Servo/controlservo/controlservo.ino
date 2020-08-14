/*--Puerto Serial--
   puerto de comunicacion com3/uart
   UART-->PUERTO SERIAL, bits para transmitir y recibir datos
   escribimos en el puerto serial la ventaja al enviar datos podemos ver en tiekmpo real que esta haciendo el microprocedor

*/
#include <Servo.h>

Servo chino;

int memoria1 = 0;


void setup() {

  Serial.begin(9600);//el 9600 es la velocidad de transmicion(badio)
  chino.attach(4);
  pinMode(13, OUTPUT);
  chino.write(90);
}

void loop() 
{

  

  if (Serial.available() > 0)//
  {
    int led = Serial.read();//Lee la variable declarada

    if (led == 'a')
    {
      digitalWrite(13, HIGH);
    }
    if (led == 'b')
    {
      digitalWrite(13, LOW);
    }
    if(led=='s'){
      
     for (int i = 30; i < 150; i++) {
        chino.write(i);
        Serial.print("Grados Servo:\n");
        Serial.print(i);
        delay(15);
      }
    }
    if(led=='d'){

      for (int i = 150; i > 30; i--) {
        
        chino.write(i);
        Serial.print("Grados Servo:\n");
        Serial.print(i);
        delay(15);
      
      
      }
      
    }
  }
}
