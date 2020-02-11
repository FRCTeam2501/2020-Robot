
#pragma once
#include "Utils/include.h"
using namespace frc;
class climber : public frc2::SubsystemBase{
public:

climber();
~climber();

void periodic();

void SpinDin(double x);

private:


rev::CANSparkMax *left, *right;




};