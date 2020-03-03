#pragma once
#include "Utils/include.h"

#include "subsystems/Drivetrain.h"
#include "Subsystems/Pneumatics.h"
#include "subsystems/hopper/hopper.h"
#include "subsystems/intake/Intake.h"
#include "subsystems/shooter/shooter.h"
#include "subsystems/hopper/Hopper.h"

#include "autoshit/AutoInput.h"
//#include "Classes/RGB.h" commented out because i dont know if we have rgb code 


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
	RGB *rgb;

	frc::Joystick *driveStick, *controlStick;
	frc2::JoystickButton *toggleDrive,
		*forwardClimbState, *reverseClimbState, *forwardClimbWinch, *reverseClimbWinch, *toggleWinches,
		*toggleIntakeDeploy, *toggleIntakeRunning, *reverseIntake,
		*evacHopper, *runHopper,
		*toggleShooter, *shooterUp, *shooterDown;
	frc2::POVButton *reverseHopper;

	frc2::Command *autoCommand;

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
