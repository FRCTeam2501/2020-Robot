#include "Shooter/Shooter.h"

using namespace rev;

Shooter::Shooter() {
    flyWheel = new CANSparkMax(CAN::FLY_WHEEL,CANSparkMax::MotorType::kBrushless);

    flyWheel->GetPIDController().SetP(ShooterConstants::kP);
    flyWheel->GetPIDController().SetI(ShooterConstants::kI);
    flyWheel->GetPIDController().SetD(ShooterConstants::kD);
    flyWheel->GetPIDController().SetIZone(ShooterConstants::kIz);
    flyWheel->GetPIDController().SetFF(ShooterConstants::kFF);
    flyWheel->GetPIDController().SetOutputRange(ShooterConstants::kMinOutput, ShooterConstants::kMaxOutput);
}
Shooter::~Shooter(){
    delete flyWheel;
}

void Shooter::FlyWheelSet(double SetPoint){
    flyWheel->GetPIDController().SetReference(SetPoint, rev::ControlType::kVelocity);
}

