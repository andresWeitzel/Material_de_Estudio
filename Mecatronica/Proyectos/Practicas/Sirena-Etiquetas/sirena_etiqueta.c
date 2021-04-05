#include "D:\Mis Cosas\Mis documentos\MECATRONICA\PICS\PRUEBAS - CCS\Pruebas - Liceo\Sirena-Etiquetas\sirena_etiqueta.h"

#define sirena PIN_A1


void main()
{  
   set_tris_a(0b00000);
   set_tris_b(0b00000000);
   
   while(true)
   {
      output_high(sirena);
      delay_ms(1000);
      output_low(sirena);
      delay_ms(1000);
   }
}
