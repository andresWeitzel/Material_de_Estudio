#include "D:\Mis Cosas\Mis documentos\MECATRONICA\Proyectos\Impresora con Sensor\Software\boton pulsado le.h"


void main()
{   set_tris_a(0b00000);
    set_tris_b(0b00000001);
    
    while(1)
    {
    
    output_a(0b10001);
    delay_ms(1000);
    output_a(0b00000);
    delay_ms(0b1000);
    
   
    
    }
    
    
    
    
    
}


