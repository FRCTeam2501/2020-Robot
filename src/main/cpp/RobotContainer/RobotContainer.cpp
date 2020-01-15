#include "RobotContainer/RobotContainer.h"

RobotContainer::RobotContainer()  {
  	drive = new Drivetrain();
	  driveStick = new Joystick(OIConstants::kDriverControllerPort);

  	drive->SetDefaultCommand(ManualDrive(
		  drive,
		  [this] { return driveStick->GetRawAxis(1); },
		  [this] { return driveStick->GetRawAxis(0); }
	));

}
