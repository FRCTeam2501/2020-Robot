#include "Intake/Intake.h"

Intake::Intake(Pneumatics *pneumatics) : pneumatics(pneumatics) {
	motor = new WPI_TalonSRX(CAN::INTAKE_LEFT);
	inverted = new bool(false);

	cout << "Intake Subsystem Booted!\n";
}

Intake::~Intake() {
	delete inverted;
}

void Intake::Periodic() {}

void Intake::Set(double speed) {
	if(*inverted)
		speed *= -1.0;

	motor->Set(speed);
}

void Intake::Toggle() {
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