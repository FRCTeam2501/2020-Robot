#pragma once

#include <frc2/command/SubsystemBase.h>

#include "Utils/include.h"

using namespace frc;
using namespace rev; 

class Shooter : public frc2::SubsystemBase {

 private:
  units::time::second_t last = frc2::GetTime();
  CANSparkMax *flyWheel, *flyWheel2;
  bool toggleShoot = false;
 public:
  Shooter();
  ~Shooter();

  void FlyWheelSet(double SetPoint);
  void ToggleShoot();

  void Periodic() override;
};
