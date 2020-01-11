#include "commands/DefaultDrive.h"

DefaultDrive::DefaultDrive(DriveSubsystem* subsystem,
	std::function<double()> forward,
	std::function<double()> rotation)
		: drive{subsystem}, forward{forward}, rotation{rotation} {
	AddRequirements({subsystem});
}

void DefaultDrive::Execute() {
	drive->ArcadeDrive(forward(), rotation());	
}