#include "Pneumatics/Pneumatics.h"




Pneumatics::Pneumatics() {

compressor = new Compressor(CAN::CAN_PCM);

VerticalLift = new DoubleSolenoid (PCM::SOL_VERTICALLIFT_A, PCM::SOL_VERTICALLIFT_B);

Climb = new DoubleSolenoid (PCM::SOL_CLIMB_A, PCM::SOL_CLIMB_B);

Intake = new DoubleSolenoid (PCM::SOL_INTAKE_A, PCM::SOL_INTAKE_B);



}


Pneumatics::~Pneumatics(){

delete Intake;
delete compressor;
delete VerticalLift;
delete Climb;

}


void Pneumatics::InitPneumatics(){

    VerticalLift->Set(DoubleSolenoid::kReverse);
    Climb->Set(DoubleSolenoid::kReverse);

}

void Pneumatics::DisableAll()
{
	VerticalLift->Set(DoubleSolenoid::kOff);
	Climb->Set(DoubleSolenoid::kOff);
}
 
void Pneumatics::VerticalLiftExtend(){
    VerticalLift->Set(DoubleSolenoid::kForward);
}

void Pneumatics::VerticalLiftRetract(){
    VerticalLift->Set(DoubleSolenoid::kReverse);
}

void Pneumatics::ClimbExtend(){
    Climb->Set(DoubleSolenoid::kForward);
}

void Pneumatics::ClimbRetract(){
    Climb->Set(DoubleSolenoid::kReverse);
}

void Pneumatics::ToggleVert(){
    switch(VerticalLift->Get()){
        case DoubleSolenoid::kForward:
             VerticalLift->Set(DoubleSolenoid::kReverse);
            break;

        case DoubleSolenoid::kReverse:
             VerticalLift->Set(DoubleSolenoid::kForward);
             break;

        case DoubleSolenoid::kOff:
             VerticalLift->Set(DoubleSolenoid::kForward);
            break;

        default:
            break;
    }
}

void Pneumatics::ToggleClimb(){
    switch(Climb->Get()){    
        case DoubleSolenoid::kForward:
             Climb->Set(DoubleSolenoid::kForward);     
            break;

        case DoubleSolenoid::kReverse:
             Climb->Set(DoubleSolenoid::kReverse);
            break;

        case DoubleSolenoid::kOff:
             Climb->Set(DoubleSolenoid::kForward);
            break;

        default:
            break;
    }
}

void Pneumatics::ToggleIntake(){
    switch(Intake->Get()){    
        case DoubleSolenoid::kForward:
             Intake->Set(DoubleSolenoid::kForward);     
            break;

        case DoubleSolenoid::kReverse:
             Intake->Set(DoubleSolenoid::kReverse);
            break;

        case DoubleSolenoid::kOff:
             Intake->Set(DoubleSolenoid::kForward);
            break;

        default:
            break;
    }
}

void Pneumatics::ToggleHopper() {
    //NOTHING!
}