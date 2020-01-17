#pragma once
#include "include.h"
#include "Drivetrain/Drivetrain.h"
#include "Drivetrain/ManualDrive.h"
#include "Climber/Climber.h"
#include "Climber/ManualClimber.h"
#include "Climber/EnableClimber.h"
#include "Climber/ToggleClimber.h"
#include "Pneumatics/Pneumatics.h"
using namespace frc;


class RobotContainer {
private:
	static Pneumatics *pneumatics;
	static Drivetrain *drive;
	static Climber *climber;
	static Joystick *driveStick, *controlStick;
	static frc2::JoystickButton *toggleClimber, *enableClimber, *toggleIntake, *reverseIntake;

public:
	RobotContainer();
	~RobotContainer();

	static double GetDriveYSpeed() {
		return -1.0 * driveStick->GetRawAxis(1);
	}

	static double GetDriveRZSpeed() {
		return driveStick->GetRawAxis(0);
	}

	static double GetClimbSpeed() {
		return controlStick->GetRawAxis(CONTROLLER::X::L_TRIGGER);
	}
};