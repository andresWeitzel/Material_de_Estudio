////////COMUNICACION POR SERIAL MEDIANTE MODULO RTCDS3231////////
////////proyecto sensado temperatura en labo/////////

#include <Wire.h>//Comunicacion I2C
#include "RTClib.h"//Libreria

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
  //Para visualizar en nuestro Serial
  Serial.print(an); Serial.print("/"); //Colocado de esta forma para eficiencia de visualizacion
  Serial.print(mes); Serial.print("/");
  Serial.print(fecha); Serial.print(" (");
  Serial.print(dia); Serial.print(") ");
  Serial.print(hs); Serial.print(":");
  Serial.print(minu); Serial.print(":");
  Serial.print(sg); Serial.println(" ");
  Serial.println("-------------------------------------------------------");
  delay(3000);


}
