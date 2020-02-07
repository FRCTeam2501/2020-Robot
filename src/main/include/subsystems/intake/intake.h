#pragma once 

#include "Utils/include.h"
#include "subsystems/Pneumatics.h"

using namespace frc; 

class Intake : public frc2::SubsystemBase { 
public: 
  
    Intake();
    ~Intake();

        void Toggledeploy();
        void IntakeSpeed (double x);

    void Periodic(); 

private:
    PWMVictorSPX *motor;
    Pneumatics *pneumatics;

};
