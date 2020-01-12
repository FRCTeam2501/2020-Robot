#include "Drivetrain/Drivetrain.h"

using namespace DriveConstants;

Drivetrain::Drivetrain()
	: left1{kLeftMotor1Port},
	left2{kLeftMotor2Port},
	right1{kRightMotor1Port},
	right2{kRightMotor2Port} {}

void Drivetrain::Periodic() {}

void Drivetrain::ArcadeDrive(double fwd, double rot) {
	drive.ArcadeDrive(fwd, rot);
}