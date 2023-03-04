#pragma once

#include <ControlTask.hpp>
#include <IMUTask.hpp>
#include <StateFieldRegistry.hpp>

class MainControlLoop : ControlTask {
  public:
  IMUTask imu_task;
  MainControlLoop(SFR& sfr);
  void setup();
  void execute();
};