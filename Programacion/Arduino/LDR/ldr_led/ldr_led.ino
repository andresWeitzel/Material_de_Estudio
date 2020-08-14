#define ldr A0
#define led 2
int valor_ldr = 0; //espara recibir el valor de lectura de la puerta analogica


void setup() {
  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  valor_ldr = analogRead(ldr);
  if (valor_ldr > 900) {
    digitalWrite(led, LOW); //Al ser la luminosidad tan grande apagamos el led
  } else {
    digitalWrite(led, HIGH); //Encenderemos el Led cuando el valor medido sea menor a 900.
  }
  Serial.println(valor_ldr);
  delay(500);


}
