#include "C:\Users\Hernan\Desktop\Proyecto 7\7 segmentos con boton e impares.h"

int vector[10]={0b01111110,0b00010010,0b10111100,0b10110110,0b11010010,0b11100110,0b11101110,0b00110010,0b11111110,0b11110010};
int j=1;
void main()
{
   set_tris_a(0b00000);
   set_tris_b(0b00000001);
   
   while(true)
   {  
     j = 1;
     while(j<10)
      {
         if(input(pin_b0))    //0b00000001
         {
            j=j+2;
            delay_ms(1000);
         }
      
         else
         {
            output_b(vector[j]);
         }
      }
   }
}
