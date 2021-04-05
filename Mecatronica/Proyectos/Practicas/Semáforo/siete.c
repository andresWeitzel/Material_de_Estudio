//Semáforo con conteo regresivo y sirena

#include "siete.h"


void main()
{
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   set_tris_a(0b00000);
   set_tris_b(0b00000000);
   
   while(1)
   {
      output_a(0b00100);      //rojo
      output_b(0b11100110);   //5
      delay_ms(1000);
      output_b(0b11010010);   //4
      delay_ms(1000);
      output_b(0b10110110);   //3
      delay_ms(1000);
      output_b(0b10111100);   //2
      delay_ms(1000);
      output_b(0b00010010);   //1
      delay_ms(1000);
      output_b(0b00000000);
      output_a(0b01000);      //Prende Amarillo - Apaga rojo
      delay_ms(2000);
      output_a(0b10011);      //Apaga amarillo - Prende verde-sirena
      output_b(0b11100110);   //5
      delay_ms(1000);
      output_b(0b11010010);   //4
      delay_ms(1000);
      output_b(0b10110110);   //3
      delay_ms(1000);
      output_b(0b10111100);   //2
      delay_ms(1000);
      output_b(0b00010010);   //1
      delay_ms(1000);
      output_b(0b00000000);
      output_a(0b01000);      //apaga verde y sirena - prende amarillo
      delay_ms(2000);
   }
}
