#pragma once
#include "Utils/include.h"


using namespace rev;


class Shooter : public frc2::SubsystemBase 
{
private:
    CANSparkMax *spinnyThrowerLeft, *spinnyThrowerRight;
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

};
 