#pragma once

#include "Utils/include.h"

using namespace frc;

class Drivetrain : public frc2::SubsystemBase {
public:
	Drivetrain();
	~Drivetrain();

	void ArcadeDrive(double x, double z);

	void Periodic();


private:
	DifferentialDrive *drive;
	PWMVictorSPX *frontLeft, *rearLeft, *frontRight, *rearRight;
	SpeedControllerGroup *left, *right;
};
