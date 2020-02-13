#include "Commands/ManualDrive.h"


ManualDrive::ManualDrive(Drivetrain* drive,
	std::function<double()> y,
	std::function<double()> rz)
	: drive(drive), y(y), rz(rz) {
	AddRequirements(drive);
}

void ManualDrive::Execute() {
	drive->ArcadeDrive(y(), rz());
}