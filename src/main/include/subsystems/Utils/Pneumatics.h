#pragma once

#include "subsystems/Utils/include.h"


using namespace frc;



class Pneumatics : public frc2::SubsystemBase 
{
private:
    
    Compressor *compressor;
    DoubleSolenoid *VerticalLift, *Climb;

public:
    Pneumatics();
    ~Pneumatics();
    void InitPneumatics();
    void DisableAll();
    void VerticalLiftExtend();
    void VerticalLiftRetract();
    void ClimbExtend();
    void ClimbRetract();
    void ToggleVert();
    void ToggleClimb();
};
