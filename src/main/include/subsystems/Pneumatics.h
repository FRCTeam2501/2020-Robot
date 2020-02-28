#pragma once;
#include "Utils/include.h"


using namespace frc;



class Pneumatics : public frc2::SubsystemBase 
{
private:
    
    Compressor *compressor;
    DoubleSolenoid *verticalifyer, *uppyWuppy, *intake, *shootyStoppy;

public:
    Pneumatics();
    ~Pneumatics();
    void InitPneumatics();
    void DisableAll();
    void verticalifyerExtend();
    void verticalifyerRetract();
    void uppyWuppyExtend();
    void uppyWuppyRetract();
    void intakeExtend();
    void intakeRetract();
    void pistonsExtend();
    void pistonsRetract();
    
    
};



