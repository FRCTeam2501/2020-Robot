#include "include.h"
#include "Hopper/Hopper.h"


Hopper::Hopper(Pneumatics* pneumatics) : pneumatics(pneumatics) {
	left = new WPI_TalonSRX(CAN::HOPPER_LEFT);
	right = new WPI_TalonSRX(CAN::HOPPER_RIGHT);

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