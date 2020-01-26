#pragma once
#include "include.h"
#include "Pneumatics/Pneumatics.h"
using namespace frc;


class Climber : public frc2::SubsystemBase {
private:
	Pneumatics *pneumatics;
	rev::CANSparkMax *right, *left;
	uint8_t *state;
	bool *enabled;

	enum STATE {
		DOWN = 0,
		UP,
		EXTEND,
		RETRACT,
		ILLEGAL,
		OFF
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