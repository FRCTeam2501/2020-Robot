#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "Utils/include.h"
#include "Climber/Climber.h"

class VariableSpeed
    : public frc2::CommandHelper<frc2::CommandBase, VariableSpeed> {
 public:
  VariableSpeed(Climber *subsystem, std::function<double()> speed);
  
  void Execute() override;
  
 private:
  Climber *climber;
  std::function<double()> speed;
};