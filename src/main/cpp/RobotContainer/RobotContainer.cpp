#include "RobotContainer/RobotContainer.h"

RobotContainer::RobotContainer()  {
  	drive = new Drivetrain();
	driveStick = new Joystick(0);
	controlStick = new Joystick(1);

	pneu = new Pneumatics();
	shoot = new Shooter();
	intake = new Intake(pneu);
	climber = new Climber(pneu);
	hopper = new Hopper(pneu);

  	drive->SetDefaultCommand(ManualDrive(
		  drive,
		  [this] { return -1.0 * driveStick->GetRawAxis(1); },
		  [this] { return driveStick->GetRawAxis(0); }
	));

	intake->SetDefaultCommand(IntakeSpeed(
		  intake,
		  [this] {return (driveStick->GetRawAxis(JOYSTICK::Z) - 1.0) / -2.0;}
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

	winchForward = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_6);
	winchForward->ToggleWhenPressed(new frc2::InstantCommand(
		[this]{
			climber->ToggleWinchOn();
		},
		{climber}
	));

	winchReverse = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_4);
	winchReverse->ToggleWhenPressed(new frc2::InstantCommand(
		[this]{
			climber->ToggleWinchDownOn();
		},
		{climber}
	));

	climber->SetDefaultCommand(VariableSpeed(
		  climber,
		  [this] { return (controlStick->GetRawAxis(JOYSTICK::Z)-1)/2;}
	));


	ShootTrigger = new frc2::JoystickButton(controlStick, JOYSTICK::TRIGGER);
	ShootTrigger->WhenPressed(new frc2::InstantCommand(
		[this] {
			shoot->Toggle();
		},
		{ shoot }
	));

	evacHopper = new frc2::JoystickButton(controlStick, JOYSTICK::THUMB);
	evacHopper->ToggleWhenPressed(new frc2::StartEndCommand(
		[this] {
			hopper->HopperToggle();
			hopper->UppyWuppy(1.0);
		},
		[this] {
			hopper->HopperToggle();
			hopper->UppyWuppy(0.0);
		},
		{ hopper }
	));

	shootUp = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_5);
	shootUp->WhenPressed(new frc2::InstantCommand(
		[this] {
			shoot->moreSpeed();
		},
		{ shoot }
	));

	shootDown = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_3);
	shootDown->WhenPressed(new frc2::InstantCommand(
		[this] {
			shoot->lessSpeed();
		},
		{ shoot }
	));

	climbForward = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_7);
	climbForward->WhenPressed(new frc2::InstantCommand(
		[this] {
			climber->StateUp();
		},
		{ climber }
	));

	climbReverse = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_9);
	climbReverse->WhenPressed(new frc2::InstantCommand(
		[this] {
			climber->StateBack();
		},
		{ climber }
	));

	runHopper = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_11);
	runHopper->ToggleWhenPressed(new frc2::StartEndCommand(
		[this] {
			hopper->UppyWuppy(-1.0);
		},
		[this] {
			hopper->UppyWuppy(0.0);
		},
		{ hopper }
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

frc2::Command *RobotContainer::GitAutoCommand() {
	return new frc2::ParallelRaceGroup(
		frc2::WaitCommand(50_s),
		frc2::StartEndCommand(
			[this] {
				drive->ArcadeDrive(1, 0.0);
			},
			[this] {
				drive->ArcadeDrive(0.0, 0.0);
			},
			{ drive }
		)
	);
}