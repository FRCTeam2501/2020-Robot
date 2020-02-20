#pragma once;
#include "Utils/include.h"


using namespace frc;



class Pneumatics : public frc2::SubsystemBase 
{
private:
    
    Compressor *compressor;
    DoubleSolenoid *verticalifyer, *uppyWuppy, *intake;

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
};


