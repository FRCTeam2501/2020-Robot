#include "RobotContainer.h"

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc2/command/button/JoystickButton.h>

RobotContainer::RobotContainer() {
	drive = new Drivetrain();
	driveStick = new frc::Joystick(OIConstants::kDriverControllerPort);

  	drive->SetDefaultCommand(ManualDrive(
		drive,
		[this] { return driveStick->GetRawAxis(1); },
		[this] { return driveStick->GetRawAxis(0); }
	));
}