#include "task1.hpp"
#include "misc.hpp"
#include "gpio.hpp"

static int pins[3]={3,4,5};

static void configPins()
{
  for(int i=0;i<3;i++)
  {
    setPinPORTD(pins[i],PINMODE_OUTPUT);
  }
}

void initT1()
{
  configPins();
}
int i=0;

void updateT1()
{
  togglePinPORTD(pins[i]);
  wait(20000);
  i++;
  if(i==3)
  {
    i=0;
  }
}