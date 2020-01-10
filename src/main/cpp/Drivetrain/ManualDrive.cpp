#include "Drivetrain/ManualDrive.h"
#include "Utils/include.h"
#include "Robot.h"

using namespace frc;

ManualDrive::ManualDrive() {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(Robot::drive);
}

// Called when the command is initially scheduled.
void ManualDrive::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ManualDrive::Execute() {
  Robot::drive->setSpeed(
    Robot::oi->getXSpeed(),
    Robot::oi->getZSpeed()
  );
  cout << "RUNNING\n";
}

// Called once the command ends or is interrupted.
void ManualDrive::End(bool interrupted) {}

// Returns true when the command should end.
bool ManualDrive::IsFinished() { return false; }