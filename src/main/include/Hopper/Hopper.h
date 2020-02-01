#pragma once
#include "include.h"
#include "Pneumatics/Pneumatics.h"
using namespace frc;


class Hopper : public frc2::SubsystemBase {
private:
	Pneumatics* pneumatics;
	WPI_TalonSRX *left, *right;

public:
	Hopper(Pneumatics* pneumatics);
	~Hopper();

	void Set(double speed);
};