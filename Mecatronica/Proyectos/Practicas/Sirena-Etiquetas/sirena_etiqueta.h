#include <16F84A.h>

#FUSES NOWDT                 	//No Watch Dog Timer
#FUSES XT                    	//Crystal osc <= 4mhz
#FUSES PUT                   	//Power Up Timer
#FUSES NOPROTECT             	//Code not protected from reading

#use delay(clock=4000000)

