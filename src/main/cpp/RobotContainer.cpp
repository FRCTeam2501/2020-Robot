/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/RobotContainer.h"
using namespace frc; 



RobotContainer::RobotContainer(){
	WPI_TalonSRX *talon = new WPI_TalonSRX(6);
  drive = new Drivetrain();
  driveStick = new Joystick(JOYSTICK::DRIVER);
	shooter = new Shooter();
drive->SetDefaultCommand(ManualDrive(
		  drive,
		  [this] { return -1.0 * driveStick->GetRawAxis(1); },
		  [this] { return driveStick->GetRawAxis(0); }
	));

	shooterToggle = new frc2::JoystickButton(driveStick, JOYSTICK::TRIGGER);
	shooterToggle->WhenPressed(new frc2::InstantCommand(
		[this] {
			shooter->Toggle();
		},
		{ shooter }
		
	)); 

lessSpeed = new frc2::JoystickButton(driveStick, JOYSTICK::BUTTON_3);
	lessSpeed->WhenPressed(new frc2::InstantCommand(
		[this] {
			shooter->lessSpeed();
		},
		{ shooter }
		
	));  
  
  moreSpeed = new frc2::JoystickButton(driveStick, JOYSTICK::BUTTON_5);
	moreSpeed->WhenPressed(new frc2::InstantCommand(
		[this] {
			shooter->moreSpeed();
		},
		{ shooter }
	)); 

RotateCameraUp = new frc2::JoystickButton(driveStick, JOYSTICK::BUTTON_9);
	RotateCameraUp->WhenPressed(new frc2::InstantCommand(
		[this] {
			camera->RotateCameraUp();
		},
		{ camera }
	));

RotateCameraDown = new frc2::JoystickButton(driveStick, JOYSTICK::BUTTON_11);
	RotateCameraDown->WhenPressed(new frc2::InstantCommand(
		[this] {
			camera->RotateCameraDown();
		},
		{ camera }
	));

}

RobotContainer::~RobotContainer(){
	delete drive;
	delete driveStick;
	delete shooter;
	delete shooterToggle;
	delete lessSpeed;
	delete moreSpeed;
	delete shooter;
	delete RotateCameraUp;
	delete RotateCameraDown;
}


