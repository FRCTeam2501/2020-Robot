#include "RobotContainer.h"
using namespace frc;


Drivetrain *RobotContainer::drive;
Joystick *RobotContainer::driveStick;

RobotContainer::RobotContainer() {
	drive = new Drivetrain();
	driveStick = new Joystick(JOYSTICK::DRIVER);

  	drive->SetDefaultCommand(ManualDrive(
		drive,
		GetDriveY,
		GetDriveX
	));
}

RobotContainer::~RobotContainer() {
	delete drive;
	delete driveStick;
}