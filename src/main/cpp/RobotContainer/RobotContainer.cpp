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

	intakeDeployButton = new frc2::JoystickButton(driveStick, JOYSTICK::BUTTON_3);
	intakeDeployButton->WhenPressed(new frc2::InstantCommand(
		[this] {
			intake->Toggledeploy();
		},
		{ intake }
	));

	intakeReverse = new frc2::JoystickButton(driveStick, JOYSTICK::BUTTON_4);
	intakeReverse->WhenHeld(new frc2::InstantCommand(
		[this]{
			intake->IntakeInvert();
		},
		{ intake }
	));

	intakeRun = new frc2::JoystickButton(driveStick, JOYSTICK::TRIGGER);
	intakeRun->WhenPressed(new frc2::InstantCommand(
		[this] {
			intake->IntakeToggle();
			cout << "Starting\n";
		},
		{ intake }
	));
	intakeRun->WhenReleased(new frc2::InstantCommand(
		[this] {
			intake->IntakeToggle();
			cout << "Ending\n";
		},
		{ intake }
	));

	winchSelect = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_12);
	winchSelect->WhenPressed(new frc2::InstantCommand(
		[this]{
			climber->WinchToggle();
		},
		{ climber }
	));

	winchForward = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_6);
	winchForward->WhenPressed(new frc2::InstantCommand(
		[this]{
			climber->ToggleWinchOn();
		},
		{climber}
	));
	winchForward->WhenReleased(new frc2::InstantCommand(
		[this]{
			climber->ToggleWinchOff();
		},
		{climber}
	));

	winchReverse = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_4);
	winchReverse->WhenPressed(new frc2::InstantCommand(
		[this]{
			climber->ToggleWinchDownOn();
		},
		{climber}
	));
	winchReverse->WhenReleased(new frc2::InstantCommand(
		[this]{
			climber->ToggleWinchDownOff();
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
	evacHopper->WhenPressed(new frc2::InstantCommand(
		[this] {
			hopper->HopperToggle();
			hopper->UppyWuppy(1.0);
		},
		{ hopper }
	));
	evacHopper->WhenReleased(new frc2::InstantCommand(
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
	runHopper->WhenPressed(new frc2::InstantCommand(
		[this] {
			hopper->UppyWuppy(0.6);
		},
		{ hopper }
	));
	runHopper->WhenReleased(new frc2::InstantCommand(
		[this] {
			hopper->UppyWuppy(0.0);
		},
		{ hopper }
	));

	reverseHopper = new frc2::POVButton(controlStick, 180);
	reverseHopper->WhenPressed(new frc2::InstantCommand(
		[this] {
			hopper->UppyWuppy(-1.0);
		},
		{ hopper }
	));
	reverseHopper->WhenReleased(new frc2::InstantCommand(
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

void RobotContainer::InitalizeRobot() {
	pneu->Initialize();
}

frc2::Command *RobotContainer::GitAutoCommand() {
	return new frc2::ParallelRaceGroup(
		frc2::WaitCommand(50_s),
		frc2::StartEndCommand(
			[this] {
				drive->ArcadeDrive(10, 0.0);
			},
			[this] {
				drive->ArcadeDrive(0.0, 0.0);
			},
			{ drive }
		)
	);
}