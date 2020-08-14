
#include "arduino.h"

void initPorts(void);
void initTimer2(void);
bool captureData(char carRec);
void parseMsg(void);

//Salidas
#define OP00 2
#define OP01 3
#define OP02 4
#define AZUL 5
//#define AD0  A0

//Pulsadores
#define P1 6    //pulsador up
#define P2 7    //pulsador down

#define TIME_STATUS_LED 100
