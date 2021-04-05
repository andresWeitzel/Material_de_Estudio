#include <Servo.h>

 
 
Servo servo1;  // Crea un Objeto servo
int posicion;    // Variable de la posicion del servo
 
void setup()
{
  servo1.attach(2);  // Selecionamos el pin 2 como el pin de control para els ervo
}
 
void loop()
{

  posicion = 150;            // Establecemos el valor de la posicion a 150º
  posicion = map(posicion, 0, 1023, 0, 179);     // Establecemos la relacion entre los grados de giro y el PWM
  /* Con el mapa de valores anterior establecemos una relacin proporcional */
  /* entre el pulso minimo 0 con el grado minimo, 0 tambien y el pulso maximo*/
  /* 1023 con el grado maximo, 179*/
  servo1.write(posicion);                  // Escribimos la posicion con el mapa de valores al servo
  delay(150);                           // Y le damos un tiempo para que sea capaz de moverse
}
