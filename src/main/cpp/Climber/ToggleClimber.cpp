#include "Climber/ToggleClimber.h"
using namespace frc;


ToggleClimber::ToggleClimber(Climber *climber) : climber(climber) {}

void ToggleClimber::Initialize() {
	climber->Toggle();
}