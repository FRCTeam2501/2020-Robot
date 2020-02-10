#pragma once
#include "include.h"


class Shooter : public frc2::SubsystemBase {
private:
	rev::CANSparkMax *left, *right;
	libcu::Lasershark *lidar;
	units::angular_velocity::revolutions_per_minute_t *speed;
	bool *on;
	bool *changed;


public:
	Shooter();
	~Shooter();
	void Periodic() override;

	void Set(units::angular_velocity::revolutions_per_minute_t rpm) {
		*speed = rpm;
		*changed = true;
	}

	units::angular_velocity::revolutions_per_minute_t GetSpeed() {
		return *speed;
	}

	units::length::foot_t GetDistance() {
		return lidar->GetDistance();
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