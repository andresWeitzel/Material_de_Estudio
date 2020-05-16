//----------Librerias-------------
#include <DHT.h>//dht11
#include "TM1637.h"//modulo display

//----------Pines----------------------
//--dht11--
#define DHTPIN 3
#define DHTTYPE DHT11
//--modulo display--
#define DIO 4
#define CLK 5

//----------Objetos------------------------
//--DHT11--
DHT dht(DHTPIN,DHTTYPE);
//--Modulo Display--
TM1637 tm1637(CLK,DIO);

//------------SETUP------------------------
void setup() {
 //--Monitor Serial-- 
 Serial.begin(9600);

//--Iniciamos el sensor dht11-- 
 dht.begin();  
//--Configuramos el Modulo Display--
 tm1637.init();//Iniciamos
 tm1637.set(2);//seteamos el brillo(0 min,7 max)
 tm1637.point(POINT_OFF);//Apagamos los 2 puntos
 
}

//------------LOOP--------------------
void loop() {
 //--Funcion dht11 Central--
 dht11Central();
 //--Funcion modulo display TM1637--
 modDisplay();
 
 
}
