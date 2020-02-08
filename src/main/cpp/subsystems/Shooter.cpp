#include "subsystems/Shooter.h"

using namespace rev;

Shooter::Shooter(){

spinnyThrowerLeft = new CANSparkMax(CAN::SHOOTER_LEFT,CANSparkMax::MotorType::kBrushless);

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
  
}

void Shooter::toggle(){

if (Toggle = 1){
     Toggle = 0;
}else {
    if(Toggle = 0){
     Toggle = 1;
    }
}

if (Toggle = true){

double rpm = 3900; 

 set(double rpm, rev::ControlType::kVelocity);
 Toggle = false;
} else {
   double rpm = 0;
     set(double rpm, rev::ControlType::kVelocity);
}


}

 void Shooter::moreSpeed(){
    if (double rpm <= 5650){
        double rpm + adjustSpeed;
        set(double rpm, rev::ControlType::kVelocity);
    }
 }

 void Shooter::lessSpeed(){
    if (double rpm >= -5650){
        double rpm - adjustSpeed;
        set(double rpm, rev::ControlType::kVelocity);
 }
 }





