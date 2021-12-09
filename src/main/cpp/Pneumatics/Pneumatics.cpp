#include "Pneumatics/Pneumatics.h"



Pneumatics::Pneumatics() {
	compressor = new Compressor(CAN::CAN_PCM);
	verticalLift = new DoubleSolenoid (PCM::SOL_VERTICALLIFT_A, PCM::SOL_VERTICALLIFT_B);
	climb = new DoubleSolenoid (PCM::SOL_CLIMB_A, PCM::SOL_CLIMB_B);
	intake = new DoubleSolenoid (PCM::SOL_INTAKE_A, PCM::SOL_INTAKE_B);

	checkFaults();
	checkSticky();
	clearSticky();

	checkFaults();
	checkSticky();
}

void Pneumatics::checkSticky() {
	if(compressor->GetCompressorShortedStickyFault())
		std::cout << "Compressor shorted sticky fault.\n";
	if(compressor->GetCompressorCurrentTooHighStickyFault())
		std::cout << "Compressor current too high sticky fault.\n";
	if(compressor->GetCompressorNotConnectedStickyFault())
		std::cout << "Compressor not connected sticky fault.\n";
}

void Pneumatics::checkFaults() {
	if(compressor->GetCompressorShortedFault())
		std::cout << "Compressor shorted.\n";
	if(compressor->GetCompressorCurrentTooHighFault())
		std::cout << "Compressor current too high.\n";
	if(compressor->GetCompressorNotConnectedFault())
		std::cout << "Compressor not connected.\n";
}

void Pneumatics::clearSticky() {
	compressor->ClearAllPCMStickyFaults();
}

Pneumatics::~Pneumatics(){
	delete intake;
	delete compressor;
	delete verticalLift;
	delete climb;
}

void Pneumatics::InitPneumatics(){

	verticalLift->Set(DoubleSolenoid::kReverse);
	climb->Set(DoubleSolenoid::kReverse);

}

void Pneumatics::DisableAll()
{
	verticalLift->Set(DoubleSolenoid::kOff);
	climb->Set(DoubleSolenoid::kOff);
}

void Pneumatics::VerticalLiftExtend(){
	verticalLift->Set(DoubleSolenoid::kForward);
}

void Pneumatics::VerticalLiftRetract(){
	verticalLift->Set(DoubleSolenoid::kReverse);
}

void Pneumatics::ClimbExtend(){
	climb->Set(DoubleSolenoid::kForward);
}

void Pneumatics::ClimbRetract(){
	climb->Set(DoubleSolenoid::kReverse);
}

void Pneumatics::ToggleVert(){
	switch(verticalLift->Get()){
		case DoubleSolenoid::kForward:
			verticalLift->Set(DoubleSolenoid::kReverse);
			break;

		case DoubleSolenoid::kReverse:
			verticalLift->Set(DoubleSolenoid::kForward);
			break;

		case DoubleSolenoid::kOff:
			verticalLift->Set(DoubleSolenoid::kForward);
			break;

		default:
			break;
	}
}

void Pneumatics::ToggleClimb(){
	switch(climb->Get()){    
		case DoubleSolenoid::kForward:
			climb->Set(DoubleSolenoid::kForward);     
			break;

		case DoubleSolenoid::kReverse:
			climb->Set(DoubleSolenoid::kReverse);
			break;

		case DoubleSolenoid::kOff:
			climb->Set(DoubleSolenoid::kForward);
			break;

		default:
			break;
	}
}

void Pneumatics::ToggleIntake(){
	switch(intake->Get()){    
		case DoubleSolenoid::kForward:
			intake->Set(DoubleSolenoid::kForward);     
			break;

		case DoubleSolenoid::kReverse:
			intake->Set(DoubleSolenoid::kReverse);
			break;

		case DoubleSolenoid::kOff:
			intake->Set(DoubleSolenoid::kForward);
			break;

		default:
			break;
	}
}

void Pneumatics::Check() {
	checkFaults();
	checkSticky();
	clearSticky();

	checkFaults();
	checkSticky();
}