#pragma once

#include "Utils/include.h"

using namespace frc;



class Pneumatics : public frc2::SubsystemBase 
{
private:
	Compressor *compressor;
	DoubleSolenoid *verticalLift, *climb, *intake;

	void checkSticky();
	void checkFaults();
	void clearSticky();

public:
	Pneumatics();
	~Pneumatics();

	void InitPneumatics();
	void DisableAll();

	void VerticalLiftExtend();
	void VerticalLiftRetract();

	void ClimbExtend();
	void ClimbRetract();

	void ToggleVert();
	void ToggleClimb();

	void ToggleIntake();

	void Check();
};
