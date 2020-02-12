/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/RobotContainer.h"
using namespace frc; 



RobotContainer::RobotContainer(){

  drive = new Drivetrain();
  driveStick = new Joystick(JOYSTICK::DRIVER);
	shooter = new Shooter();
drive->SetDefaultCommand(ManualDrive(
		  drive,
		  [this] { return -1.0 * driveStick->GetRawAxis(1); },
		  [this] { return driveStick->GetRawAxis(0); }
	));
shooter = new Shooter;

trigger = new frc2::JoystickButton(driveStick, JOYSTICK::TRIGGER);
	trigger->WhenPressed(new frc2::InstantCommand(
		[this] {
			shooter->toggle();
		},
		{ shooter }
	), false);

BUTTON_11 = new frc2::JoystickButton(driveStick, JOYSTICK::BUTTON_11);
	BUTTON_11->WhenPressed(new frc2::InstantCommand(
		[this] {
			shooter->lessSpeed();
		},
		{ shooter }
	), false);
  
  BUTTON_12 = new frc2::JoystickButton(driveStick, JOYSTICK::BUTTON_11);
	BUTTON_12->WhenPressed(new frc2::InstantCommand(
		[this] {
			shooter->moreSpeed();
		},
		{ shooter }
	), false);

}
RobotContainer::~RobotContainer(){
	delete drive;
	delete driveStick;
	delete shooter;
	delete trigger;
	delete BUTTON_11;
	delete BUTTON_12;

}


