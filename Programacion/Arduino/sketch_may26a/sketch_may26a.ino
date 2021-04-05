

//------------------------------------
//Funcion principal
//------------------------------------
void setup() // Se ejecuta cada vez que el Arduino se inicia
{
Serial.begin(9600); //Inicia comunicación serial
pinMode(13,OUTPUT); //Configurar el pin 13 como una salida
}
//------------------------------------
//Funcion ciclicla
//------------------------------------
void loop() // Esta funcion se mantiene ejecutando
{ // cuando este energizado el Arduino
//Guardar en una variable el valor de la lectura análoga
int valor = analogRead(A0);
Serial.println(valor); //Imprime el valor por la consola
//Si el valor es mayor o igual a 500
if (valor >= 500)
{
digitalWrite(13,HIGH); //Enciende el LED en el pin 13
}
//Si el valor es menor a 500
else
{
digitalWrite(13,LOW); //Apaga el LED en el pin 13
}
delay(100); //Retardo de 100ms para ver los datos de la consola
}
//Fin programa
