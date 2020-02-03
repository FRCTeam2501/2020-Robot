#include "Robot.h"
using namespace frc;


TylerRobot::TylerRobot() {
	container = new RobotContainer();
	cout << "Robot Booted!\n";
}

TylerRobot::~TylerRobot() {
	delete container;
}

void TylerRobot::RobotInit() {}

void TylerRobot::RobotPeriodic() {
	container->Periodic();
	frc2::CommandScheduler::GetInstance().Run();
}

void TylerRobot::DisabledInit() {}

void TylerRobot::DisabledPeriodic() {}

void TylerRobot::AutonomousInit() {}

void TylerRobot::AutonomousPeriodic() {}

void TylerRobot::TeleopInit() {}

void TylerRobot::TeleopPeriodic() {}

void TylerRobot::TestPeriodic() {}


#ifndef RUNNING_FRC_TESTS
int main() {
	return StartRobot<TylerRobot>();
}
#endif