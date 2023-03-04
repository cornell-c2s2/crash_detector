#pragma once

#include <StateFieldRegistry.hpp>

class ControlTask {
  public:
  SFR& sfr_;
  ControlTask(SFR& sfr);
  void setup();
  void execute();
};