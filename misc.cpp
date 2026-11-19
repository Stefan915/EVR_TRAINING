#include "misc.hpp"

volatile long long int waitVal;

void wait(long long int num)
{
  waitVal = num;

  while(waitVal > 0)
  {
    waitVal = waitVal - 1;
  }
}