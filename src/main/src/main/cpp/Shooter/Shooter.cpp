#include "Subsystems/Shooter.h"

using namespace rev;

Shooter::Shooter() {

    flyWheel = new CANSparkMax(CAN::SHOOTER_LEFT, CANSparkMax::MotorType::kBrushless);
    
    flyWheel->SetInverted(true);

    flyWheel->GetPIDController().SetP(ShooterConstants::kP);
    flyWheel->GetPIDController().SetI(ShooterConstants::kI);
    flyWheel->GetPIDController().SetD(ShooterConstants::kD);
    flyWheel->GetPIDController().SetIZone(ShooterConstants::kIz);
    flyWheel->GetPIDController().SetFF(ShooterConstants::kFF);
    flyWheel->GetPIDController().SetOutputRange(ShooterConstants::kMinOutput, ShooterConstants::kMaxOutput);


    flyWheel2 = new CANSparkMax(CAN::SHOOTER_RIGHT, CANSparkMax::MotorType::kBrushless);

    flyWheel2->SetInverted(false);
    
    flyWheel2->GetPIDController().SetP(ShooterConstants::kP);
    flyWheel2->GetPIDController().SetI(ShooterConstants::kI);
    flyWheel2->GetPIDController().SetD(ShooterConstants::kD);
    flyWheel2->GetPIDController().SetIZone(ShooterConstants::kIz);
    flyWheel2->GetPIDController().SetFF(ShooterConstants::kFF);
    flyWheel2->GetPIDController().SetOutputRange(ShooterConstants::kMinOutput, ShooterConstants::kMaxOutput);    


    flyWheel2->Follow(*flyWheel);
    flyWheel->GetEncoder().GetVelocityConversionFactor();

    wpi::outs() << "shooter made\n";
}
Shooter::~Shooter(){
    delete flyWheel;
}

void Shooter::FlyWheelSet(double SetPoint){
    flyWheel->GetPIDController().SetReference(SetPoint, rev::ControlType::kVelocity);
    flyWheel2->GetPIDController().SetReference(SetPoint, rev::ControlType::kVelocity);
}

void Shooter::Periodic() {
    if(frc2::GetTime() - last > units::time::second_t(0.1)) {
        wpi::outs() << flyWheel->GetEncoder().GetVelocity() << "\n";
        last = frc2::GetTime();
    }
}


void Shooter::ToggleShoot(){
    wpi::outs() << "toggle shoot\n";
    if(toggleShoot){
        toggleShoot = false;
        FlyWheelSet(0);
    }
    else{
        toggleShoot = true;
        FlyWheelSet(5000);
    }
}