#include "task3.hpp"
#include "gpio.hpp"
#define LED 3
#define BUTTON 2

void enableInterrupts()
{  
  cli();

  EIMSK |=  0b1;
  EICRA |= 0b11; 

  sei();
}

void initT3()
{
  setPinPORTC(LED,PINMODE_OUTPUT);
  setPinPORTD(BUTTON,PINMODE_INPUT);

  enableInterrupts();
}

void updateT3()
{
  
}


ISR(INT0_vect) 
{
  togglePinPORTC(LED);
}