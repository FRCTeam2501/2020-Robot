#pragma once
#include "include.h"
using namespace frc;

class AutoInput : public ErrorBase {
private:
	DigitalInput *switch0, *switch1, *switch2, *switch3, *switch4;

public:
	AutoInput();
	~AutoInput();

	uint8_t Get();
};
