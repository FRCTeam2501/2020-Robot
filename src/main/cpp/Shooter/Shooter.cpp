#include "Shooter/Shooter.h"
using namespace frc;


Shooter::Shooter() {
	left = new rev::CANSparkMax(CAN::SHOOTER_LEFT, rev::CANSparkMax::MotorType::kBrushless);
	right = new rev::CANSparkMax(CAN::SHOOTER_RIGHT, rev::CANSparkMax::MotorType::kBrushless);
	speed = new double(0.0);
	on = new bool(false);
	changed = new bool(false);

	left->GetPIDController().SetP(CONSTANTS::SHOOTER::P);
	left->GetPIDController().SetI(CONSTANTS::SHOOTER::I);
	left->GetPIDController().SetD(CONSTANTS::SHOOTER::D);
	left->GetPIDController().SetIZone(CONSTANTS::SHOOTER::IZ);
	left->GetPIDController().SetFF(CONSTANTS::SHOOTER::FF);
	left->GetPIDController().SetOutputRange(CONSTANTS::SHOOTER::MIN, CONSTANTS::SHOOTER::MAX);

	left->GetEncoder().SetVelocityConversionFactor(CONSTANTS::SHOOTER::PPR);
	
	right->SetInverted(true);
	right->Follow(*left);
	cout << "Shooter Subsystem Booted!\n";
}

Shooter::~Shooter() {

}

void Shooter::Periodic() {
	if(*changed) {
		left->GetPIDController().SetReference(*speed, rev::ControlType::kVelocity);
		*changed = false;
	}
}