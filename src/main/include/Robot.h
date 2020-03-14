#pragma once
#include "include.h"
#include "RobotContainer.h"


class TylerRobot : public frc::TimedRobot {
private:
	/*
	 *	The robot container "contains" all subsystems and sets up all buttons.
	 */
	RobotContainer *container;
	frc2::Command *autoCommand;

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