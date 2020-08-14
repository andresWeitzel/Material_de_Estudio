const float c = 261.63; // Do (Octava 0)

  const float d = 293.66; // Re (Octava 0)

  const float e = 329.63; // Mi (Octava 0)

  const float f = 349.23; // Fa (Octava 0)

  const float g = 392.00; // Sol (Octava 0)

  const float gS = 415.30;  // Sol# (Octava 0)

  const float a = 440.00; // La (Octava 0)

  const float b = 466.16; // La# (Octava 0)

  const float cH = 523.25;   // Do (Octava 1)

  const float cSH = 554.37;  // Do# (Octava 1)

  const float dH = 587.33; // Re (Octava 1)

  const float dSH = 622.25; // Re# (Octava 1)

  const float eH = 659.26; // Mi (Octava 1)

  const float fH = 698.46; // Fa (Octava 1)

  const float fSH = 739.99; // Fa# (Octava 1)

  const float gH = 783.99;  // Sol (Octava 1)

  const float gSH = 830.61; // Sol# (Octava 1)

  const float aH = 880.00; // La (Octava 1)

   

  const int zumbador = 8; // Pin digital para el zumbador

  const int LED_1 = 11; // Pin digital para el LED 1

  const int LED_2 = 12; // Pin digital para el LED 2

   

  int contador = 0;

   

  void setup()

  {

    pinMode(zumbador, OUTPUT); // Pin digital 8 como salida

    pinMode(LED_1, OUTPUT); // Pin digital 12 como salida

    pinMode(LED_2, OUTPUT); // Pin digital 13 como salida

  }

   

  void loop()

  { 

    // Suena la primera sección

    primeraSeccion();

   

    // Suena la segunda sección

    segundaSeccion();

   

    // Variante 1

    tono(f, 250);  

    tono(gS, 500);  

    tono(f, 350);  

    tono(a, 125);

    tono(cH, 500);

    tono(a, 375);  

    tono(cH, 125);

    tono(eH, 650);

   

    delay(500);

   

    // Se repite la segunda sección

    segundaSeccion();

   

    // Variante 2

    tono(f, 250);  

    tono(gS, 500);  

    tono(f, 375);  

    tono(cH, 125);

    tono(a, 500);  

    tono(f, 375);  

    tono(cH, 125);

    tono(a, 650);  

   

    delay(650);

  }

  

  // Función que ejecuta cada tono 

  void tono(int frecuencia, int duracion)

  {

    // Suena el tono en el zumbador

    tone(zumbador, frecuencia, duracion);

   

    // Se enciende LED_1 o LED_2 alternamente cada vez que suena un nuevo tono

    if(contador % 2 == 0)

    {

      digitalWrite(LED_1, HIGH);

      delay(duracion);

      digitalWrite(LED_1, LOW);

    }

    else

    {

      digitalWrite(LED_2, HIGH);

      delay(duracion);

      digitalWrite(LED_2, LOW);

    }

   

    // Para de sonar el tono en el zumbador

    noTone(zumbador);

   

    delay(50);

   

    // Se incrementa el contador

    contador++;

  }

  

  // Función de la primera sección 

  void primeraSeccion()

  {

    tono(a, 500);

    tono(a, 500);    

    tono(a, 500);

    tono(f, 350);

    tono(cH, 150);  

    tono(a, 500);

    tono(f, 350);

    tono(cH, 150);

    tono(a, 650);

   

    delay(500);

   

    tono(eH, 500);

    tono(eH, 500);

    tono(eH, 500);  

    tono(fH, 350);

    tono(cH, 150);

    tono(gS, 500);

    tono(f, 350);

    tono(cH, 150);

    tono(a, 650);

   

    delay(500);

  }

  

  // Función de la segunda sección  

  void segundaSeccion()

  {

    tono(aH, 500);

    tono(a, 300);

    tono(a, 150);

    tono(aH, 500);

    tono(gSH, 325);

    tono(gH, 175);

    tono(fSH, 125);

    tono(fH, 125);    

    tono(fSH, 250);

   

    delay(325);

   

    tono(a, 250);

    tono(dSH, 500);

    tono(dH, 325);  

    tono(cSH, 175);  

    tono(cH, 125);  

    tono(b, 125);  

    tono(cH, 250);  

   

    delay(350);

  }
