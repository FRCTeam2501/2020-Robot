#pragma once

#include <frc/XboxController.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/Command.h>

#include "Constants.h"
#include "commands/DefaultDrive.h"
#include "subsystems/DriveSubsystem.h"

class RobotContainer {
public:
	RobotContainer();
private:
	DriveSubsystem drive;
	frc::XboxController driverController{OIConstants::kDriverControllerPort};
};