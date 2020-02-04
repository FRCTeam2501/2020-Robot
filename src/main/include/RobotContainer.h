#pragma once
#include "include.h"
#include "Drivetrain/Drivetrain.h"
#include "Drivetrain/ManualDrive.h"
#include "Pneumatics/Pneumatics.h"
#include "Climber/Climber.h"
#include "Climber/ManualClimber.h"
#include "Intake/Intake.h"
#include "Intake/ManualIntake.h"
#include "Shooter/Shooter.h"
#include "Hopper/Hopper.h"
using namespace frc;


class RobotContainer {
private:
	Drivetrain *drive;
	Pneumatics *pneumatics;
	Climber *climber;
	Intake *intake;
	Hopper *hopper;
	Shooter *shooter;
	Joystick *driveStick, *controlStick;
	frc2::JoystickButton *toggleDrive,
		*forwardClimb, *reverseClimb, *enableClimber,
		*toggleIntake, *reverseIntake,
		*toggleShooter, *shooterUp, *shooterDown,
		*runHopper;

public:
	RobotContainer();
	~RobotContainer();

	void Periodic();
};