#include <FS.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "FLIA.WEITZEL";
const char* password = "20203030";
ESP8266WebServer server(80);
void setup() {
   Serial.begin(250000);
   WiFi.mode(WIFI_STA);
   WiFi.begin(ssid,password);
   // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(WiFi.localIP());

server.begin();
server.on("/", fileindex);
server.on("/index.html", fileindex);
server.on("/bootstrap.min.css", bootstrap);
server.on("bootstrap.min.css", bootstrap);
server.on("/popper.min.js", popper);
server.on("/bootstrap.min.js", bootstrapmin);
server.on("bootstrap.min.js", bootstrapmin);


//NEW
SPIFFS.begin();


}

void loop() {
server.handleClient();


// Página WEB. ///////////////////////////////

<body>
<div class="jumbotron jumbotron-fluid">;
<div class="container">;
<h1 class="display-4">Tech Tutorials X</h1>
<p class="lead">Testing Bootstrap.</p>
 
</div>
</div>
</body>
<body>
<div class="jumbotron jumbotron-fluid">
<div class="container">
<h1 class="display-4">Tech Tutorials X</h1>
<p class="lead">Testing Bootstrap.</p>
 
</div>
</div>
</body>



}

void fileindex()
{
  File file = SPIFFS.open("/index.html.gz", "r");
  size_t sent = server.streamFile(file, "text/html");
}
void bootstrap()
{
  File file = SPIFFS.open("/bootstrap.min.css.gz", "r");
  size_t sent = server.streamFile(file, "text/css");
}
void popper()
{
  File file = SPIFFS.open("/popper.min.js.gz", "r");
  size_t sent = server.streamFile(file, "application/javascript");
}
void bootstrapmin()
{
  File file = SPIFFS.open("/bootstrap.min.js.gz", "r");
  size_t sent = server.streamFile(file, "application/javascript");
}
