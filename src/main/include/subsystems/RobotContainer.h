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
using namespace frc;


class RobotContainer {
 public:
  RobotContainer();
~RobotContainer();


private:
  
  static Drivetrain *drive;
  static Joystick *driveStick;
  
};
