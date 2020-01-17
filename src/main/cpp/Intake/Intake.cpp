#include "Intake/Intake.h"
using namespace frc;

Intake::Intake(Pneumatics *pneumatics) : pneumatics(pneumatics) {
	motor = new PWMVictorSPX(PWM::INTAKE);
	inverted = new bool(false);
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
		case DoubleSolenoid::kForward:
			pneumatics->SetIntake(DoubleSolenoid::kReverse);
			break;
		case DoubleSolenoid::kReverse:
			pneumatics->SetIntake(DoubleSolenoid::kForward);
			break;
		default:
			break;
	}
}