/*
*Thanks to the Hardwork and Dedication of all the 2501 Programmers
*Brian Alberg, "I haven't slept in days"
*Tony DeMars, "https://www.youtube.com/watch?v=dQw4w9WgXcQ"
*Parker Nelson, "my only inspiration was the robots movie with the thicc mom"
*Jacob Hagberg, "I don't know how to program"
*Maxwell Xiong, "I love the chinease"
*and Ethan Owens "What is C++?"
*Also, our sincere gratitute to our programming mentor,
*Tyler Seiford
*/

#include "Robot/Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>

using namespace frc;

Robot::Robot() {
  container = new RobotContainer();
  autoCommand = nullptr;
}
Robot::~Robot() {
  delete container;
}

void Robot::RobotInit() {

}

void Robot::RobotPeriodic() {
    frc2::CommandScheduler::GetInstance().Run();
    container->Periodic();
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::AutonomousInit() {
  if(autoCommand == nullptr){
    autoCommand = container->GitAutoCommand();
    autoCommand->Schedule();
  }
  container->InitalizeRobot();
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  if(autoCommand != nullptr){
    autoCommand->Cancel();
    autoCommand = nullptr;
  }
  else{
    container->InitalizeRobot();
  }
}

void Robot::TeleopPeriodic() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
