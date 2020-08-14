#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <SimpleDHT.h>


// Set these to run example.
#define FIREBASE_HOST "sensadoconesp8266.firebaseio.com"

#define FIREBASE_AUTH "ks4xxX4UDDW7s89MHVBHjTVIu7fg7PqxMgYbadW3"


//#define WIFI_SSID "AndroidAP"
//#define WIFI_PASSWORD "kkmt3952"

//#define WIFI_SSID "JS"
//#define WIFI_PASSWORD "rt@rt r t"

//#define WIFI_SSID "FLIA.WEITZEL"
//#define WIFI_PASSWORD "20203030"

#define WIFI_SSID "AP1-ALUMNOS"
#define WIFI_PASSWORD "medrano665"

int pinDHT11 = 5;
SimpleDHT11 dht11(pinDHT11);


void setup() {
  Serial.begin(115200);

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
}

//int n = 0;

void loop() {
  
  byte t = 0;
  byte h = 0;  
  dht11.read(pinDHT11, &t, &h, NULL);

  Serial.print("Temperatura: ");
  Serial.print((float)t);
  Serial.println("°C");  
  
  
  
  
  if (t != 0){
  // set value
  Firebase.setFloat("Temperatura", (float)t);
  Firebase.pushInt("Temp", (float)t);
  delay(2000);
  
  }
  
   
  
  
  
}
