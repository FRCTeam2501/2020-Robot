#include "Subsystems/Shooter.h"


Shooter::Shooter() {
	left = new rev::CANSparkMax(PORTS::CAN::SHOOTER_LEFT, rev::CANSparkMax::MotorType::kBrushless);
	right = new rev::CANSparkMax(PORTS::CAN::SHOOTER_RIGHT, rev::CANSparkMax::MotorType::kBrushless);
	lidar = new libcu::Lasershark(PORTS::DIO::LASERSHARK);
	speed = new units::angular_velocity::revolutions_per_minute_t(0.0);
	on = new bool(false);
	changed = new bool(false);

	left->SetSmartCurrentLimit(CONSTANTS::SHOOTER::CURRENT_LIMIT.to<double>());
	left->SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

	right->SetSmartCurrentLimit(CONSTANTS::SHOOTER::CURRENT_LIMIT.to<double>());
	right->SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

	left->GetPIDController().SetP(CONSTANTS::SHOOTER::P);
	left->GetPIDController().SetI(CONSTANTS::SHOOTER::I);
	left->GetPIDController().SetD(CONSTANTS::SHOOTER::D);
	left->GetPIDController().SetIZone(CONSTANTS::SHOOTER::IZ);
	left->GetPIDController().SetFF(CONSTANTS::SHOOTER::FF.to<double>());
	left->GetPIDController().SetOutputRange(CONSTANTS::SHOOTER::MIN, CONSTANTS::SHOOTER::MAX);
	
	//Set left inverted, and set right to follow it inverted of that
	left->SetInverted(true);
	right->Follow(*left, true);

	cout << "Shooter Subsystem Booted!\n";
}

Shooter::~Shooter() {
	delete left;
	delete right;
	delete speed;
	delete on;
	delete changed;
}

void Shooter::Periodic() {
	if(*changed) {
		left->GetPIDController().SetReference(speed->to<double>(), rev::ControlType::kVelocity);
		frc::SmartDashboard::PutNumber("Shooter Target", speed->to<double>());
		*changed = false;
	}

	frc::SmartDashboard::PutNumber("LIDAR Distance", lidar->GetDistance().to<double>());
	frc::SmartDashboard::PutNumber("Shooter RPM", left->GetEncoder().GetVelocity());
}