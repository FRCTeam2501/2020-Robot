#include "subsystems/Shooter.h"

using namespace rev;

Shooter::Shooter(){

spinnyThrowerLeft = new CANSparkMax(CAN::SPINNYTHROWERLEFT,CANSparkMax::MotorType::kBrushless);

    spinnyThrowerLeft->GetPIDController().SetP(kP);
    spinnyThrowerLeft->GetPIDController().SetI(kI);
    spinnyThrowerLeft->GetPIDController().SetD(kD);
    spinnyThrowerLeft->GetPIDController().SetIZone(kIz);
    spinnyThrowerLeft->GetPIDController().SetFF(kFF);
    spinnyThrowerLeft->GetPIDController().SetOutputRange(kMinOutput, kMaxOutput);

    spinnyThrowerRight->Follow (*spinnyThrowerLeft);
}


Shooter::~Shooter(){
delete spinnyThrowerLeft;
delete spinnyThrowerRight;
}

void Shooter::flywheleSpeed(double SetPoint){
    spinnyThrowerLeft->GetPIDController().SetReference(SetPoint, rev::ControlType::kVelocity);
    spinnyThrowerRight->GetPIDController().SetReference(SetPoint, rev::ControlType::kVelocity);
}