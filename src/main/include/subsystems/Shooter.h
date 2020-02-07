#include "Utils/include.h"


using namespace rev;

class Shooter : public frc2::SubsystemBase 
{
private:


CANSparkMax *spinnyThrowerLeft, *spinnyThrowerRight;
//spinnyThrower is the motor controller for the flywhele.
    
double kP = 6e-5, kI = 1e-6, kD = 0, kIz = 0, kFF = 0.000015, kMaxOutput = 1.0, kMinOutput = -1.0;
const double MaxRPM = 5700;
bool Toggle = 0;
double rpm, adjustSpeed = 50;

public:
    Shooter();
    ~Shooter();
    void flywheleSpeed(double SetPoint);
    toggle();
    moreSpeed();
    lessSpeed();


};
