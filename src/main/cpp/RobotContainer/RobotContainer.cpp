#include "RobotContainer/RobotContainer.h"

RobotContainer::RobotContainer()  {
  	drive = new Drivetrain();
	  driveStick = new Joystick(OIConstants::kDriverControllerPort);

  	drive->SetDefaultCommand(ManualDrive(
		  drive,
		  [this] { return -1.0 * driveStick->GetRawAxis(1); },
		  [this] { return driveStick->GetRawAxis(0); }
	));

	cameras = new Cameras();

	switchDirection = new frc2::JoystickButton(driveStick, JOYSTICK::THUMB);
	
	switchDirection->WhenPressed(new SwitchDirection(drive));

	Pneumatics1 = new frc2::JoystickButton(driveStick, JOYSTICK::BUTTON_8);

	Pneumatics1->WhenPressed(new ToggleVert(pneu));

	Pneumatics2 = new frc2::JoystickButton(driveStick, JOYSTICK::BUTTON_9);

	Pneumatics2->WhenPressed(new ToggleClimb(pneu));

	
}

RobotContainer::~RobotContainer() {
	delete drive;
	delete driveStick;
	delete cameras;
	delete switchDirection;
}
