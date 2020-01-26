#include "Climber/Climber.h"
using namespace frc;


Climber::Climber(Pneumatics *pneumatics) : pneumatics(pneumatics) {
	right = new rev::CANSparkMax(CAN::CLIMBER_RIGHT, rev::CANSparkMax::MotorType::kBrushless);
	left = new rev::CANSparkMax(CAN::CLIMBER_LEFT, rev::CANSparkMax::MotorType::kBrushless);

	right->RestoreFactoryDefaults();
	left->RestoreFactoryDefaults();

	left->Follow(*right);

	enabled = new bool(false);
}

Climber::~Climber() {
	delete right;
	delete left;

	delete enabled;
}

void Climber::Periodic() {}

void Climber::SetWinch(double speed) {
	right->Set(speed);
}

void Climber::ToggleArm() {
	if(*enabled) {
		switch(pneumatics->GetClimbArm()) {
			case DoubleSolenoid::kForward:
				pneumatics->SetClimbArm(DoubleSolenoid::kReverse);
				break;
			case DoubleSolenoid::kReverse:
				pneumatics->SetClimbArm(DoubleSolenoid::kForward);
				break;
			default:
				break;
		}
	}
}

void Climber::ToggleExtend() {
	if(*enabled) {
		switch(pneumatics->GetClimbExtend()) {
			case DoubleSolenoid::kForward:
				pneumatics->SetClimbExtend(DoubleSolenoid::kReverse);
				break;
			case DoubleSolenoid::kReverse:
				pneumatics->SetClimbExtend(DoubleSolenoid::kForward);
				break;
			default:
				break;
		}
	}
}

void Climber::SetArm(bool up) {
	if(up) {
		pneumatics->SetClimbArm(DoubleSolenoid::kForward);
	}
	else {
		pneumatics->SetClimbArm(DoubleSolenoid::kReverse);
	}
}

void Climber::SetExtend(bool extend) {
	if(extend) {
		pneumatics->SetClimbExtend(DoubleSolenoid::kForward);
	}
	else {
		pneumatics->SetClimbExtend(DoubleSolenoid::kReverse);
	}
}