#pragma once
#include "include.h"
#include "Drivetrain/Drivetrain.h"
#include "Drivetrain/ManualDrive.h"
using namespace frc;


class RobotContainer {
public:
	RobotContainer();

	static double GetDriveY() {
		return -1.0 * driveStick->GetRawAxis(1);
	}

	static double GetDriveX() {
		return driveStick->GetRawAxis(0);
	}

private:
	static Drivetrain *drive;
	static Joystick *driveStick;
};