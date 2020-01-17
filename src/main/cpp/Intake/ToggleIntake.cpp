#include "Intake/ToggleIntake.h"
using namespace frc;


ToggleIntake::ToggleIntake(Intake *intake) : intake(intake) {}

void ToggleIntake::Initialize() {
	intake->Toggle();
}