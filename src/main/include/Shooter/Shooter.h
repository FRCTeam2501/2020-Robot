#pragma once
#include "include.h"
using namespace frc;


class Shooter : public frc2::SubsystemBase {
private:
	rev::CANSparkMax *left, *right;
	double *speed;
	bool *on;
	bool *changed;

public:
	Shooter();
	~Shooter();
	void Periodic() override;

	void Set(double rpm) {
		*speed = rpm;
		*changed = true;
	}

	double Get() {
		return *speed;
	}

	void Toggle() {
		*on = !*on;
		if(*on) {
			Set(CONSTANTS::SHOOTER::ON);
		}
		else {
			Set(CONSTANTS::SHOOTER::OFF);
		}
	}
};