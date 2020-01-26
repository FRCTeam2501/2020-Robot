#pragma once
#include "include.h"
#include "Climber/Climber.h"
using namespace frc;


class ForwardClimb
	: public frc2::CommandHelper<frc2::InstantCommand, ForwardClimb> {
private:
	Climber *climber;

public:
	ForwardClimb(Climber *climber);
	void Initialize() override;
};