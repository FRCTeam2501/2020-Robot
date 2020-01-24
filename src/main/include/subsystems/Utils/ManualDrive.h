#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "utils/include.h"
#include "Drivetrain/Drivetrain.h"

using namespace frc;

class ManualDrive 
    : public frc2::CommandHelper<frc2::CommandBase, ManualDrive> {
public: 
                ManualDrive(Drivetrain *subsystem, std::function<double()>forward,
                                std::function<double()>rotation); 
                    void Exucute() override;

                    private: 
                        Drivetrain *drive; 
                        std::fuction<double()> forward;
                            std::function<double()>rotation:

    };