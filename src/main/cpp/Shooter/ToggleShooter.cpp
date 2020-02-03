#include "Shooter/ToggleShooter.h"
using namespace frc;


ToggleShooter::ToggleShooter(Shooter *shooter) : shooter(shooter) {
	AddRequirements(shooter);
	cout << "Created ToggleShooter\n";
}

void ToggleShooter::Initialize() {
	shooter->Toggle();
	cout << "Ran ToggleShooter::Initialize()\n";
}