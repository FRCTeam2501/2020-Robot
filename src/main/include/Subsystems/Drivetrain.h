#pragma once
#include "include.h"

class RGB;

class Drivetrain : public frc2::SubsystemBase {
private:
	rev::CANSparkMax *leftFront, *leftRear, *rightFront, *rightRear;
	frc::DifferentialDrive *drive;
	bool *inverted;

	units::meter_t GetDistance(rev::CANSparkMax *smax) {
		return units::length::foot_t(smax->GetEncoder().GetPosition());
	}

	units::meters_per_second_t GetSpeed(rev::CANSparkMax *smax) {
		return units::feet_per_second_t(smax->GetEncoder().GetVelocity());
	}

protected:
	friend class RGB;

	double* GetLeft() {
		return nullptr;
	}
	double* GetRight() {
		return nullptr;
	}

public:
	Drivetrain();
	~Drivetrain();
	void Periodic() override;

    /**
     * Runs the drivetrain with a certain forward and rotation
     *
     * @param x		1.0 for full forward, -1.0 for full reverse
	 * @param rz	1.0 for full rotation clockwise, -1.0 for full rotation counterclockwise
     */
	void ArcadeDrive(double x, double rz);

	void Stop() {
		ArcadeDrive(0.0, 0.0);
	}

	void ToggleInverted() {
		*inverted = !*inverted;
	}

	void SetInverted(bool inverted) {
		*Drivetrain::inverted = inverted;
	}

	bool GetInverted() {
		return *inverted;
	}

	void ResetEncoders() {
		leftFront->GetEncoder().SetPosition(0);
		rightFront->GetEncoder().SetPosition(0);
	}

	units::meter_t GetLeftDistance() {
		return GetDistance(leftFront);
	}

	units::meter_t GetRightDistance() {
		return GetDistance(rightFront);
	}

	units::meters_per_second_t GetLeftSpeed() {
		return GetSpeed(leftFront);
	}

	units::meters_per_second_t GetRightSpeed() {
		return GetSpeed(rightFront);
	}
};