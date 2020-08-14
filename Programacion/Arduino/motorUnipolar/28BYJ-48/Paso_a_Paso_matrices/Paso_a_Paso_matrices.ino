int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;

//Demora entre pasos,no debe ser menor a 10 ms
int demora = 20;

//Matriz paso completo simple
int paso[4][4] {
  {1, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 1},

};
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

    for (int i = 0; i < 4; i++) {//Recorre la matriz de unha fila por vez
      digitalWrite(IN1, paso[i][0]);//i=0->Queremos obtener el valor de la fila 0 y la columna cero(resultado:HIGH EN ESA POSICION por la matriz-->1 0 0 0--> IN1)
      digitalWrite(IN2, paso[i][1]);//Posicion de fila 0(porque i=0) y posicion de columna 1-->1 0 0 0(resultado:LOW IN2)
      digitalWrite(IN3, paso[i][2]);//LOW
      digitalWrite(IN4, paso[i][3]);//LOW
      delay(demora);//Luego de acá la i=1-->fila posicion 1-->0 1 0 0-->IN1=LOW IN2=HIG....ETC

    }
  }
  //Desenergizamos las bobinas
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(5000);
}
