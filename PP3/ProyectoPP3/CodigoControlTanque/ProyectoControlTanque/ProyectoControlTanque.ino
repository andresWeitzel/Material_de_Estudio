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
unsigned int tiempo, distancia;

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
//-----------------------------------------------------------------
 // ENVIAR PULSO DE DISPARO EN EL PIN "TRIGGER"
  digitalWrite(pintrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pintrigger, HIGH);
  // EL PULSO DURA AL MENOS 10 uS EN ESTADO ALTO
  delayMicroseconds(10);
  digitalWrite(pintrigger, LOW);

  // MEDIR EL TIEMPO EN ESTADO ALTO DEL PIN "ECHO" EL PULSO ES PROPORCIONAL A LA DISTANCIA MEDIDA
  tiempo = pulseIn(pinecho, HIGH);

  // LA VELOCIDAD DEL SONIDO ES DE 340 M/S O 29 MICROSEGUNDOS POR CENTIMETRO
  // DIVIDIMOS EL TIEMPO DEL PULSO ENTRE 58, TIEMPO QUE TARDA RECORRER IDA Y VUELTA UN CENTIMETRO LA ONDA SONORA
  distancia = tiempo / 58;

  // ENVIAR EL RESULTADO AL MONITOR SERIAL
  Serial.print(distancia);
  Serial.println(" cm");
  delay(200);
//------------------------------------------------------------------------

  

  //--Leemos los valores del sensor--
  limiteAgua=analogRead(A2);
 
  
  //--Leemos la temperatura y humedad del dht11--
  temp=dht.readTemperature();
  hum=dht.readHumidity();
  
  //--Invocamos a la funcion del ledNormal para destello
  if(temp <= 26 && limiteAgua <= 500){
   ledDestello();
  }

  //--invocamos a la funcion que nos muestra los valored del dht11 y el sensor de agua
  outputLcd();

  //--Invocamos a la funcion del ledAdvertencia junto con la funcion buzzerAdvertencia
  if((temp >= 27 && temp <= 28) || limiteAgua >= 390){
    ledAdvertenciaLow();
    buzzerAdvertenciaLow();
  }
  if((temp >= 29 && temp <= 30) || limiteAgua >= 450){
    ledAdvertenciaMedium();
    buzzerAdvertenciaMedium();
  }
  if(temp >= 31 || limiteAgua >= 550){
    ledAdvertenciaHigh();
    buzzerAdvertenciaHigh();
  }
  
  //delay de control de sistema para no tener problema
  delay(200);
}
