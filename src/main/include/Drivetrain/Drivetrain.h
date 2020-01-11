#include "include.h"
#pragma once
using namespace frc;


class Drivetrain : public frc2::SubsystemBase {
public:
	Drivetrain();
	~Drivetrain();
	void Periodic() override;

	void SetSpeed(double y, double rz);
	double GetYSpeed();
	double GetRZSpeed();
private:
	DifferentialDrive *drive;
	SpeedControllerGroup *left, *right;
	PWMVictorSPX *frontLeft, *rearLeft, *frontRight, *rearRight;

	double *ySpeed, *rzSpeed;
};
