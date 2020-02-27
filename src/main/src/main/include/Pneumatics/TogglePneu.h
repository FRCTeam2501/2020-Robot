#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>
#include "include.h"
#include "Classes/Pneumatics.h"

class ToggleVert
    : public frc2::CommandHelper<frc2::InstantCommand,
                                 ToggleVert> {
 public:
  ToggleVert(Pneumatics *subsystem);

  void Initialize() override;

  private:
    Pneumatics *pneu; 
};
