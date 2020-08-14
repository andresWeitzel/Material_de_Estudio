////////COMUNICACION POR SERIAL MEDIANTE MODULO RTCDS3231////////
////////proyecto sensado temperatura en labo/////////
//////////////////////////////////////////////////////////////////


//Librerias del modulo DHT11
#include <SimpleDHT.h>

//Librerias del modulo RTC
#include <Wire.h>//Comunicacion I2C
#include "RTClib.h"//Libreria

//Declaramos el modulo DHT11
int pinDHT11 = D3;
SimpleDHT11 dht11(pinDHT11);

//Declaramos el led
int ledGreen = D4;
int ledRed = D5; //(Emergencia)


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

void setup() {
  //Pasamos los pines del rtc
  Wire.begin(D1, D2); //SCL Y SDA
  Serial.begin(9600);//Vemos la hora en Moni Serial

  //Declaramos la salida del led
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);



  //Inicializamos nuestro rtc
  if (rtc.begin()) {
    //Si inicializa entonces ajustamos y grabamos  los horarios iniciales
    rtc.adjust(DateTime(an, mes, fecha, hs, minu, sg));
  } else {
    Serial.print("//////////////Error al iniciar el modulo RTC!!////////////////");
  }

}

void loop() {

  //Declaracion y Lectura del DHT11
  byte t = 0;
  byte h = 0;
  dht11.read(pinDHT11, &t, &h, NULL);

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
  //Para visualizar en nuestro Serial
  Serial.print(an); Serial.print("/"); //Colocado de esta forma para eficiencia de visualizacion
  Serial.print(mes); Serial.print("/");
  Serial.print(fecha); Serial.print(" (");
  Serial.print(dia); Serial.print(") ");
  Serial.print(hs); Serial.print(":");
  Serial.print(minu); Serial.print(":");
  Serial.print(sg); Serial.print(" ");
  Serial.print("Temperatura: ");
  Serial.print((float)t);
  Serial.println("°C");
  if (t != 0) {
    digitalWrite(ledGreen, HIGH);
    delay(300);
    digitalWrite(ledGreen, LOW);
    if (t >= 26 ) {
      digitalWrite(ledRed, HIGH);
      delay(300);
      digitalWrite(ledRed, LOW);
      delay(300);
      digitalWrite(ledRed, HIGH);
      delay(300);
      digitalWrite(ledRed, LOW);
    }
  }

  Serial.println("-------------------------------------------------------");

  delay(3000);


}
