#pragma once
#include "include.h"
#include "Subsystems/Pneumatics.h"


class RGB;

class Intake : public frc2::SubsystemBase {
private:
	Pneumatics *pneumatics;
	WPI_TalonSRX *left, *right;
	double *speed;
	bool *inverted, *running, *changed;

protected:
	friend class RGB;

	bool* GetInvertedPointer() {
		return inverted;
	}
	bool* GetRunningPointer() {
		return running;
	}
	double* GetSpeedPointer() {
		return speed;
	}

public:
	Intake(Pneumatics *pneumatics);
	~Intake();
	void Periodic();

	void ToggleDeploy();

	void SetSpeed(double speed) {
		*Intake::speed = speed;
		*changed = true;
	}

	double GetSpeed() {
		return *speed;
	}

	void ToggleInverted() {
		*inverted = !*inverted;
		*changed = true;
	}

	bool GetInverted() {
		return *inverted;
	}

	void ToggleRunning() {
		*running = !*running;
		*changed = true;
	}

	bool GetRunning() {
		return *running;
	}
};
