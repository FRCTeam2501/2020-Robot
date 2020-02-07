#pragma once 

#include <frc2/command/CommandBase.h> 
#include <frc2/command/CommandHelper.h>
#include "subsystems/intake/intake.h"

#include "Utils/include.h"
class IntakeSpeed 
 
 :public frc2::CommandHelper<frc2::CommandBase, IntakeSpeed> { 
    public: 
        IntakeSpeed(Intake *subsystem, std::function<double()> intakeRC); 
        void Execute() override;
    private: 
    Intake *intake;
    std::function<double()> intakeRC;
  };