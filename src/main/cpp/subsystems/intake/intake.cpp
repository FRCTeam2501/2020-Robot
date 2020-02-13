
#include "subsystems/intake/intake.h"
#include "Utils/include.h" 

 void Intake::Periodic() {}

 Intake::Intake() {
    motor = new PWMVictorSPX(PWM::motor);
    pneumatics = new Pneumatics();
 }


Intake::~Intake() {
    delete motor;
    delete pneumatics;
}

void Intake::Toggledeploy(){
    //pneumatics->intake
}
void Intake::IntakeSpeed (double x){
    motor-> Set (x);
}
