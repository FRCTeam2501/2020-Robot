#include "Subsystems/Hopper.h"


Hopper::Hopper(Pneumatics* pneumatics) : pneumatics(pneumatics) {
	left = new WPI_TalonSRX(PORTS::CAN::HOPPER_LEFT);
	right = new WPI_TalonSRX(PORTS::CAN::HOPPER_RIGHT);

	left->ConfigContinuousCurrentLimit(CONSTANTS::HOPPER::CONTINUOUS_LIMIT.to<int>());
	left->ConfigPeakCurrentLimit(CONSTANTS::HOPPER::PEAK_LIMIT.to<int>());
	left->ConfigPeakCurrentDuration(CONSTANTS::HOPPER::PEAK_TIME.to<int>());
	left->EnableCurrentLimit(true);
	right->ConfigContinuousCurrentLimit(CONSTANTS::HOPPER::CONTINUOUS_LIMIT.to<int>());
	right->ConfigPeakCurrentLimit(CONSTANTS::HOPPER::PEAK_LIMIT.to<int>());
	right->ConfigPeakCurrentDuration(CONSTANTS::HOPPER::PEAK_TIME.to<int>());
	right->EnableCurrentLimit(true);

	right->Follow(*left, ctre::phoenix::motorcontrol::FollowerType::FollowerType_PercentOutput);

	cout << "Hopper Subsystem Booted!\n";

	pneumatics->SetHopper(frc::DoubleSolenoid::kForward);
}

Hopper::~Hopper() {
	delete left;
	delete right;
}

void Hopper::Set(double speed) {
	left->Set(speed);
}