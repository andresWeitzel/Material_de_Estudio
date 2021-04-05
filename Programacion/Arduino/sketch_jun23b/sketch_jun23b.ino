int LED []= {3,6,9};
int boton=2;

void setup()
          {
       for (int i=0;i<3;i++){
             pinMode( LED[i], OUTPUT) ;
              }
       
             pinMode( boton , INPUT_PULLUP) ;
             
          }


void apagar(){
for (int i=0;i<3;i++){
     digitalWrite(LED[i], LOW) ;
              }

}


void flash(int tiempo){  
    
for (int i=0;i<3;i++){
     digitalWrite(LED[i], HIGH) ;
              }
  delay(tiempo);
   apagar();
  delay(tiempo);
    
  }
  






     void loop()
          { 
                             //leemos el botón: false  =  LOW
              if ( digitalRead(boton) == LOW )                               // esto es que han pulsado el botón
                   {
                     flash(100);   
              }else{
              
                if (analogRead(A3)>950){
                  analogWrite (LED[0],analogRead(A0)/4);
                  analogWrite (LED[1],analogRead(A1)/4);
                  analogWrite (LED[2],analogRead(A2)/4);               
                
                }              
                
                else{
                  analogWrite (LED[0],analogRead(A0)/4);
                  analogWrite (LED[1],analogRead(A1)/4);
                  analogWrite (LED[2],analogRead(A2)/4);
                  delay(analogRead(A3));
                  apagar();
                  delay(analogRead(A3));
                
                
                }
                    
                
                
                
                
                                
              
              }
          }
