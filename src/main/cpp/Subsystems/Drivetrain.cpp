#include "Subsystems/Drivetrain.h"


Drivetrain::Drivetrain() {
	leftFront = new rev::CANSparkMax(PORTS::CAN::LEFT_FRONT, rev::CANSparkMax::MotorType::kBrushless);
	leftRear = new rev::CANSparkMax(PORTS::CAN::LEFT_REAR, rev::CANSparkMax::MotorType::kBrushless);
	rightFront = new rev::CANSparkMax(PORTS::CAN::RIGHT_FRONT, rev::CANSparkMax::MotorType::kBrushless);
	rightRear = new rev::CANSparkMax(PORTS::CAN::RIGHT_REAR, rev::CANSparkMax::MotorType::kBrushless);

	leftFront->SetSmartCurrentLimit(CONSTANTS::DRIVETRAIN::CURRENT_LIMIT.to<double>());
	leftFront->SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
	leftFront->GetEncoder().SetPositionConversionFactor(CONSTANTS::DRIVETRAIN::TURN_TO_METER.to<double>());
	leftFront->GetEncoder().SetVelocityConversionFactor(CONSTANTS::DRIVETRAIN::TURN_TO_METER.to<double>());

	rightFront->SetSmartCurrentLimit(CONSTANTS::DRIVETRAIN::CURRENT_LIMIT.to<double>());
	rightFront->SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
	rightFront->GetEncoder().SetPositionConversionFactor(CONSTANTS::DRIVETRAIN::TURN_TO_METER.to<double>());
	rightFront->GetEncoder().SetVelocityConversionFactor(CONSTANTS::DRIVETRAIN::TURN_TO_METER.to<double>());

	leftRear->SetSmartCurrentLimit(CONSTANTS::DRIVETRAIN::CURRENT_LIMIT.to<double>());
	leftRear->SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
	
	rightRear->SetSmartCurrentLimit(CONSTANTS::DRIVETRAIN::CURRENT_LIMIT.to<double>());
	rightRear->SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

	leftRear->Follow(*leftFront);
	rightRear->Follow(*rightFront);

	drive = new frc::DifferentialDrive(*leftFront, *rightFront);

	left = new double(0.0);
	right = new double(0.0);
	inverted = new bool(false);

	cout << "Drivetrain Subsystem Booted!\n";
}

Drivetrain::~Drivetrain() {
	delete leftFront;
	delete leftRear;
	delete rightFront;
	delete rightRear;

	delete drive;

	delete left;
	delete right;
	delete inverted;
}

void Drivetrain::Periodic() {}

void Drivetrain::ArcadeDrive(double x, double rz) {
	if(!*inverted) {
		x *= -1.0;
	}

	drive->ArcadeDrive(x, rz);

	*left = leftFront->Get();
	*right = rightFront->Get();
}