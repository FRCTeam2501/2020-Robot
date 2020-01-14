#include "Robot.h"
using namespace frc;


Robot::Robot() {
	container = new RobotContainer();
}

Robot::~Robot() {
	delete container;
}

void Robot::RobotInit() {}

void Robot::RobotPeriodic() {
	frc2::CommandScheduler::GetInstance().Run();
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {}

void Robot::TestPeriodic() {}


#ifndef RUNNING_FRC_TESTS
int main() {
	return StartRobot<Robot>();
}
#endif