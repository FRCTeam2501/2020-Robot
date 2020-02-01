#include "Pneumatics/Pneumatics.h"
using namespace frc;


Pneumatics::Pneumatics() {
    compressor = new Compressor(CAN::PCM);

    climbArm = new DoubleSolenoid(CAN::PCM, PCM::CLIMBER_ARM_A, PCM::CLIMBER_ARM_B);
    climbExtend = new DoubleSolenoid(CAN::PCM, PCM::CLIMBER_EXTEND_A, PCM::CLIMBER_EXTEND_B);
    intake = new DoubleSolenoid(CAN::PCM, PCM::INTAKE_A, PCM::INTAKE_B);
    shooter = new DoubleSolenoid(CAN::PCM, PCM::SHOOTER_A, PCM::SHOOTER_B);

    compressor->ClearAllPCMStickyFaults();
	cout << "Pneumatics Subsystem Booted!\n";
}

Pneumatics::~Pneumatics() {
    delete compressor;

    delete climbArm;
    delete climbExtend;
    delete intake;
    delete shooter;
}

void Pneumatics::Periodic() {}