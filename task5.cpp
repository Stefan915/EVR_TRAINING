#include "task5.hpp"
#include "gpio.hpp"


static void timer()
{
  cli();
  // PRESCALER
  TCCR0B |= 0b11;

  // SET FAST PWM
  TCCR0A |= 0B11;

  // SET OUTPUT PIN
  TCCR0A |= (1 << COM0A1);

  OCR0A = 255;
  sei();
}

void initT5()
{
  setPinPORTD(6,PINMODE_OUTPUT);

  timer();
}


static int dir = 1;
void updateT5()
{
  OCR0A += dir*3;

  if(OCR0A >= 255)
  {
    OCR0A=255;
    dir = -1;
  }

  if(OCR0A == 0)
  {
    OCR0A=0;
    dir = 1;
  }
  delay(1);
}