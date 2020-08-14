#include <Servo.h>

#define potenciometro A0
#define led 2
#define pinMotor 4
#define temporizador 10

Servo servo1;

int valorPotenciometro;

void setup() {
  // put your setup code here, to run once:
servo1.attach(pinMotor);
pinMode(potenciometro,INPUT);
valorPotenciometro=0;

}

void loop() {
  // put your main code here, to run repeatedly:
  //Colocamos todo en una sola linea para ahorrar codigo
  //la funcion map convierte la señal analogo y digital en una sola de salida relacionada
  //La funcion analogRead es la lectura de los valores del pote
valorPotenciometro=map(analogRead(potenciometro), 0, 1023, 0, 255);

servo1.write(valorPotenciometro);

delay(temporizador);



}
