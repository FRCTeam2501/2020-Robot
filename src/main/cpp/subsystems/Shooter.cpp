#include "subsystems/Shooter.h"

using namespace rev;


Shooter::Shooter(){

spinnyShootyLeft = new CANSparkMax(CAN::SHOOTER_LEFT,CANSparkMax::MotorType::kBrushless);
spinnyShootyRight = new CANSparkMax(CAN::SHOOTER_RIGHT,CANSparkMax::MotorType::kBrushless);

    spinnyShootyLeft->GetPIDController().SetP(CONSTANTS::SHOOTER:: kP);
    spinnyShootyLeft->GetPIDController().SetI(CONSTANTS::SHOOTER:: kI);
    spinnyShootyLeft->GetPIDController().SetD(CONSTANTS::SHOOTER:: kD);
    spinnyShootyLeft->GetPIDController().SetIZone(CONSTANTS::SHOOTER:: kIz);
    spinnyShootyLeft->GetPIDController().SetFF(CONSTANTS::SHOOTER:: kFF);
    spinnyShootyLeft->GetPIDController().SetOutputRange(CONSTANTS::SHOOTER:: kMinOutput, CONSTANTS::SHOOTER::  kMaxOutput);

    spinnyShootyRight->Follow (*spinnyShootyLeft);

    rpm = new double; 
}


Shooter::~Shooter(){
    delete spinnyShootyLeft;
    delete spinnyShootyRight;
}

void Shooter::flywheleSpeed(double SetPoint){
    spinnyShootyLeft->GetPIDController().SetReference(SetPoint, rev::ControlType::kVelocity);

}

void Shooter::Toggle(){

    if (toggle){
        toggle = 0;
    } else {
        toggle = 1;
    }

    if (toggle){

        *rpm = 3900; 

        spinnyShootyLeft->GetPIDController().SetReference(*rpm, rev::ControlType::kVelocity);
        toggle = false;
    } else {
        double *rpm = 0;
        spinnyShootyLeft->GetPIDController().SetReference(*rpm, rev::ControlType::kVelocity);
    }
}

 void Shooter::moreSpeed(){
    if (*rpm <= 5650){
        *rpm + CONSTANTS::SHOOTER::adjustSpeed ;
        spinnyShootyLeft->GetPIDController().SetReference(*rpm, rev::ControlType::kVelocity);
    }
 }

 void Shooter::lessSpeed(){
    if (*rpm >= -5650){
        *rpm - CONSTANTS::SHOOTER::adjustSpeed;
        spinnyShootyLeft->GetPIDController().SetReference(*rpm, rev::ControlType::kVelocity);
    }
 }
