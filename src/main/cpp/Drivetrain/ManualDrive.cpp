#include "Robot.h"
#include "Drivetrain/ManualDrive.h"


ManualDrive::ManualDrive(Drivetrain *drive, std::function<double()> y,
            	std::function<double()> rz) : 
				drive(drive), y(y), rz(rz) {
	AddRequirements(drive);
	cout << "Created ManualDrive\n";
}

ManualDrive::~ManualDrive() {
	cout << "Destructing ManualDrive\n";
}

void ManualDrive::Initialize() {
	cout << "Initialized ManualDrive\n";
}

void ManualDrive::Execute() {
	cout << "Executing start\n";
	drive->SetSpeed(y(), rz());
	cout << "Executing end\n";
}

void ManualDrive::End(bool interrupted) {
	cout << "Ending: " << interrupted << "\n";
}

bool ManualDrive::IsFinished() {
	cout << "IsFinished\n";
	return false;
}
