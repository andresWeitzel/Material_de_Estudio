#include <DHT.h>
#include <DHT_U.h>

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid = "SPEEDY-78D56A";
const char* password = "3727571113";

const int led = 5;//D1
int sensor=2;//A0
int temp;

ESP8266WebServer server(80);
DHT dht(sensor,DHT11);



void handleRoot() {
  digitalWrite(led, 1);

  String textoHTML;
  

  textoHTML = " <h1><b>SENSANDO TEMPERATURA(DHT11)</b><br></br></h1>  ";
  textoHTML += " <h2><b>TEMPERATURA</b></h2>";
  textoHTML += temp=dht.readTemperature(sensor);
  //textoHTML += temp;
  textoHTML += " <b>°C</b> ";
   
  server.send(200, "text/html", textoHTML);
  digitalWrite(led, 0);
}
//En caso de no encontrar la pagina
void handleNotFound(){
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}

void setup(void){
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

  server.on("/inline", [](){
    server.send(200, "text/plain", "this works as well");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
}
