#include "Drivetrain/Drivetrain.h"

using namespace DriveConstants;


Drivetrain::Drivetrain() {
	left1 = new frc::PWMVictorSPX(kLeftMotor1Port);
	left2 = new frc::PWMVictorSPX(kLeftMotor2Port);
	right1 = new frc::PWMVictorSPX(kRightMotor1Port);
	right2 = new frc::PWMVictorSPX(kRightMotor2Port);

	left = new frc::SpeedControllerGroup(*left1, *left2);
	right = new frc::SpeedControllerGroup(*right1, *right2);

	drive = new frc::DifferentialDrive(*left, *right);
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