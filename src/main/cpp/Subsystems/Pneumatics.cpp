#include "Subsystems/Pneumatics.h"


Pneumatics::Pneumatics() {
	compressor = new frc::Compressor(PORTS::CAN::PCM);

	climbArm = new frc::DoubleSolenoid(PORTS::CAN::PCM, PORTS::PCM::CLIMBER_ARM_A, PORTS::PCM::CLIMBER_ARM_B);
	climbExtend = new frc::DoubleSolenoid(PORTS::CAN::PCM, PORTS::PCM::CLIMBER_EXTEND_A, PORTS::PCM::CLIMBER_EXTEND_B);
	intake = new frc::DoubleSolenoid(PORTS::CAN::PCM, PORTS::PCM::INTAKE_A, PORTS::PCM::INTAKE_B);
	hopper = new frc::DoubleSolenoid(PORTS::CAN::PCM, PORTS::PCM::SHOOTER_A, PORTS::PCM::SHOOTER_B);

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