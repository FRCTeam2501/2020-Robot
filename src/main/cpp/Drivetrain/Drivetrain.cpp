#include "Drivetrain/Drivetrain.h"
using namespace frc;


Drivetrain::Drivetrain() {
	left1 = new PWMVictorSPX(DriveConstants::kLeftMotor1Port);
	left2 = new PWMVictorSPX(DriveConstants::kLeftMotor2Port);
	right1 = new PWMVictorSPX(DriveConstants::kRightMotor1Port);
	right2 = new PWMVictorSPX(DriveConstants::kRightMotor2Port);

	left = new SpeedControllerGroup(*left1, *left2);
	right = new SpeedControllerGroup(*right1, *right2);

	drive = new DifferentialDrive(*left, *right);
}

Drivetrain::~Drivetrain() {
	delete left1;
	delete left2;
	delete right1;
	delete right2;

	delete left;
	delete right;

	delete drive;
}

void Drivetrain::Periodic() {}

void Drivetrain::ArcadeDrive(double fwd, double rot) {
	drive->ArcadeDrive(fwd, rot);
}