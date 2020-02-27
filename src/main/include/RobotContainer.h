#pragma once
#include "include.h"

#include "Subsystems/Drivetrain.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Climber.h"
#include "Subsystems/Hopper.h"

#include "Classes/Pneumatics.h"
#include "Classes/Cameras.h"


class RobotContainer {
private:
	Drivetrain *drive;
	Climber *climber;
	Intake *intake;
	Hopper *hopper;
	Shooter *shooter;

	Pneumatics *pneu;

	Joystick *driveStick, *controlStick;
	frc2::JoystickButton *switchDirection,
						*ShootTrigger,
						*intakeDeployButton, *intakeSet, *intakeReverse, *intakeRun,
						*winchForward, *winchReverse, *winchSelect,
						*evacHopper, *shootUp, *shootDown, *climbForward, *climbReverse, *runHopper;

public:
	RobotContainer();
	~RobotContainer();

	void Periodic();
	frc2::Command *GetAutoCommand();
};
