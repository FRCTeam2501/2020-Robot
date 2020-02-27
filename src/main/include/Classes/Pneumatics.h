#pragma once

#include "include.h"
using namespace frc;



class Pneumatics : public ErrorBase {
private:
    
    Compressor *compressor;
    DoubleSolenoid *VerticalLift, *Climb, *Intake, *hopper;

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

    void ToggleIntake();

    void ToggleHopper();
};
