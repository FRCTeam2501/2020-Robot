#pragma once
#include "include.h"
#include "RobotContainer.h"
using namespace frc;


class Robot : public TimedRobot {
public:
	Robot();
	~Robot();
	void RobotInit() override;
	void RobotPeriodic() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;

private:
	RobotContainer *container;
};