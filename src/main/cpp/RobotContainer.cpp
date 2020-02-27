#include "RobotContainer.h"


RobotContainer::RobotContainer()  {
	drive = new Drivetrain();
	climber = new Climber(pneu);
	intake = new Intake(pneu);
	hopper = new Hopper(pneu);
	shooter = new Shooter();

	pneu = new Pneumatics();

	driveStick = new Joystick(0);
	controlStick = new Joystick(1);

	drive->SetDefaultCommand(frc2::RunCommand(
		[this] {
			drive->ArcadeDrive(
				-1.0 * driveStick->GetRawAxis(1),
				driveStick->GetRawAxis(0)
			);
		},
		{ drive }
	));

	intake->SetDefaultCommand(frc2::RunCommand(
		[this] {
			intake->IntakeSpeed((driveStick->GetRawAxis(JOYSTICK::Z) - 1.0) / -2.0);
		},
		{ intake }
	));

	switchDirection = new frc2::JoystickButton(driveStick, JOYSTICK::THUMB);
	switchDirection->WhenPressed(new frc2::InstantCommand(
		[this] {
			drive->Switch();
		},
		{ drive }
	));

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
	intakeRun->ToggleWhenPressed(new frc2::StartEndCommand(
		[this]{
			intake->IntakeToggle();
		},
		[this]{
			intake->IntakeToggle();
		},
		{intake}
	));

	winchSelect = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_12);
	winchSelect->WhenPressed(new frc2::InstantCommand(
		[this]{
			climber->WinchToggle();
		},
		{ climber }
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

	climber->SetDefaultCommand(frc2::RunCommand(
		[this] {
			climber->SetSpeed((controlStick->GetRawAxis(JOYSTICK::Z)-1)/2);
		},
		{ climber }
	));

	ShootTrigger = new frc2::JoystickButton(controlStick, JOYSTICK::TRIGGER);
	ShootTrigger->WhenPressed(new frc2::InstantCommand(
		[this] {
			shooter->Toggle();
		},
		{ shooter }
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
			shooter->moreSpeed();
		},
		{ shooter }
	));

	shootDown = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_3);
	shootDown->WhenPressed(new frc2::InstantCommand(
		[this] {
			shooter->lessSpeed();
		},
		{ shooter }
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
			hopper->UppyWuppy(1.0);
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

frc2::Command *RobotContainer::GetAutoCommand() {
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