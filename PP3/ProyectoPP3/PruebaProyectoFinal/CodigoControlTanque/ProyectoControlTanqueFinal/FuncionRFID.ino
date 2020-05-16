void accesoRFID(){
/*
  byte ActualUID[4]; //almacenará el código del Tag leído
  byte Usuario1[4]= {0x4D, 0x5C, 0x6A, 0x45} ; //código del usuario 1
  byte Usuario2[4]= {0xC1, 0x2F, 0xD6, 0x0E} ; //código del usuario 2

  // Revisamos si hay nuevas tarjetas  presentes
  if ( mfrc522.PICC_IsNewCardPresent()) 
        {  
      //Seleccionamos una tarjeta
            if ( mfrc522.PICC_ReadCardSerial()) 
            {
                  // Enviamos serialemente su UID
                  Serial.print(F("Card UID:"));
                  for (byte i = 0; i < mfrc522.uid.size; i++) {
                          Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                          Serial.print(mfrc522.uid.uidByte[i], HEX);   
                          ActualUID[i]=mfrc522.uid.uidByte[i];          
                  }
           else{
                  Serial.print("     ");
               }           
          
          //comparamos los UID para determinar si es uno de nuestros usuarios  
          if(compareArray(ActualUID,Usuario1)){
               Serial.println("Acceso concedido...");    
          }else if(compareArray(ActualUID,Usuario2)){
               Serial.println("Acceso concedido...");
          }else{
               Serial.println("Acceso denegado...");
          // Terminamos la lectura de la tarjeta tarjeta  actual
           mfrc522.PICC_HaltA();
             }
    }   
            
    //Función para comparar dos vectores
    boolean compareArray(byte array1[],byte array2[])
    {
      if(array1[0] != array2[0]){return(false);}
      if(array1[1] != array2[1]){return(false);}
      if(array1[2] != array2[2]){return(false);}
      if(array1[3] != array2[3]){return(false);}
      else{return(true);}
    }
*/
}
