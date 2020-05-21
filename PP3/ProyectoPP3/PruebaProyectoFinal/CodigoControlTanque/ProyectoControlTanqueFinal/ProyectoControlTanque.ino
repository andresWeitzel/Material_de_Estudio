 /*PROYECTO SISTEMA DE CONTROL DE TANQUE*/
 
//================Librerias=============================

//--Librerias Lcd--
#include<Wire.h> //i2c
#include <LiquidCrystal_I2C.h>//lcd

//--Libreria DHT11--
 #include <DHT.h>

//--Libreria Teclado Matricial--
#include <Keypad.h>

//--Librerias rfid--
#include<SPI.h>//COMUNICACINO PROTOCOLO BUS ARDUINO PINES RFID
#include<MFRC522.h>//RFIF

//--Librerias RTC---
//#include <Wire.h>Esta incluida
#include<RTClib.h>

//--Libreria TM1637 display 7 segmentos--
#include <TM1637.h>
 
//===============================Constantes====================================

//--Constantes para pins HC-SR04--
const int pinecho = 5;
const int pintrigger = 6;

//--Constantes para filas columnas teclado matricial--
const byte filasTeclado=4;
const byte columnasTeclado=4;

//===============================VariablesPines====================================

//--Variables pines dht11 del tanque-
int tempTanque,humTanque;

//--Variables pines dht11 de la sala de control
int tempSalaControl,humSalaControl;

//--Variable MQ2--
int deteccionHumo;

//--Variable pin Sensor Agua--
int limiteAgua;//A2

//--Variables pins Leds--
int pinLedNormal=2;
int pinLedAdvertencia=3;

//--Variables pin buzzer--
int pinBuzzer=4;

//--Variable pin Rele--
int pinRele=7;

/*--PINES ANALOGICOS--
 * 
 * --ARDUINO UNO--
--LCD NO SE ASIGNA(viene por defecto con el i2c)--
SCL=A5;
SDA=A4;

--ARDUINO MEGA--
SENSORAGUA:A2;
DHT´S:A3 Y A4;
MQ2:A5;

--LCD--
SCL=21
SDA=20

*/

//--Variable pines para el teclado matricial--
byte pinesFilaTeclado[]={22,23,24,25};//Usando el arduino Mega, son los 4 primeros cables de izq a derecha de la matriz
byte pinesColumnaTeclado[]={26,27,28,29};//idem, los 4 cables que les siguen

//===============================Variables====================================

//--TECLADO MATRICIAL--
char valorBotonKeypad;


char botonesTeclado[filasTeclado][columnasTeclado]={//FILAS,COLUMNAS
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

//--VOLUMEN DE AGUA--
//--Calculo de volumen--
float volumenMin=0.00;
float volumenMax=1.50;
float alturaMax=9.80;
float alturaMin=18.79;
float volumen;
float tiempo,altura;//variables para el HC-SR04 
//unsigned int tiempo, distancia;//Variables de altura para el hc-sr04

//--BUZZER Y LEDS--
//--Variables para la Frecuencia del Buzzer--
  const int f1=540;
  const int f2=560;
  //--Variables para los delays--
  const int d1=1000;
  const int d2=200;
  const int d3=100;
  const int d4=100;
  const int d5=50;
  const int d6=30;

 //--Variables RTC--
int dia,mes,anio,hora,minuto,segundo;
 


//===============================Objetos====================================

//--Objeto Lcd--
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Inicia el LCD en la dirección 0x27, con 16 caracteres y 2 líneas

//--Objeto dht11 del tanque--
DHT dhtTanque(A3,DHT11);//Indicamos entrada y nombre del objeto

//--Objeto dht11 de la sala de control--
DHT dhtSalaControl(A4,DHT11);

//--Objeto keypad--
//Se le pasa la funcion de mapeo para los botones, luego la asignacion de pines para fila columna y luego la cantidad de 
//c/u(4x4)
Keypad teclado=Keypad(makeKeymap(botonesTeclado),pinesFilaTeclado,pinesColumnaTeclado,filasTeclado,columnasTeclado);

//--Objeto RFID--
MFRC522 mfrc522(8,9);//PIN RST, PIN SS

//--Objeto RTC DS3231--
RTC_DS3231 rtc;

//--Objeto Display7segmentos--
TM1637 displaySegmentos(15,14);//CLK,DIO


//*********************************************************
//*******************SETUP*********************************
//*********************************************************
void setup()
{
  Serial.begin(9600);//Monitor Serial para testeo
  
//===============================ObjetosSetup====================================
  //--DHT--
  dhtTanque.begin();
  dhtSalaControl.begin();

  //--LCD--
  lcd.begin();//Iniciamos el Lcd   
  lcd.backlight();//Prendemos luz de fondo      

  //--RFID--
  SPI.begin();//Iniciamos el protocolo
  mfrc522.PCD_Init(); // Iniciamos el MFRC522
  //Serial.println("Control de acceso:");

  //--RTC--
  // Comprobamos si tenemos el RTC conectado
 if (! rtc.begin()) {
 Serial.println("No hay un módulo RTC");
 while (1);
 }

//--Display 7 segmentos--
displaySegmentos.set();//Seteamos el display con alsa configuraciones que lepasamso
displaySegmentos.init();//Iniciamos el display



 
//===============================PinesSetup====================================
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
  
  //--Funcion RTC--
  horarioRTC();
  
  //--Funcion del sensor ultrasonico--
   sensorHCSR04();

  //--Funcion del sensor dht11 para el tanque--
  sensorDHT11Tanque();

  //--Funcion del sensor dht11 para la sala de control--
  sensorDHT11SalaControl();

  //--Funcion del sensor MQ2--
  detectorHumoMQ2();
  
  //--Funcion del sensor de Agua--
  sensorAgua();

  //--Funcion que activa la bomba de agua mediante el rele--
  releBombaAgua();

  //--Funcion de volumen del tanque--
  volumenTanque();

  //--fUNCON DISPLAY 7 SEGMENTOS--
  displaySegmentosTM1637();

   //--Funcion keyPad()--
  //keyPad();

  //--Funcion rfid--
  //accesoRFID();
  
  //-- funcion logicaDeControl--
  controlMonitoreo();

  

  //Delay de control de sistema para no tener problema
  delay(200);
  
  
  
  
}
