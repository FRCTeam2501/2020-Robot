#pragma once 

#include "Utils/include.h"
#include "Pneumatics/Pneumatics.h"

using namespace frc; 
using namespace ctre::phoenix::motorcontrol::can;

class Intake : public frc2::SubsystemBase { 
public: 
  
    Intake(Pneumatics *pneumatics);
    ~Intake();

        void Toggledeploy();
        void IntakeSpeed (double x);

    void Periodic(); 

private:
    PWMVictorSPX *motor1, *motor2;
    Pneumatics *pneumatics;
};