#pragma once
#include "include.h"
#include "Subsystems/Pneumatics.h"


class RGB;

class Climber : public frc2::SubsystemBase {
private:
	Pneumatics *pneumatics;
	rev::CANSparkMax *right, *left;
	double *winchSpeed;
	uint32_t *armState, *winchState, *runState;
	bool *changed;

	void SetArm(bool up);
	void SetExtend(bool extend);

protected:
	friend class RGB;

	enum ARM_STATE {
		DEFAULT = 0,
		DOWN,
		UP,
		EXTEND,
		RETRACT
	};
	uint32_t* GetArmState() {
		return armState;
	}

	enum WINCH_STATE {
		BOTH = 0,
		LEFT,
		RIGHT
	};
	uint32_t* GetWinchState() {
		return winchState;
	}

	enum RUN_STATE {
		OFF = 0,
		FORWARD,
		REVERSE
	};
	uint32_t* GetRunState() {
		return runState;
	}

	double* GetWinchSpeed() {
		return winchSpeed;
	}

public:

	Climber(Pneumatics *pneumatics);
	~Climber();
	void Periodic();

	void ForwardArmState();
	void ReverseArmState();
	void SetWinchSpeed(double speed);


	void ToggleWinches();
	void ToggleRunning(bool reverse = false);
};