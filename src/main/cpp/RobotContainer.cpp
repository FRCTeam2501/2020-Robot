#include "RobotContainer.h"


void RobotContainer::BootSubsystems() {
	//	Create joystick objects.
	driveStick = new frc::Joystick(PORTS::JOYSTICK::DRIVER);
	controlStick = new frc::Joystick(PORTS::JOYSTICK::CONTROL);

	//	Create subsystem objects.
	drive = new Drivetrain();
	pneumatics = new Pneumatics();
	climber = new Climber(pneumatics);
	intake = new Intake(pneumatics);
	hopper = new Hopper(pneumatics);
	shooter = new Shooter();

	//	Create helper objects.
	autoInput = new AutoInput();
	cameras = new Cameras();
	rgb = new RGB(drive, climber, intake, shooter);

	cout << "Subsystems Booted!\n";
}

void RobotContainer::BootDefaultCommands() {
	//	Create default commands for each subsystem that needs one.

	drive->SetDefaultCommand(frc2::RunCommand(
		[this] {
			//	Run the drivetrain with Y and RZ from the joysticks.
			drive->ArcadeDrive(CONSTANTS::DRIVETRAIN::Y_SPEED * driveStick->GetRawAxis(JOYSTICK::AXIS::Y), CONSTANTS::DRIVETRAIN::RZ_SPEED * driveStick->GetRawAxis(JOYSTICK::AXIS::X));
		},
		{ drive }
	));

	climber->SetDefaultCommand(frc2::RunCommand(
		[this] {
			//	Varies climber winch speed from 0% to 100%.
			climber->SetWinchSpeed((controlStick->GetRawAxis(JOYSTICK::AXIS::Z) + 1) / 2);
		},
		{ climber }
	));

	intake->SetDefaultCommand(frc2::RunCommand(
		[this] {
			//	Varies intake speed from 50% to 100%.
			intake->SetSpeed((driveStick->GetRawAxis(JOYSTICK::AXIS::Z) + 1) / 2);
		},
		{ intake }
	));

	cout << "Default Commands Booted!\n";
}

void RobotContainer::BootInstantCommands() {
	//	Create joystick buttons and commands for controlling the robot.

	toggleDrive = new frc2::JoystickButton(driveStick, JOYSTICK::BUTTON::THUMB);
	toggleDrive->WhenPressed(new frc2::InstantCommand(
		[this] {
			drive->ToggleInverted();
		},
		{ drive }
	));

	forwardClimbState = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON::BUTTON_7);
	forwardClimbState->WhenPressed(new frc2::InstantCommand(
		[this] {
			climber->ForwardArmState();
		},
		{ climber }
	));
	reverseClimbState = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON::BUTTON_9);
	reverseClimbState->WhenPressed(new frc2::InstantCommand(
		[this] {
			climber->ReverseArmState();
		},
		{ climber }
	));
	forwardClimbWinch = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON::BUTTON_6);
	forwardClimbWinch->ToggleWhenPressed(new frc2::StartEndCommand(
		[this] {
			climber->ToggleRunning();
		},
		[this] {
			climber->ToggleRunning();
		},
		{ climber }
	));
	reverseClimbWinch = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON::BUTTON_4);
	reverseClimbWinch->ToggleWhenPressed(new frc2::StartEndCommand(
		[this] {
			climber->ToggleRunning(true);
		},
		[this] {
			climber->ToggleRunning(true);
		},
		{ climber }
	));
	toggleWinches = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON::BUTTON_12);
	toggleWinches->WhenPressed(new frc2::InstantCommand(
		[this] {
			climber->ToggleWinches();
		},
		{ climber }
	));

	toggleIntakeRunning = new frc2::JoystickButton(driveStick, JOYSTICK::BUTTON::TRIGGER);
	toggleIntakeRunning->ToggleWhenPressed(new frc2::StartEndCommand(
		[this] {
			intake->ToggleRunning();
		},
		[this] {
			intake->ToggleRunning();
		},
		{ intake }
	));
	toggleIntakeDeploy = new frc2::JoystickButton(driveStick, JOYSTICK::BUTTON::BUTTON_3);
	toggleIntakeDeploy->WhenPressed(new frc2::InstantCommand(
		[this] {
			intake->ToggleDeploy();
		},
		{ intake }
	));
	reverseIntake = new frc2::JoystickButton(driveStick, JOYSTICK::BUTTON::BUTTON_4);
	reverseIntake->WhenPressed(new frc2::InstantCommand(
		[this] {
			intake->ToggleInverted();
		},
		{ intake }
	));

	evacHopper = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON::THUMB);
	evacHopper->ToggleWhenPressed(new frc2::StartEndCommand(
		[this] {
			hopper->Set(CONSTANTS::HOPPER::ON);
			hopper->TogglePin();
		},
		[this] {
			hopper->Set(CONSTANTS::HOPPER::OFF);
			hopper->TogglePin();
		},
		{ hopper }
	));
	runHopper = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON::BUTTON_11);
	runHopper->ToggleWhenPressed(new frc2::StartEndCommand(
		[this] {
			hopper->Set(CONSTANTS::HOPPER::ON);
		},
		[this] {
			hopper->Set(CONSTANTS::HOPPER::OFF);
		},
		{ hopper }
	));
	reverseHopper = new frc2::POVButton(controlStick, JOYSTICK::POV::TOP);
	reverseHopper->ToggleWhenPressed(new frc2::StartEndCommand(
		[this] {
			hopper->Set(CONSTANTS::HOPPER::REVERSE);
		},
		[this] {
			hopper->Set(CONSTANTS::HOPPER::OFF);
		},
		{ hopper }
	));

	toggleShooter = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON::TRIGGER);
	toggleShooter->WhenPressed(new frc2::InstantCommand(
		[this] {
			shooter->Toggle();
		},
		{ shooter }
	));
	shooterUp = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON::BUTTON_5);
	shooterUp->WhenPressed(new frc2::InstantCommand(
		[this] {
			shooter->Up();
		},
		{ shooter }
	));
	shooterDown = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON::BUTTON_3);
	shooterDown->WhenPressed(new frc2::InstantCommand(
		[this] {
			shooter->Down();
		},
		{ shooter }
	));

	cout << "Instant Commands Booted!\n";
}

