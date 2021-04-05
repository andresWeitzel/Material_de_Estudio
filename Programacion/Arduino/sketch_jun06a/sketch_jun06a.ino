int led=9;
int pote=0;



void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(pote,INPUT);
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:

int val=analogRead(pote);
val=map(val,0,1023,255,0);


}
