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
			Set(CONSTANTS::SHOOTER::ON_SPEED);
		}
		else {
			Set(CONSTANTS::SHOOTER::OFF_SPEED);
		}
	}

	void Up() {
		*speed += CONSTANTS::SHOOTER::ADJUST_SPEED;
		*changed = true;
	}

	void Down() {
		*speed -= CONSTANTS::SHOOTER::ADJUST_SPEED;
		*changed = true;
	}
};