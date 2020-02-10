#pragma once
#include "include.h"
#include "Climber/Climber.h"


class ManualClimber
	: public frc2::CommandHelper<frc2::CommandBase, ManualClimber> {
private:
	Climber *climber;
	std::function<double()> speed;

public:
	ManualClimber(Climber *climber, std::function<double()> speed);
	void Execute() override;
};