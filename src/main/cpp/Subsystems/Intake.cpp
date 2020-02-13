#include "Subsystems/Intake.h"

Intake::Intake(Pneumatics *pneumatics) : pneumatics(pneumatics) {
	left = new WPI_TalonSRX(CAN::INTAKE_LEFT);
	right = new WPI_TalonSRX(CAN::INTAKE_RIGHT);
	speed = new double(0.0);
	inverted = new bool(false);
	running = new bool(false);
	changed = new bool(false);

	left->ConfigContinuousCurrentLimit(CONSTANTS::INTAKE::CONTINUOUS_LIMIT.to<int>());
	left->ConfigPeakCurrentLimit(CONSTANTS::INTAKE::PEAK_LIMIT.to<int>());
	left->ConfigPeakCurrentDuration(CONSTANTS::INTAKE::PEAK_TIME.to<int>());
	left->EnableCurrentLimit(true);
	right->ConfigContinuousCurrentLimit(CONSTANTS::INTAKE::CONTINUOUS_LIMIT.to<int>());
	right->ConfigPeakCurrentLimit(CONSTANTS::INTAKE::PEAK_LIMIT.to<int>());
	right->ConfigPeakCurrentDuration(CONSTANTS::INTAKE::PEAK_TIME.to<int>());
	right->EnableCurrentLimit(true);

	right->Follow(*left, ctre::phoenix::motorcontrol::FollowerType::FollowerType_PercentOutput);

	cout << "Intake Subsystem Booted!\n";
}

Intake::~Intake() {
	delete left;
	delete right;
	delete speed;
	delete inverted;
	delete running;
	delete changed;
}

void Intake::Periodic() {
	if(*changed) {
		if(*inverted) {
			left->Set(*speed * -1.0);
		}
		else {
			right->Set(*speed);
		}
		*changed = false;
	}
}

void Intake::ToggleDeploy() {
	switch(pneumatics->GetIntake()) {
		case frc::DoubleSolenoid::kForward:
			pneumatics->SetIntake(frc::DoubleSolenoid::kReverse);
			break;
		case frc::DoubleSolenoid::kReverse:
			pneumatics->SetIntake(frc::DoubleSolenoid::kForward);
			break;
		default:
			break;
	}
}