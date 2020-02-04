#include "Shooter/ToggleShooter.h"
using namespace frc;


ToggleShooter::ToggleShooter(Shooter *shooter) : shooter(shooter) {
	AddRequirements(shooter);
}

void ToggleShooter::Initialize() {
	shooter->Toggle();
}