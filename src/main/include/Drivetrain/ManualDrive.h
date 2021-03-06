#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "Utils/include.h"
#include "Drivetrain/Drivetrain.h"

using namespace frc;

class ManualDrive
    : public frc2::CommandHelper<frc2::CommandBase, ManualDrive> {
 public:
  	ManualDrive(Drivetrain *subsystem, std::function<double()> forward,
			std::function<double()> rotation);
	  void Execute() override;
  
  private:
    Drivetrain *drive;
    std::function<double()> forward;
	  std::function<double()> rotation;
};
