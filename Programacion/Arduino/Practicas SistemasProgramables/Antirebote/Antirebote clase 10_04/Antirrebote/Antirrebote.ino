

#define ROJO 2
#define VERDE 4
#define AZUL 5
#define P1 6


#define TIEMPO1 250
#define ANTIRREBOTE 500

void initPorts(void);
void initTimer2(void);
void antirrebote(void);

int contMseg1=0;
bool ledTestigo=0;
bool ledTestStatus=0;

bool latch=0;
bool inpToTest=0; 
int timeOut=0;

void setup() 
{
    initPorts();
    initTimer2();
}

void loop() 
{

  if(ledTestigo)
  {
    ledTestigo=0;
    ledTestStatus=!ledTestStatus;
    digitalWrite(AZUL,ledTestStatus);
  }

  if(inpToTest)
  {
    digitalWrite(VERDE,HIGH);
  }
  else
  {
    digitalWrite(VERDE,LOW);
  }
  
  
}

void antirrebote(void)
{
  bool inputReal;
  inputReal=digitalRead(P1);
  
  if(inputReal!=latch)
  {
    latch=inputReal;
    timeOut=ANTIRREBOTE;
  }
  else
  {
    if(timeOut>0)
    {
      timeOut--;
    }
    else
    {
      inpToTest=latch;
    }
  }
}



//*********************************************************
//Vector interrupcion Timer2. Interrumpe c/1ms
//********************************************************
ISR(TIMER2_OVF_vect)
{
    TCNT2=5;
    contMseg1++;
    antirrebote();
    if(contMseg1==TIEMPO1) 
    {
      ledTestigo=1;
      contMseg1=0;
    }
}


void initPorts(void)
{
    pinMode(ROJO,OUTPUT);
    pinMode(VERDE,OUTPUT);
    pinMode(AZUL,OUTPUT);
    pinMode(P1,INPUT);
}


//*******************************************************
//Configura Timer2
//Interrup c/1ms
//******************************************************
void initTimer2(void)
{
   SREG = 0b01111111;       //Desabilitar interrupciones
   TIMSK2 = 0b00000001;     //Habilita la interrupcion por desbordamiento
   TCCR2B = 0b00000011;     //Configura preescala para que FT2 sea de 250KHz
   SREG = 0b10000000;       //Habilitar interrupciones //Desabilitar interrupciones
   TCNT2=5;                 //255-5 =250 (el valor que queremos)
}  
