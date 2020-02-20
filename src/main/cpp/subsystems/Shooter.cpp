#include "subsystems/Shooter.h"


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


    rpm = new double(0);
}


Shooter::~Shooter(){
    delete spinnyShootyLeft;
    delete spinnyShootyRight;
}

void Shooter::flywheleSpeed(double SetPoint){
    //spinnyShootyLeft->GetPIDController().SetReference(SetPoint, rev::ControlType::kVelocity);

}

void Shooter::Toggle(){
    toggle = !toggle;

    if (toggle) {
        *rpm = 3900.0;
    } else {
        *rpm = 0.0;
    }

    spinnyShootyLeft->GetPIDController().SetReference(*rpm, rev::ControlType::kVelocity);
}

 void Shooter::moreSpeed(){
    if (*rpm <= 5650){
<<<<<<< HEAD
<<<<<<< HEAD
        *rpm + CONSTANTS::SHOOTER::adjustSpeed;
        spinnyShootyLeft->GetPIDController().SetReference(*rpm, rev::ControlType::kVelocity);
=======
        *rpm += CONSTANTS::SHOOTER::adjustSpeed;
>>>>>>> 4812a405f9e9237e4bf308398b2be8904bc45ad1
=======
        *rpm += CONSTANTS::SHOOTER::adjustSpeed;
>>>>>>> 4812a405f9e9237e4bf308398b2be8904bc45ad1
    }
 }

 void Shooter::lessSpeed(){
    if (*rpm >= -5650){
        *rpm -= CONSTANTS::SHOOTER::adjustSpeed;
    }
 }


void Shooter::Periodic() {
    SmartDashboard::PutNumber("Setpoint: ", *rpm);
    SmartDashboard::PutNumber("Speed: ", spinnyShootyLeft->GetEncoder().GetVelocity());
}