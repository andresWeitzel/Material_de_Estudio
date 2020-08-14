#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#include <DHT.h>
#include <DHT_U.h>

#define FIREBASE_HOST "sensadoconesp8266.firebaseio.com"

#define FIREBASE_AUTH "ks4xxX4UDDW7s89MHVBHjTVIu7fg7PqxMgYbadW3"


#define WIFI_SSID "FLIA.WEITZEL"
#define WIFI_PASSWORD "20203030"

//#define WIFI_SSID "JS"
//#define WIFI_PASSWORD "rt@rt r t"

//#define WIFI_SSID "AndroidAP"
//#define WIFI_PASSWORD "kkmt3952"

int sensor = 5;
//int temp;
int temp;
//int hum;

DHT dht(sensor, DHT11); //llamaremos al objeto : dht indicaremos el pin conectado(2) y el modelo(dht11);


void setup() {

  Serial.begin(115200);
  //Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  dht.begin();//indicamos al objeto dht la relacion con el monitor serial
}

void loop() {
  temp = dht.readTemperature();
  //hum = dht.readHumidity();

  Serial.print("Temperatura:");
  Serial.print(temp);
  Serial.print("°C ");
  Serial.println();
  delay(3000);

  /*Serial.print("Humedad:");
  Serial.print(hum);
  Serial.print("% ");
  Serial.println();
  delay(500);
*/
  if (temp != 0){
  // set value
  Firebase.setFloat("Temperatura", temp);
  Firebase.pushInt("Temp", temp);
 // Firebase("Temperatura", temp);
  //Firebase("Temp", temp);
}
}
