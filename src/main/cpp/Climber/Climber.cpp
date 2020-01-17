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
}

void Climber::Periodic() {}

void Climber::SetWinch(double speed) {
	if(*enabled)
		right->Set(speed);
}

void Climber::ToggleArm() {
	if(*enabled) {
		switch(pneumatics->GetClimb()) {
			case DoubleSolenoid::kForward:
				pneumatics->SetClimb(DoubleSolenoid::kReverse);
				break;
			case DoubleSolenoid::kReverse:
				pneumatics->SetClimb(DoubleSolenoid::kForward);
				break;
			default:
				break;
		}
	}
}