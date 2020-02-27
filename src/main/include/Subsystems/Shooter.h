#pragma once
#include "include.h"


using namespace rev;
using namespace frc;

class Shooter : public frc2::SubsystemBase 
{
private:
    CANSparkMax *spinnyShootyLeft, *spinnyShootyRight;
        //spinnyThrower is the motor controller for the flywhele.
    
    bool toggle = 0;    
    double *rpm;
public:
    Shooter();
    ~Shooter();
    void flywheleSpeed(double SetPoint);
    void Toggle();
    void moreSpeed();
    void lessSpeed();

    void Periodic();
};
 