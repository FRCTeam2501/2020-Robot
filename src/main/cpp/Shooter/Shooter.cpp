#include "Shooter/Shooter.h"


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
    spinnyShootyRight->Follow(*spinnyShootyLeft, true);


    rpm = new double(0);
}


Shooter::~Shooter(){
    delete spinnyShootyLeft;
    delete spinnyShootyRight;
}

void Shooter::flywheleSpeed(double SetPoint){
    spinnyShootyLeft->GetPIDController().SetReference(SetPoint, rev::ControlType::kVelocity);
}

void Shooter::Toggle(){
    toggle = !toggle;

    if (toggle) {
        *rpm = 4500.0;
    } else {
        *rpm = 0.0;
    }
    wpi::outs() << "toggle: " << *rpm << " " << toggle << "\n";
    spinnyShootyLeft->GetPIDController().SetReference(*rpm, rev::ControlType::kVelocity);
}

 void Shooter::moreSpeed(){
    if (*rpm <= 5650){
        *rpm += CONSTANTS::SHOOTER::adjustSpeed_RPM.to<double>();
        spinnyShootyLeft->GetPIDController().SetReference(*rpm, rev::ControlType::kVelocity);

    }
 }

 void Shooter::lessSpeed(){
    if (*rpm >= -5650){
        *rpm -= CONSTANTS::SHOOTER::adjustSpeed_RPM.to<double>();
        spinnyShootyLeft->GetPIDController().SetReference(*rpm, rev::ControlType::kVelocity);

    }
 }


void Shooter::Periodic() {
    SmartDashboard::PutNumber("Setpoint: ", *rpm);
    SmartDashboard::PutNumber("Speed: ", spinnyShootyLeft->GetEncoder().GetVelocity());
}