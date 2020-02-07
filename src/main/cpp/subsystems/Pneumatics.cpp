
#include "subsystems/Pneumatics.h"




Pneumatics::Pneumatics() {

compressor = new Compressor(CAN::CAN_PCM);

verticalifyer = new DoubleSolenoid (PCM::SOL_VERTICALIFYER_A, PCM::SOL_verticalifyer_B);
uppyWuppy = new DoubleSolenoid (PCM::SOL_UPPYWUPPY_A, PCM::SOL_UPPYWUPPY_B);
intake = new DoubleSolenoid (PCM::SOL_INTAKE_A, PCM::SOL_INTAKE_B);

}


Pneumatics::~Pneumatics(){

delete compressor;
delete verticalifyer;
delete uppyWuppy;
delete intake;

}


void Pneumatics::InitPneumatics(){

verticalifyer->Set(DoubleSolenoid::kReverse);
uppyWuppy->Set(DoubleSolenoid::kReverse);

}

void Pneumatics::DisableAll()
{
	verticalifyer->Set(DoubleSolenoid::kOff);
	uppyWuppy->Set(DoubleSolenoid::kOff);
}
 
void Pneumatics::verticalifyerExtend(){
    verticalifyer->Set(DoubleSolenoid::kForward);
}

void Pneumatics::verticalifyerRetract(){
    verticalifyer->Set(DoubleSolenoid::kReverse);
}

void Pneumatics::uppyWuppyExtend(){
    uppyWuppy->Set(DoubleSolenoid::kForward);
}

void Pneumatics::uppyWuppyRetract(){
    uppyWuppy->Set(DoubleSolenoid::kReverse);
}

void Pneumatics:: intakeExtend(){
    intake->Set(DoubleSolenoid::kForward);
}

void Pneumatics:: intakeRetract(){
    intake->Set(DoubleSolenoid::kReverse);
}







