 #include "D:\Mis Cosas\Mis documentos\MECATRONICA\Proyectos\Impresora con Sensor\Software\impresora_sensor.h"
#define sensor_der pin_b3
#define sensor_izq pin_b4
#define finalcarr_der pin_b5
#define finalcarr_izq pin_b6
#define motor_der pin_b1
#define motor_izq pin_b2

void main ()
{  set_tris_a(0b00000);
   set_tris_b(0b00111100);
   
   
      while(1)
      {
          if(input (finalcarr_izq && !sensor_der))   //pregunto si finalcarr_izq está prendido y sensor_der está apagado
         {      
           output_low(motor_der);                              //Apaga los dos motores
           output_low(motor_izq);
         }
         else if (input(finalcarr_der && !sensor_izq)) 
         {
            output_low(motor_der);
            output_low(motor_izq);
         }
          else if (input (sensor_der && sensor_izq))
          {
            output_low(motor_der);
            output_low(motor_izq);
          }
          else if (input (!sensor_der  && !sensor_izq))
          {  output_low (motor_der);
             output_low (motor_izq);
          }
          else if (input (sensor_der))
          {
            output_low(motor_izq);
            output_high(motor_der);
            delay_ms(300);
            output_low(motor_der);
            
          }
          else if (input (sensor_izq))
          {
            output_low(motor_der);
            output_high(motor_izq);
            delay_ms(300);
            output_low(motor_izq);
          }
         
      
      
      
      
      }
}
