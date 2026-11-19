#include "gpio.hpp"

void setPinPORTD(uint16_t pinNum,int pinMode)
{
  if(pinMode == 1)
  {
    DDRD |= (1 << pinNum);
  }
  else
  {
    DDRD &= (~(1 << pinNum));
    PORTD |= (1 << pinNum);
  }
}

void setPinPORTC(uint16_t pinNum,int pinMode)
{
  if(pinMode == 1)
  {
    DDRC |= (1 << pinNum);
  }
  else
  {
    DDRC &= (~(1 << pinNum));
  }
}

void togglePinPORTD(uint16_t pinNum)
{
  PIND = (1 << pinNum);
}

void togglePinPORTC(uint16_t pinNum)
{
  PINC = (1 << pinNum);
}

void setPinPORTB(uint16_t pinNum,int pinMode)
{
  if(pinMode == 1)
  {
    DDRB |= (1 << pinNum);
  }
  else
  {
    DDRB &= (~(1 << pinNum));
    PORTB |= (1 << pinNum);
  }
}

void togglePinPORTB(uint16_t pinNum)
{
  PINB = (1 << pinNum);
}

int readPinPORTD(uint16_t pinNum)
{
  return PIND & (1 << pinNum);
}

int readPinPORTB(uint16_t pinNum)
{
  return PINB & (1 << pinNum);
}
