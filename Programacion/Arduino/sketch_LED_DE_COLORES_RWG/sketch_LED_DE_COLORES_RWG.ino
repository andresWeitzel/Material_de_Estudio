int ledRojo=9;
int ledVerde=10;
int ledAzul=11;


void setup() {
  // put your setup code here, to run once:
pinMode(ledRojo,OUTPUT);
pinMode(ledVerde,OUTPUT);
pinMode(ledAzul,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
color(255,0,0); //rojo
delay(1000);

color(0,255,0);  //verde
delay(1000);

color(0,0,255);  //azul
delay(1000);

color(255,255,255);  //blanco
delay(1000);

color(255,0,255); //magenta
delay(1000);

color(255,128,0); //naranja 
delay(1000);


}

//fucion color 

void color(int rojo,int verde,int azul) {

  //escritura del color rojo
  analogWrite(ledRojo,255-rojo);
  //escritura color verde 
  analogWrite(ledVerde,255-verde);
  //escritura color azul
  analogWrite(ledAzul,255-azul);
}

