#include "Robot.h"

RobotContainer *Robot::robit;

Robot::Robot() {
	robit = new RobotContainer();
	cout << "Built container\n";
}

Robot::~Robot() {
	delete robit;
}

void Robot::RobotInit() {
	//
}

void Robot::RobotPeriodic() {
	cout << "Starting run\n";
	//frc2::CommandScheduler::GetInstance().Enable();
	//cout << "Enabled\n";
	frc2::CommandScheduler::GetInstance().Run();
	cout << "Ending run\n";
}

void Robot::DisabledInit() {
	//
}

void Robot::DisabledPeriodic() {
	//
}

void Robot::AutonomousInit() {
	//
}

void Robot::AutonomousPeriodic() {
	//
}

void Robot::TeleopInit() {
	//
}

void Robot::TeleopPeriodic() {
	//
}

void Robot::TestPeriodic() {

}

#ifndef RUNNING_FRC_TESTS
int main() {
	return frc::StartRobot<Robot>();
}
#endif
