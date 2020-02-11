#include "RobotContainer.h"


void RobotContainer::BootSubsystems() {
	driveStick = new frc::Joystick(JOYSTICK::DRIVER);
	controlStick = new frc::Joystick(JOYSTICK::CONTROL);

	drive = new Drivetrain();
	pneumatics = new Pneumatics();
	climber = new Climber(pneumatics);
	intake = new Intake(pneumatics);
	hopper = new Hopper(pneumatics);
	shooter = new Shooter();

	autoInput = new AutoInput();
	cameras = new Cameras();

	cout << "Subsystems Booted!\n";
}

void RobotContainer::BootDefaultCommands() {
	drive->SetDefaultCommand(ManualDrive(
		drive,
		[this] {
			return -1.0 * driveStick->GetRawAxis(JOYSTICK::Y);
		},
		[this] {
			return driveStick->GetRawAxis(JOYSTICK::X);
		}
	));

	climber->SetDefaultCommand(ManualClimber(
		climber,
		[this] {
			return (controlStick->GetRawAxis(JOYSTICK::Z) + 1) / 2;
		}
	));

	intake->SetDefaultCommand(ManualIntake(
		intake,
		[this] {
			return (driveStick->GetRawAxis(JOYSTICK::Z) + 1) / 2;
		}
	));

	cout << "Default Commands Booted!\n";
}

void RobotContainer::BootInstantCommands() {
	toggleDrive = new frc2::JoystickButton(driveStick, JOYSTICK::THUMB);
	toggleDrive->WhenPressed(new frc2::InstantCommand(
		[this] {
			drive->ToggleInverted();
		},
		{ drive }
	));

	forwardClimbState = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_7);
	forwardClimbState->WhenPressed(new frc2::InstantCommand(
		[this] {
			climber->ForwardArmState();
		},
		{ climber }
	));
	reverseClimbState = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_9);
	reverseClimbState->WhenPressed(new frc2::InstantCommand(
		[this] {
			climber->ReverseArmState();
		},
		{ climber }
	));
	forwardClimbWinch = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_6);
	forwardClimbWinch->ToggleWhenPressed(new frc2::StartEndCommand(
		[this] {
			climber->ToggleRunning(false);
		},
		[this] {
			climber->ToggleRunning(false);
		},
		{ climber }
	));
	reverseClimbWinch = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_4);
	reverseClimbWinch->ToggleWhenPressed(new frc2::StartEndCommand(
		[this] {
			climber->ToggleRunning(true);
		},
		[this] {
			climber->ToggleRunning(true);
		},
		{ climber }
	));

	toggleIntakeRunning = new frc2::JoystickButton(driveStick, JOYSTICK::TRIGGER);
	toggleIntakeRunning->ToggleWhenPressed(new frc2::StartEndCommand(
		[this] {
			intake->ToggleRunning();
		},
		[this] {
			intake->ToggleRunning();
		},
		{ intake }
	));
	toggleIntakeDeploy = new frc2::JoystickButton(driveStick, JOYSTICK::BUTTON_3);
	toggleIntakeDeploy->WhenPressed(new frc2::InstantCommand(
		[this] {
			intake->ToggleDeploy();
		},
		{ intake }
	));
	reverseIntake = new frc2::JoystickButton(driveStick, JOYSTICK::BUTTON_4);
	reverseIntake->WhenPressed(new frc2::InstantCommand(
		[this] {
			intake->ToggleInverted();
		},
		{ intake }
	));

	runHopper = new frc2::JoystickButton(controlStick, JOYSTICK::THUMB);
	runHopper->WhenPressed(new frc2::StartEndCommand(
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

	toggleShooter = new frc2::JoystickButton(controlStick, JOYSTICK::TRIGGER);
	toggleShooter->WhenPressed(new frc2::InstantCommand(
		[this] {
			shooter->Toggle();
		},
		{ shooter }
	));
	shooterUp = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_5);
	shooterUp->WhenPressed(new frc2::InstantCommand(
		[this] {
			shooter->Up();
		},
		{ shooter }
	));
	shooterDown = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_3);
	shooterDown->WhenPressed(new frc2::InstantCommand(
		[this] {
			shooter->Down();
		},
		{ shooter }
	));

	cout << "Instant Commands Booted!\n";
/*
	TODO:
	*	controlStick Thumb: Run hopper and retract pins on start, stop hopper and extend pins on end
	*	Climber toggle: Toggle which winch is being run at a time
	*	Climber speed:	Vary climber winch speed
*/
}

void RobotContainer::BootAutoCommands() {
	simpleDriveAuto  = new frc2::ParallelRaceGroup(
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

	simpleShootAuto = new frc2::SequentialCommandGroup(
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

	simpleShootDriveAuto = new frc2::SequentialCommandGroup(
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

	simpleDriveShootAuto = new frc2::SequentialCommandGroup(
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

	autoCommand = nullptr;

	cout << "Auto Commands Booted!\n";
}

RobotContainer::RobotContainer() {
	BootSubsystems();
	BootDefaultCommands();
	BootInstantCommands();
	BootAutoCommands();

	cout << "RobotContainer Booted!\n";
}

void RobotContainer::DeleteSubsystems() {
	delete driveStick;
	delete controlStick;

	delete drive;
	delete pneumatics;
	delete climber;
	delete intake;
	delete hopper;
	delete shooter;

	delete autoInput;

	cout << "Subsystems Deleted!\n";
}

void RobotContainer::DeleteInstantCommands() {
	delete toggleDrive;

	delete forwardClimbState;
	delete reverseClimbState;

	delete toggleIntakeDeploy;
	delete toggleIntakeRunning;
	delete reverseIntake;

	delete runHopper;

	delete toggleShooter;
	delete shooterUp;
	delete shooterDown;
	
	cout << "Instant Commands Deleted!\n";
}

void RobotContainer::DeleteAutoCommands() {
	delete simpleDriveAuto;
	delete simpleShootAuto;
	delete simpleDriveShootAuto;
	delete simpleShootDriveAuto;

	cout << "Auto Commands Deleted!\n";
}

RobotContainer::~RobotContainer() {
	DeleteSubsystems();
	DeleteInstantCommands();
	DeleteAutoCommands();

	cout << "RobotContainer Deleted!\n";
}

void RobotContainer::Periodic() {}

frc2::Command* RobotContainer::GetAutoCommand() {
	switch(autoInput->Get()) {
		case CONSTANTS::AUTO::SIMPLE_SHOOT_DRIVE::MODE:
			autoCommand = simpleShootDriveAuto;
			break;
		case CONSTANTS::AUTO::SIMPLE_DRIVE_SHOOT::MODE:
			autoCommand = simpleDriveShootAuto;
			break;
		case CONSTANTS::AUTO::SIMPLE_SHOOT::MODE:
			autoCommand = simpleShootAuto;
			break;
		case CONSTANTS::AUTO::SIMPLE_DRIVE::MODE:
			autoCommand = simpleDriveAuto;
			break;
		case CONSTANTS::AUTO::OFF_1::MODE:
		case CONSTANTS::AUTO::OFF_0::MODE:
		default:
			autoCommand = simpleDriveAuto;
			break;
	}
	return autoCommand;
}