/*PROYECTO SISTEMA DE CONTROL DE TANQUE*/
//---------------Librerias--------------------------

//--Librerias Lcd--
#include<Wire.h> 
#include <LiquidCrystal_I2C.h>

//--Libreria DHT11--
 #include <DHT.h>
//---------------Constantes---------------------------

//--Constantes para HC-SR04--
const int pinecho = 5;
const int pintrigger = 6;
//------------------Variables--------------------------

//--Variables para calculos HC-SR04--
//unsigned int tiempo, distancia;
unsigned int tiempo,capacidad;

//--Variables dht11-
int temp;
int hum;

//--Variables Leds--
int pinLedNormal=2;
int pinLedAdvertencia=3;

//--Variables buzzer--
int pinBuzzer=4;

//--Variable Sensor Agua--
int limiteAgua=0;


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

}
//***********************************************************
//******************LOOP**************************************
//************************************************************
void loop()
{
  //--Medicion del sensor ultrasonico--
   funcionHCSR04();

  //--Leemos los valores del sensor de agua--
  limiteAgua=analogRead(A2);
 
  
  //--Leemos la temperatura y humedad del dht11--
  temp=dht.readTemperature();
  hum=dht.readHumidity();

  //--invocamos a la funcion que nos muestra los valored del dht11 y el sensor de agua
  outputLcd();
 
  //--Invocamos nuestra funcion logicaDeControl--
  logicaDeControl();

  //delay de control de sistema para no tener problema
  delay(200);
  
  
  
  
}
