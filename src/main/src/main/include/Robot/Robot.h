#pragma once

#include <frc/TimedRobot.h>
#include <frc2/command/Command.h>

#include "Utils/include.h"
#include "RobotContainer/RobotContainer.h"

class Robot : public frc::TimedRobot {
 public:

  Robot();
  ~Robot();
  //constructs and destructs Robot
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
