#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

//Librerias para RTC
#include <Wire.h>//Comunicacion I2C
#include "RTClib.h"//Libreria



// URL DE LA PAGINA Y HASH
#define FIREBASE_HOST "dht11-rtc.firebaseio.com"
#define FIREBASE_AUTH "e0nYDwD2bqnGhUKJQX0EhZ2V6F7mpXy5K9lypioA"
                        

//#define WIFI_SSID "FLIA.WEITZEL"
//#define WIFI_PASSWORD "20203030"
#define WIFI_SSID "AP1-ALUMNOS"
#define WIFI_PASSWORD "medrano665"

//Creamos nuestro objeto rtc
RTC_DS3231 rtc;

//Crearemos un vector para los dias de la semana
//[7 elementos->7 dias] [8 elementos->8 letras]
String diaSem [7] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};

//Variables tiempo
int sg = 19;
int minu = 26;
int hs = 23;
int fecha = 8;
int mes = 8;
int an = 2019; //"año", problema con utf-08(lectura de "ñ")
String dia = " ";

int tiempo;

void setup() {

  Serial.begin(115200);
  //Declaramos la salida del led
  pinMode(D4, OUTPUT);

  //////////////////////////CONEXION WIFI///////////////////////////

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    //delay(500);
    digitalWrite(D4, HIGH);
    delay(300);
    digitalWrite(D4, LOW);
  }
  Serial.println();
  Serial.print("Connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  ///////////////MODULO RTC///////////////////

  //Pasamos los pines del rtc
  Wire.begin(D1, D2); //SCL Y SDA
  Serial.begin(9600);//Vemos la hora en Moni Serial

  //Inicializamos nuestro rtc
  if (rtc.begin()) {
    //Si inicializa entonces ajustamos y grabamos  los horarios iniciales
    rtc.adjust(DateTime(an, mes, fecha, hs, minu, sg));
  } else {
    Serial.print("//////////////Error al iniciar el modulo RTC!!////////////////");
  }

}


void loop() {
  //Lectura de hora
  DateTime lectura = rtc.now(); //Nos devuelve año, mes,hora,etc

  //Reescribimos en nuestras variables las lecturas en tiempo real
  an = lectura.year();
  mes = lectura.month();
  fecha = lectura.day();
  hs = lectura.hour();
  minu = lectura.minute();
  sg = lectura.second();
  dia = diaSem[lectura.dayOfTheWeek()]; //Al devolvernos un entero lo convertimos a String
  //dia = lectura.dayOfTheWeek();

  tiempo=an,mes,fecha;

  
  Firebase.setInt("Tiempo:",tiempo);
  Firebase.pushInt("Tiempo",tiempo);
  /*Firebase.pushInt("AÑO:", an); //Firebase.pushString(" /");
  Firebase.pushInt("MES:", mes); //Firebase.pushString(" /");
  Firebase.pushInt("FECHA:", fecha); //Firebase.pushString(" /");
  Firebase.pushString("DIA:", dia); //Firebase.pushString(" /");
  Firebase.pushInt("HORAS:", hs); //Firebase.pushString(" /");
  Firebase.pushInt("MINUTOS:", minu); //Firebase.pushString(" /");
  Firebase.pushInt("SEGUNDOS:", sg); //Firebase.pushString(" /");
  Firebase.pushString("----------------------------------------------------");*/
  digitalWrite(D4, HIGH);
  delay(300);
  digitalWrite(D4, LOW);
  delay(2000);


}
