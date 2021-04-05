#include <16F84A.h>

#FUSES NOWDT                 	//No Watch Dog Timer
#FUSES XT                    	//Crystal osc <= 4mhz
#FUSES NOPUT                 	//No Power Up Timer
#FUSES NOPROTECT             	//Code not protected from reading

#use delay(clock=4000000)
#use rs232(baud=9600,parity=N,xmit=PIN_A3,rcv=PIN_A2,bits=8)

