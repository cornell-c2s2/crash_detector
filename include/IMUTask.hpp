#pragma once

#include <Adafruit_BNO055.h>
#include <ControlTask.hpp>

class IMUTask : ControlTask
{
public:
  Adafruit_BNO055 bno;

  IMUTask(SFR &sfr);
  void setup();
  void execute();
  void display();
  bool detectCrash(float init_acc_x, float init_acc_y, float init_acc_z);
};
