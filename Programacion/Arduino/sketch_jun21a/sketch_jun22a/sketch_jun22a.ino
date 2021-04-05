
// Pines utilizados
#define LEDVERDE1 2
#define LEDAMARILLO1 3
#define LEDROJO1 4
#define LEDVERDE2 5
#define LEDAMARILLO2 6
#define LEDROJO2 7
#define PULSADOR1 8
#define PULSADOR2 9
 
// Variables
bool activo1 = true; // Indica si el semáforo 1 está activo, de lo contrario será el semáforo 2
int tiempoCambio = 1500; // Tiempo de espera entre transición de LEDs
int tiempoEspera = 5000; // Tiempo de espera hasta comenzar transición
 
void setup() {
  // Iniciamos el monitor serie
  Serial.begin(9600);
 
  // Modo entrada/salida de los pines
  pinMode(LEDVERDE1, OUTPUT);
  pinMode(LEDAMARILLO1, OUTPUT);
  pinMode(LEDROJO1, OUTPUT);
  pinMode(LEDVERDE2, OUTPUT);
  pinMode(LEDAMARILLO2, OUTPUT);
  pinMode(LEDROJO2, OUTPUT);
  pinMode(PULSADOR1, INPUT);
  pinMode(PULSADOR2, INPUT);
 
  // Apagamos todos los LEDs
  digitalWrite(LEDVERDE1, LOW);
  digitalWrite(LEDAMARILLO1, LOW);
  digitalWrite(LEDROJO1, LOW);
  digitalWrite(LEDVERDE2, LOW);
  digitalWrite(LEDAMARILLO2, LOW);
  digitalWrite(LEDROJO2, LOW);
 
  // Estado inicial: semáforo 1 abierto, semáforo 2 cerrado
  digitalWrite(LEDVERDE1, HIGH);
  digitalWrite(LEDROJO2, HIGH);
}
 
void loop() {
  // Dependiendo del semáforo que tengamos activo
  if (activo1)
  {
    // Está encendido el semáforo 1, comprobamos el pulsador 2
    int valor2 = digitalRead(PULSADOR2);
 
    // Si hay un coche esperando, pulsador pulsado
    if (valor2 == HIGH)
    {
      // Encender semáforo 2
      encenderSemaforo2();
 
      // Semáforo 2 activo
      activo1 = false;
    }
  }
  else
  {
    // Está encendido el semáforo 1, comprobamos el pulsador 1
    int valor1 = digitalRead(PULSADOR1);
 
    // Si hay un coche esperando, pulsador pulsado
    if (valor1 == HIGH)
    {
      // Encender semáforo 1
      encenderSemaforo1();
 
      // Semáforo 1 activo
      activo1 = true;
    }
  }
}
 
void encenderSemaforo2()
{
  // Apagamos semáforo 1
  // Esperamos
  delay(tiempoEspera);
 
  // Pasamos a luz amarilla
  digitalWrite(LEDVERDE1,LOW);
  digitalWrite(LEDAMARILLO1,HIGH);
 
  // Esperamos
  delay(tiempoCambio);
 
  // Pasamos a luz roja
  digitalWrite(LEDAMARILLO1,LOW);
  digitalWrite(LEDROJO1,HIGH);
 
  // Encendemos semáforo 2
  // Esperamos
  delay(tiempoCambio);
 
  // Pasamos a luz amarilla
  digitalWrite(LEDROJO2,LOW);
  digitalWrite(LEDVERDE2,HIGH);
}
 
void encenderSemaforo1()
{
  // Apagamos semáforo 2
  // Esperamos
  delay(tiempoEspera);
 
  // Pasamos a luz amarilla
  digitalWrite(LEDVERDE2,LOW);
  digitalWrite(LEDAMARILLO2,HIGH);
 
  // Esperamos
  delay(tiempoCambio);
 
  // Pasamos a luz roja
  digitalWrite(LEDAMARILLO2,LOW);
  digitalWrite(LEDROJO2,HIGH);
 
  // Encendemos semáforo 1
  // Esperamos
  delay(tiempoCambio);
 
  // Pasamos a luz amarilla
  digitalWrite(LEDROJO1,LOW);
  digitalWrite(LEDVERDE1,HIGH);
}
