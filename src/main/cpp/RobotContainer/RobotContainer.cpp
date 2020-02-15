#include "RobotContainer/RobotContainer.h"

RobotContainer::RobotContainer()  {
  	drive = new Drivetrain();
	driveStick = new Joystick(0);
	controlStick = new Joystick(1);

	pneu = new Pneumatics();
	shoot = new Shooter();
	intake = new Intake(pneu);
	climber = new Climber(pneu);

  	drive->SetDefaultCommand(ManualDrive(
		  drive,
		  [this] { return -1.0 * driveStick->GetRawAxis(1); },
		  [this] { return driveStick->GetRawAxis(0); }
	));

	intake->SetDefaultCommand(IntakeSpeed(
		  intake,
		  [this] {return (controlStick->GetRawAxis(3)+1)/2;}
	));

	switchDirection = new frc2::JoystickButton(driveStick, JOYSTICK::THUMB);
	
	switchDirection->WhenPressed(new SwitchDirection(drive));

//

	intakeDeployButton = new frc2::JoystickButton(driveStick, JOYSTICK::BUTTON_3);
	intakeDeployButton->WhenPressed(new frc2::InstantCommand(
		[this] {
			intake->Toggledeploy();
		},
		{ intake }
	));

	winchForward = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_7);
	winchForward->ToggleWhenPressed(new frc2::StartEndCommand(
		[this]{
			climber->ToggleWinchOn();
		},
		[this]{
			climber->ToggleWinchOff();
		},
		{climber}
	));

	winchReverse = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_9);
	winchReverse->ToggleWhenPressed(new frc2::StartEndCommand(
		[this]{
			climber->ToggleWinchDownOn();
		},
		[this]{
			climber->ToggleWinchDownOff();
		},
		{climber}
	));

	climber->SetDefaultCommand(VariableSpeed(
		  climber,
		  [this] { return (controlStick->GetRawAxis(JOYSTICK::Z)+1)/2;}
	));
}
RobotContainer::~RobotContainer(){
	delete drive;
	delete driveStick;
	delete switchDirection;
	delete intake;
	delete winchForward;
	delete winchReverse;
}


void RobotContainer::Periodic() {

}