RobotContainer::RobotContainer() {
	BootSubsystems();
	BootDefaultCommands();
	BootInstantCommands();

	cout << "RobotContainer Booted!\n";
}

void RobotContainer::DeleteSubsystems() {
	//	Delete all joysticks, subsystems, and helper class objects.

	delete driveStick;
	delete controlStick;

	delete drive;
	delete pneumatics;
	delete climber;
	delete intake;
	delete hopper;
	delete shooter;

	delete autoInput;
	delete cameras;
	delete rgb;

	cout << "Subsystems Deleted!\n";
}

void RobotContainer::DeleteDefaultCommands() {
	//	Get default commands from subsystems and delete them.

	delete drive->GetDefaultCommand();
	delete climber->GetDefaultCommand();
	delete intake->GetDefaultCommand();

	cout << "Default Commands Deleted!\n";
}

void RobotContainer::DeleteInstantCommands() {
	//	Delete all joystick buttons.

	delete toggleDrive;

	delete forwardClimbState;
	delete reverseClimbState;
	delete forwardClimbWinch;
	delete reverseClimbWinch;
	delete toggleWinches;

	delete toggleIntakeDeploy;
	delete toggleIntakeRunning;
	delete reverseIntake;

	delete evacHopper;
	delete runHopper;

	delete toggleShooter;
	delete shooterUp;
	delete shooterDown;
	
	cout << "Instant Commands Deleted!\n";
}

RobotContainer::~RobotContainer() {
	DeleteSubsystems();
	DeleteInstantCommands();

	cout << "RobotContainer Deleted!\n";
}

void RobotContainer::Periodic() {
	//	Run any periodic functions of helper classes.

	rgb->Periodic();
}

