#include "RobotContainer.h"
#include "Drivetrain/ManualDrive.h"


RobotContainer::RobotContainer() {
	drive = new Drivetrain();
	cout << "Built Drivetrain\n";
	driveStick = new Joystick(JOYSTICK::DRIVER);
	cout << "Built Joysticks\n";

	drive->SetDefaultCommand(ManualDrive(
		drive,
		[this] { return driveStick->GetY(); },
		[this] { return driveStick->GetX(); }
	));
	cout << "Setup Drivetrain\n";
}

RobotContainer::~RobotContainer() {
	delete drive;
	delete driveStick;
}

double RobotContainer::GetRZSpeed() {
	return driveStick->GetX();
}

double RobotContainer::GetYSpeed() {
	return driveStick->GetY();
}