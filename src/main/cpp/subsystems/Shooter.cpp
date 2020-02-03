#include "subsystems/Shooter.h"

using namespace rev;

Shooter::Shooter(){

spinnyThrowerLeft = new CANSparkMax(CAN::SPINNYTHROWERLEFT,CANSparkMax::MotorType::kBrushless);
spinnyThrowerRight = new CANSparkMax(CAN::SPINNYTHROWERRIGHT,CANSparkMax::MotorType::kBrushless);
    spinnyThrowerLeft->GetPIDController().SetP(kP);
    spinnyThrowerLeft->GetPIDController().SetI(kI);
    spinnyThrowerLeft->GetPIDController().SetD(kD);
    spinnyThrowerLeft->GetPIDController().SetIZone(kIz);
    spinnyThrowerLeft->GetPIDController().SetFF(kFF);
    spinnyThrowerLeft->GetPIDController().SetOutputRange(kMinOutput, kMaxOutput);

    spinnyThrowerRight->GetPIDController().SetP(kP);
    spinnyThrowerRight->GetPIDController().SetI(kI);
    spinnyThrowerRight->GetPIDController().SetD(kD);
    spinnyThrowerRight->GetPIDController().SetIZone(kIz);
    spinnyThrowerRight->GetPIDController().SetFF(kFF);
    spinnyThrowerRight->GetPIDController().SetOutputRange(kMinOutput, kMaxOutput);
}


Shooter::~Shooter(){
delete spinnyThrowerLeft;
delete spinnyThrowerRight;
}

void Shooter::flywheleSpeed(double SetPoint){
    spinnyThrowerLeft->GetPIDController().SetReference(SetPoint, rev::ControlType::kVelocity);
    spinnyThrowerRight->GetPIDController().SetReference(SetPoint, rev::ControlType::kVelocity);
}