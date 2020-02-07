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

Shooter::toggle(){

if (Toggle = 1){
    return Toggle = 0;
}else {
    if(Toggle = 0){
    return Toggle = 1;
    }
}

if Toggle(){

double rpm = 3900; 

void set(double rpm, rev::ControlType::kVelocity);
return Toggle = false;
} else {
   double rpm = 0;
    void set(double rpm, rev::ControlType::kVelocity);
}


}

 Shooter::moreSpeed(){
    if (double rpm < 5650){
       double rpm + adjustSpeed;
        void set(double rpm, rev::ControlType::kVelocity);
    }
 }

 Shooter::lessSpeed(){
if (double rpm > -5650){
 double rpm + adjustSpeed;
void set(double rpm, rev::ControlType::kVelocity);
 }
 }





