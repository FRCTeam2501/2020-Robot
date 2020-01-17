#include "RobotContainer.h"
using namespace frc;


Drivetrain *RobotContainer::drive;
Pneumatics *RobotContainer::pneumatics;
Climber *RobotContainer::climber;
Intake *RobotContainer::intake;
Joystick *RobotContainer::driveStick, *RobotContainer::controlStick;
frc2::JoystickButton *RobotContainer::toggleClimber, *RobotContainer::enableClimber, *RobotContainer::toggleIntake, *RobotContainer::reverseIntake;

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

	toggleClimber = new frc2::JoystickButton(controlStick, CONTROLLER::X::LB);
	enableClimber = new frc2::JoystickButton(controlStick, CONTROLLER::X::START);
	toggleIntake = new frc2::JoystickButton(driveStick, CONTROLLER::X::RB);
	reverseIntake = new frc2::JoystickButton(controlStick, CONTROLLER::X::X);

	toggleClimber->WhenPressed(new ToggleClimber(climber));
	enableClimber->WhenPressed(new EnableClimber(climber));
	toggleIntake->WhenPressed(new ToggleIntake(intake));
	reverseIntake->WhenHeld(new ReverseIntake(intake));
}

RobotContainer::~RobotContainer() {
	delete pneumatics;
	delete drive;
	delete climber;
	delete driveStick;
}