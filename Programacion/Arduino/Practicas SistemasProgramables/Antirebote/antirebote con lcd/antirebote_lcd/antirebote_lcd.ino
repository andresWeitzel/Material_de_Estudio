/*  TITULO: Pulsador antirrebote con contador de pulsaciones.
 
    AUTOR:
   
    MARIANO DEL CAMPO GARCÍA (@2015) --> INGENIERO TÉCNICO INDUSTRIAL ESPECIALIDAD ELECTRÓNICA
    - FACEBOOK: https://www.facebook.com/mariano.delcampogarcia
    - TWITTER: https://twitter.com/MarianoCampoGa
    - CORREO: marianodc83@gmail.com
   
   
    DESCRIPCIÓN DEL PROGRAMA
   
    Con este programa se soluciona el problema de los rebotes del pulsador. Además podremos observar
    a ravés del monitor serie, el número de veces que hemos activado el pulsador.
   
   
    ESQUEMA DE CONEXION
   
                                      +-----+
         +----[PWR]-------------------| USB |--+
         |                            +-----+  |
         |         GND/RST2  [ ][ ]            |
         |       MOSI2/SCK2  [ ][ ]  A5/SCL[ ] |   SCL del módulo I2C
         |          5V/MISO2 [ ][ ]  A4/SDA[ ] |   SDA del módulo I2C
         |                             AREF[ ] |
         |                              GND[ ] |
         | [ ]N/C                    SCK/13[ ] |  
         | [ ]IOREF                 MISO/12[ ] |  
         | [ ]RST                   MOSI/11[ ]~|  
         | [ ]3V3    +---+               10[ ]~|  
         | [ ]5v    -| A |-               9[ ]~|  
         | [ ]GND   -| R |-               8[ ] |  
         | [ ]GND   -| D |-                    |
         | [ ]Vin   -| U |-               7[ ] |  
         |          -| I |-               6[ ]~|  
         | [ ]A0    -| N |-               5[ ]~|  
         | [ ]A1    -| O |-               4[ ] |   PA
         | [ ]A2     +---+           INT1/3[ ]~|    
         | [ ]A3                     INT0/2[ ] |  
         | [ ]A4/SDA  RST SCK MISO     TX>1[ ] |  
         | [ ]A5/SCL  [ ] [ ] [ ]      RX<0[ ] |  
         |            [ ] [ ] [ ]              |
         |  UNO_R3    GND MOSI 5V  ____________/
          \_______________________/
 
  NOTAS:
   
   - Los pulsadores suelen tener dos pines, que vamos a denominar PA y PB (si es de 4 sólo usamos 2 de ellos)
   - Conexión PULL-DOWN del pulsador.
       - PB conectado a VCC.
       - PA conectado a GND a través de una R=10K omhs.
   - La alimentación y la masa del módulo LCM 1602 I2C V1 van directamente conectadas a VCC (+5V) y GND
     respectivamente.        
*/
 
  // Importar librerías
  #include <Wire.h> // Librería comunicación I2C
  #include <LiquidCrystal_I2C.h> // Librería LCD I2C
   
  // Declaración del objeto
  // Poner la dirección del LCD a 0x27 para display 16x2, 20x2 y 20x4
  // Terminales de conexión del LCD
  //                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
  LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
     
  const int pulsador = 4; // Entrada digital para el pulsador
  const int tiempoAntirrebote = 10; // tiempo en ms para evitar el rebote
 
  int cuenta = 0;
  int estadoBoton;
  int estadoBotonAnterior;
 
  // Función que evita el rebote del pulsador
  boolean antirrebote(int pin)
  {
    int contador = 0;
    boolean estado;
    boolean estadoAnterior;
   
    do
    {
      estado = digitalRead(pin);
      if(estado != estadoAnterior)
      {
        contador = 0;
        estadoAnterior = estado;
      }
      else
      {
        contador = contador+ 1;
      }
      delay(1);
    } while(contador < tiempoAntirrebote);
   
    return estado;
  }
   
       
  void setup()
  {
    Serial.begin(9600);  // Configura la velocidad de la comunicación serie
    lcd.begin(16,2);   // Inicializa el LCD para 16x2  
    lcd.backlight(); // LED de fondo encendido (backlight)
 
    pinMode(pulsador, INPUT); // PIN digital del pulsador como entrada
   
    // Presentamos datos por el LCD
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Pulsaciones: ");
  }
 
  void loop()
  {  
    estadoBoton = digitalRead(pulsador);
   
    if(estadoBoton != estadoBotonAnterior)
    {
      if(antirrebote(pulsador))
      {
        cuenta++;
        lcd.setCursor(13,0);
        lcd.print(cuenta);  // Se muestra a través del LCD el nº de veces que presionamos el pulsador
      }
