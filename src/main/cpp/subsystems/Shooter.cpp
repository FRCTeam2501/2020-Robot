#include "subsystems/Shooter.h"

using namespace rev;


Shooter::Shooter(){

spinnyThrowerLeft = new CANSparkMax(CAN::SHOOTER_LEFT,CANSparkMax::MotorType::kBrushless);
spinnyThrowerRight = new CANSparkMax(CAN::SHOOTER_RIGHT,CANSparkMax::MotorType::kBrushless);

    spinnyThrowerLeft->GetPIDController().SetP(CONSTANTS::SHOOTER:: kP);
    spinnyThrowerLeft->GetPIDController().SetI(CONSTANTS::SHOOTER:: kI);
    spinnyThrowerLeft->GetPIDController().SetD(CONSTANTS::SHOOTER:: kD);
    spinnyThrowerLeft->GetPIDController().SetIZone(CONSTANTS::SHOOTER:: kIz);
    spinnyThrowerLeft->GetPIDController().SetFF(CONSTANTS::SHOOTER:: kFF);
    spinnyThrowerLeft->GetPIDController().SetOutputRange(CONSTANTS::SHOOTER:: kMinOutput, CONSTANTS::SHOOTER::  kMaxOutput);

    spinnyThrowerRight->Follow (*spinnyThrowerLeft);

    rpm = new double; 
}


Shooter::~Shooter(){
    delete spinnyThrowerLeft;
    delete spinnyThrowerRight;
}

void Shooter::flywheleSpeed(double SetPoint){
    spinnyThrowerLeft->GetPIDController().SetReference(SetPoint, rev::ControlType::kVelocity);

}

void Shooter::Toggle(){

    if (toggle){
        toggle = 0;
    } else {
        toggle = 1;
    }

    if (toggle){

        *rpm = 3900; 

        spinnyThrowerLeft->GetPIDController().SetReference(*rpm, rev::ControlType::kVelocity);
        toggle = false;
    } else {
        double *rpm = 0;
        spinnyThrowerLeft->GetPIDController().SetReference(*rpm, rev::ControlType::kVelocity);
    }
}

 void Shooter::moreSpeed(){
    if (*rpm <= 5650){
        *rpm + CONSTANTS::SHOOTER::adjustSpeed ;
        spinnyThrowerLeft->GetPIDController().SetReference(*rpm, rev::ControlType::kVelocity);
    }
 }

 void Shooter::lessSpeed(){
    if (*rpm >= -5650){
        *rpm - CONSTANTS::SHOOTER::adjustSpeed;
        spinnyThrowerLeft->GetPIDController().SetReference(*rpm, rev::ControlType::kVelocity);
    }
 }
