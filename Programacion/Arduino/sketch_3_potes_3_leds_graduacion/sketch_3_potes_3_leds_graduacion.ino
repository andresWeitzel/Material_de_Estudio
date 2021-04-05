int led=7;
int pote=0;
int led1=6;
int pote1=1;
int led2=5;
int pote2=2;



void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(pote,INPUT);
  pinMode(pote1,INPUT);
  pinMode(pote2,INPUT);
  
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:

int val=analogRead(pote);
  int val1=analogRead(pote1);
  int val2=analogRead(pote2);
val=map(val,0,1023,255,0);
  val1=map(val1,0,1023,0,255);
  val2=map(val2,0,1023,0,255);
  analogWrite(7,val);
  analogWrite(6,val1);
  analogWrite(5,val2);
  


}
