#pragma once
#include "Utils/include.h"
#include "RobotContainer.h"
using namespace frc;

class Robot : public TimedRobot {

    public:

    Robot();
    ~Robot();
    void RobotInit();
    void RobotPeriodic();
    void DisabledInit();
    void Disableperiodic();
    void AutonomousInit();
    void AutonomousPeriodic();
    void TeleopInit();
    void TeleopPeriodic();
    void TestPeriodic();



private:

  RobotContainer *container;
};


























