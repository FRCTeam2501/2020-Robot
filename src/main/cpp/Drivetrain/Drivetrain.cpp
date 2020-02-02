#include "Drivetrain/Drivetrain.h"
using namespace frc;


Drivetrain::Drivetrain() {
	leftFront = new rev::CANSparkMax(CAN::LEFT_FRONT, rev::CANSparkMax::MotorType::kBrushless);
	leftRear = new rev::CANSparkMax(CAN::LEFT_REAR, rev::CANSparkMax::MotorType::kBrushless);
	rightFront = new rev::CANSparkMax(CAN::RIGHT_FRONT, rev::CANSparkMax::MotorType::kBrushless);
	rightRear = new rev::CANSparkMax(CAN::RIGHT_REAR, rev::CANSparkMax::MotorType::kBrushless);

	leftRear->Follow(*leftFront);
	rightRear->Follow(*rightFront);

	drive = new DifferentialDrive(*leftFront, *rightFront);

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