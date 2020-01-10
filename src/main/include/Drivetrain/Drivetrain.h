#include "Utils/include.h"

#pragma once

using namespace frc;

class Drivetrain : public frc2::SubsystemBase {
public:
	Drivetrain();
	~Drivetrain();

	void setSpeed(double x, double z);

	double getXSpeed();
	double getZSpeed();

	/**
	 * Will be called periodically whenever the CommandScheduler runs.
	 */
	void Periodic();


private:
	DifferentialDrive *drive;
	PWMVictorSPX *frontLeft, *rearLeft, *frontRight, *rearRight;
	SpeedControllerGroup *left, *right;

	double *xSpeed, *zSpeed;
	// Components (e.g. motor controllers and sensors) should generally be
	// declared private and exposed only through public methods.
};
