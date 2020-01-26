#pragma once
#include "include.h"
#include "Climber/Climber.h"
using namespace frc;


class ReverseClimb
	: public frc2::CommandHelper<frc2::InstantCommand, ReverseClimb> {
private:
	Climber *climber;

public:
	ReverseClimb(Climber *climber);
	void Initialize() override;
};