#pragma once
#include "include.h"
#include "Pneumatics/Pneumatics.h"
using namespace frc;


class Climber : public frc2::SubsystemBase {
private:
	Pneumatics *pneumatics;
	rev::CANSparkMax *right, *left;
	bool *enabled;

public:
	Climber(Pneumatics *pneumatics);
	~Climber();
	void Periodic();

	void SetWinch(double speed);
	void ToggleArm();
	void ToggleExtend();
	void SetArm(bool up);
	void SetExtend(bool extend);

	void ToggleEnable() {
		*enabled = !*enabled;
	}

	bool GetEnabled() {
		return *enabled;
	}
};