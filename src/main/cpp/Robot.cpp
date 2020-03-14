#include "Robot.h"


TylerRobot::TylerRobot() {
	//	Create a new robot container.
	container = new RobotContainer();
	autoCommand = nullptr;

	cout << "Robot Booted!\n";
}

TylerRobot::~TylerRobot() {
	//	Delete the robot container.
	delete container;
}

void TylerRobot::RobotInit() {}

void TylerRobot::RobotPeriodic() {
	//	Run the container's periodic function.
	container->Periodic();

	//	Run the scheduler.
	frc2::CommandScheduler::GetInstance().Run();
}

void TylerRobot::DisabledInit() {}

void TylerRobot::DisabledPeriodic() {}

void TylerRobot::AutonomousInit() {
	//	Get the auto command from the robot container.
	autoCommand = container->GetAutoCommand();

	//	If the auto command is not null, start it.
	if(autoCommand != nullptr) {
		autoCommand->Schedule();
	}
}

void TylerRobot::AutonomousPeriodic() {}

void TylerRobot::TeleopInit() {
	//	If the auto command is not null, stop it.
	if(autoCommand != nullptr) {
		autoCommand->Cancel();
		autoCommand = nullptr;
	}
}

void TylerRobot::TeleopPeriodic() {}

void TylerRobot::TestPeriodic() {}


#ifndef RUNNING_FRC_TESTS
int main() {
	//	Screw around with HAL usage reporting.
	cout << HAL_Report(HALUsageReporting::kResourceType_Language, 7, 0, "Assembly time!") << " " << HAL_Report(HALUsageReporting::kResourceType_Framework, HALUsageReporting::kFramework_ROS, 0, "ROS time!") << " " << HAL_Report(HALUsageReporting::kResourceType_Kinematics, HALUsageReporting::kKinematics_SwerveDrive, 0, "Swervy time!") << " " << HAL_Report(HALUsageReporting::kResourceType_Odometry, HALUsageReporting::kOdometry_SwerveDrive, 0, "Curvy time!");
	return frc::StartRobot<TylerRobot>();
}
#endif