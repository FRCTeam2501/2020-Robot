#pragma once 

#include "/Utils/include.h"
#include "Utils/Pneumatics.h"

using namespace frc; 

class Intake : public frc::SubsystemBase { 
public: 
    Intake();
    ~Intake();


    void Periodic(); 

private:
    PWMVictorSPX *motor;
    Pneumatics *pneumatics;

}
