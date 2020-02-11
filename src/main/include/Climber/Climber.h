#pragma once
#include "include.h"
#include "Pneumatics/Pneumatics.h"


class Climber : public frc2::SubsystemBase {
private:
	Pneumatics *pneumatics;
	rev::CANSparkMax *right, *left;
	double *winchSpeed;
	uint8_t *armState, *winchState, *runState;
	bool *changed;

	enum ARM_STATE {
		DEFAULT = 0,
		DOWN,
		UP,
		EXTEND,
		RETRACT
	};
	enum WINCH_STATE {
		BOTH = 0,
		LEFT,
		RIGHT
	};
	enum RUN_STATE {
		OFF = 0,
		FORWARD,
		REVERSE
	};

	void SetArm(bool up);
	void SetExtend(bool extend);

public:
	Climber(Pneumatics *pneumatics);
	~Climber();
	void Periodic();

	void ForwardArmState();
	void ReverseArmState();
	void SetWinchSpeed(double speed);

	void ToggleWinches();
	void ToggleRunning(bool reverse);
};