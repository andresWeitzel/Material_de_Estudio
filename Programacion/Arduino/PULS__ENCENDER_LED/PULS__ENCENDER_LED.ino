int pulsador=2;
int led=13;

void setup() {
  // put your setup code here, to run once:
pinMode(pulsador,INPUT);
pinMode(led,OUTPUT);




}

void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead(pulsador)==HIGH)
{
  digitalWrite(led,HIGH);
}
else
{
  digitalWrite(led,LOW);
}
}

