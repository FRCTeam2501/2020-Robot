#include "subsystems/hopper/hopper.h"
#include "Utils/include.h"
#include "Utils/ports.h"

void Hopper::Periodic() {}

Hopper::Hopper() { 
    frontmotor = new PWMVictorSPX(PWM :: frontmotor);
    backmotor = new PWMVictorSPX(PWM :: backmotor);
    pneumatics = new Pneumatics(); 


}

Hopper::~Hopper() { 
    delete frontmotor;
    delete backmotor;
    delete pneumatics; 
} 

void Hopper::hoppertoggle(){

}
//start motor 
//stop motor 
//open the the gate dumbshit
//close it dummy

