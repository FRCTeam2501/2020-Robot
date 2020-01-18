#include "Drivetrain/ToggleDrive.h"
using namespace frc;


ToggleDrive::ToggleDrive(Drivetrain *drive) : drive(drive) {}

void ToggleDrive::Initialize() {
	drive->ToggleInverted();
}