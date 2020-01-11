#include "subsystems/DriveSubsystem.h"

using namespace DriveConstants;

DriveSubsystem::DriveSubsystem()
		: left1{kLeftMotor1Port},
    left2{kLeftMotor2Port},
    right1{kRightMotor1Port},
    right2{kRightMotor2Port} {}

void DriveSubsystem::Periodic() {}

void DriveSubsystem::ArcadeDrive(double fwd, double rot) {
  drive.ArcadeDrive(fwd, rot);
}