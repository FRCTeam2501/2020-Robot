#pragma once
#include "include.h"
using namespace frc;


class Drivetrain : public frc2::SubsystemBase {
private:
	rev::CANSparkMax *leftFront, *leftRear, *rightFront, *rightRear;
	DifferentialDrive *drive;
	bool *inverted;

public:
	Drivetrain();
	~Drivetrain();
	void Periodic() override;

	void ArcadeDrive(double y, double rz);

	void ToggleInverted() {
		*inverted = !*inverted;
	}

	void SetInverted(bool inverted) {
		*Drivetrain::inverted = inverted;
	}

	bool GetInverted() {
		return *inverted;
	}
};