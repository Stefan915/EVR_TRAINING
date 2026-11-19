#include "task2.hpp"
#include "gpio.hpp"

#define BUTTON_PIN 0
#define LED1 4  
#define LED2 5

int lastState = 0;

void initT2()
{
  setPinPORTB(BUTTON_PIN,PINMODE_INPUT);
  setPinPORTC(LED1,PINMODE_OUTPUT);
  setPinPORTC(LED2,PINMODE_OUTPUT);
  togglePinPORTC(LED1);
}

void updateT2()
{
  if(!readPinPORTB(BUTTON_PIN))
  {
    if(lastState==0)
    {
      togglePinPORTC(LED1);
      togglePinPORTC(LED2);
      lastState = 1;
    }
  }
  else
  {
    lastState=0;
  }
}