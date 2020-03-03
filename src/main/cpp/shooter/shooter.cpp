#include "Shooter/Shooter.h"

using namespace rev;
using namespace frc;
using namespace std;

Shooter::Shooter(){

spinnyShootyLeft = new CANSparkMax(CAN::SHOOTER_LEFT,CANSparkMax::MotorType::kBrushless);
spinnyShootyRight = new CANSparkMax(CAN::SHOOTER_RIGHT,CANSparkMax::MotorType::kBrushless);

    spinnyShootyLeft->GetPIDController().SetP(CONSTANTS::SHOOTER:: kP);
    spinnyShootyLeft->GetPIDController().SetI(CONSTANTS::SHOOTER:: kI);
    spinnyShootyLeft->GetPIDController().SetD(CONSTANTS::SHOOTER:: kD);
    spinnyShootyLeft->GetPIDController().SetIZone(CONSTANTS::SHOOTER:: kIz);
    spinnyShootyLeft->GetPIDController().SetFF(CONSTANTS::SHOOTER:: kFF);
    spinnyShootyLeft->GetPIDController().SetOutputRange(CONSTANTS::SHOOTER:: kMinOutput, CONSTANTS::SHOOTER::  kMaxOutput);

    spinnyShootyLeft->SetInverted(true);
    spinnyShootyRight->Follow (*spinnyShootyLeft, true);

    spinnyShootyLeft->SetSmartCurrentLimit(CONSTANTS::SHOOTER::CURRENT_LIMIT.to<double>());
    spinnyShootyRight->SetSmartCurrentLimit(CONSTANTS::SHOOTER::CURRENT_LIMIT.to<double>());

    spinnyShootyLeft->SetSecondaryCurrentLimit(100);
    spinnyShootyRight->SetSecondaryCurrentLimit(100);



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
        *rpm = 3800.0;
    } else {
        *rpm = 0.0;
    }

    spinnyShootyLeft->GetPIDController().SetReference(*rpm, rev::ControlType::kVelocity);
}

 void Shooter::moreSpeed(){
    if (*rpm <= 5650){
        *rpm += CONSTANTS::SHOOTER::adjustSpeed;
        spinnyShootyLeft->GetPIDController().SetReference(*rpm, rev::ControlType::kVelocity);
    }
 }

 void Shooter::lessSpeed(){
    if (*rpm >= -5650){
        *rpm -= CONSTANTS::SHOOTER::adjustSpeed;
        spinnyShootyLeft->GetPIDController().SetReference(*rpm, rev::ControlType::kVelocity);
    }
 }


void Shooter::Periodic() {
    SmartDashboard::PutNumber("Setpoint: ", *rpm);
    SmartDashboard::PutNumber("Speed: ", spinnyShootyLeft->GetEncoder().GetVelocity());
}