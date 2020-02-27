#include "include.h"
#include "Subsystems/Intake.h"

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>

class ToggleDeployIntake
    : public frc2::CommandHelper<frc2::InstantCommand,
                                 ToggleDeployIntake> {
 public:
  ToggleDeployIntake(Intake* subsytem);

  void Initialize() override;

 private:
  Intake *intake;
};
