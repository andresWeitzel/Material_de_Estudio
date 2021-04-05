//Cuando aprieto el boton, se prende la luz verde; cuando lo suelto, luz roja y Sirena

#include "condicion.h"


void main()
{
   set_tris_a(0b00000);
   set_tris_b(0b00000001);
   
   while(1)
   {
      if( input(pin_b0))  //cuando pulse el boton
      {
         output_a(0b10001);   //prendo led verde
         delay_ms(3000);
      }
      
      else
      {
         output_a(0b00110);  //prendo luz roja y sirena
         output_a(0b00000);  //se apaga todo
      }
   }

}
