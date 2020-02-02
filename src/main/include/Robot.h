#pragma once
#include "include.h"
#include "RobotContainer.h"
using namespace frc;


class TylerRobot : public TimedRobot {
private:
	RobotContainer *container;

public:
	TylerRobot();
	~TylerRobot();

	void RobotInit() override;
	void RobotPeriodic() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;
};