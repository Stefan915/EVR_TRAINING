#include "task1.hpp"
#include "task2.hpp"
#include "task3.hpp"
#include "task4.hpp"
#include "task5.hpp"
#include "task6.hpp"


void setup() {
  Serial.begin(9600);

  //initT1();
  initT2();
  initT3();
  initT4();
  initT5();
  initT6();
}

void loop()
{
  //updateT1();
  updateT2();
  updateT3();
  updateT4();
  updateT5();
  updateT6();
}
