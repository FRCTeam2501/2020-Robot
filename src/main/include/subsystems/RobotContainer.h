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
#include "subsystems/Drivetrain.h"
using namespace frc;





class RobotContainer {
 public:
  RobotContainer();


static double getDriveY(){

  return driverStick-> getRawAxes(1);
}

static double getDriveX(){

  return driverStick -> getRawAxes();
}
  frc2::Command* GetAutonomousCommand();

 private:
  
  static Drivetrain *drive;
  static Joystick *drivestick;
  
};