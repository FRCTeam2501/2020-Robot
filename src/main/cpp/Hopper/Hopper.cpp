#include "Hopper/Hopper.h"

void Hopper::Periodic() {}

Hopper::Hopper(Pneumatics *pneumatics) : pneumatics(pneumatics) { 
    hopper = new PWMVictorSPX(CAN::HOPPER);
    
}

Hopper::~Hopper() { 
    delete hopper;
}

void Hopper::HopperToggle(){
    pneumatics->ToggleHopper();
}

void Hopper::UppyWuppy(double speed){
    hopper->Set(speed);
    wpi::outs() << "UppyWuppy: " << speed << "\n";
}

