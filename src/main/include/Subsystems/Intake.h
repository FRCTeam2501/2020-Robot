#pragma once
#include "include.h"
#include "Subsystems/Pneumatics.h"


class Intake : public frc2::SubsystemBase {
private:
	Pneumatics *pneumatics;
	WPI_TalonSRX *left, *right;
	double *speed;
	bool *inverted, *running, *changed;

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
