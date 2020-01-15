#include "Drivetrain/Drivetrain.h"
using namespace frc;


Drivetrain::Drivetrain() {
	leftFront = new PWMVictorSPX(DriveConstants::kLeftMotor1Port);
	leftRear = new PWMVictorSPX(DriveConstants::kLeftMotor2Port);
	rightFront = new PWMVictorSPX(DriveConstants::kRightMotor1Port);
	rightRear = new PWMVictorSPX(DriveConstants::kRightMotor2Port);

	left = new SpeedControllerGroup(*leftFront, *leftRear);
	right = new SpeedControllerGroup(*rightFront, *rightRear);

	drive = new DifferentialDrive(*left, *right);
}

Drivetrain::~Drivetrain() {
	delete leftFront;
	delete leftRear;
	delete rightFront;
	delete rightRear;

	delete left;
	delete right;

	delete drive;
}

void Drivetrain::Periodic() {}

void Drivetrain::ArcadeDrive(double y, double rz) {
	drive->ArcadeDrive(y, rz);
}