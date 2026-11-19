#ifndef _GPIOo_H_
#define _GPIOo_H_
#include "Arduino.h"

#define PINMODE_OUTPUT 1
#define PINMODE_INPUT 0

void setPinPORTD(uint16_t pinNum,int pinMode);
void togglePinPORTD(uint16_t pinNum);
int readPinPORTD(uint16_t pinNum);

void setPinPORTB(uint16_t pinNum,int pinMode);
void togglePinPORTB(uint16_t pinNum);
int readPinPORTB(uint16_t pinNum);

void setPinPORTC(uint16_t pinNum,int pinMode);
void togglePinPORTC(uint16_t pinNum);


#endif