//Activa sirena, cada vez más rapido

#include "buzzer.h"


void main(void)
{
   int tiempo = 1000;
   
   set_tris_b(0b00000000);
   set_tris_a(0b00000);
   output_b(0x00);

   while(true)
   {
      while(tiempo>0)
      {
         output_a(0b00110);
         delay_ms(tiempo);
         output_a(0b00000);
         delay_ms(tiempo);
         
         tiempo = tiempo - 5;
      }
      tiempo = 1000;
   }
}
