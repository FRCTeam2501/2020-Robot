#pragma once
#include "include.h"
#include "Climber/Climber.h"
using namespace frc;


class EnableClimber
	: public frc2::CommandHelper<frc2::InstantCommand, EnableClimber> {
private:
	Climber *climber;

public:
	EnableClimber(Climber *climber);
	void Initialize() override;
};