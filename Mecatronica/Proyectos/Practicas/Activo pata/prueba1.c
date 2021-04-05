//Activa una pata del micro durante 2 segundo y la mantiene inactiva por otros 2 segundos
//Repite c{iclicamente

#include "prueba1.h"

void main()
{
  set_tris_a(0b00000);               //aviso que vamos a usar todos los puertos como salida
  set_tris_b(0b00000000);
   
   
   while(1)
   {
      output_a(0b00100);      //Prende A2
      delay_ms(2000);
      output_a(0b00000);      //Apaga A2
      delay_ms(2000);
   }
   
}
   
   
 
  
  
