#pragma once

#include "Utils/include.h"

using namespace frc;

class Drivetrain : public frc2::SubsystemBase {
public:
	Drivetrain();
	~Drivetrain();

	void ArcadeDrive(double x, double z);

	void Periodic();

	void Switch();


private:
	DifferentialDrive *drive;
	rev::CANSparkMax *frontLeft, *rearLeft, *frontRight, *rearRight;
	bool direction = false;
};
