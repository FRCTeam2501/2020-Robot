#include "Shooter/Shooter.h"
using namespace frc;


Shooter::Shooter() {
	shooter = new rev::CANSparkMax(CAN::SHOOTER, rev::CANSparkMax::MotorType::kBrushless);
	speed = new double(0.0);
	on = new bool(false);
	changed = new bool(false);

	shooter->GetPIDController().SetP(CONSTANTS::SHOOTER::P);
	shooter->GetPIDController().SetI(CONSTANTS::SHOOTER::I);
	shooter->GetPIDController().SetD(CONSTANTS::SHOOTER::D);
	shooter->GetPIDController().SetIZone(CONSTANTS::SHOOTER::IZ);
	shooter->GetPIDController().SetFF(CONSTANTS::SHOOTER::FF);
	shooter->GetPIDController().SetOutputRange(CONSTANTS::SHOOTER::MIN, CONSTANTS::SHOOTER::MAX);

	shooter->GetEncoder().SetVelocityConversionFactor(CONSTANTS::SHOOTER::PPR);
}

Shooter::~Shooter() {

}

void Shooter::Periodic() {
	if(*changed) {
		shooter->GetPIDController().SetReference(*speed, rev::ControlType::kVelocity);
		*changed = false;
	}
}