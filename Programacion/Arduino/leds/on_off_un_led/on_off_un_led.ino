#define led1 2
#define led2 3
#define led3 4
#define led4 5
#define s1 6

int s1_lectura;

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(s1,INPUT);

}

void loop() {
  s1_lectura=digitalRead(s1);
  if(s1_lectura==HIGH){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
     digitalWrite(led4,HIGH);
    delay(1000);
    digitalWrite(led4,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
    delay(1000);
  
  }else{
    digitalWrite(led3,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
    delay(1000);
    
  } 
  

}
