#include "subsystems/Shooter.h"

using namespace rev;

Shooter::Shooter(){

spinnyThrower = new CANSparkMax(CAN::SPINNYTHROWER,CANSparkMax::MotorType::kBrushless);
//spinnyThrower is the motor controller for the flywhele.


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






