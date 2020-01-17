#include "RobotContainer.h"
using namespace frc;


Pneumatics *RobotContainer::pneumatics;
Drivetrain *RobotContainer::drive;
Climber *RobotContainer::climber;
Joystick *RobotContainer::driveStick, *RobotContainer::controlStick;
frc2::JoystickButton *RobotContainer::toggleClimber, *RobotContainer::enableClimber, *RobotContainer::toggleIntake, *RobotContainer::reverseIntake;

RobotContainer::RobotContainer() {
	pneumatics = new Pneumatics();
	drive = new Drivetrain();
	climber = new Climber(pneumatics);
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

	toggleClimber = new frc2::JoystickButton(controlStick, CONTROLLER::X::LB);
	enableClimber = new frc2::JoystickButton(controlStick, CONTROLLER::X::START);
	toggleIntake = new frc2::JoystickButton(driveStick, CONTROLLER::X::RB);
	reverseIntake = new frc2::JoystickButton(controlStick, CONTROLLER::X::X);

	toggleClimber->WhenPressed(new ToggleClimber(climber));
	enableClimber->WhenPressed(new EnableClimber(climber));
}

RobotContainer::~RobotContainer() {
	delete pneumatics;
	delete drive;
	delete climber;
	delete driveStick;
}