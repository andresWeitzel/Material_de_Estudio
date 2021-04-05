//--------------------------------------------------
//Declara puertos de entradas y salidas y variables
//--------------------------------------------------
int brillo = 0; //Variable de brillo inicia en 0
int variacion = 5; //Variable de incremento configurada de 5 en 5
int led = 9; //Pin donde se encuentra el LED, salida
//------------------------------------
//Funcion principal
//------------------------------------
void setup () // Se ejecuta cada vez que el Arduino se inicia
{
pinMode(led, OUTPUT); //Configurar el LED como una salida
}
//------------------------------------
//Funcion ciclicla
//------------------------------------
void loop () // Esta funcion se mantiene ejecutando
{ // cuando este energizado el Arduino
// Escritura analoga (PWM) en el LED escribo el valor de brillo
analogWrite(led, brillo);
// Incremento la variable brillo de 5 en 5
brillo = brillo + variacion;
// Nota: PWM ----> 0 - 255
// Si el brillo es 0 o 255
if (brillo == 0 || brillo == 255)
variacion = -variacion; //La variación se vuelve negativa
delay (30); //Tiempo de incremento en el brillo
}
//Fin
