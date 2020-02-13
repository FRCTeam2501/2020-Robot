#pragma once
#include "include.h"

#include "Subsystems/Drivetrain.h"
#include "Subsystems/Climber.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Hopper.h"

#include "Commands/ManualDrive.h"
#include "Commands/ManualClimber.h"
#include "Commands/ManualIntake.h"

#include "Classes/Pneumatics.h"
#include "Classes/AutoInput.h"
#include "Classes/Cameras.h"


class RobotContainer : public frc::ErrorBase {
private:
	Drivetrain *drive;
	Pneumatics *pneumatics;
	Climber *climber;
	Intake *intake;
	Hopper *hopper;
	Shooter *shooter;

	AutoInput *autoInput;
	Cameras *cameras;

	frc::Joystick *driveStick, *controlStick;
	frc2::JoystickButton *toggleDrive,
		*forwardClimbState, *reverseClimbState, *forwardClimbWinch, *reverseClimbWinch, *toggleWinches,
		*toggleIntakeDeploy, *toggleIntakeRunning, *reverseIntake,
		*runHopper, *timedHopper,
		*toggleShooter, *shooterUp, *shooterDown;

	frc2::Command *autoCommand,
		*simpleDriveAuto, *simpleShootAuto, *simpleDriveShootAuto, *simpleShootDriveAuto;

	void BootSubsystems();
	void BootDefaultCommands();
	void BootInstantCommands();
	void BootAutoCommands();

	void DeleteSubsystems();
	void DeleteInstantCommands();
	void DeleteAutoCommands();

public:
	RobotContainer();
	~RobotContainer();

	void Periodic();

	frc2::Command* GetAutoCommand();
};