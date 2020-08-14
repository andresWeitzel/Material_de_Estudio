
//BLINK1

#define ROJO 2
#define VERDE 4
#define AMARILLO 3
#define AZUL 5
#define P1 6
#define P2 7
#define TOSC 200
#define TOSC2 400

void initTimer2(void);

int cont=0;
int cont2=0;
int estadop1=0;
bool estado=0;
bool estado2=0;
bool flag=0;
bool flag2=0;
bool flag3=0;
void setup() 
{
  pinMode(ROJO,OUTPUT);
  pinMode(VERDE,OUTPUT);
  pinMode(AMARILLO,OUTPUT);
  pinMode(AZUL,OUTPUT);
  pinMode(P1,INPUT);
  pinMode(P2,INPUT);
  initTimer2();
}

void loop() 
{
  //animacion led testigo
  if(flag)
  {
    flag=0;
    estado=!estado;
    digitalWrite(AZUL,estado);
  }

   if(flag2)
  {
    flag2=0;
    estado2=!estado2;
    digitalWrite(VERDE,estado2);
  }
  
   
  if(digitalRead(P1)==1&&flag3==0)
  {
    flag3=1;
    estadop1=!estadop1;
    digitalWrite(AMARILLO,estadop1);
  }
  if(digitalRead(P1)==0&&flag3==1){
    flag3=0;
  }
  /*else
  {
    digitalWrite(AMARILLO,0);
  }
   */
    if(digitalRead(P2)==HIGH)
  {
    digitalWrite(ROJO,1);
  }
  else
  {
    digitalWrite(ROJO,0);
  }
}


//*********************************************************
//Vector interrupcion Timer2
//********************************************************
ISR(TIMER2_OVF_vect)
{
  TCNT2=5;
  cont++;
  cont2++;
  if(cont==TOSC) 
  {
    cont=0;
    flag=1;
  }
   if(cont2==TOSC2) 
  {
    cont2=0;
    flag2=1;
  }

}

//*******************************************************
//Configura Timer2
//******************************************************
void initTimer2(void)
{
   SREG = 0b01111111;       //Desabilitar interrupciones
   TIMSK2 = 0b00000001;     //Habilita la interrupcion por desbordamiento
   TCCR2B = 0b00000011;     //Configura preescala para que FT2 sea de 250KHz
   SREG = 0b10000000;       //Habilitar interrupciones //Desabilitar interrupciones
   TCNT2=5;                 //255-5 =250 (el valor que queremos)
}  
