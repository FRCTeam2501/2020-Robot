#include "Pneumatics/Pneumatics.h"
using namespace frc;


Pneumatics::Pneumatics() {
    compressor = new Compressor(CAN::PCM);

    climbRight = new DoubleSolenoid(CAN::PCM, PCM::CLIMBER_RIGHT);
    climbLeft = new DoubleSolenoid(CAN::PCM, PCM::CLIMBER_LEFT);
    intakeRight = new DoubleSolenoid(CAN::PCM, PCM::INTAKE_RIGHT);
    intakeLeft = new DoubleSolenoid(CAN::PCM, PCM::INTAKE_LEFT);

    compressor->ClearAllPCMStickyFaults();
}

Pneumatics::~Pneumatics() {
    delete compressor;

    delete climbRight;
    delete climbLeft;
    delete intakeRight;
    delete intakeLeft;
}

void Pneumatics::Periodic() {}
