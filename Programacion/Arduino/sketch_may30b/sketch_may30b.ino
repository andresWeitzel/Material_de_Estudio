const int led1 = 10;
const int led2 = 11;
const int led3 = 5;
const int led4 = 3;
const int pote= 0;
int  x1, x2;

long val = 0;
// -----------------------------------------------------------------------------
void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin (9600);
  
}
// -----------------------------------------------------------------------------
void loop()
{
  val=analogRead(pote);
  x1=map(val, 0 , 1023, 0, 255);
  x2=map(val, 0, 1023, 255, 0);

  if (val >500 && val <600)
  {
    analogWrite(led1, 0);
    analogWrite(led2, 0);
    analogWrite(led3, 0);
    analogWrite(led4, 0);
 }  

  if (val >0 && val<499);
  {
    analogWrite(led1, x1);
    analogWrite(led2, x1);
    analogWrite(led3, 0);
    analogWrite(led4, 0);
  }

    
//  else 
  {
    analogWrite(led1, x1);
    analogWrite(led2, x1);
    analogWrite(led3, x2);
    analogWrite(led4, x2);

  }
  Serial.println(val);
}

