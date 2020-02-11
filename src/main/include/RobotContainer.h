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
		*forwardClimbState, *reverseClimbState, *forwardClimbWinch, *reverseClimbWinch,
		*toggleIntakeDeploy, *toggleIntakeRunning, *reverseIntake,
		*runHopper,
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