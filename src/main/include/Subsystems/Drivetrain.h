#pragma once
#include "include.h"


class Drivetrain : public frc2::SubsystemBase {
private:
	rev::CANSparkMax *leftFront, *leftRear, *rightFront, *rightRear;
	frc::DifferentialDrive *drive;
	bool *inverted;

public:
	Drivetrain();
	~Drivetrain();
	void Periodic() override;

	void ArcadeDrive(double y, double rz);
	void Stop();

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