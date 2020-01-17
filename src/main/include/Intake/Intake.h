#pragma once
#include "include.h"
#include "Pneumatics/Pneumatics.h"
using namespace frc;


class Intake : public frc2::SubsystemBase {
private:
	Pneumatics *pneumatics;
	PWMVictorSPX *motor;
	bool *inverted;

public:
	Intake(Pneumatics *pneumatics);
	~Intake();
	void Periodic();

	void Set(double speed);
	void Toggle();

	void ToggleInverted() {
		*inverted = !*inverted;
	}

	void SetInverted(bool inverted) {
		*Intake::inverted = inverted;
	}

	bool GetInverted() {
		return *inverted;
	}
};
