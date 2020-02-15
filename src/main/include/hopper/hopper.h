#pragma once 
#include "Utils/include.h"
#include "subsystems/Pneumatics.h"

using namespace frc; 

class Hopper : public frc2::SubsystemBase { 
public: 

    Hopper(Pneumatics *pneumatics); 
    ~Hopper(); 

       void HopperToggle();
    void Periodic(); 
    void UppyWuppy(double speed);
    private:
   
   WPI_TalonSRX *hopper;
   
    Pneumatics *pneumatics;

};
