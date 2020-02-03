/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/RobotContainer.h"
using namespace frc; 
using namespace JOYSTICK;
Drivetrain *RobotContainer::drive;
Joystick *RobotContainer::driveStick;

RobotContainer::RobotContainer(){

  drive = new Drivetrain();
  driveStick = new Joystick(JOYSTICK::DRIVER);

drive->SetDefaultCommand(ManualDrive(
		  drive,
		  [this] { return -1.0 * driveStick->GetRawAxis(1); },
		  [this] { return driveStick->GetRawAxis(0); }
	));
cameras = new Cameras;


 
}
RobotContainer::~RobotContainer(){
	delete drive;
	delete driveStick;
}


