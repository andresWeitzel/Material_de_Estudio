/*PROYECTO SISTEMA DE CONTROL DE TANQUE*/

//--Librerias Lcd--
#include<Wire.h> 
#include <LiquidCrystal_I2C.h>

//--Libreria DHT11--
 #include <DHT.h>

 //--Variables dht11-
int temp;
int hum;

//--Variables Leds--
int pinLedNormal=2;
int pinLedAdvertencia=3;

//--Variables buzzer--
int pinBuzzer=4;

//--Variable Sensor Agua--
int nivelAgua=0;


//--Objeto Lcd--
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Inicia el LCD en la dirección 0x27, con 16 caracteres y 2 líneas

//--Objeto dht11--
DHT dht(A3,DHT11);//Indicamos entrada y nombre del objeto





void setup()
{
  //Serial.begin(9600);//Monitor Serial para testeo
  
  dht.begin();//Iniciamos dht11
  
  lcd.begin();//Iniciamos el Lcd   
  lcd.backlight();//Prendemos luz de fondo      

  pinMode(pinLedNormal,OUTPUT);//Definimos ledNormal como salida          
  pinMode(pinLedAdvertencia,OUTPUT);//Definimos ledAdvertencia como salida          
  
}

void loop()
{
  //--Leemos los valores del sensor--
  nivelAgua=analogRead(A2);
 
  
  //--Leemos la temperatura y humedad del dht11--
  temp=dht.readTemperature();
  hum=dht.readHumidity();
  
  //--Invocamos a la funcion del ledNormal para destello
  if(temp <= 26 && nivelAgua <= 500){
   ledDestello();
  }

  //--invocamos a la funcion que nos muestra los valored del dht11 y el sensor de agua
  outputLcd();

  //--Invocamos a la funcion del ledAdvertencia junto con la funcion buzzerAdvertencia
  if(temp >= 27 || nivelAgua >= 501){
    ledAdvertencia();
    buzzerAdvertencia();
  }
  //delay de control de sistema para no tener problema
  delay(200);
}
