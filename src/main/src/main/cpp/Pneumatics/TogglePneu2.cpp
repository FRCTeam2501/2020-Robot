#include "Classes/TogglePneu2.h"

ToggleClimb::ToggleClimb(Pneumatics* subsystem)
	: pneu2(subsystem) {
	AddRequirements(subsystem);
}

void ToggleClimb::Initialize() {
  pneu2 -> ToggleClimb();
}
