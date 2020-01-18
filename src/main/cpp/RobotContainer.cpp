#include "RobotContainer.h"
using namespace frc;


Drivetrain *RobotContainer::drive;
Pneumatics *RobotContainer::pneumatics;
Climber *RobotContainer::climber;
Intake *RobotContainer::intake;
Joystick *RobotContainer::driveStick, *RobotContainer::controlStick;
frc2::JoystickButton *RobotContainer::toggleDrive,
	*RobotContainer::toggleClimber, *RobotContainer::enableClimber,
	*RobotContainer::toggleIntake, *RobotContainer::reverseIntake;

RobotContainer::RobotContainer() {
	drive = new Drivetrain();
	pneumatics = new Pneumatics();
	climber = new Climber(pneumatics);
	intake = new Intake(pneumatics);
	driveStick = new Joystick(JOYSTICK::DRIVER);
	controlStick = new Joystick(JOYSTICK::CONTROL);

  	drive->SetDefaultCommand(ManualDrive(
		drive,
		GetDriveYSpeed,
		GetDriveRZSpeed
	));
	climber->SetDefaultCommand(ManualClimber(
		climber,
		GetClimbSpeed
	));
	intake->SetDefaultCommand(ManualIntake(
		intake,
		GetIntakeSpeed
	));

	toggleDrive = new frc2::JoystickButton(driveStick, JOYSTICK::THUMB);
	toggleClimber = new frc2::JoystickButton(controlStick, CONTROLLER::X::LB);
	enableClimber = new frc2::JoystickButton(controlStick, CONTROLLER::X::START);
	toggleIntake = new frc2::JoystickButton(controlStick, CONTROLLER::X::RB);
	reverseIntake = new frc2::JoystickButton(controlStick, CONTROLLER::X::X);

	toggleDrive->WhenPressed(new ToggleDrive(drive));
	toggleClimber->WhenPressed(new ToggleClimber(climber));
	enableClimber->WhenPressed(new EnableClimber(climber));
	toggleIntake->WhenPressed(new ToggleIntake(intake));
	reverseIntake->WhenHeld(new ReverseIntake(intake));
}

RobotContainer::~RobotContainer() {
	delete drive;
	delete pneumatics;
	delete climber;
	delete intake;

	delete driveStick;
	delete controlStick;

	delete toggleDrive;
	delete toggleClimber;
	delete enableClimber;
	delete toggleIntake;
	delete reverseIntake;
}