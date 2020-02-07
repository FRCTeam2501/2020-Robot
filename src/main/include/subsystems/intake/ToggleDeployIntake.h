#pragma once 

#include "Utils/include.h"
#include "subsystems/intake/Intake.h"

#include <frc2/command/CommandHelper.h> 
#include <frc2/command/InstantCommand.h> 

class ToggleDeployIntake
    : public frc2::CommandHelper<frc2::InstantCommand, 
                                ToggleDeployIntake>{ 
  public: 
  ToggleDeployIntake(Intake* subsystem);

      void Initialize() override;

      private:
      Intake *intake; 
  };
  