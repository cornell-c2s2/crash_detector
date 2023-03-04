#include <MainControlLoop.hpp>
#include <Arduino.h>

MainControlLoop::MainControlLoop(SFR& sfr) :
  ControlTask(sfr),
  imu_task(sfr)
  {
};

void MainControlLoop::setup() {
  Serial.begin(9600);
  Serial.println("MCL Setup"); 
  imu_task.setup();
};

void MainControlLoop::execute() {
  while(true) {
    Serial.println("MCL execute");
    imu_task.execute();
  }
};