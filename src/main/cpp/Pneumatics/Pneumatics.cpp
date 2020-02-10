#include "Pneumatics/Pneumatics.h"


Pneumatics::Pneumatics() {
	compressor = new frc::Compressor(CAN::PCM);

	climbArm = new frc::DoubleSolenoid(CAN::PCM, PCM::CLIMBER_ARM_A, PCM::CLIMBER_ARM_B);
	climbExtend = new frc::DoubleSolenoid(CAN::PCM, PCM::CLIMBER_EXTEND_A, PCM::CLIMBER_EXTEND_B);
	intake = new frc::DoubleSolenoid(CAN::PCM, PCM::INTAKE_A, PCM::INTAKE_B);
	hopper = new frc::DoubleSolenoid(CAN::PCM, PCM::SHOOTER_A, PCM::SHOOTER_B);

	compressor->ClearAllPCMStickyFaults();
	cout << "Pneumatics Subsystem Booted!\n";
}

Pneumatics::~Pneumatics() {
	delete compressor;

	delete climbArm;
	delete climbExtend;
	delete intake;
	delete hopper;
}

void Pneumatics::Periodic() {}