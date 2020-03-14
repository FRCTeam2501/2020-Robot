#pragma once
#include "include.h"

#include "Subsystems/Drivetrain.h"
#include "Subsystems/Pneumatics.h"
#include "Subsystems/Climber.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Hopper.h"

#include "Classes/AutoInput.h"
#include "Classes/Cameras.h"
#include "Classes/RGB.h"


class RobotContainer : public frc::ErrorBase {
private:
	/*
	 *	Declare pointers to all of the robot's subsystems.
	 */
	Drivetrain *drive;
	Pneumatics *pneumatics;
	Climber *climber;
	Intake *intake;
	Hopper *hopper;
	Shooter *shooter;

	/*
	 *	Declare pointers to all of the robot's helper classes.
	 */
	AutoInput *autoInput;
	Cameras *cameras;
	RGB *rgb;

	/*
	 *	Declare pointers to all of the robot's joysticks and buttons.
	 */
	frc::Joystick *driveStick, *controlStick;
	frc2::JoystickButton *toggleDrive,
		*forwardClimbState, *reverseClimbState, *forwardClimbWinch, *reverseClimbWinch, *toggleWinches,
		*toggleIntakeDeploy, *toggleIntakeRunning, *reverseIntake,
		*evacHopper, *runHopper,
		*toggleShooter, *shooterUp, *shooterDown;
	frc2::POVButton *reverseHopper;

	//	Create the robot's subsystems
	void BootSubsystems();
	//	Setup the robot's default commands
	void BootDefaultCommands();
	//	Setup the robot's instant commands
	void BootInstantCommands();
	//	Delete the robot's subsystems
	void DeleteSubsystems();
	//	Delete the robot's default commands
	void DeleteDefaultCommands();
	//	Delete the robot's instant commands
	void DeleteInstantCommands();

public:
	//	Create a RobotContainer
	RobotContainer();
	//	Delete a RobotContainer
	~RobotContainer();

	//	Run helper classes
	void Periodic();

	//	Get command for autonomous
	frc2::Command* GetAutoCommand();
};