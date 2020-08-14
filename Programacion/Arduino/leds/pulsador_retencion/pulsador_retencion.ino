#define led1 2
#define led2 3
#define led3 4
#define s1 5

int s1_lectura=0;
int estado_s1=0;


void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(s1, INPUT);

}

void loop() {
  s1_lectura = digitalRead(s1);

  if (s1_lectura == HIGH)  {
    estado_s1= 1 - estado_s1;
    delay(10);
  }
    


  if(estado_s1==HIGH){  
    
    digitalWrite(led1, HIGH);
    delay(200);
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    delay(200);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(200);
    digitalWrite(led3, LOW);
    delay(700);

  } else {
    digitalWrite(led3, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led1, LOW);
    delay(700);

  }


}
