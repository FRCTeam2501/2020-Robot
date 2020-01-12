#include "Drivetrain/ManualDrive.h"

ManualDrive::ManualDrive(Drivetrain* subsystem,
	std::function<double()> forward,
	std::function<double()> rotation)
		: drive{subsystem}, forward{forward}, rotation{rotation} {
	AddRequirements({subsystem});
}

void ManualDrive::Execute() {
	drive->ArcadeDrive(forward(), rotation());	
}