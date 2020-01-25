#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>
#include "Utils/include.h"
#include "Drivetrain/Drivetrain.h"

class SwitchDirection
    : public frc2::CommandHelper<frc2::InstantCommand,
                                 SwitchDirection> {
 public:
  SwitchDirection(Drivetrain *subsystem);

  void Initialize() override;

  private:
    Drivetrain *drive;
};
