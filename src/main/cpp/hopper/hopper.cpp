#include "hopper/hopper.h"

void Hopper::Periodic() {}

Hopper::Hopper(Pneumatics *pneumatics) : pneumatics(pneumatics) { 
    hopper = new WPI_TalonSRX(PWM::Hopper);
    
}

Hopper::~Hopper() { 
    delete hopper;
}

void Hopper::HopperToggle(){
    pneumatics->ToggleHopper();
}

void Hopper::UppyWuppy(double x){
    hopper->Set(x);         
    }

