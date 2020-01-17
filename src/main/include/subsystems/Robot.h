#pragma once
#include "Utils/include.h"
#include "RobotContainer.h"
using namespace frc;

class Robot : public timedRobot
{
    public:
    Robot();
    ~Robot();
    void RobotInit() override;
    void RobotPeriodic() override;
    void DisabledInit() override;
    void disableperiodic() override;
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;
};

Robot::Robot()
{
}

Robot::~Robot()
{
private:
  RobotContainer *container;

}


























