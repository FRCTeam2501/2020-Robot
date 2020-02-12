/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>
#include "Utils/include.h"
#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"
#include "Drivetrain/Drivetrain.h"
#include "Drivetrain/ManualDrive.h"
#include "subsystems/Cameras.h"
#include "subsystems/Pneumatics.h"
#include "subsystems/Shooter.h"
#include "frc/WPILib.h"

using namespace frc;
using namespace JOYSTICK;

class RobotContainer {
 public:
  RobotContainer();
~RobotContainer();


private:
  
  Shooter *shooter;
   Drivetrain *drive;
   Joystick *driveStick;
  Cameras *cameras;
  frc2::JoystickButton *shooterToggle, *lessSpeed, *moreSpeed;
};
