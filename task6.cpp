#include "task6.hpp"
#include "gpio.hpp"

static int potVal=0;

static void ADCinit()
{
  ADCSRA = ( 1 << ADEN ) | ( 1 << ADIE ) | bit(ADPS0) | bit(ADPS1) | bit(ADPS2);

  ADMUX = bit(REFS0);
}

static void timer()
{
  cli();
  // PRESCALER  
  TCCR2B |= 0b11;

  // SET FAST PWM
  TCCR2A |= 0b11;

  // SET OUTPUT PIN
  TCCR2A |= (1 << COM2A1);

  OCR2A = 255;

  sei();
}

void initT6()
{
  setPinPORTB(3,PINMODE_OUTPUT);

  ADCinit();
  timer();

}


static int dir = 1;
void updateT6()
{
  OCR2A = potVal / 4;
  ADCSRA |= 1<<ADSC;
}



ISR(ADC_vect) 
{
  potVal = ADC;
}

