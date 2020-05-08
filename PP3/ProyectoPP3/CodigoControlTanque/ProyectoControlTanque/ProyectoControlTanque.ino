/*PROYECTO SISTEMA DE CONTROL DE TANQUE*/
//---------------Librerias--------------------------

//--Librerias Lcd--
#include<Wire.h> 
#include <LiquidCrystal_I2C.h>

//--Libreria DHT11--
 #include <DHT.h>
//---------------Constantes---------------------------

//--Constantes para pins HC-SR04--
const int pinecho = 5;
const int pintrigger = 6;
//------------------Variables Pines--------------------------

//--Variables dht11-
int temp,hum;

//--Variable Sensor Agua--
int limiteAgua;//A2

//--Variables pins Leds--
int pinLedNormal=2;
int pinLedAdvertencia=3;

//--Variables pin buzzer--
int pinBuzzer=4;

//--Variable pin Rele--
int pinRele=7;

//--LCD NO SE ASIGNA(viene por defecto con el i2c)--
//SCL=A5;
//SDA=A4;

//-----------------Variables-------------------------
//--Calculo de volumen--
float volumenMin=0.00;
float volumenMax=2.92;
float alturaMax=18.80;
float alturaMin=3.21;
float volumen=0.00;
float tiempo,altura;//variables para el HC-SR04 
//unsigned int tiempo, distancia;//Variables originales oara el hc-sr04

//------------------Objetos---------------------------

//--Objeto Lcd--
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Inicia el LCD en la dirección 0x27, con 16 caracteres y 2 líneas

//--Objeto dht11--
DHT dht(A3,DHT11);//Indicamos entrada y nombre del objeto
//----------------------------------------------

//*********************************************************
//*******************SETUP*********************************
//*********************************************************
void setup()
{
  Serial.begin(9600);//Monitor Serial para testeo
  
//------------------Objetos------------------------------
  
  dht.begin();//Iniciamos dht11
  
  lcd.begin();//Iniciamos el Lcd   
  lcd.backlight();//Prendemos luz de fondo      
  
//------------------Pines---------------------------------
//--Configuramos los pines de los leds--
pinMode(pinLedNormal,OUTPUT);        
pinMode(pinLedAdvertencia,OUTPUT);        

//--Configuramos los pines del HC-SR04--  
pinMode(pinecho, INPUT);
pinMode(pintrigger, OUTPUT);

//--Configuramos pin del rele--
pinMode(pinRele,OUTPUT);

}
//***********************************************************
//******************LOOP**************************************
//************************************************************
void loop()
{
  //--Funcion del sensor ultrasonico--
   sensorHCSR04();

  //--Funcion de volumen del tanque--
  volumenTanque();
  
  //--Funcion del sensor dht11--
  sensorDHT11();

  //--Funcion del sensor de Agua--
  sensorAgua();

   //--Funcion que activa la bomba de agua mediante el rele--
  releBombaAgua();

  
  //-- funcion logicaDeControl--
  logicaDeControl();

 
  
  //--invocamos a la funcion que nos muestra los valored del dht11 y el sensor de agua
  outputLcd();
 
  

  //delay de control de sistema para no tener problema
  delay(200);
  
  
  
  
}
