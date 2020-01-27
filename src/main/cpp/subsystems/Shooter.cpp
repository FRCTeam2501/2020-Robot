#include "subsystems/Shooter.h"

using namespace rev;

Shooter::Shooter(){

spinnyThrower = new CANSparkMax(CAN::SPINNYTHROWER,CANSparkMax::MotorType::kBrushless);

    spinnyThrower->GetPIDController().SetP(kP);
    spinnyThrower->GetPIDController().SetI(kI);
    spinnyThrower->GetPIDController().SetD(kD);
    spinnyThrower->GetPIDController().SetIZone(kIz);
    spinnyThrower->GetPIDController().SetFF(kFF);
    spinnyThrower->GetPIDController().SetOutputRange(kMinOutput, kMaxOutput);

}


Shooter::~Shooter(){
delete spinnyThrower;

}

void Shooter::flywheleSpeed(double SetPoint){
    spinnyThrower->GetPIDController().SetReference(SetPoint, rev::ControlType::kVelocity);

}