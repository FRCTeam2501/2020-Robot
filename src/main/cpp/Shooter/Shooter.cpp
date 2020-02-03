#include "Shooter/Shooter.h"
using namespace frc;


Shooter::Shooter() {
	left = new rev::CANSparkMax(CAN::SHOOTER_LEFT, rev::CANSparkMax::MotorType::kBrushless);
	right = new rev::CANSparkMax(CAN::SHOOTER_RIGHT, rev::CANSparkMax::MotorType::kBrushless);
	speed = new double(0.0);
	on = new bool(false);
	changed = new bool(false);

	left->SetSmartCurrentLimit(CONSTANTS::SHOOTER::CURRENT_LIMIT);
	left->SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

	right->SetSmartCurrentLimit(CONSTANTS::SHOOTER::CURRENT_LIMIT);
	right->SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

	left->GetPIDController().SetP(CONSTANTS::SHOOTER::P);
	left->GetPIDController().SetI(CONSTANTS::SHOOTER::I);
	left->GetPIDController().SetD(CONSTANTS::SHOOTER::D);
	left->GetPIDController().SetIZone(CONSTANTS::SHOOTER::IZ);
	left->GetPIDController().SetFF(CONSTANTS::SHOOTER::FF);
	left->GetPIDController().SetOutputRange(CONSTANTS::SHOOTER::MIN, CONSTANTS::SHOOTER::MAX);
	//left->GetEncoder().SetVelocityConversionFactor(CONSTANTS::SHOOTER::PPR);
	//left->GetPIDController().SetFeedbackDevice(left->GetAlternateEncoder(rev::CANEncoder::AlternateEncoderType::kQuadrature, 2048));
	
	//Set left inverted, and set right to follow it inverted of that
	left->SetInverted(true);
	right->Follow(*left, true);

	cout << "Shooter Subsystem Booted!\n";
}

Shooter::~Shooter() {

}

void Shooter::Periodic() {
	if(*changed) {
		left->GetPIDController().SetReference(*speed, rev::ControlType::kVelocity);
		*changed = false;
	}

	SmartDashboard::PutNumber("Shooter RPMs", left->GetEncoder().GetVelocity());
	//SmartDashboard::PutNumber("Shooter %", (left->Get() * 100));
}