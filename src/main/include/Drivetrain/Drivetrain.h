#pragma once
#include "include.h"
using namespace frc;

class Drivetrain : public frc2::SubsystemBase {
public:
	Drivetrain();
	~Drivetrain();
	void Periodic() override;

	void ArcadeDrive(double fwd, double rot);
private:
	PWMVictorSPX *left1, *left2, *right1, *right2;
	SpeedControllerGroup *left, *right;
	DifferentialDrive *drive;
};