#include "RobotContainer.h"
using namespace frc;


Drivetrain *RobotContainer::drive;
Joystick *RobotContainer::driveStick;

RobotContainer::RobotContainer() {
	drive = new Drivetrain();
	driveStick = new Joystick(OIConstants::kDriverControllerPort);

  	drive->SetDefaultCommand(ManualDrive(
		drive,
		GetDriveY,
		GetDriveX
	));
}