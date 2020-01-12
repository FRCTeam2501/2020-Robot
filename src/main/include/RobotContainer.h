#pragma once

#include <frc/XboxController.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/Command.h>

#include "Constants.h"
#include "Drivetrain/ManualDrive.h"
#include "Drivetrain/Drivetrain.h"

class RobotContainer {
public:
	RobotContainer();
private:
	Drivetrain drive;
	frc::XboxController driverController{OIConstants::kDriverControllerPort};
};