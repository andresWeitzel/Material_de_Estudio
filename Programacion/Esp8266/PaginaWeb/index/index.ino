//Pagina web

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid="FLIA.WEITZEL";
const char* password="20203030";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);

  //Busqueda de red
  WiFi.begin(ssid, password);

  //Inicio del Servidor
  server.begin();

  //SERVER
  Serial.print("IP:");Serial.println(WiFi.localIP());
}

void loop() {
  
  //Inicio del client
  WiFiClient client=server.available();
  
  /*if (!client) {
    return;
  }

  
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();


  //Pagina HTML
  client.println(
    "<!DOCTYPE HTML>"
    "<html>"
    "<head>meta charset=utf-8</head>"
    "<body><h1>Hello World!!</h1></body>"
    "</html>"   
    
    );*/
}
