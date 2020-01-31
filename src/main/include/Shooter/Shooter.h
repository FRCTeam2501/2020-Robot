#pragma once

#include <frc2/command/SubsystemBase.h>

#include "Utils/include.h"

using namespace frc;
using namespace rev; 

class Shooter : public frc2::SubsystemBase {

 private:
  CANSparkMax *flyWheel;

 public:
  Shooter();
  ~Shooter();

  void FlyWheelSet(double SetPoint);
};
