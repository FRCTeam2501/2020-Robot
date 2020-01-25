#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>
#include "Utils/include.h"
#include "Pneumatics/Pneumatics.h"

class ToggleVert
    : public frc2::CommandHelper<frc2::InstantCommand,
                                 ToggleVert> {
 public:
  ToggleVert(Pneumatics *subsystem);

  void Initialize() override;

  private:
    Pneumatics *pneu; 
};
