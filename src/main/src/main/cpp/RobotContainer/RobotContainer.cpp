#include "RobotContainer.h"

RobotContainer::RobotContainer()  {
  	drive = new Drivetrain();
	driveStick = new Joystick(OIConstants::kDriverControllerPort);
	controlStick = new Joystick(OIConstants::kControlControllerPort);

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
		  [this] {return controlStick->GetRawAxis(3);}
	));

	cameras = new Cameras();

	switchDirection = new frc2::JoystickButton(driveStick, JOYSTICK::THUMB);
	
	switchDirection->WhenPressed(new SwitchDirection(drive));

	Pneumatics1 = new frc2::JoystickButton(driveStick, JOYSTICK::BUTTON_8);

	Pneumatics1->WhenPressed(new ToggleVert(pneu));

	Pneumatics2 = new frc2::JoystickButton(driveStick, JOYSTICK::BUTTON_9);

	Pneumatics2->WhenPressed(new ToggleClimb(pneu));

	ShootTrigger = new frc2::JoystickButton(driveStick, JOYSTICK::TRIGGER);

	ShootTrigger->WhenPressed(new Shoot(shoot));

	intakeDeployButton = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_8);

	intakeDeployButton->WhenPressed(new ToggleDeployIntake(intake));

	winchForward = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_6);
	winchForward->ToggleWhenPressed(new frc2::StartEndCommand(
		[this]{
			climber->ToggleWinchOn();
		},
		[this]{
			climber->ToggleWinchOff();
		},
		{climber}
	));

	winchReverse = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_4);
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
	delete cameras;
	delete switchDirection;
	delete intake;
	delete winchForward;
	delete winchReverse;
}


void RobotContainer::Periodic() {
	if(driveStick->GetTrigger()) {
		if(!state) {
			shoot->ToggleShoot();
			state = true;
		}
	}
	else if(state) {
		state = false;
	}
}