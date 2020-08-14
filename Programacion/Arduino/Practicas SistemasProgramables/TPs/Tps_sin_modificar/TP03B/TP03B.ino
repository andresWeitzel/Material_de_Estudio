
//BLINK1

#define ROJO 2
#define AMARILLO 3
#define AZUL 5
#define P1 6
#define TOSC 200

void initTimer2(void);

int cont=0;
bool estado=0;
bool flag=0;

void setup() 
{
  pinMode(ROJO,OUTPUT);
  pinMode(AMARILLO,OUTPUT);
  pinMode(AZUL,OUTPUT);
  pinMode(P1,INPUT);
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
  
  if(digitalRead(P1)==HIGH)
  {
    digitalWrite(AMARILLO,1);
  }
  else
  {
    digitalWrite(AMARILLO,0);
  }
}


//*********************************************************
//Vector interrupcion Timer2
//********************************************************
ISR(TIMER2_OVF_vect)
{
  TCNT2=5;
  cont++;
  if(cont==TOSC) 
  {
    cont=0;
    flag=1;
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
