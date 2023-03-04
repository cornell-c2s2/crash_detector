#include <Arduino.h>
#include <MainControlLoop.hpp>

void setup()
{
  // put your setup code here, to run once:
  SFR sfr = SFR();
  MainControlLoop mcl = MainControlLoop(sfr);
  mcl.setup();
  mcl.execute();
}

void loop()
{
  // do nothing
}