/*A medida que disminuimos la resistencia del
  pote se van encendiendo los leds y viceversa se apagan*/

#define pot A0
int leds[] = {2, 3, 4, 5, 6, 7, 8};
int valor_pot;
int valor_map;
int i, x, z;




void setup() {
  //El for es para declarar en una sentencia todos los leds OUTPUT
  for (i = 0; i < 8; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(pot, INPUT);
}

//La x representa el valor que le pasariamos para que el for compare
void encender(int x) {
  //int i;

  for (z = 0; z < x; z++) { //ACA VAMOS DE 0 HASTA EL VALOR PASADO
    digitalWrite(leds[z], HIGH); //Con el i declaramos cual rango de leds se prenderan

  }
  for (z = x; z < 8; z++) { //ACA VAMOS DEL VALOR PASADO HASTA EL FINAL
    digitalWrite(leds[z], LOW);
  }

}


void loop() {

  valor_pot = analogRead(pot);

  valor_map = map(valor_pot, 0, 1023, 0, 8); //La maxima salida(8) sera los leds que yo tenga,
  //cual valo quiero pasar a la funcion encender

  encender(valor_map);
}
