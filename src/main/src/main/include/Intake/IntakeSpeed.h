#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "include.h"
#include "Subsystems/Intake.h"

using namespace frc;

class IntakeSpeed
    : public frc2::CommandHelper<frc2::CommandBase, IntakeSpeed> {
 public:
  	IntakeSpeed(Intake *subsystem, std::function<double()> intakeRC);
	  void Execute() override;
  
  private:
    Intake *intake;
    std::function<double()> intakeRC;
};
