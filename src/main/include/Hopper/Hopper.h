#pragma once
#include "include.h"
using namespace frc;


class Hopper : public frc2::SubsystemBase {
private:
	WPI_TalonSRX *left, *right;

public:
	Hopper();
	~Hopper();

	void Set(double speed);
};