#include <ESP8266WiFi.h>
const char* ssid = "FLIA.WEITZEL";
const char* password = "20203030";
IPAddress ip(192, 168, 1, 55); // IP estática
IPAddress gateway(192, 168, 1, 1); // Puerta de enlace.
IPAddress subnet(255, 255, 255, 0);// MascaraRed.

WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  // Conecta a la red wifi.
  Serial.println();
  Serial.println();
  Serial.print("Conectando con ");
  Serial.println(ssid);
  
  WiFi.config(ip, gateway, subnet); // Configura IP estática
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Conectado con WiFi.");
 
  // Inicio del Servidor web.
  server.begin();
  Serial.println("Servidor web iniciado.");
 
  // Esta es la IP
  Serial.print("Esta es la IP para conectar: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}
 
void loop() {
  // Consulta si se ha conectado algún cliente.
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Espera hasta que el cliente envíe datos.
  Serial.println("Nuevo cliente.");
  while(!client.available()){
    delay(1);
  }
 
  // Página WEB. ///////////////////////////////
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  Comillas importantes.
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head><meta charset=utf-8></head>");
  client.println("<body><font face='Arial'><center><h1>Servidor web con NodeMCU.</h1>");
  client.println("<h2><font color='#009900'>KIO4.COM - Juan A. Villalpando</font></h2>");
  client.println("<h3>Página web.</h3>");
  client.println("<br><br>");
  client.println("<img src='http://kio4.esy.es/kio42.png'><br>");
  client.println("<button>Juan Antonio </button>");
  client.println("<button>KIO4.COM </button>"); 
  client.println("<button>Buen tiempo. </button>");
  client.println("<a href=\"/mensaje=4\"\"><button>Puerto Real </button></a>"); 
  client.println("</font></center></body></html>");
 
  Serial.println("Cliente desconectado.");
}
