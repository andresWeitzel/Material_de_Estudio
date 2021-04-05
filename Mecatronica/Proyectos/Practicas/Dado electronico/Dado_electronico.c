#include "C:\Users\Hernan\Desktop\Dado electronico\Dado_electronico.h"
#include <STDLIB.H>
int vector[10]={0b01111110,0b00010010,0b10111100,0b10110110,0b11010010,0b11100110,0b11101110,0b00110010,0b11111110,0b11110010};
int j=0;

void main()
{  set_tris_a(0b00000);
   set_tris_b(0b00000001);
   
   srand(10);
      
   while(true)
   {    
      j=rand();
      output_b(vector[j]);
      delay_ms(1000);
   }
}
