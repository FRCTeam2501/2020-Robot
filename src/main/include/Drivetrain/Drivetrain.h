#pragma once
#include "Utils/include.h"
using namespace frc;

class Drivetrain : public frc2::SubsystemBase {  

public:

Drivetrain();
~Drivetrain();
void ArcadeDrive(double x, double z);

void Periodic();

private:

DifferentialDrive *drive;
PWMVictorSPX *frontLeft, *frontRight, *rearRight,*rearLeft;
SpeedControllerGroup *left, *right;

};