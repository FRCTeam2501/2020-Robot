#pragma once
#include "include.h"
#include "Climber/Climber.h"
using namespace frc;


class ToggleClimber
	: public frc2::CommandHelper<frc2::InstantCommand, ToggleClimber> {
private:
	Climber *climber;

public:
	ToggleClimber(Climber *climber);
	void Initialize() override;
};