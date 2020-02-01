#include "include.h"
#include "Hopper/Hopper.h"
using namespace frc;


Hopper::Hopper(Pneumatics* pneumatics) : pneumatics(pneumatics) {
	left = new WPI_TalonSRX(CAN::HOPPER_LEFT);
	right = new WPI_TalonSRX(CAN::HOPPER_RIGHT);

	// right->SetInverted(true);
	right->Follow(*left, ctre::phoenix::motorcontrol::FollowerType::FollowerType_PercentOutput);
	cout << "Hopper Subsystem Booted!\n";
}

Hopper::~Hopper() {
	delete left;
	delete right;
}

void Hopper::Set(double speed) {
	left->Set(speed);
}