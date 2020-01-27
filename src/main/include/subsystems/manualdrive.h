#pragma once 
#include "Utils/include.h"
#include "Drivetrain/Drivetrain.h"
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
using namespace frc;
class manualdrive
: public frc2::CommandHelper<frc2::CommandBase, manualdrive>{  
public:
manualdrive(Drivetrain *subsystem, std::function<double()> forward,
 std::function<double()> rotation);
 void Execute() override;
 private:
 Drivetrain *drive;
 std::function<double()> forward;
 std::function<double()>rotation;
};