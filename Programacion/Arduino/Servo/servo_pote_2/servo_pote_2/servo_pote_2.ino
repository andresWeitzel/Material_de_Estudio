#include<Servo.h>

Servo Motor1;
int Pin_Motor1 = 2;
//---OJO-- en los siguientes pulsos se ajusto al giro-angulo perfecto del servo.
int Pulso_Min = 1050; //para PWM un pulso de 1 miliseg(1000 microsegundos) equivale a 90°
int Pulso_Max = 1900; //equivale a 180°(1900 equivalente a 2000)

int Valor_Pote;
int Angulo;
int Pote=0;


void setup() {
  Motor1.attach(Pin_Motor1,Pulso_Min,Pulso_Max);//La funcion attach sirve para inicializar al servo
//Los pulsos requieren estar en microsegundos
}

void loop() {

Valor_Pote=analogRead(Pote);
//--Con la funcion map, en este caso,convertimos la señal analogica(0 a 1023) a señal digital de pulsos del motor(1050(0°)a 1900(180°))
Angulo=map(Valor_Pote,0,1023,0,180);//Hace la conversion de un valor a otro proporcional,analogico/digital(1023/1900(180°))
Motor1.write(Angulo);
delay(20);


}
