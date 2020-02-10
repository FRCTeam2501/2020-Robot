#pragma once
#include "include.h"
#include "Pneumatics/Pneumatics.h"


class Climber : public frc2::SubsystemBase {
private:
	Pneumatics *pneumatics;
	rev::CANSparkMax *right, *left;
	double *speed;
	uint8_t *state;
	bool *enabled, *changed;

	enum STATE {
		OFF = 0,
		DOWN,
		UP,
		EXTEND,
		RETRACT
	};

	void SetArm(bool up);
	void SetExtend(bool extend);

public:
	Climber(Pneumatics *pneumatics);
	~Climber();
	void Periodic();

	void SetWinch(double speed);
	void Forward();
	void Reverse();

	void ToggleEnable() {
		*enabled = !*enabled;
	}

	bool GetEnabled() {
		return *enabled;
	}
};