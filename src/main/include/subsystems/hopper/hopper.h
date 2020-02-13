#pragma once 
#include "Utils/include.h"
#include "subsystems/Pneumatics.h"

using namespace frc; 

class Hopper : public frc2::SubsystemBase { 
public: 

    Hopper(); 
    ~Hopper(); 

       void hoppertoggle();
    void Periodic(); 

    private:
   // WPI_TalonSRX *motor;
   PWMVictorSPX *frontmotor;
   PWMVictorSPX *backmotor;
    Pneumatics *pneumatics;

};