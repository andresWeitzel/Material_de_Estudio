int boton=2;
void setup() {
  // put your setup code here, to run once:
pinMode(boton,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int estado = digitalRead(boton);
if(estado==1)
{
  Serial.println("pulsador");
}
else
{
    Serial.println("no pulsado");
}
delay (100);

}
