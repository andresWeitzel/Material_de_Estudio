/*PROYECTO SISTEMA DE CONTROL DE TANQUE*/

//--Librerias Lcd--
#include<Wire.h> 
#include <LiquidCrystal_I2C.h>

//--Libreria DHT11--
 #include <DHT.h>

//--Objeto Lcd--
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Inicia el LCD en la dirección 0x27, con 16 caracteres y 2 líneas

//--Objeto dht11--
DHT dht(A3,DHT11);//Indicamos entrada y nombre del objeto

//--Variables dht11-
int temp;
int hum;



void setup()
{
  dht.begin();//Iniciamos dht11
  
  lcd.begin();//Iniciamos el Lcd   
  lcd.backlight();//Prendemos luz de fondo                
  
}

void loop()
{
  //--Leemos la temperatura y humedad del dht11--
  temp=dht.readTemperature();
  hum=dht.readHumidity();

  //--Imprimimos la salida al Lcd con las lecturas del sensor dht11
  lcd.setCursor(0, 0);//Primera fila
  lcd.print("Temperatura:");lcd.print(temp);lcd.print((char)223);//Lo ultimo es para grados centigrados
  lcd.setCursor(0, 1);//segunda fila
  lcd.print("Humedad:");lcd.print(hum);lcd.print("%");
  //delay(2000);
  //lcd.clear();

}
