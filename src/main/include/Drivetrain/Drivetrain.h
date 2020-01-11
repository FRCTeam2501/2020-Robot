#include "Utils/include.h"

#pragma once

using namespace frc;

class Drivetrain : public frc2::SubsystemBase
{
public:
	Drivetrain();
	~Drivetrain();

	void setSpeed(double x, double r);
	double getXSpeed();
	double getRSpeed();

	void Periodic();


private:
	DifferentialDrive *drive;
	PWMVictorSPX *frontLeft, *rearLeft, *frontRight, *rearRight;

	double *xSpeed, *rSpeed;
};
