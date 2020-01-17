#include "Climber/EnableClimber.h"
using namespace frc;


EnableClimber::EnableClimber(Climber *climber) : climber(climber) {}

void EnableClimber::Initialize() {
	climber->ToggleEnable();
}