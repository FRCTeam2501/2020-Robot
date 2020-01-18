#pragma once

#include <frc2/command/Command.h>

#include "Utils/include.h"
#include "Drivetrain/Drivetrain.h"
#include "Drivetrain/ManualDrive.h"

#include "Cameras/Cameras.h"

using namespace frc;

class RobotContainer {
 public:

  RobotContainer();
  ~RobotContainer();
  
 private:
  
  Drivetrain *drive;
  Joystick *driveStick;
  Cameras *cameras;

};
