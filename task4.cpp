#include "task4.hpp"
#include "gpio.hpp"

volatile int cnt = 0;
static int pins[3]={5,3,4};



static void timer_interrupt()
{
  cli();
  TCCR0B |= 0b11;
  OCR0B = 255;
  TIMSK0 |= (1 << OCIE0B);
  sei();
}

static void configPins()
{
  for(int i=0;i<3;i++)
  {
    setPinPORTD(pins[i],PINMODE_OUTPUT);
  }
}

void initT4()
{
  timer_interrupt();
  configPins();
}

volatile int idx = 0;
void updateT4()
{
}

ISR(TIMER0_COMPB_vect) 
{
  cnt++;
  if(cnt >= 245)
  {
    cnt = 0;
    idx++;
    if(idx==3)
    {
      idx=0;
    }
    togglePinPORTD(pins[idx]);
  }
}