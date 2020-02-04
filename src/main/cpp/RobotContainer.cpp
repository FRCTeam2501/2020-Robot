#include "RobotContainer.h"
using namespace frc;


RobotContainer::RobotContainer() {
	driveStick = new Joystick(JOYSTICK::DRIVER);
	controlStick = new Joystick(JOYSTICK::CONTROL);


	drive = new Drivetrain();

	drive->SetDefaultCommand(ManualDrive(
		drive,
		[this] {
			return -1.0 * driveStick->GetRawAxis(JOYSTICK::Y);
		},
		[this] {
			return driveStick->GetRawAxis(JOYSTICK::X);
		}
	));

	toggleDrive = new frc2::JoystickButton(driveStick, JOYSTICK::TRIGGER);

	toggleDrive->WhenPressed(new frc2::InstantCommand(
		[this] {
			drive->ToggleInverted();
		},
		{ drive }
	));


	pneumatics = new Pneumatics();


	climber = new Climber(pneumatics);

	climber->SetDefaultCommand(ManualClimber(
		climber,
		[this] {
			return controlStick->GetRawAxis(CONTROLLER::X::L_TRIGGER);
		}
	));

	forwardClimb = new frc2::JoystickButton(controlStick, CONTROLLER::X::LB);
	reverseClimb = new frc2::JoystickButton(controlStick, CONTROLLER::X::BACK);
	enableClimber = new frc2::JoystickButton(controlStick, CONTROLLER::X::START);

	forwardClimb->WhenPressed(new frc2::InstantCommand(
		[this] {
			climber->Forward();
		},
		{ climber }
	));
	reverseClimb->WhenPressed(new frc2::InstantCommand(
		[this] {
			climber->Reverse();
		},
		{ climber }
	));
	enableClimber->WhenPressed(new frc2::InstantCommand(
		[this] {
			climber->ToggleEnable();
		},
		{ climber }
	));


	intake = new Intake(pneumatics);

	intake->SetDefaultCommand(ManualIntake(
		intake,
		[this] {
			return (controlStick->GetRawAxis(JOYSTICK::Z) + 1) / 2;
		}
	));

	toggleIntake = new frc2::JoystickButton(controlStick, JOYSTICK::THUMB);
	reverseIntake = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_3);

	toggleIntake->WhenPressed(new frc2::InstantCommand(
		[this] {
			intake->Toggle();
		},
		{ intake }
	));
	reverseIntake->WhenPressed(new frc2::InstantCommand(
		[this] {
			intake->ToggleInverted();
		},
		{ intake }
	));


	hopper = new Hopper(pneumatics);

	runHopper = new frc2::JoystickButton(controlStick, CONTROLLER::X::RB);

	runHopper->WhenPressed(new frc2::InstantCommand(
		[this] {
			hopper->Set(CONSTANTS::HOPPER::SPEED);
		},
		{ hopper }
	));


	shooter = new Shooter();

	toggleShooter = new frc2::JoystickButton(controlStick, CONTROLLER::X::B);
	shooterUp = new frc2::JoystickButton(controlStick, CONTROLLER::X::Y);
	shooterDown = new frc2::JoystickButton(controlStick, CONTROLLER::X::A);

	toggleShooter->WhenPressed(new frc2::InstantCommand(
		[this] {
			shooter->Toggle();
		},
		{ shooter }
	));
	shooterUp->WhenPressed(new frc2::InstantCommand(
		[this] {
			shooter->Up();
		},
		{ shooter }
	));
	shooterDown->WhenPressed(new frc2::InstantCommand(
		[this] {
			shooter->Down();
		},
		{ shooter }
	));


	cout << "RobotContainer Booted!\n";
}

RobotContainer::~RobotContainer() {
	delete driveStick;
	delete controlStick;

	delete drive;
	delete toggleDrive;

	delete pneumatics;

	delete climber;
	delete forwardClimb;
	delete reverseClimb;
	delete enableClimber;

	delete intake;
	delete toggleIntake;
	delete reverseIntake;

	delete hopper;
	delete runHopper;

	delete shooter;
	delete toggleShooter;
	delete shooterUp;
	delete shooterDown;
}

void RobotContainer::Periodic() {}