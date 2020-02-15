

#include "RobotContainer.h"
#include "Constants.h"
#include "frc2/command/ParallelRaceGroup.h"
#include "subsystems/drivetrain.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {

  return &m_autonomousCommand;
}
/*void autocommand(){
  new frc2::ParallelRaceGroup( 
 frc::WaitCommand(AutoConstants::AUTO_TIME),
 frc::StartEndCommand(
   [this]{
     drive->ArcadeDrive(AutoConstants::AUTO_SPEED, 0.0);
   },
   [this]{
     drive->ArcadeDrive(0.0, 0.0);
   },
   {drive}
 )
);*/
//}