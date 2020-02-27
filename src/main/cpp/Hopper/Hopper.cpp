#include "Hopper/Hopper.h"

void Hopper::Periodic() {
    
}

Hopper::Hopper(Pneumatics *pneumatics) : pneumatics(pneumatics) { 
    hopper = new WPI_TalonSRX(CAN::HOPPER);

    hopper->ConfigContinuousCurrentLimit(CONSTANTS::HOPPER::CURRENT_LIMIT.to<double>());
    hopper->ConfigPeakCurrentLimit(CONSTANTS::HOPPER::PEAK_LIMIT.to<double>());
    hopper->ConfigPeakCurrentDuration(500);
}

Hopper::~Hopper() { 
    delete hopper;
}

void Hopper::HopperToggle(){
    pneumatics->ToggleHopper();
}

void Hopper::UppyWuppy(double speed){
    hopper->Set(speed);
}

void Hopper::NoPin(double speed){

}

