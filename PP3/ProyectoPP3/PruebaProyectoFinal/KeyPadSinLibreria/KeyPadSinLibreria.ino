const unsigned long period = 50;
unsigned long prevMillis = 0;
 
byte iRow = 0, iCol = 0;
const byte countRows = 4;
const byte countColumns = 4;
 
const byte rowsPins[countRows] = {22,23,24,25};
const byte columnsPins[countColumns] = {26,27,28,29};
 
char keys[countRows][countColumns] = {
  { '1','2','3', 'A' },
  { '4','5','6', 'B' },
  { '7','8','9', 'C' },
  { '#','0','*', 'D' }
};
 
// Leer el estado del teclado
bool readKeypad()
{
  bool rst = false;
 
  // Barrido de columnas
  for (byte c = 0; c < countColumns; c++)
  {
    // Poner columna a LOW
    pinMode(columnsPins[c],OUTPUT);
    digitalWrite(columnsPins[c], LOW);
    
    // Barrer todas las filas comprobando pulsaciones
    for (byte r = 0; r < countRows; r++)
    {
      if (digitalRead(columnsPins[r]) == LOW)   
      {
        // Pulsacion detectada, guardar fila y columna
        iRow = r;
        iCol = c;
        rst = true; 
      }
    }
    // Devolver la columna a alta impedancia
    digitalWrite(columnsPins[c], HIGH);
    pinMode(columnsPins[c], INPUT);
  }
  return rst;
}
 
// Inicializacion
void setup()
{
  Serial.begin(9600);
 
  // Columnas en alta impedancia
  for (byte c = 0; c < countColumns; c++)
  {
    pinMode(columnsPins[c], INPUT);
    digitalWrite(columnsPins[c], HIGH);
  }
 
  // Filas en pullup
  for (byte r = 0; r < countRows; r++)
  {
    pinMode(rowsPins[r], INPUT_PULLUP);
  }
}
 
void loop()
{
  if (millis() - prevMillis > period)   // Espera no bloqueante
  {
    prevMillis = millis();
    if (readKeypad())   // Detección de tecla pulsada
    {
      Serial.println(keys[iRow][iCol]);   // Mostrar tecla
    }
  }
}  
