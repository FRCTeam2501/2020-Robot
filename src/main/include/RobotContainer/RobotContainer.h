#pragma once

#include <frc2/command/Command.h>

#include "Utils/include.h"
#include "Drivetrain/Drivetrain.h"
#include "Drivetrain/SwitchDirection.h"
#include "Drivetrain/ManualDrive.h"

#include "Cameras/Cameras.h"

#include "Pneumatics/Pneumatics.h"
#include "Pneumatics/TogglePneu.h"
#include "Pneumatics/TogglePneu2.h"

using namespace frc;

class RobotContainer {
 public:

  RobotContainer();
  ~RobotContainer();
  
 private:
  
  Drivetrain *drive;
  Joystick *driveStick;
  Cameras *cameras;
  frc2::JoystickButton *switchDirection, *Pneumatics1, *Pneumatics2;
  Pneumatics *pneu;
};
