#include "Drivetrain/ManualDrive.h"
using namespace frc;


ManualDrive::ManualDrive(Drivetrain* subsystem,
	std::function<double()> y,
	std::function<double()> rz)
	: drive(subsystem), y(y), rz(rz) {
	AddRequirements(subsystem);
}

void ManualDrive::Execute() {
	drive->ArcadeDrive(y(), rz());	
}