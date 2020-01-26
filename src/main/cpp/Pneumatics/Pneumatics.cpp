#include "Pneumatics/Pneumatics.h"
using namespace frc;


Pneumatics::Pneumatics() {
    compressor = new Compressor(CAN::PCM);

    climbArm = new DoubleSolenoid(CAN::PCM, PCM::SOL_CLIMBER_ARM_A, PCM::SOL_CLIMBER_ARM_B);
    climbExtend = new DoubleSolenoid(CAN::PCM, PCM::SOL_CLIMBER_EXTEND_A, PCM::SOL_CLIMBER_EXTEND_B);
    intake = new DoubleSolenoid(CAN::PCM, PCM::SOL_INTAKE_A, PCM::SOL_INTAKE_B);
    shooter = new DoubleSolenoid(CAN::PCM, PCM::SOL_SHOOTER_A, PCM::SOL_SHOOTER_B);

    compressor->ClearAllPCMStickyFaults();
}

Pneumatics::~Pneumatics() {
    delete compressor;

    delete climbArm;
    delete climbExtend;
    delete intake;
    delete shooter;
}

void Pneumatics::Periodic() {}