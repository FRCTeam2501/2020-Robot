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
#include "Auto/AutoInput.h"
using namespace frc;


class RobotContainer : public ErrorBase {
private:
	Drivetrain *drive;
	Pneumatics *pneumatics;
	Climber *climber;
	Intake *intake;
	Hopper *hopper;
	Shooter *shooter;
	AutoInput *autoInput;
	DigitalInput *auto0;
	Joystick *driveStick, *controlStick;
	frc2::JoystickButton *toggleDrive,
		*forwardClimb, *reverseClimb, *enableClimber,
		*toggleIntake, *reverseIntake,
		*toggleShooter, *shooterUp, *shooterDown,
		*runHopper;

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