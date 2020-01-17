#include "Climber/ManualClimber.h"
using namespace frc;


ManualClimber::ManualClimber(Climber* climber,
	std::function<double()> speed)
	: climber(climber), speed(speed) {
	AddRequirements(climber);
}

void ManualClimber::Execute() {
	climber->SetWinch(speed());
}