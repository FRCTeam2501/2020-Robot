
#include "subsystems/intake/intake.h"

 void Intake::Periodic() {}

 Intake::Intake(Pneumatics *pneumatics) : pneumatics(pneumatics) {
    motor1 = new WPI_TalonSRX(CAN::front);
    motor2 = new WPI_TalonSRX(CAN::back);
    
 }


Intake::~Intake() {
    delete motor1;
    delete motor2;
    delete pneumatics;
}

void Intake::Toggledeploy(){
    pneumatics->ToggleIntake();
}

void Intake::IntakeSpeed (double x){
    motor1-> Set (x);
    motor2-> Set (x);
}
void Intake::intaketoggle(){
    *running = !*running; 
}
