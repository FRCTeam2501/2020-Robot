#include "Intake/ReverseIntake.h"
using namespace frc;


ReverseIntake::ReverseIntake(Intake *intake) : intake(intake) {}

void ReverseIntake::Initialize() {
	intake->ToggleInverted();
}

void ReverseIntake::End(bool interrupted) {
	intake->ToggleInverted();
}