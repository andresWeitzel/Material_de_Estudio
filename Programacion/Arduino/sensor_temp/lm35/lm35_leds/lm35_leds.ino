// Declaracion de variables globales
float tempC; // Variable para almacenar el valor obtenido del sensor (0 a 1023)
int LM35 = A0; // Variable del pin de entrada del sensor (A0)
int led1 = 2;
int led2 = 3;

void setup() {
  // Configuramos el puerto serial a 9600 bps
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

}

void loop() {
  // Con analogRead leemos el sensor, recuerda que es un valor de 0 a 1023
  tempC = analogRead(LM35);

  // Calculamos la temperatura con la fórmula
  tempC = (5.0 * tempC * 100.0) / 1024.0;

  // Envia el dato al puerto serial
  Serial.print(tempC);
  Serial.print("°C");
  // Salto de línea
  Serial.print("\n");

  if (tempC < 18.00) {
    digitalWrite(led1, HIGH);
    if (tempC > 25.00 && tempC < 35.00) {
      Serial.println("-------------------ADVERTENCIA(TEMPERATURA ELEVADA)-------------");
      digitalWrite(led1, HIGH);
      delay(250);
      digitalWrite(led1, LOW);
      delay(250);
    }else{digitalWrite(led1, HIGH);} 
  }else {
      digitalWrite(led1, LOW);
    }
  

  if (tempC > 36.00) {
    digitalWrite(led2, HIGH);
    if (tempC > 50.00 && tempC < 70.00) {
      Serial.println("-------------------EVACUACION INMEDIATA-------------");
      digitalWrite(led2, HIGH);
      delay(250);
      digitalWrite(led2, LOW);
      delay(250);
    }else{digitalWrite(led2, HIGH);} 
  }else {
      digitalWrite(led2, LOW);
    }
  


  // Esperamos un tiempo para repetir el loop
  delay(500);
}
