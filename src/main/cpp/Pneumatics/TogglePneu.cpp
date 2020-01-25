#include "Pneumatics/TogglePneu.h"

ToggleVert::ToggleVert(Pneumatics* subsystem)
	: pneu(subsystem) {
	AddRequirements(subsystem);

}

void ToggleVert::Initialize() {
  pneu -> ToggleVert();
}
