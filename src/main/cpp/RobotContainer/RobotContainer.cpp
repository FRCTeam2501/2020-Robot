#include "RobotContainer/RobotContainer.h"

RobotContainer::RobotContainer()  {
  	drive = new Drivetrain();
	  driveStick = new Joystick(OIConstants::kDriverControllerPort);

  	drive->SetDefaultCommand(ManualDrive(
		  drive,
		  [this] { return -1.0 * driveStick->GetRawAxis(1); },
		  [this] { return driveStick->GetRawAxis(0); }
	));

	cameras = new Cameras();
}

RobotContainer::~RobotContainer() {
	delete drive;
	delete driveStick;
	delete cameras;
}
