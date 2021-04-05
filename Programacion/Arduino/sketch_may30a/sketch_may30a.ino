
int led = 10;
int boton = 2;
int value ;

void setup() 
{
  // aca empieza el codigo 
    Serial.begin(9600);
    pinMode(led, OUTPUT);
    //pinMode(boton, INPUT);

}
void loop() 
{
value=digitalRead(boton);
  if (value == HIGH)
   {
    digitalWrite(led, HIGH);
    Serial.println("On");
   }
  else
  {
    digitalWrite(led, LOW);
    Serial.println("Off");
  }
 }

