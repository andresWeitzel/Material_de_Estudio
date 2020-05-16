//Funcion valores LCD

void outputLcd(){
   //**TANQUE DE AGUA**
   
  //--Imprimimos  las lecturas del sensor dht11
  lcd.clear();
  lcd.setCursor(0, 0);//Primera fila
  lcd.print("-TANQUE DE AGUA-");
  lcd.setCursor(0, 1);//segunda fila
  lcd.print("V");lcd.print(volumen);lcd.print("L"); 
  lcd.setCursor(7, 1);
  lcd.print("T");lcd.print(tempTanque);lcd.print((char)223);//Lo ultimo es para grados centigrados
  lcd.setCursor(12,1);
  lcd.print("H");lcd.print(humTanque);lcd.print("%");
  delay(2000);//Sensado cada x segundos
  
  lcd.clear();
  lcd.setCursor(1, 0);//Primera fila
  lcd.print("SALA DE CONTROL");
  lcd.setCursor(0, 1);//segunda fila
  lcd.print(deteccionHumo);lcd.print("ppm"); 
  lcd.setCursor(7, 1);
  lcd.print("T");lcd.print(tempSalaControl);lcd.print((char)223);//Lo ultimo es para grados centigrados
  lcd.setCursor(12,1);
  lcd.print("H");lcd.print(humSalaControl);lcd.print("%");
  //delay(2000);//Sensado cada x segundos
  
  
}

void outputLcdAdvertenciaLow(){
    lcd.clear();
    lcd.setCursor(0, 0);//Primera fila
    lcd.print("**ADVERTENCIA**");
    lcd.setCursor(1, 1);//segunda fila
    lcd.print("**PREVENTIVA**"); 
    delay(1000);//Para visualizacion de mensaje de advertencia antes del borrado y darle lugar a otro msj
    lcd.clear(); 
    
}

void outputLcdAdvertenciaMedium(){
    lcd.clear();
    lcd.setCursor(0, 0);//Primera fila
    lcd.print("**ADVERTENCIA**");
    lcd.setCursor(3, 1);//segunda fila
    lcd.print("**MEDIA**"); 
     delay(1000);//Para visualizacion de mensaje de advertencia antes del borrado y darle lugar a otro msj
    lcd.clear(); 
    
    
}

void outputLcdAdvertenciaHigh(){ 
    lcd.clear();
    lcd.setCursor(0, 0);//Primera fila
    lcd.print("**ADVERTENCIA**");
    lcd.setCursor(4, 1);//segunda fila
    lcd.print("**ALTA**"); 
     delay(1000);//Para visualizacion de mensaje de advertencia antes del borrado y darle lugar a otro msj
    lcd.clear(); 
    
}



  //delay(2000);//Cada 2 seg se actualizan las mediciones

  /*//--Imprimimos la lectura del sensor de agua--
  lcd.setCursor(0,0);
  lcd.print("CAPACIDAD LIMITE:");
  lcd.setCursor(7,1);//columna 8 fila 1
  lcd.print(limiteAgua);lcd.print("%"); 
  delay(200);
 */

  //**SALA DE CONTROL**
  //PROXIMAMENTE............
  
  



/*
//-----------------Variables-------------------------
//--Calculo de volumen--
float volumenMin=0.00;
float volumenMax=1.50;
float alturaMax=9.80;
float alturaMin=18.79;
float volumen=0.00;
float tiempo,altura;//variables para el HC-SR04 


*/
