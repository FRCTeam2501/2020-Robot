#pragma once

#include <frc2/command/SubsystemBase.h>

#include "Utils/include.h"
#include "Pneumatics/Pneumatics.h"

using namespace frc;
using namespace ctre::phoenix::motorcontrol::can;

class Intake : public frc2::SubsystemBase {
 private:
  WPI_TalonSRX *intakeWheel, *intakeWheel2;
  Pneumatics *pneumatics;

 public:
  Intake(Pneumatics *pneumatics);
  ~Intake();
  
  void IntakeSpeed(double IntakeSet);
  void ToggleDeploy();
  };
