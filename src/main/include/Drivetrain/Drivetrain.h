#pragma once
#include "include.h"
using namespace frc;


class Drivetrain : public frc2::SubsystemBase {
public:
	Drivetrain();
	~Drivetrain();
	void Periodic() override;

	void ArcadeDrive(double y, double rz);
private:
	PWMVictorSPX *leftFront, *leftRear, *rightFront, *rightRear;
	SpeedControllerGroup *left, *right;
	DifferentialDrive *drive;
};