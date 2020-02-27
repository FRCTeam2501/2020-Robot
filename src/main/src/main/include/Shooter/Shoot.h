#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "Subsystems/Shooter.h"

#include "include.h"

class Shoot
    : public frc2::CommandHelper<frc2::CommandBase, Shoot> {
 public:
  Shoot(Shooter *subsystem);

  void Initialize() override;

  private:
    Shooter *shoot;
};
