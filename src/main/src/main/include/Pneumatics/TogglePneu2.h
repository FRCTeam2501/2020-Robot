#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>
#include "Utils/include.h"
#include "Pneumatics/Pneumatics.h"

class ToggleClimb
    : public frc2::CommandHelper<frc2::InstantCommand,
                                 ToggleClimb> {
 public:
  ToggleClimb(Pneumatics *subsystem);

  void Initialize() override;

  private:
    Pneumatics *pneu2;
};
