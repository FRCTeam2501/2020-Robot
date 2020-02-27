#pragma once 

#include "include.h"
#include "Classes/Pneumatics.h"

using namespace frc; 
using namespace ctre::phoenix::motorcontrol::can;

class Intake : public frc2::SubsystemBase { 
public: 
  
    Intake(Pneumatics *pneumatics);
    ~Intake();

        void Toggledeploy();
        void IntakeSpeed(double x);
        void IntakeToggle();
        void IntakeInvert();

        bool GetRunning(){
            return *running;
        }

        bool GetInverted(){
            return *inverted;
        }

        void Periodic(); 

private:
    WPI_TalonSRX *motorLeft, *motorRight;
    Pneumatics *pneumatics;
    bool *running, *changed, *inverted;
    double *speed;
};
