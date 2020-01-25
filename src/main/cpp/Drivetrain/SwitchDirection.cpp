#include "Drivetrain/SwitchDirection.h"

SwitchDirection::SwitchDirection(Drivetrain* subsystem)
	: drive(subsystem) {
	AddRequirements(subsystem);
  }

void SwitchDirection::Initialize() {
  drive -> Switch();
}
