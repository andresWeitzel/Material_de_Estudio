int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;

int demora = 20; //Demora entre pasos,no debe ser menor a 10 ms

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  //Para que el rotor de una vuelta completa se deben dar 2048 pasos
  //Dividimos por 4 y nos da 512, corresponde a cada cuarto de vuelta POR BOBINA  
  for (int i = 0; i < 512; i++) {

    //PASO 1
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(demora);

    //PASO2
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(demora);

    //PASO3
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(demora);

    //PASO4
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(demora);

    
  }
  //Desenergizamos las bobinas
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(5000);
}
