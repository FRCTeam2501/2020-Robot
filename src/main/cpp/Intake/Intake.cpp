#include "Intake/Intake.h"

void Intake::Periodic() {
    if(*running){
        if(*inverted){
            motorLeft->Set(*speed*-1);
        }
        else{
            motorLeft->Set(*speed);
        }
    }
    else{
        motorLeft->Set(0);
    }
 }

 Intake::Intake(Pneumatics *pneumatics) : pneumatics(pneumatics) {
    motorLeft = new WPI_TalonSRX(CAN::INTAKE_LEFT);
    motorRight = new WPI_TalonSRX(CAN::INTAKE_RIGHT);

   // motorLeft->SetInverted(true);
    motorRight->SetInverted(true);
    motorRight->Follow(*motorLeft);

    speed = new double(0.0);
    running = new bool(false);
    changed = new bool(false);
    inverted = new bool(false);

    motorLeft->ConfigContinuousCurrentLimit(CONSTANTS::INTAKE::CURRENT_LIMIT.to<double>());
    motorLeft->ConfigPeakCurrentLimit(CONSTANTS::INTAKE::PEAK_LIMIT.to<double>());
    motorLeft->ConfigPeakCurrentDuration(500);

    motorRight->ConfigContinuousCurrentLimit(CONSTANTS::INTAKE::CURRENT_LIMIT.to<double>());
    motorRight->ConfigPeakCurrentLimit(CONSTANTS::INTAKE::PEAK_LIMIT.to<double>());
    motorRight->ConfigPeakCurrentDuration(500);
 }


Intake::~Intake() {
    delete motorLeft;
    delete motorRight;
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