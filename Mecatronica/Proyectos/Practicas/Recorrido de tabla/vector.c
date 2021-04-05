#include "C:\Users\Hernan\Desktop\prueba 5\vector.h"


int medina[10] = {0b00010010,0b10111100,0b10110110,0b11010010,0b11100110,0b11101110,0b00110010,0b11111110,0b11110110,0b01111110};
int j=0;

void main()
{
   set_tris_a(0b00000);
   set_tris_b(0b00000000);
   
   while(1)
   {
      j=0;
      while(j<10)
      {
         output_b(medina[j]);
         delay_ms(1000);
         j=j+2;
      }
   }
}
