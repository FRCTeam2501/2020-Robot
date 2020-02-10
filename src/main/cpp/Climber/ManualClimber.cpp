#include "Climber/ManualClimber.h"


ManualClimber::ManualClimber(Climber* climber,
	std::function<double()> speed)
	: climber(climber), speed(speed) {
	AddRequirements(climber);
}

void ManualClimber::Execute() {
	climber->SetWinch(speed());
}