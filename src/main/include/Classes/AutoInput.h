#pragma once
#include "include.h"

class AutoInput : public frc::ErrorBase {
private:
	frc::DigitalInput *switch0, *switch1, *switch2, *switch3, *switch4;

public:
	AutoInput();
	~AutoInput();

	uint8_t Get();
};