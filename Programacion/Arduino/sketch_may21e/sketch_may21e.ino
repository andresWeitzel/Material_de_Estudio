//--------------------------------------------------
//Declara puertos de entradas y salidas y variables
//--------------------------------------------------
int pulsador =7; //Declara Pin del pusaldor
int motor=3; //Declara Pin del motor
//------------------------------------
//Funcion principal
//------------------------------------
void setup() // Se ejecuta cada vez que el Arduino se inicia
{
pinMode(pulsador,INPUT); //El pulsador como una entrada
pinMode(motor,OUTPUT); //El motor como una salida
}
//------------------------------------
//Funcion ciclicla
//------------------------------------
void loop() // Esta funcion se mantiene ejecutando
{ // cuando este energizado el Arduino
// Si el pulsador se encuentra oprimido
if(digitalRead(pulsador) == HIGH){
digitalWrite(motor,HIGH); //Enciende el motor
}else{ //si el pulsador no esta oprimido
digitalWrite(motor,LOW); //Apaga el motor
}
}
// Fin programa
