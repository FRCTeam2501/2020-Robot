#pragma once
#include "Utils/include.h"


using namespace rev;


class Shooter : public frc2::SubsystemBase 
{
private:
    CANSparkMax *spinnyThrowerLeft, *spinnyThrowerRight;
        //spinnyThrower is the motor controller for the flywhele.
    
    const double MaxRPM = 5700;
    bool Toggle = 0;    
    double rpm, adjustSpeed = 50;
public:
    Shooter();
    ~Shooter();
    void flywheleSpeed(double SetPoint);
    void toggle();
    void moreSpeed();
    void lessSpeed();

};
