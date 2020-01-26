#pragma once
#include "include.h"
#include "Drivetrain/Drivetrain.h"
#include "Drivetrain/ManualDrive.h"
#include "Drivetrain/ToggleDrive.h"
#include "Pneumatics/Pneumatics.h"
#include "Climber/Climber.h"
#include "Climber/ManualClimber.h"
#include "Climber/EnableClimber.h"
#include "Climber/ToggleClimber.h"
#include "Intake/Intake.h"
#include "Intake/ManualIntake.h"
#include "Intake/ToggleIntake.h"
#include "Intake/ReverseIntake.h"
#include "Shooter/Shooter.h"
#include "Shooter/ToggleShooter.h"
using namespace frc;


class RobotContainer {
private:
	static Drivetrain *drive;
	static Pneumatics *pneumatics;
	static Climber *climber;
	static Intake *intake;
	static Shooter *shooter;
	static Joystick *driveStick, *controlStick;
	static frc2::JoystickButton *toggleDrive,
		*toggleClimber, *enableClimber,
		*toggleIntake, *reverseIntake,
		*toggleShooter;

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

	static double GetIntakeSpeed() {
		return controlStick->GetRawAxis(CONTROLLER::X::R_TRIGGER);
	}
};