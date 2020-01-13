#include "RobotContainer.h"

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc2/command/button/JoystickButton.h>

RobotContainer::RobotContainer() {
  	drive.SetDefaultCommand(ManualDrive(
		&drive,
		[this] { return driverController.GetRawAxis(1); },
		[this] { return driverController.GetRawAxis(0); }
	));
}