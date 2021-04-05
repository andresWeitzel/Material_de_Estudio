#include <NewPing.h>

     #define TRIGGER_PIN 12 // Arduino pin tied to trigger pin on the ultrasonic sensor.    
     #define ECHO_PIN 11    // Arduino pin tied to echo pin on the ultrasonic sensor.
     #define MAX_DISTANCE 200 
     
     NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance
 
     void setup() 
        {
           Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
        }
 
     void loop()
       {
           delay(50); 
           unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS)
           Serial.print("Ping: ");
           Serial.print(uS / US_ROUNDTRIP_CM); 
           Serial.println("cm");
       }
