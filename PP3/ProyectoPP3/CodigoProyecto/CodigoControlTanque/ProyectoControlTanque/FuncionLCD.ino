//Funcion valores LCD

void outputLcd(){
   //**TANQUE DE AGUA**
   
  //--Imprimimos  las lecturas del sensor dht11
  lcd.setCursor(0, 0);//Primera fila
  lcd.print("-TANQUE DE AGUA-");
  lcd.setCursor(0, 1);//segunda fila
  lcd.print("V");lcd.print(volumen);lcd.print("L"); 
  lcd.setCursor(7, 1);
  lcd.print("T");lcd.print(temp);lcd.print((char)223);//Lo ultimo es para grados centigrados
  lcd.setCursor(12,1);
  lcd.print("H");lcd.print(hum);lcd.print("%");
  delay(1000);//Sensado cada 1 segundo
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
