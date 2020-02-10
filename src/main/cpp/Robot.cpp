#include "Robot.h"


TylerRobot::TylerRobot() {
	container = new RobotContainer();
	autoCommand = nullptr;

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

void TylerRobot::AutonomousInit() {
	autoCommand = container->GetAutoCommand();

	if(autoCommand != nullptr) {
		autoCommand->Schedule();
	}
}

void TylerRobot::AutonomousPeriodic() {}

void TylerRobot::TeleopInit() {
	if(autoCommand != nullptr) {
		autoCommand->Cancel();
		autoCommand = nullptr;
	}
}

void TylerRobot::TeleopPeriodic() {}

void TylerRobot::TestPeriodic() {}


#ifndef RUNNING_FRC_TESTS
int main() {
	return frc::StartRobot<TylerRobot>();
}
#endif