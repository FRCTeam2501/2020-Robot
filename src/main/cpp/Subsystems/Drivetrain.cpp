#include "Subsystems/Drivetrain.h"


Drivetrain::Drivetrain() {
	leftFront = new rev::CANSparkMax(CAN::LEFT_FRONT, rev::CANSparkMax::MotorType::kBrushless);
	leftRear = new rev::CANSparkMax(CAN::LEFT_REAR, rev::CANSparkMax::MotorType::kBrushless);
	rightFront = new rev::CANSparkMax(CAN::RIGHT_FRONT, rev::CANSparkMax::MotorType::kBrushless);
	rightRear = new rev::CANSparkMax(CAN::RIGHT_REAR, rev::CANSparkMax::MotorType::kBrushless);

	leftFront->RestoreFactoryDefaults();
	leftFront->SetSmartCurrentLimit(CONSTANTS::DRIVETRAIN::CURRENT_LIMIT.to<double>());
	leftFront->SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
	rightFront->RestoreFactoryDefaults();
	rightFront->SetSmartCurrentLimit(CONSTANTS::DRIVETRAIN::CURRENT_LIMIT.to<double>());
	rightFront->SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
	leftRear->RestoreFactoryDefaults();
	leftRear->SetSmartCurrentLimit(CONSTANTS::DRIVETRAIN::CURRENT_LIMIT.to<double>());
	leftRear->SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
	rightRear->RestoreFactoryDefaults();
	rightRear->SetSmartCurrentLimit(CONSTANTS::DRIVETRAIN::CURRENT_LIMIT.to<double>());
	rightRear->SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

	leftRear->Follow(*leftFront);
	rightRear->Follow(*rightFront);

	drive = new frc::DifferentialDrive(*leftFront, *rightFront);

	inverted = new bool(false);
	cout << "Drivetrain Subsystem Booted!\n";
}

Drivetrain::~Drivetrain() {
	delete leftFront;
	delete leftRear;
	delete rightFront;
	delete rightRear;

	delete drive;

	delete inverted;
}

void Drivetrain::Periodic() {}

void Drivetrain::ArcadeDrive(double y, double rz) {
	if(*inverted)
		y *= -1.0;

	drive->ArcadeDrive(y, rz);
}

void Drivetrain::Stop() {
	ArcadeDrive(0.0, 0.0);
}