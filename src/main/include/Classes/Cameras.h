#pragma once
#include "include.h"

class Cameras : public frc::ErrorBase {
private:
	cs::UsbCamera *front, *top;
	cs::MjpegServer stream;
	uint32_t *state;

	enum STATE {
		OFF = 0,
		FRONT,
		TOP
	};

public:
	Cameras();
	~Cameras();

	void Toggle();
};