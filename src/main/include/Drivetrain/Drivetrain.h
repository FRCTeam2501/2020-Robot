#pragma once

#include <frc/Encoder.h>
#include <frc/PWMVictorSPX.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class Drivetrain : public frc2::SubsystemBase {
public:
	Drivetrain();
	void Periodic() override;

	void ArcadeDrive(double fwd, double rot);
private:
	frc::PWMVictorSPX left1;
	frc::PWMVictorSPX left2;
	frc::PWMVictorSPX right1;
	frc::PWMVictorSPX right2;

	frc::SpeedControllerGroup leftMotors{left1, left2};
	frc::SpeedControllerGroup rightMotors{right1, right2};

	frc::DifferentialDrive drive{leftMotors, rightMotors};
};