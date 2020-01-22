#pragma once
#include "Utils/include.h"
#include "Drivetrain/Drivetrain.h"  
#include "frc2/command/CommandHelper.h"

using namespace frc;


class ManualDrive
   : public frc2::CommandHelper<frc2::CommandBase, ManualDrive> {
private:
    
    Drivetrain *drive;
    std::function<double()> x;
    std::function<double()> y;
    
public:

    ManualDrive(Drivetrain* subsystem, 
    std::function<double()> y,
	std::function<double()> x);
    void Execute() override;
         
};

   