frc2::Command* RobotContainer::GetAutoCommand() {
	//	Return a command for autonomous.

	frc2::Command* autoCommand = nullptr;

	switch(autoInput->Get()) {
		case CONSTANTS::AUTO::ADV_DRIVE::MODE:
			autoCommand = new frc2::SequentialCommandGroup(
				frc2::InstantCommand( 
					[this] {
						drive->ArcadeDrive(CONSTANTS::AUTO::ADV_DRIVE::SPEED, 0.0);
					},
					{ drive }
				),
				frc2::WaitUntilCommand(
					[this] {
						return drive->GetAvgDistance() > CONSTANTS::AUTO::ADV_DRIVE::DISTANCE;
					}
				),
				frc2::InstantCommand(
					[this] {
						drive->Stop();
					},
					{ drive }
				)
			);
			break;
		case CONSTANTS::AUTO::SIMPLE_SHOOT_DRIVE::MODE:
			autoCommand = new frc2::SequentialCommandGroup(
				frc2::InstantCommand(
					[this] {
						shooter->Set(CONSTANTS::SHOOTER::ON_SPEED);
					},
					{ shooter }
				),
				frc2::WaitCommand(CONSTANTS::AUTO::SIMPLE_SHOOT::SPIN_UP_TIME),
				frc2::InstantCommand(
					[this] {
						hopper->Set(CONSTANTS::HOPPER::ON);
						hopper->TogglePin();
					},
					{ hopper }
				),
				frc2::WaitCommand(CONSTANTS::AUTO::SIMPLE_SHOOT::SHOOT_TIME),
				frc2::InstantCommand(
					[this] {
						shooter->Set(CONSTANTS::SHOOTER::OFF_SPEED);
						hopper->Set(CONSTANTS::HOPPER::OFF);
						hopper->TogglePin();
					},
					{ shooter, hopper }
				),
				frc2::ParallelRaceGroup(
					frc2::StartEndCommand(
						[this] {
							drive->ArcadeDrive(CONSTANTS::AUTO::SIMPLE_DRIVE::SPEED, 0.0);
						},
						[this] {
							drive->Stop();
						},
						{ drive }
					),
					frc2::WaitCommand(CONSTANTS::AUTO::SIMPLE_DRIVE::TIME)
				)
			);
			break;
		case CONSTANTS::AUTO::SIMPLE_DRIVE_SHOOT::MODE:
			autoCommand = new frc2::SequentialCommandGroup(
				frc2::ParallelRaceGroup(
					frc2::StartEndCommand(
						[this] {
							drive->ArcadeDrive(CONSTANTS::AUTO::SIMPLE_DRIVE::SPEED, 0.0);
						},
						[this] {
							drive->Stop();
						},
						{ drive }
					),
					frc2::WaitCommand(CONSTANTS::AUTO::SIMPLE_DRIVE::TIME)
				),
				frc2::InstantCommand(
					[this] {
						shooter->Set(CONSTANTS::SHOOTER::ON_SPEED);
					},
					{ shooter }
				),
				frc2::WaitCommand(CONSTANTS::AUTO::SIMPLE_SHOOT::SPIN_UP_TIME),
				frc2::InstantCommand(
					[this] {
						hopper->Set(CONSTANTS::HOPPER::ON);
						hopper->TogglePin();
					},
					{ hopper }
				),
				frc2::WaitCommand(CONSTANTS::AUTO::SIMPLE_SHOOT::SHOOT_TIME),
				frc2::InstantCommand(
					[this] {
						shooter->Set(CONSTANTS::SHOOTER::OFF_SPEED);
						hopper->Set(CONSTANTS::HOPPER::OFF);
						hopper->TogglePin();
					},
					{ shooter, hopper }
				)
			);
			break;
		case CONSTANTS::AUTO::SIMPLE_SHOOT::MODE:
			autoCommand = new frc2::SequentialCommandGroup(
				frc2::InstantCommand(
					[this] {
						shooter->Set(CONSTANTS::SHOOTER::ON_SPEED);
					},
					{ shooter }
				),
				frc2::WaitCommand(CONSTANTS::AUTO::SIMPLE_SHOOT::SPIN_UP_TIME),
				frc2::InstantCommand(
					[this] {
						hopper->Set(CONSTANTS::HOPPER::ON);
					},
					{ hopper }
				),
				frc2::WaitCommand(CONSTANTS::AUTO::SIMPLE_SHOOT::SHOOT_TIME),
				frc2::InstantCommand(
					[this] {
						shooter->Set(CONSTANTS::SHOOTER::OFF_SPEED);
						hopper->Set(CONSTANTS::HOPPER::OFF);
					},
					{ shooter, hopper }
				)
			);
			break;
		case CONSTANTS::AUTO::SIMPLE_DRIVE::MODE:
			autoCommand = new frc2::ParallelRaceGroup(
				frc2::StartEndCommand(
					[this] {
						drive->ArcadeDrive(CONSTANTS::AUTO::SIMPLE_DRIVE::SPEED, 0.0);
					},
					[this] {
						drive->Stop();
					},
					{ drive }
				),
				frc2::WaitCommand(CONSTANTS::AUTO::SIMPLE_DRIVE::TIME)
			);
			break;
		case CONSTANTS::AUTO::OFF_1::MODE:
		case CONSTANTS::AUTO::OFF_0::MODE:
		default:
			autoCommand = new frc2::PrintCommand("Error: " + autoInput->GetTwine());
			break;
	}

	return autoCommand;
}