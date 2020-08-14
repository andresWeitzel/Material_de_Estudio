int Led1 = 2;
int Led2 = 3;
int Led3 = 4;
// Pin analogico de entrada para el LDR
int LDR = 0;
 
// Variable donde se almacena el valor del LDR
int valor_LDR = 0;  
 
void setup()
{
  // Configuramos como salidas los pines donde se conectan los led
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  
  //  Configurar el puerto serial
  Serial.begin(9600);
}
 
void loop()
{
  // Apagar todos los leds siempre que se inicia el ciclo
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);
  digitalWrite(Led3, LOW);
 
  // Guardamos el valor leido del ADC en una variable
  // El valor leido por el ADC (voltaje) aumenta de manera directamente proporcional
  // con respecto a la luz percibida por el LDR
  valor_LDR= analogRead(LDR);
  
  // Devolver el valor leido a nuestro monitor serial en el IDE de Arduino
  Serial.print("El valor medido es: ");
  Serial.println(valor_LDR);
 
  // Encender los leds apropiados de acuerdo al valor de ADC
  if(valor_LDR > 220)
  {
    digitalWrite(Led1, HIGH);
  }
  if(valor_LDR > 412)
  {
    digitalWrite(Led2, HIGH);
  }
  if(valor_LDR > 620)
  {
    digitalWrite(Led3, HIGH);
  }
  // Esperar unos milisegundos antes de actualizar
  delay(200);
}
