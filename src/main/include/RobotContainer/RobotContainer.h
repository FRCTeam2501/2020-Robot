#pragma once

#include <frc2/command/Command.h>

#include "Utils/include.h"
#include "Drivetrain/Drivetrain.h"
#include "Drivetrain/ManualDrive.h"

using namespace frc;

class RobotContainer {
 public:

  RobotContainer();

 private:
  
  Drivetrain *drive;
  Joystick *driveStick;

};
