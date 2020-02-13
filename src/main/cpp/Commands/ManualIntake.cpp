#include "Commands/ManualIntake.h"


ManualIntake::ManualIntake(Intake* intake,
	std::function<double()> speed)
	: intake(intake), speed(speed) {
	AddRequirements(intake);
}

void ManualIntake::Execute() {
	intake->SetSpeed(speed());
}