#pragma once
#include "include.h"
using namespace frc;


class Drivetrain : public frc2::SubsystemBase {
private:
	PWMVictorSPX *leftFront, *leftRear, *rightFront, *rightRear;
	SpeedControllerGroup *left, *right;
	DifferentialDrive *drive;

public:
	Drivetrain();
	~Drivetrain();
	void Periodic() override;

	void ArcadeDrive(double y, double rz);
};