

// Programa : Display LCD 16x2 con modulo I2C y dht11.

//Librerias LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Libreria Sensor
#include <SimpleDHT.h>

//Libreria mult 7 segmentos
#include <TM1637Display.h>

//================================================
#define CLK 4
#define DIO 5

//llamaremos al objeto : dht indicaremos el pin conectado(2) y el modelo(dht11);
int pinDHT11 = 3;
SimpleDHT11 dht11(pinDHT11);

//int sensor=3;
int led1 = 2;
int temp;
int hum;

//========================================

//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27, 16, 2);

//Inicializo el display multiplexor
TM1637Display display(CLK, DIO);


void setup() {
  Serial.begin(9600);

  //Led Sensado
  pinMode(led1, OUTPUT);

  // Inicializar el LCD
  lcd.init();

  //Encender la luz de fondo.
  lcd.backlight();

  //Defino el brillo del display 7 seg
  display.setBrightness(0x0f);



}

void loop() {



  byte t = 0;
  byte h = 0;
  dht11.read(pinDHT11, &t, &h, NULL);

  //Led Sensado
  digitalWrite(led1, HIGH);

  //Variable del conteo
  int valor = 0;
  //Muestro los conteos del sensado
  display.showNumberDec(valor, false);


  // Ubicamos el cursor en la primera posición(columna:0) de la primera línea(fila:0)
  //LCD
  lcd.setCursor(0, 0);
  lcd.print("Temperatura:");
  lcd.print(t);
  lcd.print(" C");
  //MONITOR
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" C");

  //LCD
  lcd.setCursor(0, 1);
  lcd.print("Humedad:");
  lcd.print(h);
  lcd.print(" %");
  //MONITOR
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.println(" %");

  delay(3000);

  //Incremento variable valor por cada sensado
  valor = valor ++;
  //Led Sensado
  digitalWrite(led1, LOW);
}
