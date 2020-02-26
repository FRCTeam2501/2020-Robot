#include "Intake/Intake.h"

 void Intake::Periodic() {}

 Intake::Intake(Pneumatics *pneumatics) : pneumatics(pneumatics) {
    motor1 = new WPI_TalonSRX(CAN::INTAKE_LEFT);
    motor2 = new WPI_TalonSRX(CAN::INTAKE_RIGHT);
 }


Intake::~Intake() {
    delete motor1;
    delete motor2;
    delete pneumatics;
}

void Intake::Toggledeploy(){
    pneumatics->ToggleIntake();
}

void Intake::IntakeSpeed(double x){
    *speed = x;
}

void Intake::IntakeToggle(){
    *running = !*running; 
}

void Intake::IntakeInvert(){
    *inverted = !*inverted;
}

void Intake::Periodic(){
    
}