#include <ESP8266WiFi.h>
#include <WiFiClient.h>

 #define LED1 5

const char* ssid = "JackScript";
const char* password = "lw kp as 6841";

WiFiServer servidorTCP(80);
WiFiClient clienteTCP;



void setup() {

  pinMode(LED1, OUTPUT);
  
  Serial.begin(115200);
  delay(100);
  
  Serial.print("Conectandose a: ");
  Serial.println(ssid);


  WiFi.begin(ssid, password);  //Intentamos conectarnos a la red Wifi
  
  while (WiFi.status() != WL_CONNECTED) {  //Esperamos hasta que se conecte.
    Serial.print ("........ ");
    delay(200);
  }

  Serial.print ("Conectado, IP: ");
  Serial.println (WiFi.localIP());

  servidorTCP.begin();

}

void loop() {

  if (!clienteTCP.connected()) {
        // try to connect to a new client
        clienteTCP = servidorTCP.available();
    } else {
        // read data from the connected client
        if (clienteTCP.available() > 0) {
            char dato = clienteTCP.read();
            

            if (dato == '1'){
              digitalWrite(LED1, HIGH);
              Serial.write(dato);
            }
            else if (dato == '0'){

              digitalWrite(LED1, LOW);
              Serial.write(dato);
              
            }
              

           
              
        }
    }
     
     
     
      

}
